/*
 *  rcf008_repl_v5.c
 *   - Implements a simple parser for polish mathematical grammar.
 *   - Traverses and evaluates the syntax tree generated by MPC. 
 *   - Uses the readline and history libraries for a simple REPL.
 *
 *  Copyright (C) 2018 Ryan Fleck under the GNU GPLv3.
 *
 *  Prerequisites: mpc.c, mpc.h, libedit-dev, libreadline-dev.
 *   MPC repo at <github.com/orangeduck/mpc> 
 *
 *  Compilation Instructions:  
 *   (GNU/Linux) cc -stc=c99 -Wall <file> mpc.c -ledit -lm
 */
#include <stdio.h>
#include <stdlib.h>
#include "mpc.h" //Included in projects repo.

#ifdef _WIN32
#include <string.h>

static char buffer[2048];

char* readline(char* prompt){
  fputs(prompt, stdout);
  fgets(buffer, 2040, stdin);
  char* cpy = malloc(strlen(buffer)+1);
  strcpy(cpy, buffer);
  cpy[strlen(cpy)-1]='\0';
  return cpy;
}

void add_history(char* unused){}

#else
#include <editline/readline.h>
#include <editline/history.h>
#endif


int rml_analyze(mpc_ast_t* tree);
long rml_eval(mpc_ast_t* tree);
long rml_op(long x, char* op, long y);

int main(int argc, char** argv){
 
  //Define grammar: 
  mpc_parser_t* Number = mpc_new("number");
  mpc_parser_t* Operator = mpc_new("operator");
  mpc_parser_t* Expr = mpc_new("expr");
  mpc_parser_t* RML = mpc_new("rml");
  mpca_lang( MPCA_LANG_DEFAULT,
  "                                                    \
    number   : /-?[0-9]+/ ;                            \
    operator : '+' | '-' | '*' | '/' | '^' | '%' ;                 \
    expr     : <number> | '(' <operator> <expr>+ ')' ; \
    rml      : /^/ <operator> <expr>+ /$/ ;    \
  ", Number, Operator, Expr, RML );

  //Enter REPL:
  puts("Ryan's Micro LISP (RML) Version 0.0.0.5"); 
  puts("Press Ctrl+C to Exit\n");

  //Add an item to the history so I don't need to type it over and over:
  add_history("+ 1 2 (+ 3 4 5) 6 (* 7 8 (+ 9 10))");

  while(1){
    
    char* input = readline("rml > ");
    mpc_result_t r;  
    add_history(input);
    
    if( mpc_parse("<stdin>", input, RML, &r) ){
      //rml_analyze(r.output);
      long result = rml_eval(r.output); 
      printf("\n\nans > %li\n\n", result);
      mpc_ast_delete(r.output);  
    }else{
      mpc_err_print(r.error); 
      mpc_err_delete(r.error); 
    }
    
    free(input);
  }
  
  return 0;
}

//atoi() converts char* to a long.
//strcmp() takes two char*s as input and returns 0 if they are equal.
//strstr() Checks if the second string is present within the first.

//Evaluates the MPC tree.
long rml_eval(mpc_ast_t* tree){
  
  if(strstr(tree->tag, "number")){
    return atoi(tree->contents);
  }

  char* op = tree->children[1]->contents;
  long x = rml_eval(tree->children[2]);
  
  int i = 3;
  while( strstr(tree->children[i]->tag, "expr") ){
    x = rml_op(x, op, rml_eval(tree->children[i])); 
    i++;
  }

  return x;
}

//Performs an operation on two numbers.
long rml_op(long x, char* op, long y){
  if(!strcmp(op,"+")){return x+y;} 
  if(!strcmp(op,"-")){return x-y;} 
  if(!strcmp(op,"/")){return x/y;} 
  if(!strcmp(op,"*")){return x*y;} 
  if(!strcmp(op,"^")){
    int z = x;
    printf("Multiplying %i exponentially by %i",x,y);
    for(int i=0; i<y; i++){z = z*x;}
    return z;
    } 
  if(!strcmp(op,"%")){
    return 1;
    } 
  return 0;
}

//Recursive analysis functions. (Half implemented.)
int rml_analyze(mpc_ast_t* tree){

  puts("MPC Syntax Tree:"); 
  mpc_ast_print(tree);
  puts(""); 

  int describe_node(mpc_ast_t* n){
    printf("\n\nNode Info:\n  Tag: %s\n  Content: %s\n  Children: %i",n->tag,n->contents,n->children_num);
    return 0;
  }


  int count_nodes(mpc_ast_t* tree){
    describe_node(tree);
    if( tree->children_num == 0 ){return 1;}
    if( tree->children_num >= 1 ){
      int total = 1;
      for(int i=0; i < tree->children_num; i++){
        total = total + count_nodes(tree->children[i]);
      }
      return total;
    }
    return 0;
  }
  int nodes = count_nodes(tree);
 

  int count_children(mpc_ast_t* tree){
    puts("Counting children...");
    return 0;
  }
  int children = count_children(tree);
 

  int count_branches(mpc_ast_t* tree){
    puts("Counting branches...");
    return 0;
  }
  int branches = count_branches(tree);
 

  printf("\nTree Info:\n\nNodes: %i\nChildren: %i\nBranches: %i", 
    nodes, children, branches);
  return 0;
}

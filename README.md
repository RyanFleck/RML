# Ryan's Micro LISP

[![Build Status](https://travis-ci.org/RyanFleck/RML.svg?branch=master)](https://travis-ci.org/RyanFleck/RML)

![RML](/docs/assets/rml.svg)

This is a tiny lisp. No use case yet, just building it for fun. It can currently only parse polish mathematical grammar with the four basic operations, separated with parentheses to an infinite depth. It can compile across UNIX OSes (discluding MacOS,) but with reduced history and line-editing functionality on Windows. Uses the `astyle` program invoked as `astyle -A3 rml.c` to enforce K&R formatting.

**Demo:**
```lisp
Ryan's Micro LISP (RML) Version 0.0.0.6
Press Ctrl+C to Exit

rml > + 1 2 (+ 3 4 5) 6 (* 7 8 (+ 9 10))
    = 1085

```

The latest build (not sure why you'd use this,) can be found [here.](https://github.com/RyanFleck/RML/releases)
More documentation can be found [here.](https://ryanfleck.github.io/RML/)

## Additions to VimRC

On a whim, I've decided to use `clang-format` as my code formatter, but upon
running it, found it uses two spaces for indentation. No matter - I made the
following tweaks to my `.vimrc` to account for this.

```vim
autocmd FileType c call SetCOptions()
function SetCOptions()
    nnoremap <F8> :w<cr> :! clear && gcc % && clear && ./a.out<cr>
    nnoremap <F7> :w<cr> :! clear && clang-format -i % && echo "Formatted."<cr>
    set tabstop=2
    set shiftwidth=2
    set softtabstop=2
endfunction
```

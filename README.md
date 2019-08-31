# Ryan's Micro LISP

[![Build Status](https://travis-ci.org/RyanFleck/RML.svg?branch=master)](https://travis-ci.org/RyanFleck/RML)

![RML](/docs/assets/rml.svg)

This is a tiny lisp. No use case yet, just building it for fun. It can currently only parse polish mathematical grammar with the four basic operations, separated with parentheses to an infinite depth. It can compile across UNIX OSes (discluding MacOS,) but with reduced history and line-editing functionality on Windows. Uses the `astyle` program invoked as `astyle -A3 rml.c` to enforce K&R formatting.

## TODOs

- Look into *ValGrind*

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

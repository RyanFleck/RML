# Ryan's Micro LISP

[![Build Status](https://travis-ci.org/RyanFleck/RML.svg?branch=master)](https://travis-ci.org/RyanFleck/RML)

![RML](/docs/assets/rml.svg)

This is a tiny lisp. No use case yet, just building it for fun. It can currently only parse polish mathematical grammar with the four basic operations, separated with parentheses to an infinite depth. It can compile across UNIX OSes (discluding MacOS,) but with reduced history and line-editing functionality on Windows. 

**Demo:**
```lisp
Ryan's Micro LISP (RML) Version 0.0.0.6
Press Ctrl+C to Exit

rml > + 1 2 (+ 3 4 5) 6 (* 7 8 (+ 9 10))
    = 1085

```

The latest build (not sure why you'd use this,) can be found [here.](https://github.com/RyanFleck/RML/releases)
More documentation can be found [here.](https://ryanfleck.github.io/RML/)

# Ryan's Micro LISP

[![Build Status](https://travis-ci.org/RyanFleck/RML.svg?branch=master)](https://travis-ci.org/RyanFleck/RML)

![RML](/docs/assets/rml.svg)

This is a tiny lisp. No use case yet, just building it for fun. It can currently only parse polish mathematical grammar with the four basic operations, separated with parentheses to an infinite depth.

**Demo:**
```lisp
Ryan's Micro LISP (RML) Version 0.0.0.5
Press Ctrl+C to Exit

rml > + 1 2 (+ 3 4 5) 6 (* 7 8 (+ 9 10))


ans > 1085
```

The latest build (not sure why you'd use this,) can be found [here.](https://github.com/RyanFleck/RML/releases)

This fun side project was built using [this fantastic tutorial](http://www.buildyourownlisp.com/). I recommend it to anybody wanting to learn `C`. 

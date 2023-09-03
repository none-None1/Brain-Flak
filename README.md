# Brain-Flak
 Cross-platform Brain-Flak implementations

This repo contains my cross-platform implementations of the [Brain-Flak](https://esolangs.org/wiki/Brain-Flak) language.

It currently contains only a C++ implementation (Brain-Crack) which has the following features:
* Unlike Crane-Flak, Brain-Crack doesn't use platform-specific functions, so it can work on **any** platform, but Crane-Flak doesn't work on Windows because it uses the `fmemopen` function.
* Brain-Crack supports debugging, but you **can't** set breakpoints, instead, Brain-Crack outputs the left and right stacks for **every** command if debug mode is on.
* Brain-Crack supports both integer output and ASCII output.
* Integers in Brain-Crack are from `-9223372036854775808` to `9223372036854775807`.
* Brain-Crack supports comments, the characters between two `#`'s are comments and are removed when preprocessing, therefore they are neither parsed nor executed. Characters other than brackets are also ignored and are neither parsed nor executed.
* Brain-Crack allows you to customize how the stack is traversed when output, if the argument `-u` is set, it traversed from bottom to top, otherwise top to bottom.
  
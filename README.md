# _printf()

<img src="https://raw.githubusercontent.com/johncoleman83/printf/master/dev/printf-screen-shot.png" alt="screen shot of custom printf function">

## Description

This Repo has our (David John Coleman II and Joann Vuong's) version of C
function ``printf()`` from ``stdio.h`` coded in C Language.  It is a part of our
work as a student at Holberton School.  The purpose of the primary functions in
this repo is create a function, ``_printf()`` that behaves exactly the same as
the C function ``printf()``.

### C functions used

* ``write``, ``malloc``, ``free``, ``va_start``, ``va_end``, ``va_copy``,
``va_arg``

## Brief Synopsis

``_printf()`` function takes 2 arguments: a character pointer to a string:
``format``, and a 'variable arguments list': ``arg_list``.  ``_printf()`` loops
through the format string searching for a conversion specifier, which is
indicated with the '%' symbol.  If found, the ``match_specifier()`` function
loops through an array of structs (contianing character and function pairs) to
find the specifier function that is matched with the given conversion specifier
from the format string, and then returns a pointer to that paired function.
``_printf()`` uses the pointer to that specifier function to call the specifier
function on the next argument from the ``arg_list``.  Each specifier function
writes a character one at a time as determined from the value in ``arg_list``.
Our code writes the characters to the buffer, in the 'buffer' branch and in the
'bo-buffer' branch, our code is instead written to standard output.
For instances of the format string that are not specifiers (non '%' prefixed
characters, whatever character is processed in the ``format`` string is written
to the buffer one at a time (or written to the standard output).  When the
buffer is full or in the end of ``_printf``, the buffer is then written to
standard output using ``write()`` function.

## File List

* ``./_printf.c``: custom ``printf()`` function that loops through format string
to then use a callback function, which finds the associated helper function,
which writes characters to buffer or standard output using custom ``_putchar()``
function.
* ``./match_specifier.c``: helper function file to match the given directive
with the associated helper print function

  #### files that contain the functions associated with all the specifiers
  * ``./specifier_cpsrr.c``: functions to write specifiers: ``c`` (char),``s``
  (string), ``%`` (percent), ``r`` (reverse string), and ``R`` (rot13) to the
  buffer.
  * ``./specifier_uoxX.c``: functions to write specifiers: ``u`` (unsigned int),
  ``o`` (octal), ``x`` (hexidecimal lowercase), ``X`` (hexidecimal uppercase)
  * ``./specifier_dib.c``: functions to write specifiers: ``d`` (integer), ``i``
  (integer), and ``b`` (binary) to the buffer.
  * ``./specifier_Sp.c``: functions to write specifiers: ``S`` (string and hex
  combination), and ``p`` (pointers in hexidecimal).

* ``./helper_funcs.c``: file that contains helper functions

  #### functions in helper file:
  * ``putchar()``: function called ``_putchar()`` to write chars to standard
  output 1 at a time
  * ``_strlen``: custom function to find string length
  * ``rev_string()``: custom reverse string function to reverse a string
  * ``skip_spaces()``: which is a function to skip trailing spaces after the '%'
  directive.

* ``./holberton.h``: header file that contains all necessary included libraries
for all functions, the struct prototype and type definition for the struct,
and prototypes for all functions
* ``./man_printf``: manual file including the manual for how our custom printf
functions.

#### development directory
  * ``./dev/``: contains a template file with function template, the redirection
  of standard output into 'expected' from test cases of standard ``printf()``
  and my output of test cases into 'custom' file.  directory also included all
  other files of function ``_printf()``.
  * ``./dev/prinf-screen-shot.png`` a screenshot of the custom ``_printf()``

#### main directory
  * this directory contains ``main()`` functions for testing custom .c files and
  testing the expected output of standard C version of ``printf()``
  * ``./dev/main/main.c``: tests expected output of standard ``printf()``
  function.  Can be compiled on its own - no need for other functions
  * ``./dev/main/custom_main.c``: tests actual output of custom ``_printf()``
  function

## buffer branch specifications

* ``./buffer.c``: contains functions for working with the buffer
  #### functions in buffer file:
  * ``_calloc()``: allocates memory slots filled with null: '\0' byte
  * ``add_to_buffer()``: adds characters 1 at at a time to the buffer
  * ``print_buffer()``: prints the entire buffer using ``_putchar()`` function
  of 1024 chars

## Authors

David John Coleman II - http://www.davidjohncoleman.com/  
Joann Vuong - https://github.com/jvpupcat

## License

Public Domain, no copyright protection

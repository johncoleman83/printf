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
``format``, and a 'variable arguments list': ``arg_list``.  The
``get_directive()`` function uses a struct to determines what helper function
is matched with, which directive and returns a pointer to that function.
``_printf()`` uses the pointer to that function to call the helper function on
the next argument from the ``arg_list``.  Each helper function stores each
character from the value in ``arg_list`` into a buffer.  If no directive is
found, whatever character being evaluated in the ``format`` string is added to
the buffer one at a time.  When the buffer is full or in the end of ``_printf``,
the buffer is print to standard output using ``write()`` function.

## File List

* ``./_printf.c``: custom ``printf()`` function that loops through format string
to then use a callback function, which finds the associated helper function,
which writes characters to a buffer to be printed with custom ``_putchar()``
function that writes characters to standard output one at a time.
* ``./get_directive.c``: helper function file to match the given directive with
the associated helper print function

  #### files that contain the functions associated with all the directives
  * ``./directives_cpsrr.c``: helper functions to write directives: ``c``
  (char),``s`` (string), ``%`` (percent), ``r`` (reverse string), and ``R``
  (rot13) to the buffer.
  * ``./directives_uoxX.c``: helper functions to write directives: ``u``
  (unsigned int), ``o`` (octal), ``x`` (hexidecimal lowercase), ``X``
  (hexidecimal uppercase)
  * ``./directives_dib.c``: helper functions to write directives: ``d``
  (integer), ``i`` (integer), and ``b`` (binary) to the buffer.

* ``./buffer.c``: contains functions for working with the buffer
  #### functions in buffer file:
  * ``_calloc()``: allocates memory slots filled with null: '\0' byte
  * ``add_to_buffer()``: adds characters 1 at at a time to the buffer
  * ``print_buffer()``: prints the entire buffer using ``_putchar()`` function
  of 1024 chars

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

## Authors

David John Coleman II - http://www.davidjohncoleman.com/  
Joann Vuong - https://github.com/jvpupcat

## License

Public Domain, no copyright protection

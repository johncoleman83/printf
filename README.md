# _printf()

<img src="https://raw.githubusercontent.com/johncoleman83/printf/master/dev/printf-screen-shot.png" alt="screen shot of custom printf function">

## Description

This Repo has our (David John Coleman II and Joann Vuong's) version of C
function ``printf()`` from ``stdio.h`` coded in C Language.  It is a part of our
work as a student at Holberton School.  The purpose of the primary functions in
this repo is create a function, ``_printf()`` that behaves exactly the same as
the C function ``printf()``.

### Commands / functions used

* ``write``, ``malloc``, ``free``, ``va_start``, ``va_end``, ``va_copy``,
``va_arg``

## File List

* ``./_printf.c``: custom ``printf()`` function that loops through format string
to then use a callback function, which finds the associated helper function,
which writes characters to a buffer to be printed with custom ``_putchar()``
function that writes characters to standard output one at a time.
* ``./get_directive.c``: helper function file to match the given directive with
the associated helper print function
* ``./csp_printf.c``: helper functions to write directives: ``c``, ``s``, and
``%`` to the buffer
* ``./dib_printf.c``: helper functions to write directives: ``d``, ``i``, and
``b`` (binary) to the buffer.
* ``print_buffer.c``: this function prints the buffer when it reaches capacity
of 1024 chars
* ``./_putchar.c``: custom ``putchar()`` function to write chars to standard
output 1 at a time
* ``./holberton.h``: header file that contains all necessary included libraries
for all functions, the struct definition and type def for struct, and prototypes
for all functions
* ``./man_printf``: manual page describing how our custom printf functions.
* ``./dev/``: development directory that contains a template file with function
template, the redirection of standard output into expected and my output of test
cases, and other files used simply for testing
* ``./dev/prinf-screen-shot.png`` a screenshot of the custom ``_printf()``
* ``./dev/main/main.c``: tests expected output of standard ``printf()`` function
* ``./dev/main/custom_main.c``: tests actual output of custom ``_printf()``
function

## Authors

David John Coleman II - http://www.davidjohncoleman.com/  
Joann Vuong - https://github.com/jvpupcat

## License

Public Domain, no copyright protection

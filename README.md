# _printf()

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

* ``./dev/main/main.c``: tests expected output of standard ``printf()`` function
* ``./dev/main/my_main.c``: tests actual output of custom ``_printf()`` function
* ``./get_directive.c``: helper function file to match the given directive with
the associated helper print function
* ``./_printf.c``: custom ``printf()`` function that loops through format string
to then use a callback function, which finds the associated helper function,
which uses custom ``_putchar()`` function to write characters to standard output
one at a time.
* ``./0_printf.c``: helper functions to print directives: ``c``, ``s``,
and ``%``
* ``./_putchar.c``: custom ``putchar()`` function to write chars to standard
output 1 at a time
* ``./holberton.h``: header file that contains all necessary included libraries
for all functions, the struct definition and type def for struct, and prototypes
for all functions
* ``./dev/``: development directory that contains a template file with function
template, the redirection of standard output into expected and my output of test
cases, and other files used simply for testing

## Authors

David John Coleman II - http://www.davidjohncoleman.com/  
Joann Vuong - https://github.com/jvpupcat

## License

Public Domain, no copyright protection

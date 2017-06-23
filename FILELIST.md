## File List

* ``./_printf.c``: custom ``printf()`` function that loops through format string
to then use a callback function, which finds the associated helper function,
which writes characters to buffer or standard output using custom ``_putchar()``
function.
* ``./match_cases.c``: helper function file to match the given directives and
modifiers with the associated helper functions

  #### functions contianed in this file:
  * ``match_modifier()``: checks if the trailing character after the '%' is a
  modifier
  * ``match_specifier()``: checks if the trailing character after the '%' is a
  specifier

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

  #### files that contain modifier functions
  * ``./modifiers_long.c``: contains functions to print long integers in
  signed and unsigned decimal, and unsigned hex and octal.

* ``./helper_funcs.c``: file that contains helper functions

  #### functions in helper file:
  * ``_putchar()``: function called ``_putchar()`` to write chars to standard
  output 1 at a time
  * ``_strlen``: custom function to find string length
  * ``_strlenconst``: custom function to find string length for type 'const
  char'.
  * ``rev_string()``: custom reverse string function to reverse a string.  This
  function became obsolete when we realized that we could not write to a
  variable argument list item.
  * ``skip_spaces()``: which is a function to skip trailing spaces after the '%'
  directive.  This function is in development phase.

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
  * ``./dev/prinf-screen-shot.png`` a screenshot of the custom ``_printf()``.
  This is a former version of our function.  For updated screenshot see root
  directory of our repository.

#### main directory
  * this directory contains ``main()`` functions for testing custom .c files and
  testing the expected output of standard C version of ``printf()``
  * ``./dev/main/main.c``: tests expected output of standard ``printf()``
  function.  Can be compiled on its own - no need for other functions
  * ``./dev/main/custom_main.c``: tests actual output of custom ``_printf()``
  function
  * ``./dev/main/combo_main.c``: tests actual output of custom ``_printf()``
  function and expected output of ``printf()`` function together.  Most test
  cases are for standard functions.

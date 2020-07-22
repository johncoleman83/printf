## File List

* `./_printf.c`: custom `printf()` function that loops through format string
to then use a callback function, which finds the associated helper function,
which writes characters to buffer or standard output using custom `_putchar()`
function.
* `./match_cases.c`: helper function file to match the given directives and
modifiers with the associated helper functions

  #### functions contianed in this file:
  * `match_specifier()`: checks if the trailing character after the '%' is a
  specifier, and looks for modifiers as well

  #### files that contain the functions associated with all the specifiers
  * `./character_write_buffer.c`, `reversed_string.c`, `rot13.c`,
  `string_write_buffer.c`: functions to write specifiers: (char), (string),
  (percent), (reverse string), and (rot13) to the buffer.
  * `unsigned_int.c`, `hex.c`: functions to write specifiers: (unsigned int),
  (octal), (hexidecimal lowercase), (hexidecimal uppercase)
  * `./binary.c`: functions to write specifiers: (integer), and (binary)
  to the buffer.
  * `./string_pointer.c`: functions to write specifiers: (string and hex
  combination), and (pointers in hexidecimal).

* `./strings.c`: file that contains strings functions

  #### functions in helper file:
  * `_putchar()`: function called `_putchar()` to write chars to standard
  output 1 at a time
  * `_strlen`: custom function to find string length
  * `_strlenconst`: custom function to find string length for type 'const
  char'.
  * `rev_string()`: custom reverse string function to reverse a string.  This
  function became obsolete when we realized that we could not write to a
  variable argument list item.

* `./bootcamp.h`: header file that contains all necessary included libraries
for all functions, the struct prototype and type definition for the struct,
and prototypes for all functions
* `./man_printf`: manual file including the manual for how our custom printf
functions.

#### development directory

  * `./dev/`: contains a template file with function template, the redirection
  of standard output into 'expected' from test cases of standard `printf()`
  and my output of test cases into 'custom' file.  directory also included all
  other files of function `_printf()`.
  * `./dev/prinf-screen-shot.png` a screenshot of the custom `_printf()`.
  This is a former version of our function.  For updated screenshot see root
  directory of our repository.

this directory also contains `main()` functions for testing custom .c files and
testing the expected output of standard C version of `printf()`

  * `./dev/main.c`: tests expected output of standard `printf()`
  function.  Can be compiled on its own - no need for other functions
  * `./dev/custom_main.c`: tests actual output of custom `_printf()`
  function
  * `./dev/combo_main.c`: tests actual output of custom `_printf()`
  function and expected output of `printf()` function together.  Most test
  cases are for standard functions.

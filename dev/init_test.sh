#!/usr/bin/env bash
# checks if code compiles with -W warning flags

# copy main file to cwd
cp dev/travis_test_main.c .

# compile with -W warning flags
gcc -Wall -Werror -Wextra -pedantic ./*.c -o testprintfile

# run code
./testprintfile

# cleanup
rm testprintfile travis_test_main.c

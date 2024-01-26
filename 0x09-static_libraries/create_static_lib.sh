#!/bin/bash

gcc -Wall -Werror -Wextra -pedantic -c *.c

ar -rc liball.a *.o

ranlib liball.a

# Display a message indicating successful library creation
echo "Static library liball.a created successfully."


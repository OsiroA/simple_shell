Simple Shell
A simple shell is a command-line interpreter program that provides a user interface for accessing the operating system's services. It is a program that accepts commands from the user and executes them. It is similar to the standard Unix shell, such as Bash, Zsh, or Ksh.

Description
The Simple Shell is a project that aims to build a simple Unix shell using the C programming language. It reads a command entered by the user, parses the command into its different arguments, and executes it.

The Simple Shell implements some built-in commands such as cd, echo, env, and exit, and also able to execute external commands.

The Simple Shell is designed to be portable and can run on different Unix-based operating systems.

Usage
To use the Simple Shell, you can compile with the source code using the gcc compiler and run the executable file. The shell will display a prompt where you can enter your commands.

Compilation:

gcc -Wall -Werror -Wextra -pedantic *.c -o hsh

Execution:

./hsh
Features
Display prompt.
Read and parse commands.
Execute built-in commands.
Handles errors and return codes.
Handles environmental variables.
Handles the PATH environment variable.
Execute external commands.
Handles command line arguments.
Handle signals.

Examples
Some examples on how to use the Simple Shell:
$ ./hsh
$ /bin/ls
$ ls
$ env
$ pwd
$ echo "Hello, World!"
$ exit

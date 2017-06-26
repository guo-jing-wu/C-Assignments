                                   Shell.c
SYNOPSIS
-----------
The Shell.c is an UNIX shell program. It is used to understand how child
processes are created to perform large-grained work and how the parent process
can follow up on a child process's work. Shell.c can utilize the UNIX commands
such as ls, more, and wc. Shell.c can also perform I/Oredirection and piping
using "<", ">", and "|". It is able to run a process in the background without
having to wait for the child process to terminate.

DESCRIPTION
-----------
The main function will be in an infinite loop so the program will continue
until the user requests to exit out of the shell. It creates a prompt for the
user to type an input into the command line. The input is then parse using the
parse function and check if the user type "exit" to exit out of the infinite
loop and end the program. If not, the program will execute the input command by
using the execute function.

AUTHOR
-----------

Guo Jing Wu

# C-shell
Implementation of Shell in C
ASSIGNMENT 2



This is shell written in C

## Files and their uses:

	headers.h:
		1. It contains all the header files,variabledeclarations,function declarations to be included 
	main.c : Contains the main loop and some array declarations

	echox.c : Print given input in console.

	format.c:Gets the input and tokenizes them

	exec.c : Finds which command to be executed and calls the required function.

	env.c   : setting and unsetting of environment variable.

	ls.c : contains the functions for ls and its flags.

	prompt.c : Prints the Username,hostname,current Directory.

	pinfo.c : Contains the pinfo Command.
	
	pipe.c  : Contains piping of commands and also command to check pipe.

	redirect.c : Redirection is taken care in this code.

	history.c : stores the typed commands in a file named history and retrieves them if 		required.

	fgbg.c :Contains functions regarding foreground and background process and executes fg and 		bg commands.It also contains jobs function.

	func.c : contains the pwd,cd,kjobs,quit and overkill functions

	signals.c  : contains function regarding signals.

## Assumptions made:
	1./proc filesystem is accessible as is to any standard linux user.
	2.Each input has a max length of 10000 and number of semicolon seperated commands is 100.
	3.Each command has a max length of 99 arguements
	4.username, hostname and cwd are 1023 characters at max.


Bonus implemented is the cd - command.

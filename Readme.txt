Total Files : 12
1  - Main program
1  - Makefile
10 - Support files

----------Main Program File--------------

*Contain the main code to make shell and run the selected commands.
*Run Internal Commands directly from the shell.
*Run External Commands by executing the Supporting file (Individual Program file for each external Command).


---------------Makefile------------------

*'build' section to compile all the required files using gcc compiler.
*'run'   section to execute the Main_Program File.
*'clean' section to remove all the executable generated files.
-----------Selected Commands-------------

INTERNAL COMMANDS:-
1. pwd   -  Contain two options 'pwd' and 'pwd -L' to show relative and absolute path.
2. echo  -  Contain two options 'echo' and 'echo * [text]' to print the input text and print all the files/folders in the current directory.
3. cd	 -  Contain two options 'cd ..' and 'cd /' to go back to Parent directory and root directory respectively.

EXTERNAL COMMANDS:-
1. ls    -  Contain two options 'ls -l' and 'ls -a' to view all the folders in List mode and show all the hidden files respectively.
2. cat   -  Contain two options 'cat' and 'tac' to view the content of a file in normal mode and in reverse order respectively.
3. mkdir -  Contain two options 'mkdir' and 'mkdir -v' to create a directory and create directory with a pop up message-'filename: Created successfully' respectively.
4. rm    -  Contain two options 'rm' and 'rm -i' to remove a file and remove a file with a pre-confirmation ?y respectively.
5. date  -  Contain two options 'date -a' and 'date -b' two print the current date and time in two different formats.




---------------ASSUMPTIONS----------------

* not all commands run exactly same as default linux command as they as custom made and have slight changes in the way they execute.


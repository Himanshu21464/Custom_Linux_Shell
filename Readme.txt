Total Files : 12
1  - Main program
1  - Makefile
10 - Support files

----------Main Program File--------------

*Contain the main code to make shell and run the selected commands.
*Run Internal Commands directly from the shell.
*Run External Commands by executing the Supporting file (Individual Program file for each external Command).
*There are two mode supported by this shell to execute External commands, by using Fork() and by using pthread_create().
*The thread based execution would be performed if the command is followed by the characters, “&t”.


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


----------------TEST CASES----------------

1. ls -l    = print all the files and folders available in the working directory in list form.
2. ls -a    = print all the hidden files and folders available in the working directory.
3. cat      = Print a message  'enter a file name to open:', then enter the name of available file and file content will be shown in normal mode.
4. tac      = Print a message  'enter a file name to open:', then enter the name of available file and file content will be shown in reverse order.
5. date -a  = show current date in format 'a'.
6. date -b  = show current date in format 'b'.
7. rm       = Ask the user to enter a file name to delete it, and will delete the file if its available and through error when file is not found or non -removable
8. rm -i    = Ask the user to enter a file name to delete it, and will delete the file if its available by confirming it using a input(Y=to delete, any other key to not) and through error when file is not found or non -removable.
9. mkdir    = Ask the user to enter a name to create a directory, and will create a directory with that name if any other file with same name does not exist.
10.mkdir -v = Ask the user to enter a name to create a directory, and will create a directory with that name with a confirmation message"filename-> directory created succesfully" if any other file with same name does not exist.


*ALL THE ABOVE COMMANDS CAN BE EXECUTE BY ADDING "&t" AT THE ENDING OF THE COMMAND.

-----------------------------------------------------------------------------------


1. pwd -L  = Print the symbolic path.
2. pwd -P  = Print the absolute path.
3. echo    = ask the user to enter a text to echo it.
4. echo *  = Print all the files and folders available in the current working directory.
5. cd ..   = Change the directory to the parent directory of current working directory.
6. cd /    = Change the directory to the root directory.


*ALL OF THE ABOVE COMMANDS ARE INTERNAL COMMANDS AND HANDLED DIRECTLY BY SHELL, AND DOES NOT USE ANY FORKING OR THREADING MEATHOD.

----------------------------------------------------------------------------------------------------------------------------------

------------------------------------CORNER CASES-------------------------------------------

1. ls    = It only shows names of files rather than all details.
	   It doesn't shows hidden files in different colour as we get in default linux shell.
	
2. date  = It will throw an error when user input incomplete command i.e. = 'date -' will ask user to confirm which command to run by showing option '-a' and '-b'.
	   It will exit the execution if user input wrong option even after asking the user.

3. rm    = It throw error when entered file name is not available.
	   It throw error when entered file name is not removable and also throw error when you don't press 'y' key to confirm in 'rm -i' command.
	  
4. mkdir = It throw error when entered file name is already present in the current working directory.
	   It throw error when  current working directory in read only type.
	   
5. cat and tac = Throw error when entered file name is encrypted and non -readable.
		 Throw error when entered file name is not present in the working directory.





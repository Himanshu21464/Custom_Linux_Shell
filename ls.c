#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <dirent.h>


void func(const char *Directory,int Hidden_Files,int List){
	
	struct dirent *d;
	DIR *Dir_h = opendir(Directory);
	if (!Dir_h){
		if (errno = ENOENT){		
			perror("Directory doesn't exist\n");
		}
		else{
			perror("Unable to read directory (Unreadable files !!!)\n");
		}
		exit(EXIT_FAILURE);
	}

	while ((d = readdir(Dir_h)) != NULL){
		if (!Hidden_Files && d->d_name[0] == '.')
			continue;
		printf("%s  ", d->d_name);
		if(List){
			 printf("\n");
		}
	}
	if(!List){
		printf("\n");
	}
}
int main(int Cmd_count, const char *Argument[]){
	if (Cmd_count == 1){
		func(".",0,0);
	}else if (Cmd_count == 2){
		if (Argument[1][0] == '-'){
			int Hidden_Files = 0, List = 0;
			char *count = (char*)(Argument[1] + 1);
			while(*count){
				if(*count == 'a'){
				 Hidden_Files = 1;
				}
				else if(*count == 'l'){
				 List = 1;
				}
				else{
					perror("The option you have entered is not available :/\n");
					exit(EXIT_FAILURE);
				}
				count++;
			}
			func(".",Hidden_Files,List);
		}
	}
	return 0;
}
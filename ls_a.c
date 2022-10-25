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
int main(){
	int Hidden_Files=1;
	int List=0;
	func(".",Hidden_Files,List);
	return 0;
}
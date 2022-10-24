#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main()
{
    char folder[40];
    int FLAG = 0;
    printf("Enter directory name to create: ");
    scanf("%s", folder);
    FLAG = mkdir(folder, 0755);
    if (FLAG == 0){
        printf("%s -> directory created successfully\n",folder);
    
    }else{
        printf("Cannot create directory %s\n", folder);
    }
    return 0;
}


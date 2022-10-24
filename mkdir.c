#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    char folder[40];
    int FLAG = 0;
    printf("Enter directory name to create: ");
    scanf("%s", folder);
    FLAG = mkdir(folder, 0755);
    if (FLAG == 0)
        printf("directory created successfully\n");
    else
        printf("Cannot create directory: %s\n", folder);
    return 0;
}


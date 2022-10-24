#include <stdio.h>
#include <stdlib.h>

int main(){
    int FLAG = 0;
    char decision;
    printf("Enter filename to be deleted: ");    
    char File[20];
    scanf("%[^\n]%*c", File);
    char Command[32] = { 0 };
    printf("rm: remove regular empty file '%s'? [Y/N]:",File);
    scanf("%c",&decision);
    if(decision=='y' || decision=='Y'){
    sprintf(Command, "rm %s", File);
    FLAG = system(Command);
    if (FLAG == 0){
        printf("File deleted successfully: '%s'\n", File);
    }else{
        printf("Unable to delete file '%s'\n", File);
    }
    }else{
        exit(0);
    }
    return 0;
}

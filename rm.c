#include <stdio.h>
#include <stdlib.h>

int main(){
   printf("Enter filename to be deleted: ");    
    char File[20];
    scanf("%[^\n]%*c", File);
    char Command[32] = { 0 };
    int FLAG = 0;
    sprintf(Command, "rm %s", File);
    FLAG = system(Command);
    if (FLAG == 0){
        printf("File deleted successfully: %s\n", File);
    }else{
        printf("Unable to delete file '%s'\n", File);
    }
    return 0;
}

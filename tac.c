#include <stdio.h>
#include <string.h>
 
int main(int Cmd_count, char *Argument[])
{
    FILE *File;     
    int Count = 0, index=0; 
    if( Cmd_count < 2 ){
        printf("Insufficient Arguments!!!\n");
        printf("Please use \"program-name file-name\" format.\n");
        return -1;
    }
    File = fopen(Argument[1],"r");
    if( File == NULL ){
        printf("\n%s File can not be opened : \n",Argument[1]);
        return -1;
    }
    fseek(File,0,SEEK_END);
    Count = ftell(File);
    while( index < Count ){
        index++;
        fseek(File,-index,SEEK_END);
        printf("%c",fgetc(File));
    }
    printf("\n");
    fclose(File);
    return 0;
}

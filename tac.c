#include <stdio.h>
#include <string.h>
 
int main()
{
    FILE *File;     
    char fname[20];
    printf("Enter a file name to open in tac mode: "); 
    scanf("%[^\n]%*c", fname);  
    int Count = 0, index=0; 
    File = fopen(fname,"r");
    if( File == NULL ){
        printf("\n%s File can not be opened : \n",fname);
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

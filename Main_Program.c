#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h> 
#include <unistd.h> 
#include <libgen.h> 
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

#define LINE_SIZE 1024

char  Command[LINE_SIZE],temp[LINE_SIZE], *Get_Directory, *Directory, Buffer[LINE_SIZE];
pid_t pid;
int status;

void pwd(){
    Get_Directory = getcwd(Buffer, sizeof(Buffer));
            printf("%s\n",Get_Directory);            
}

void func() {
   int n=0;
    while (1) {  
        printf("[Shell] >>  ");    
        scanf("%[^\n]%*c", Command);

        if(!strcmp("pwd",Command)){
            pwd();  
        }else if(!strcmp("\0",Command)){
            break;

        }else if(!strcmp("exit",Command)){
            exit(0);

        }else if(!strcmp("echo",Command)&&(sizeof(Command)>4)){
            char chProgramVar[1024];
            for (int i=0;i<sizeof(Command-5);i++){
                chProgramVar[i]=Command[i+5];
            }
            printf("%s\n",chProgramVar);  
        }else if(!strcmp("mkdir",Command)){
            execl("./mkdir","./mkdir",NULL);
            func();

        }else if(!strcmp("mkdir -v",Command)){
            execl("./mkdir_v","./mkdir_v",NULL);
            func();

        }else if(!strcmp("date -a",Command)){
            execl("./date1","./date1",NULL);
            func();

        }else if(!strcmp("date -b",Command)){
            execl("./date2","./date2",NULL);
            func();

        }else if(!strcmp("cat",Command)){
            execl("./cat","./cat",NULL);
            func();

        }else if(!strcmp("tac",Command)){
            execl("./tac","./tac",NULL);
            func();

        }else if(!strcmp("ls -l",Command)){
            execl("./ls_l","./ls_l",NULL);
            func();

        }else if(!strcmp("ls -a",Command)){
            execl("./ls_a","./ls_a",NULL);
            func();

        }else if(!strcmp("rm",Command)){
            execl("./rm","./rm",NULL);
            func();

        }else if(!strcmp("rm -i",Command)){
            execl("./rm_i","./rm_i",NULL);
            func();

        }

        else{
            printf("%s :command not found!!\n", Command);
            func();
        }

        n=n+1;
        
    }
    
}

int main(){
    printf("---------------Welcome to Custom shell --------------------- \n\n");
    printf("You can use following commands in this shell:-\n");
    printf("----Internal commands------\n\n");
    printf("1. cd    =  cd .. and cd [directory]\n");
    printf("2. echo  =  echo -e [String, ]echo -n [String]\n");
    printf("3. pwd   =  pwd -P, pwd- L\n\n");
    printf("----External Commands-------\n\n");
    printf("1. cat   =  cat [filename], tac [filename]\n");
    printf("2. date  =  date -a, date -b\n");
    printf("3. rm    =  rm [filename], rm -i [filename]\n");
    printf("4. mkdir =  mkdir -v [Directory name], mkdir [Directory name]\n");
    printf("5. ls    =  ls -a, ls -l\n");
    printf("---------------------------------------------------------------\n\n");

    func();
    return 0;
}

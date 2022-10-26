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
pid_t pid1,pid2,pid3,pid4,pid5,pid6,pid7,pid8,pid9,pid10;
int status;

void pwd(){
    Get_Directory = getcwd(Buffer, sizeof(Buffer));
    printf("%s\n",Get_Directory);            
}

void mkdir_(){
    pid1 = fork();
    if(pid1==-1){
        printf("Unable to create child process!!!\n");
    }else if(pid1==0){
        execl("./mkdir","./mkdir",NULL);
    }waitpid(pid1,&status,0);
}

void mkdir_v(){
    pid2 = fork();
    if(pid2==-1){
        printf("Unable to create child process!!!\n");
    }else if(pid2==0){
        execl("./mkdir_v","./mkdir_v",NULL);
    }waitpid(pid2,&status,0);
}

void remove_i(){
    pid3 = fork();
    if(pid3==-1){
        printf("Unable to create child process!!!\n");
    }else if(pid3==0){
        execl("./rm_i","./rm_i",NULL);
    }waitpid(pid3,&status,0);
}

void remove_(){
    pid4 = fork();
    if(pid4==-1){
        printf("Unable to create child process!!!\n");
    }else if(pid4==0){
        execl("./rm","./rm",NULL);
    }waitpid(pid4,&status,0);
}

void date_a(){
    pid5 = fork();
    if(pid5==-1){
        printf("Unable to create child process!!!\n");
    }else if(pid5==0){
        execl("./date1","./date1",NULL);
    }waitpid(pid5,&status,0);
}

void date_b(){
    pid6 = fork();
    if(pid6==-1){
        printf("Unable to create child process!!!\n");
    }else if(pid6==0){
        execl("./date2","./date2",NULL);
    }waitpid(pid6,&status,0);
}

void ls_a(){
    pid7 = fork();
    if(pid7==-1){
        printf("Unable to create child process!!!\n");
    }else if(pid7==0){
        execl("./ls_a","./ls_a",NULL);
    }waitpid(pid7,&status,0);
}

void ls_l(){
    pid8 = fork();
    if(pid8==-1){
        printf("Unable to create child process!!!\n");
    }else if(pid8==0){
        execl("./ls_l","./ls_l",NULL);
    }waitpid(pid8,&status,0);
}

void cat_(){
    pid9 = fork();
    if(pid9==-1){
        printf("Unable to create child process!!!\n");
    }else if(pid9==0){
        execl("./cat","./cat",NULL);
    }waitpid(pid9,&status,0);
}

void tac_(){
    pid10 = fork();
    if(pid10==-1){
        printf("Unable to create child process!!!\n");
    }else if(pid10==0){
        execl("./tac","./tac",NULL);
    }waitpid(pid10,&status,0);
}

void help(){
    printf("You can use following commands in this shell:-\n");
    printf("----Internal commands------\n\n");
    printf("1. cd    =  cd .. and cd /\n");
    printf("2. echo  =  echo [String], echo *\n");
    printf("3. pwd   =  pwd -P, pwd- L\n\n");
    printf("----External Commands-------\n\n");
    printf("1. cat   =  cat [filename], tac [filename]\n");
    printf("2. date  =  date -a, date -b\n");
    printf("3. rm    =  rm [filename], rm -i [filename]\n");
    printf("4. mkdir =  mkdir -v [Directory name], mkdir [Directory name]\n");
    printf("5. ls    =  ls -a, ls -l\n");
    printf("---------------------------------------------------------------\n\n");
}

void forking_method() {

    while (1) {  
        printf("[Shell] >>  ");    
        scanf("%[^\n]%*c", Command);   
        if(!strcmp("pwd",Command)||(!strcmp("pwd -P",Command)||(!strcmp("pwd -L",Command)))){
            pwd();  
        }else if(!strcmp("\0",Command)){
            break;

        }else if(!strcmp("exit",Command)){
            exit(0);

        }else if(!strcmp("echo",Command)){
            char Cmd[100];
            printf("Enter a text to echo it: ");        
            scanf("%[^\n]%*c", Cmd);
            char str[100];
            strcat(Command," ");
            strcpy(str,strcat(Command,Cmd));
            system(str);
            
        }else if(!strcmp("echo *",Command)){
            system("ls");
            
        }else if(!strcmp("cd ..",Command)){
            chdir("..");      
        }else if(!strcmp("cd /",Command)){
            chdir("/");
        
        }else if(!strcmp("mkdir",Command)){
            mkdir_();
            

        }else if(!strcmp("mkdir -v",Command)){
            //execl("./mkdir_v","./mkdir_v",NULL);
            mkdir_v();

        }else if(!strcmp("date -a",Command)){
            //execl("./date1","./date1",NULL);
            date_a();

        }else if(!strcmp("date -b",Command)){
            //execl("./date2","./date2",NULL);
            date_b();          
        }else if(!strcmp("cat",Command)){
            //execl("./cat","./cat",NULL);
            cat_();

        }else if(!strcmp("tac",Command)){
            //execl("./tac","./tac",NULL);
            tac_();

        }else if(!strcmp("ls -l",Command)){
            //execl("./ls_l","./ls_l",NULL);
            ls_l();
        
        }else if(!strcmp("ls -a",Command)){
            //execl("./ls_a","./ls_a",NULL);
            ls_a();

        }else if(!strcmp("rm",Command)){
            //execl("./rm","./rm",NULL);
            remove_();

        }else if(!strcmp("rm -i",Command)){
            //execl("./rm_i","./rm_i",NULL);
            remove_i();
            
    
        }else if(!strcmp("help",Command)){
            help();

        }
        else{
            printf("%s :command not found!!\n", Command);
        }       
    }   
}
int main(){
    printf("---------------Welcome to Custom shell --------------------- \n\n");
    //help();
    forking_method();
    return 0;
}

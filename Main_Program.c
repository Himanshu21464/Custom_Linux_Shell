#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h> 
#include <unistd.h> 
#include <libgen.h> 
#include <sys/shm.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

#define LINE_SIZE 1024

char  Command[LINE_SIZE],temp[LINE_SIZE], *Get_Directory, *Directory, Buffer[LINE_SIZE];
pid_t pid1,pid2,pid3,pid4,pid5,pid6,pid7,pid8,pid9,pid10;
int status;

pthread_t thread1, thread2, thread3, thread4, thread5, thread6, thread7, thread8, thread9, thread10;
char *temp2 = "Thread";  
int  iret1, iret2, iret3, iret4, iret5, iret6, iret7, iret8, iret9, iret10;


void pwd_l(){            
    system("pwd -L");
}

void pwd_p(){
    system("pwd -P");
}


void *mkdir_thread( void *ptr ){
    printf("This command will execute  using 'PTHREAD_CREATE' \n\n");
    system("./mkdir");
}

void *mkdir_v_thread( void *ptr ){
    printf("This command will execute  using 'PTHREAD_CREATE' \n\n");
    system("./mkdir_v");
}

void *remove_thread( void *ptr ){
    printf("This command will execute  using 'PTHREAD_CREATE' \n\n");
    system("./rm");
}

void *rm_i_thread( void *ptr ){
    printf("This command will execute  using 'PTHREAD_CREATE' \n\n");
    system("./rm_i");
}

void *date1_thread( void *ptr ){
    printf("This command will execute  using 'PTHREAD_CREATE' \n\n");
    system("./date1");
}

void *date2_thread( void *ptr ){
    printf("This command will execute  using 'PTHREAD_CREATE' \n\n");
    system("./date2");
}

void *ls_l_thread( void *ptr ){
    printf("This command will execute  using 'PTHREAD_CREATE' \n\n");
    system("./ls_l");
}

void *ls_a_thread( void *ptr ){
    printf("This command will execute  using 'PTHREAD_CREATE' \n\n");
    system("./ls_a");
}

void *cat_thread( void *ptr ){
    printf("This command will execute  using 'PTHREAD_CREATE' \n\n");
    system("./cat");
}

void *tac_thread( void *ptr ){
    printf("This command will execute  using 'PTHREAD_CREATE' \n\n");
    system("./tac");
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
    printf("This shell support two type of execution - by fork() and by pthread_create()\n");
    printf("*The thread based execution would be performed if the command is followed by the characters, “&t”.\n\n");
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

void execution() {

    while (1) {  
        printf("[Shell] >>  ");    
        scanf("%[^\n]%*c", Command);   
        if(!strcmp("pwd -P",Command)){
            pwd_p();  
        }else if(!strcmp("pwd -L",Command)){
            pwd_l();

        }else if(!strcmp("\0",Command)){
            break;

        }else if(!strcmp("exit",Command)){
            exit(0);

        }else if((Command[0]=='e')&&(Command[1]=='c')&&(Command[2]=='h')&&(Command[3]=='o')&&(Command[4]==' ')){
            system(Command);

        }else if(!strcmp("echo *",Command)){
            system("ls");
            
        }else if(!strcmp("cd ..",Command)){
            chdir("..");      
        }else if(!strcmp("cd /",Command)){
            chdir("/");
        
        }else if(!strcmp("mkdir",Command)){
            mkdir_();
            
        }else if(!strcmp("mkdir -v",Command)){
            mkdir_v();

        }else if(!strcmp("date -a",Command)){
            date_a();

        }else if(!strcmp("date -b",Command)){
            date_b();   

        }else if(!strcmp("date -",Command)){
            printf("Did you mean '-a' or '-b' ?? :\n");
            char temp3 [1];
            scanf("%[^\n]%*c", temp3); 
            if (!strcmp("-a",temp3)){
                date_a();
            }else if(!strcmp("-b",temp3)){
                date_b();
            }else{
                printf("Wrong input!!!");
            }

        }else if(!strcmp("cat",Command)){
            cat_();

        }else if(!strcmp("tac",Command)){
            tac_();

        }else if(!strcmp("ls -l",Command)){
            ls_l();
        
        }else if(!strcmp("ls -a",Command)){
            ls_a();

        }else if(!strcmp("rm",Command)){
            remove_();

        }else if(!strcmp("rm -i",Command)){
            remove_i();
            
    
        }else if(!strcmp("mkdir &t",Command)){
            iret1 = pthread_create( &thread1, NULL, mkdir_thread, (void*) temp2);
            pthread_join( thread1, NULL);
            

        }else if(!strcmp("mkdir -v &t",Command)){
            iret2 = pthread_create( &thread2, NULL, mkdir_v_thread, (void*) temp2);
            pthread_join( thread2, NULL);


        }else if(!strcmp("date -a &t",Command)){
            iret3 = pthread_create( &thread3, NULL, date1_thread, (void*) temp2);
            pthread_join( thread3, NULL);
            

        }else if(!strcmp("date -b &t",Command)){
            iret4 = pthread_create( &thread4, NULL, date2_thread, (void*) temp2);
            pthread_join( thread4, NULL);          


        }else if(!strcmp("cat &t",Command)){
            iret5 = pthread_create( &thread5, NULL, cat_thread, (void*) temp2);
            pthread_join( thread5, NULL);
            

        }else if(!strcmp("tac &t",Command)){
            iret6 = pthread_create( &thread6, NULL, tac_thread, (void*) temp2);
            pthread_join( thread6, NULL);

        }else if(!strcmp("ls -l &t",Command)){
            iret7 = pthread_create( &thread7, NULL, ls_l_thread, (void*) temp2);
            pthread_join( thread7, NULL);
            
        
        }else if(!strcmp("ls -a &t",Command)){
            iret8 = pthread_create( &thread8, NULL, ls_a_thread, (void*) temp2);
            pthread_join( thread8, NULL);
    

        }else if(!strcmp("rm &t",Command)){
            iret9 = pthread_create( &thread9, NULL, remove_thread, (void*) temp2);
            pthread_join( thread9, NULL);

        
        }else if(!strcmp("rm -i &t",Command)){
            iret10 = pthread_create( &thread10, NULL, rm_i_thread, (void*) temp2);
             pthread_join( thread10, NULL);
            
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
    execution();
    return 0;
}
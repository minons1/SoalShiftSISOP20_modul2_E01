#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
#include<wait.h>
#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<errno.h>
#include<syslog.h>

int main(int argc,char *argv[]){
    
    printf("%d\n",argc);

    if(argc<5){
        printf("Argumen Kurang\n");
        return 0;
    }
    if((atoi(argv[1])>0 &&atoi(argv[1])<61) || strcmp(argv[1],"*")==0){
        puts(argv[1]);
    }
    else{
        puts("EROR ARGUMEN 1 BRO");
    }
    if((atoi(argv[2])>0 &&atoi(argv[2])<61) || strcmp(argv[2],"*")==0){
        puts(argv[1]);
    }
    else{
        puts("EROR ARGUMEN 2 BRO");
    }
    if((atoi(argv[3])>0 &&atoi(argv[3])<61) || strcmp(argv[3],"*")==0){
        puts(argv[3]);
    }
    else{
        puts("EROR ARGUMEN 3 BRO");
    }

    pid_t pid;
    pid=fork();

    if(pid<0){
        exit(EXIT_FAILURE);
    }
    if(pid>0){
        exit(EXIT_SUCCESS);
    }
    umask(0);

    sid = setsid();
    if(sid<0){
        exit(EXIT_FAILURE);
    }

    if((chdir("/"))<0){
        exit(EXIT_FAILURE);
    }

    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    while(1){
        if(strcpy(argv[1],*)){
            
        }
        
    }

    // puts(argv[4]);
    char *args[] = {"bash",argv[4],NULL};
    execv("/bin/bash",args);
}
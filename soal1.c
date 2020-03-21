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
#include<stdbool.h>
#include<time.h>

int main(int argc,char *argv[]){

    if(argc<5){
        printf("Argumen Kurang\n");
        return 0;
    }

    if((atoi(argv[1])>=0 &&atoi(argv[1])<60) || strcmp(argv[1],"*")==0){
        puts(argv[1]);
    }
    else{
        puts("EROR ARGUMEN 1 BRO");
        return 0;
    }

    if((atoi(argv[2])>=0 &&atoi(argv[2])<60) || strcmp(argv[2],"*")==0){
        puts(argv[2]);
    }
    else{
        puts("EROR ARGUMEN 2 BRO");
        return 0;
    }

    if((atoi(argv[3])>=0 &&atoi(argv[3])<60) || strcmp(argv[3],"*")==0){
        puts(argv[3]);
    }
    else{
        puts("EROR ARGUMEN 3 BRO");
        return 0;
    }
    // puts(argv[4]);
    if(access(argv[4],F_OK)==-1){
        puts("FILENYA GAADA!!\n");
        return 0;
    }

    pid_t pid, sid;        // Variabel untuk menyimpan PID

    pid = fork();     // Menyimpan PID dari Child Process

    /* Keluar saat fork gagal
    * (nilai variabel pid < 0) */
    if (pid < 0) {
        exit(EXIT_FAILURE);
    }

    /* Keluar saat fork berhasil
    * (nilai variabel pid adalah PID dari child process) */
    if (pid > 0) {
        exit(EXIT_SUCCESS);
    }

    umask(0);

    sid = setsid();
    if (sid < 0) {
        exit(EXIT_FAILURE);
    }

    if ((chdir("/home/salim/modul2")) < 0) {
        exit(EXIT_FAILURE);
    }

    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    while (1) {
        // Tulis program kalian di sini
        time_t rawtime=time(NULL);
        struct tm *timeinfo=localtime(&rawtime);
        int sec=timeinfo->tm_sec;
        int min=timeinfo->tm_min;
        int hour=timeinfo->tm_hour;

        if(sec==atoi(argv[1])||strcmp(argv[1],"*")==0){
            sec=100;
        }
        if(min==atoi(argv[2])||strcmp(argv[2],"*")==0){
            min=100;
        }
        if(hour==atoi(argv[3])||strcmp(argv[3],"*")==0){
            hour=100;
        }
        if(sec==100&&min==100&&hour==100){
            if(fork()==0){
                char *args[] = {"bash",argv[4],NULL};
                execv("/bin/bash",args);
            }   
        }
        sleep(1);
    }
}

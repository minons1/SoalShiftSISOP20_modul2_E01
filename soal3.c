#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<wait.h>
#include<stdio.h>
#include<dirent.h>
#include<string.h>

int main(){

    // char *args[]= {"copy","-r","/home/salim/newfolder","/home/salim/modul2",NULL};
    // execv("/bin/cp",args);

    int status;
    
    if(fork()==0){
        char *args[]= {"copy","-r","/home/salim/newfolder","/home/salim/modul2",NULL};
        execv("/bin/cp",args);
    }
    while((wait(&status))>0);

    if(fork()==0){
            char *args[]= {"rename","newfolder","indomie",NULL};
            execv("/bin/mv",args);
    }
    while((wait(&status))>0);

    sleep(5);
    if(fork()==0){
        char *args[]= {"copy","-r","/home/salim/newfolder","/home/salim/modul2",NULL};
        execv("/bin/cp",args);
    }
    while((wait(&status))>0);

    if(fork()==0){
        char *args[]= {"rename","newfolder","sedaap",NULL};
        execv("/bin/mv",args);        
    }
    while((wait(&status))>0);

    if(fork()==0){
        char *args[]= {"unzip","jpg.zip",NULL};
        execv("/usr/bin/unzip",args);
    }
    while((wait(&status))>0);
    
    struct dirent *drnt;

    DIR *dir = opendir("/home/salim/modul2/jpg");
    if(dir){
            while(drnt = readdir(dir))
            {
                if(strcmp(drnt->d_name,"..")==0||strcmp(drnt->d_name,".")==0){
                    continue;
                }

                struct stat sb;

                char args2[50]="/home/salim/modul2/jpg/";
                strcat(args2,drnt->d_name);

                if(stat(args2, &sb)==0 &&S_ISDIR(sb.st_mode)){;
                    if(fork()==0){
                        char *args[]= {"move",args2,"/home/salim/modul2/indomie",NULL};
                        execv("/bin/mv",args);
                    }
                    while((wait(&status))>0);
                    char args3[50];
                    strcpy(args3,"/home/salim/modul2/indomie/");
                    strcat(args3,drnt->d_name);
                    strcat(args3,"/coba1.txt");
                    if(fork()==0){
                        char *args[]= {"touch",args3,NULL};
                        execv("/bin/touch",args);
                    }
                    while((wait(&status))>0);

                    strcpy(args3,"/home/salim/modul2/indomie/");
                    strcat(args3,drnt->d_name);
                    strcat(args3,"/coba2.txt");
                    sleep(3);
                    if(fork()==0){
                        char *args[]= {"touch",args3,NULL};
                        execv("/bin/touch",args);
                    }
                    while((wait(&status))>0);

                }
                else{
                    if(fork()==0){
                        char *args[]= {"move",args2,"/home/salim/modul2/sedaap",NULL};
                        execv("/bin/mv",args);
                    }
                    while((wait(&status))>0);
                }
            }
            closedir(dir);
    }
    else{
            printf("'/home/salim/modul2/jpg' Gaiso Dibuka Boss!!\n");
    }

    return 0;
}

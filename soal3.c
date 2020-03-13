#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<wait.h>
#include<stdio.h>

int main(){

    // char *args[]= {"copy","-r","/home/salim/newfolder","/home/salim/modul2",NULL};
    // execv("/bin/cp",args);

    pid_t child_id1;
    int status;
    child_id1=fork();

    if(child_id1<0){
        exit(EXIT_FAILURE);
    }

    if(child_id1==0){
        char *args[]= {"copy","-r","/home/salim/newfolder","indomie",NULL};
        execv("/bin/cp",args);
    }
    else{
        while((waitpid(child_id1,&status,0))>0);
        sleep(5);
        char *args[]= {"copy","-r","/home/salim/newfolder","sedaap",NULL};
        execv("/bin/cp",args);
        
        char *args2[]= {"unzip","jpg.zip",NULL};
        execv("/usr/bin/unzip",args2);

        child_id1=fork();
        if(child_id1<0){
            exit(EXIT_FAILURE);
        }
        if(child_id1==0){

        }
        else{
            
        }
    }
    
    // printf("Pertama ini keprint 2 kali\n");
    

    
    // printf("yang ini berapa kali ya\n");

    return 0;
}
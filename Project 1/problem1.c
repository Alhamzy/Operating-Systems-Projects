#include <stdio.h>
#include <stdlib.h>
//#include <unistd.h>

int main(int argc, char *argv[])
{
    //fork process
    int cid = fork();
    if(cid==0){
    if(argc==2){//if only cmd

        //copy arguments to array
        char *cmd[2];
        cmd[0]=strdup(argv[1]);//argument to execute
        cmd[1]=NULL;
        execvp(cmd[0], cmd);//execute first case (only cmd)
 
    }
    else if (argc>2){
    char *cmd[1];
    cmd[0] =strdup(argv[1]);//grab cmd
    char *params[5];//store params
    int i; for(i=0;i<argc-1;i++){//grab params
        params[i]=strdup(argv[i+1]);//only grab arguments after cmd starting from argv[2]
    }
    params[i+1]=NULL;//terminate array w/NULL
     
    execvp(params[0],params); // runs cmd and params
    printf("Execution Failed!\n");//prints only if execution fails
    } }
    else { // parent goes down this path (main)
        int wc= wait(NULL);//wait for child process
        printf("\n++++\n");
        }
    }

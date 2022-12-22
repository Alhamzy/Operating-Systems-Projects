#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int fd[2]; //file descriptor for read/write access
    if(pipe(fd)==-1){//if file descriptor fails
        return 1;
    }

    //arrays of char pointers to store cmd1 and cmd2 arguments
    char *cmd1[]={NULL};
    char *cmd2[]={NULL};


    //cmd1 inputs
    cmd1[0]=strdup(argv[1]);//take ls as cmd1

    //cmd2 inputs
    cmd2[0]=strdup(argv[3]);
    
   
    //fork process
    int pid1=fork();
    if(pid1==0){ //run first process (child)
        dup2(fd[1],STDOUT_FILENO);//write to buffer
        close(fd[0]);
        close(fd[1]);
        execlp(cmd1[0],cmd1,NULL);
    }

    //start another child process
    int pid2=fork();
    if(pid2==0){//process 2 runs
        dup2(fd[0],STDIN_FILENO);//read from buffer - previous output from first child process
        close(fd[0]);
        close(fd[1]);
        execlp(cmd2[0],cmd2,NULL);
    }

    //close both read & write ends to terminate execution
    close(fd[0]);
    close(fd[1]);

    //prioritize child processes
    wait(pid1,NULL,0);
    wait(pid2,NULL,0);
    printf("++++\n");
    }

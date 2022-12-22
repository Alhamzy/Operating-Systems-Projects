#include <sys/types.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char **argv)
{

int lineCnt = 0;
int printBegin = atoi(argv[1]); //input of the last # of lines to be saved
// open the file
FILE *f = fopen(argv[2] , "r"); 

// if there was an error
if(f == NULL){
  perror("Error opening file"); // print error
  return(-1); 
}
// if there was no error
else
{ 

int buffSize = 1024;
char buff[buffSize]; // will hold each line in file  


while(fgets(buff, buffSize, f)) { // first loop to get number of lines
    lineCnt++;
}


  int totalLines = ++lineCnt; // save total lines

  int lineToStartPrint = totalLines - printBegin; // save specific point to start printing (relative to beginning)

  fseek(f, 0, SEEK_SET); //reset pointer to beginning of file
 


  
  printf("These are the last %d of %s\n",printBegin,argv[2]);
  
  lineCnt = 0; // reset so we can start keeping count again
  int lineFound = 0; // flag to signal start of output
  while(fgets(buff, buffSize, f)) { // loop again and only print when we reach desired line
      lineCnt++;
      if(lineCnt==lineToStartPrint || lineFound == 1) {
        printf("%s", buff);
        lineFound = 1; // since we arrived at postion
      }
      
  }


fclose(f); // close file
}

return(0);
}
	
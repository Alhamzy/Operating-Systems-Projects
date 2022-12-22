#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>

// function that takes in a directory name and list all files and directories (files inside directories as well) in it
void listFiles(DIR *dirToSearch)
{
  struct dirent* ent; // entity variable
  while((ent = readdir(dirToSearch))) // loop through directory
  {

    if((strcmp(ent->d_name,".") != 0) && (strcmp(ent->d_name,"..") != 0)) // make sure to skip . and .. directories
    {
      printf("Filename: %s\n",ent->d_name); // print each file name
    
      if(ent->d_type == DT_DIR) // check if this file is a directory
      {
        
        //recursively call the filename as a directory to list files before moving to next file
        DIR *newDir = opendir(ent->d_name);
        if(newDir)
        {
          listFiles(newDir);
        }
      }
    }
  }
}


int main(int argc, char *argv[])
{
  if (argc == 1) // list current directory
  {
    DIR *dir = opendir(".");
    if(dir)
    {
      listFiles(dir);
    }
  }
  else if(argc == 2) // list specified directory (second cmd argument)
  {
    DIR *dir = opendir(argv[1]);
    if(dir)
    {
      listFiles(dir);
    }
  }
  else
  {
    printf("Invalid arguments\n");
    return 1;
  }
  printf("Search has finished!\n");
}
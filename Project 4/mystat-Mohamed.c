#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

  if (argc < 2)
  {
    return 1;
  }

  struct stat fStats;
  if( stat(argv[1], &fStats) == 0) // if stats of file can be grabbed
  {// print stats
    printf("File Information of %s\n",argv[1]);
    printf("File Size: %ld Bytes\n",fStats.st_size);
    printf("Number of Blocks Allocated: %ld\n",fStats.st_blocks);
    printf("Number of Links: %ld\n", fStats.st_nlink);
    printf("File Permissions: ");
    if(S_ISREG(fStats.st_mode))//check if file or dir
    {
      printf("-");
    }
    else
    {
      printf("d");
    }
    //check owner/group/others permissions and print
    if(S_IRUSR & fStats.st_mode)
      {
        printf("r");
      }
    else
      {
        printf("-");
      }
    if(S_IWUSR & fStats.st_mode)
      {
        printf("w");
      }
    else
      {
        printf("-");
      }
    if(S_IXUSR & fStats.st_mode)
      {
        printf("x");
      }
    else
      {
        printf("-");
      }
    if(S_IRGRP & fStats.st_mode)
      {
        printf("r");
      }
    else
      {
        printf("-");
      }
    if(S_IWGRP & fStats.st_mode)
      {
        printf("w");
      }
    else
      {
        printf("-");
      }
    if(S_IXGRP & fStats.st_mode)
      {
        printf("x");
      }
    else
      {
        printf("-");
      }
    if(S_IROTH & fStats.st_mode)
      {
        printf("r");
      }
    else
      {
        printf("-");
      }
    if(S_IWOTH & fStats.st_mode)
      {
        printf("w");
      }
    else
      {
        printf("-");
      }
    if(S_IXOTH & fStats.st_mode)
      {
        printf("x");
      }
    else
      {
        printf("-");
        }
    
    printf("\nFile Inode: %ld\n", fStats.st_ino);
  }  
   
  return 0;
}

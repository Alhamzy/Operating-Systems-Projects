#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

struct dirent *ent;
struct stat fStats;

void printDir(const char *rootDir);

int main(int argc, char *argv[]) {
  DIR *dir;

  if (argc == 1) // print file names of current directory (no dir specified)
  {
    dir = opendir(".");
    if (dir == NULL) {
      printf("Error\n");
      return 1;
    }

    // loop directory
    while ((ent = readdir(dir))) // while directory is valid
    {
      if (ent->d_name[0] == '.') // check if file and not a dir, if so,print
      {
        continue;
      }
      printf("%s\n", ent->d_name);
    }
    closedir(dir);
  }

  if (argv[1] != NULL) // print files names of specified directory
  {
    char argCheck[64];
    strcpy(argCheck, argv[1]);
    if (argc == 2 && strcmp(argCheck, "-l") != 0) // print file names of desired (argv[1]) directory
    {
      dir = opendir(argv[1]);
      if (dir == NULL) {
        printf("Error\n");
        return 1;
      }
      // loop directory
      while ((ent = readdir(dir))) // while directory is valid
      {
        if (ent->d_name[0] == '.') // check if file and not a dir, if so,print
        {
          continue;
        }
        printf("%s\n", ent->d_name);
      }
      closedir(dir);
    }
  }

  if (argc == 2 && strcmp(argv[1], "-l") == 0) // print stats of current directory (no dir specified)
  {
    dir = opendir(".");
    if (dir == NULL) {
      printf("Error\n");
      return 1;
    }
    // loop directory
    while ((ent = readdir(dir))) // while directory is valid
    {

      if (stat(ent->d_name, &fStats) == 0) {
        if (!S_ISREG(fStats.st_mode)) {
          continue;
        } // if directory folder then skip
        // start printing stats
        printf("File Information of %s\n", ent->d_name);
        printf("File Size: %ld Bytes\n", fStats.st_size);
        printf("Number of Blocks Allocated: %ld\n", fStats.st_blocks);
        printf("Number of Links: %ld\n", fStats.st_nlink);
        printf("File Permissions: ");
        if (S_ISREG(fStats.st_mode)) // check if file or dir
        {
          printf("-");
        } else {
          printf("d");
        }
        // check owner/group/others permissions and print
        if (S_IRUSR & fStats.st_mode) {
          printf("r");
        } else {
          printf("-");
        }
        if (S_IWUSR & fStats.st_mode) {
          printf("w");
        } else {
          printf("-");
        }
        if (S_IXUSR & fStats.st_mode) {
          printf("x");
        } else {
          printf("-");
        }
        if (S_IRGRP & fStats.st_mode) {
          printf("r");
        } else {
          printf("-");
        }
        if (S_IWGRP & fStats.st_mode) {
          printf("w");
        } else {
          printf("-");
        }
        if (S_IXGRP & fStats.st_mode) {
          printf("x");
        } else {
          printf("-");
        }
        if (S_IROTH & fStats.st_mode) {
          printf("r");
        } else {
          printf("-");
        }
        if (S_IWOTH & fStats.st_mode) {
          printf("w");
        } else {
          printf("-");
        }
        if (S_IXOTH & fStats.st_mode) {
          printf("x");
        } else {
          printf("-");
        }
        printf("\nFile Inode: %ld\n", fStats.st_ino);
        printf("\n");

      }
    }
    closedir(dir);
  }

  if (argc == 3) // printf stats of desired (argv[2]) directory
  {
    
    DIR* dir = opendir(argv[2]);
    if (dir == NULL) {
        return 1;
    }

    printf("reading directory: %s\n",argv[2]);
    while ((ent = readdir(dir))) //loop directory
    {
      if((strcmp(ent->d_name,".") !=0) && (strcmp(ent->d_name,"..") != 0))
      {
        printf("File: %s\n",ent->d_name);
        if (stat(ent->d_name, &fStats) == 0) 
        { // print stats
          printf("File Information of %s\n", ent->d_name);
          printf("File Size: %ld Bytes\n", fStats.st_size);
          printf("Number of Blocks Allocated: %ld\n", fStats.st_blocks);
          printf("Number of Links: %ld\n", fStats.st_nlink);
          printf("File Permissions: ");
          if (S_ISREG(fStats.st_mode)) // check if file or dir
          {
            printf("-");
          } else {
            printf("d");
          }
          // check owner/group/others permissions and print
          if (S_IRUSR & fStats.st_mode) {
            printf("r");
          } else {
            printf("-");
          }
          if (S_IWUSR & fStats.st_mode) {
            printf("w");
          } else {
            printf("-");
          }
          if (S_IXUSR & fStats.st_mode) {
            printf("x");
          } else {
            printf("-");
          }
          if (S_IRGRP & fStats.st_mode) {
            printf("r");
          } else {
            printf("-");
          }
          if (S_IWGRP & fStats.st_mode) {
            printf("w");
          } else {
            printf("-");
          }
          if (S_IXGRP & fStats.st_mode) {
            printf("x");
          } else {
            printf("-");
          }
          if (S_IROTH & fStats.st_mode) {
            printf("r");
          } else {
            printf("-");
          }
          if (S_IWOTH & fStats.st_mode) {
            printf("w");
          } else {
            printf("-");
          }
          if (S_IXOTH & fStats.st_mode) {
            printf("x");
          } else {
            printf("-");
          }
          printf("\nFile Inode: %ld\n", fStats.st_ino);
          printf("\n");
        }
      }
    }
        
    

    closedir(dir);
  }

  return 0;
}


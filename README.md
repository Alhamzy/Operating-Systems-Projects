# Operating-Systems-Projects
+ Collection of compeleted operating systems projects. Under the supervision of Dr Wanwan Li of University of South Florida. Covering major operating systems topics such as:
- CPU Virtualization, Paging, Conurrency, Persistance, etc.

# Project 1
## Topics Covered
+ CPU Virtualization
+ Process API in UNIX

## Program Specifications
### p1:
Program that runs through command line. Creates a new process through fork method. The program then executes the second command line argument. Taking the third and following arguments as paramters to the second argument's *specified* process. Methods used: 
### p2: 
The program uses 'fork()' to create processes and 'exec()' to assign the newly created processes what to do. Utilizing the pipe function, that uses a file descriptor to send input from one process to another. The second cmd argument outputs to the pipe function, allowing command at fourth argument to use it as input.

## How to compile and run on Command Line Interface  
### p1:
#### Compile
```
gcc -o p1.out problem1.c
```
#### Run
```
./p1.out <insert_command_name_here> <insert_command_paramters_here>
```
#### Input example:
```
./p1.out ls -l
```

### p2:
#### Compile:
```
gcc -o p2.out problem2.c
```
#### Run
```
./p2.out <insert_first_command_here> "|" <insert_second_command_here> 
```
#### Input example:
```
./p2.out ls "|" wc
```
---------
# Project 2
## Topics Covered
+ Paging
+ Least Recently Used Algorithm
+ Memory Management

## Program Specifications
In the LRU algorithm, the page being replaced from memory during a page fault is the one that
has been least recently used. And the page table stores frames based on how recently they
have been referenced or used. In the case of my implementation, the most recent pages are
pushed to the front of the page table (cache).
- Comments throughout the code explain the through process behind the approach.

## How to compile and run on Command Line Interface  
#### Compile
```
g++ lru.cpp -o lru
```
#### Run
```
./lru <tracefile_name> <number of frames> <mode>
```
#### Input example:
```
./lru bzip.trace 64 debug
```
---------
# Project 3
## Topics Covered
+ Concurrency
+ Mutex Locks

## Program Specifications
Porgram that solves the readers and writers problem. While avoiding the starvation of either the reader and writer threads. This was done by adding a mutex lock on top of the conventional two mutex locks for each type of thread (reader or writer). Full overview of the code can be found in "Project 3" directory.
## How to compile and run on Command Line Interface  
**Files that need to be in the directory before compiling**
- main.c
- readers_writers.c
- readers_writers.h
- scenarios.txt
- Makefile   <-optional to comp. & run w/make
#### Compile
##### With make
```
make
```
##### Without make
```
gcc -o rwmain main.c reader_writer.c
```
#### Run
```
./rwmain
```
-----------
# Project 4
## Topics Covered
+ File System
+ UNIX Utilities

## Program Specifications
**Program 1 (mystat)** imitates the comman linde program 'stat'. The program does that by calling the stat() system call on the specfied file or direecotry. Listing the file description: file size, number of blocks allocated, 
reference (link) count, file permissions, and file inode. Just like the UNIX 'stat' cmd command would do.

**Program 2 (mylist)** lists files in the given directory. When called without any 
arguments, the program should just print the file names. When invoked with the -l flag, the program prints out information about each file, such as the owner, group, permissions, and other information obtained from the stat() system call. The program take one additional argument, which is the directory to read, e.g., mylist -l directory. If no directory is given, the program uses the current working directory.   

**Program 3 (mylist)** prints out the last few lines of a file. When the user gives the specific number of lines from the end of the file.

**Program 4 (mysearch)** prints out the names of each file and directory in the same file system tree. Starting at a given point in the tree.

## How to compile and run on Command Line Interface  

#### Compile all files
##### With make
```
make
```
##### Without Make
```
gcc -o <executable_file_name> <c_file_name>
```
----------------------------------------
#### Run mystat
*show stats of directory or file*
```
./mystat <directory_or_file_name>
```
-------
#### Run mylist
*list file names in current directory*
```
./myls
```
*list file names and stats of files in current directory*
```
./myls -l
```
*list files names in specific directory given path*
```
./myls <directory_or_file_name>
```
*list files names and stats in specific directory*
```
./myls -l <directory_or_file_name>
```
----------------------------------------
#### Run mytail
*Print last # lines from buttom of a file*
```
./mytail <number-of-last-lines-from-bottom> <filename>
```
----------------------------------------
#### Run mysearch
*list files and content of subdirectories of current directory*
```
./mysearch 
```
*list files and content of subdirectories of specified directory*
```
./mysearch <directory-relative-path>
```




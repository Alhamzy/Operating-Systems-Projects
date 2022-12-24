# Operating-Systems-Projects
+ Collection of compeleted operating systems projects. Under the supervision of Dr Wanwan Li of University of South Florida.

# Project 1
## Fields Covered
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

# Project 2
## Fields Covered
+ Paging
+ Least Recently Used Algorithm
+ Memeory Management

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

# Project 3
## Fields Covered
+ Concurrency
+ Mutex Locks

## Program Specifications
Porgram that solves the readers and writers problem. While avoiding the starvation of either the reader and writer threads. This was done by adding a mutex lock on top of the conventional two mutex locks for each type of thread (reader or writer). Full overview of the code can be found in "Project 3" directory.
## How to compile and run on Command Line Interface  
**Files that need to be in the directory before compiling**
main.c
readers_writers.c
readers_writers.h
scenarios.txt
Makefile   <-optional to comp. & run w/make
#### Compile
##### w/make:
```
make
```
##### w.o/make
```
gcc -o rwmain main.c reader_writer.c
```
#### Run
```
./rwmain
```




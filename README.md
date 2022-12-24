# Operating-Systems-Projects
Collection of compeleted operating systems projects. Under the supervision of Dr Wanwan Li of University of South Florida.

-------------------------
# Fields Covered
CPU Virtualization
Process API in UNIX

# Program Specifications
## p1:
Program that runs through command line. Creates a new process through fork method. The program then executes the second command line argument. Taking the third and following arguments as paramters to the second argument's *specified* process. Methods used: 
## p2: 
The program uses 'fork()' to create processes and 'exec()' to assign the newly created processes what to do. Utilizing the pipe function, that uses a file descriptor to send input from one process to another. The second cmd argument outputs to the pipe function, allowing command at fourth argument to use it as input.

# How to compile and run on Command Line Interface  
## p1:
### Compile:
```
gcc -o p1.out problem1.c
'''
### Run:
'''
./p1.out <insert_command_name_here> <insert_command_paramters_here>.
'''
### Input example:
'''
./p1.out ls -l
'''

## p2:
### Compile:
'''
gcc -o p2.out problem2.c
'''
### Run:
'''
./p2.out <insert_first_command_here> "|" <insert_second_command_here> 
'''
### Input example:
'''
./p2.out ls "|" wc
'''



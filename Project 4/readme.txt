To compile files using make:
just type: (in command line)
->make

To compile normally:
->gcc -o <executable-file-name> myFile.c

example:
->gcc -o mystat.c mystat-Mohamed.c

----------------------------------------
To run mystat.exe:
*show stats of directory or file*
->./mystat <directoryORfile-name>
----------------------------------------
To run myls:
*list file names in current directory*
->./myls

*list file names and stats of files in current directory*
->./myls -l

*list files names in specific directory given path*
->./myls <directoryORfile-name>

*list files names and stats in specific directory*
->./myls -l <directoryORfile-name>
----------------------------------------
To run mytail:
*Print last # lines from buttom of a file*
->./mytail <number-of-last-lines-from-bottom> <filename>
----------------------------------------
To run mysearch:
*list files and content of subdirectories of current directory*
->./mysearch 

*list files and content of subdirectories of specified directory*
->./mysearch <directory-relative-path>
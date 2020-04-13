[cat(1)]: <http://man7.org/linux/man-pages/man1/cat.1.html>

###### dog(1)&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;This command acts just like [cat(1)] but in a reverse order&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;dog(1)
#
##### NAME
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;dog -- concatenate and print files
##### SYNOPSIS
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;cat [-benstuv] [file ...]
##### DESCRIPTION
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;The cat utility reads files sequentially, writing them to the standard
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;output.  The file operands are processed in command-line order. If file is a single dash ('-') or absent, dog reads from the standard input. If file is a UNIX domain socket, cat connects to it and then reads it until EOF.


##### EXIT STATUS
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;The cat utility exits 0 on success, and >0 if an error occurs.

##### EXAMPLES
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;The command:<br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;./dog file1<br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;will print the contents of file1 to the standard output.
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;The command:<br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;./dog file1 file2 - file3<br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;will sequentially dog reads from the standard input then prints the contents of file3, file2 and file1

##### run
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;follow the steps bellow in the command line:

            1) dog.c, Makefile should be in a same directory as commandline directory
            2) $ make
            3) $./dog
            
##### License
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Author: [Babak Farahmand](https://babak.us) formating from orginal cat command

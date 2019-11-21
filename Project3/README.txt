Nicholas Basti
Video Link:https://streamable.com/7m5bn
For my implementation of wordfreak I used a structure which I typedef to keep track of frequency of words.
Each Word structure contains text, a counter, and a reference to the next Word structure. My program checks the
environment variable to parse frequency and if that doesn't exist it will loop through all arguments given and
parse frequency. I limited all my I/O to system calls to what is supported by the Linux api. I created a
makefile that will run all my required program files. A pointer is used to keep track of my buffer while
reading through the text files.

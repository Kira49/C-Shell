# C-Shell
assignment:(

## Description
This is a shell designed to run like a linux terminal written in C.
Semicolon separated commands are taken as inputs, parsed, and executed.
Certain commands like ls, pwd, cd, pinfo, echo are inbuilt, and the remaining are executed using execvp command. 
Implementaion is majorly done using stat and dirent.
Background processes are also handled

## To run
```console
$ make
$ ./shell
```

## To exit
```console
$ quit
```

## ;-;
Has been made colorful to mimic your terminal to make it feel more usable

## bonus
:( if prev command executed with an error, else :) before prompt.
Previous working directory has been implemented. Use as:
```console
$ cd -
``


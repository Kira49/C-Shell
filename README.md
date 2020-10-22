# C-Shell
assignment:(

## Description
This is a shell designed to run like a linux terminal written in C.
Semicolon separated commands are taken as inputs, parsed, and executed.
Certain commands like ls, pwd, cd, pinfo, echo are inbuilt, and the remaining are executed using execvp command. 
Implementaion is majorly done using stat and dirent.
Background processes are also handled

### To run
```console
$ make
$ ./shell
```

### To exit
```console
$ quit
```
## Unusual commands
### jobs
Displays all ruinning jobs
```console
$ jobs
```
## kjob
Kills a specified job
```console
$ kjob [job id] [signal]
```
### overkill
Kills all running jobs
```console
$ overkill
```
### fg
Continues a suspended background process identified by Job ID as a foreground process
```console
$ fg [job id]
```
### bg
Continues a suspended background process identified by Job ID jid as a background process
```console
$ bg [job id]
```
### pinfo 
Takes a process ID as input and provides information about the process. If no arguments given, it provides information about the shell process running
```console
$ pinfo [pid]
```
### ;-;
Has been made colorful to mimic your terminal to make it feel more usable

### bonus
:( if prev command executed with an error, else :) before prompt.
Previous working directory has been implemented. Use as:
```console
$ cd -
```


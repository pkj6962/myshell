# MyShell

## How to Compile 

```
make
```

## How to Run
```
$ ./myshell
```

## Source Chart Flow 

### Show prompt
### Read command
### Parse command

### Check if built-in Command

```
- cd        :  change a working directory  
- exit      : kill all child process and terminate shell 
- jobs      : show all running or suspended background process 
- fg        : change suspended or running background process into running foreground process
- bg        :change suspended background process into running background process
- kill      : kill the process 

```

### Fork child process
### Wait child process to be terminated (if it is a foreground process)



### In Child Process 
```
if it is a pipe process
    open pipe with using pipe() function 
    duplicate piped file descriptor with STDIN or STDOUT 
    close all unused file descriptor (important!)
```
execute proceess with execvp() function 


### In Parent(Shell) Process
```
    if(Child process is on background)


    else (foreground)
        wait child process to be terminated (with waitpid() function)

```


# minishell
[![tclement's 42 minishell Score](https://badge42.vercel.app/api/v2/cl59lbrtc003009jqom2qgm4z/project/2129220)](https://github.com/JaeSeoKim/badge42)<br>
***This project is to create a simple shell. Concepts about processes and file descriptors are introduced.***

This is a group project completed by [T. Clement](https://github.com/DelicaTessa) & [J.B. Cornelisse](https://github.com/JayBeest)

## Technical considerations
> The following elements need to work like in bash

- Show a ```prompt``` when waiting for a new command

- Search and launch the right ```executable``` (based on the ```$PATH``` variable or by using relative or absolute path)

- Implement the below builtins:
  - ```echo``` with option ’-n’
  - ```cd``` with only a relative or absolute path
  - ```pwd``` without any options
  - ```export``` without any options
  - ```unset``` without any options
  - ```env``` without any options and any arguments
  - ```exit``` without any options

- Pipes ```|```

- ```'``` and ```"``` except for multiline commands

- Redirections ```<``` ```>``` ```>>``` ```<<``` except for file descriptor aggregation

- ```Environment variables``` ($ followed by characters)

- ```$?``` to store exit status of the previous command

- ```ctrl-C```, ```ctrl-D``` and ```ctrl-\```

## How to test
> Run the following commands

```shell
$ git clone https://github.com/DelicaTessa/42-minishell
$ cd 42-minishell
$ make
$ ./minishell
```

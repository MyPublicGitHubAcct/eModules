# Make

## Hello, World

In Makefile, enter this text then run using the ```make``` command. Run this using the command ```make hello```.

```shell
hello:
   echo "Hello, World"
```

## To use terminal in Sublime Text

### Install Terminus

- Ctrl+shift+p

```shell

Terminus
```

### Update Command Palette settings

- Preferences >Package Settings > Terminus > Command Palette

```shell

[
   {
        "caption": "Terminal (panel)",
        "command": "terminus_open",
        "args"   : {
           "cmd": "bash",
           "cwd": "${file_path:${folder}}",
           "title": "Command Prompt",
           "panel_name": "Terminus"
        }
   },
]
```

### Update key bindings

- Preferences >Package Settings > Terminus > Key Bindings

```shell
[
   {
       "keys": ["alt+1"],
       "command": "terminus_open",
       "args" : {
           "cmd": "bash",
           "cwd": "${file_path:${folder}}",
           "panel_name": "Terminus"
       }
   }
]
```

## To compile

### With gcc

```shell
g++ main.cpp -o main
```

### With Makefile

```shell
make
```

## To run the application

```shell
open main
```

## Makefile basics

The main use of Make is to list out a set of directions to compile some c or c++ files. The syntax of makefile stuff is...

```shell
targets : prerequisites
   command
   command
   command
```

.PHONY is used to tell make that the command will not create a file of the same name as the target.

For example, this tells make that it is not making a file called "clean".

```zsh
.PHONY: clean
```

Some odd symbols are used in makefiles. For example,

```makefile
all: library.cpp main.cpp
```
- $@ evaluates to all
- $< evaluates to library.cpp
- $^ evaluates to library.cpp main.cpp

## To run the executable
```shell
./main
```

## Unit testing

The Criterion framework is used in this example.

## Sources
- https://earthly.dev/blog/make-flags/

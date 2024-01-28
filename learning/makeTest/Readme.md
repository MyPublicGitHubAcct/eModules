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

Documentation can be found [here](https://www.gnu.org/software/make/manual/make.html)

Makefiles usually have a form like:

```makefile
CC=
CFLAGS=
LDFLAGS=
SOURCE=
OBJECTS=$(SOURCE:.cpp=.o)
TARGET=

all: $(SOURCE) $(TARGET)

$(TARGET): $(OBJECTS)
   $(CC) $(LDFLAGS) $(OBJECTS) -o $@

$(SOURCE):
   $(CC) $(CFLAGS) $< -o $@

clean:
   rm $(OBJECTS)
```

### Rules

A rule tells make two things: when the targets are out of date, and how to update them when necessary.  The syntax of a rule is:

```shell
targets : prerequisites
   recipe
   ...
```

- targets are file names, separated by spaces.
- prerequisites are targets, separated by spaces.
- recipes are the shell commands being run.

### Keywords

- _wildcard_ allows for wildcard expansion in functions.
- _patsubst_ ?

### Phony

.PHONY is used to tell make that the command will not create a file of the same name as the target.

For example, this tells make that it is not making a file called "clean".

```shell
.PHONY: clean
```

### Automatic variables

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

The [Criterion framework](https://github.com/Snaipe/Criterion) is used in this example. Used this [video](https://youtu.be/JarMkGWTF8Y?si=QexhSTRI7c8ywzLt) as an example.

## Sources

- https://earthly.dev/blog/make-flags/

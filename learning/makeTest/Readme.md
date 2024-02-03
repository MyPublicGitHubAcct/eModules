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

## Compile and run

### Compile with gcc

```shell
g++ main.cpp -o main
```

### Compile with Makefile

```shell
make
```

### To run the application

```shell
open main
```

-or-

```shell
./main
```

## Makefiles basics

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

Rules are shell command emitted by make to produce an output file. They use pattern matching on file types. A rule tells make two things: when the targets are out of date, and how to update them when necessary.

The syntax of a rule is:

```shell
targets : prerequisites
   recipe
   ...
```

- targets are file names, separated by spaces.
- prerequisites are targets, separated by spaces.
- recipes are the shell commands being run.

### Phony

.PHONY is used to tell make that the command will not create a file of the same name as the target.

For example, this tells make that it is not making a file called "clean".

```shell
.PHONY: clean
```

#### Syntax

Examples from this [video](https://youtu.be/FfG-QqRK4cY).

An example makefile from that video can be found [here](https://git.io/JvLW5)

__=__ --> _verbatim assignment_.

```makefile
SRCS = main.c
```

__:=__ --> _simple expansion_.

```makefile
SRCS := $(wildcard *.c)
```

```makefile
SRCS := $(shell find . -name '*.c')
```

__Note__: Should not do inline comments as these will be included in expansions.

```makefile
FOO := $(BAR) # comment
```

__!=__ --> _shell output_.

```makefile
SRCS != find . -name '*.c'
```

__?=__ --> _conditional assignment_. In the example, if CFLAGS does not exist, it will be created and will be assigned whatever CC_FLAGS represents.

```makefile
CFLAGS ?= $(CC_FLAGS)
```

__+=__ --> _append to_.

```makefile
CC_FLAGS = -g
CC_FLAGS += -Wextra
```

### Built-in functions

1. Automatically list the objects defined as sources, simply change the extension.

```makefile
$(SRCS:.c=.o)
```

2. Place objects in a folder. There are many filename functions.

```makefile
$(addprefix build/,$(OBJS))
```

3.  Logic functions - should rarely be used.

```makefile
$(if ...) $(or ...) $(and ...)
$(foreach var, list, text)
```

4. Value function allows you to print a variable without expanding it. ```echo``` will expand the variable.

```makefile
$(value (VARIABLE))
```

5. _error_ will stop compilation, _warning_ and _info_ will provide messaging based on the string passed to the function.

```makefile
$(error ...) $(warning ...) $(info ...)
```

### Automatic variables

Some odd symbols are used in makefiles. For example,

```makefile
SRCS = main.c
OBJS = $(SRCS:.c=.o)
DIR := build
OBJS := $(addprefix $(DIR), $(OBJS))
TARGET := foo
.PHONY clean

$(DIR)/%.o: %.c
   $(CC) -c $(CFLAGS) -o $@ $<

$(TARGET): $(OBJS) | $(DIR)
   $(CC) -o $@ $<

$(DIR):
   mkdir -p $@
```

- __$@__: current target
- __$<__: first prerequisite
- __$^__: all prerequisites
- __$?__: prerequisites that have changed
- __$|__: order-only prerequisites (prevents prerequisites higher in the chain from being rebuilt unless something has changed)

### Automatic Dependency

```makefile
DEPDIR = .deps
DEPFILES := $(SRCS.%c = $(DEPDIR)/%.d)
DEPFLAGS = -MT $@ -MMD -MP -MF $(DEPDIR)/*.d

%.o: %.c $(DEPDIR)/.%d | $(DEPDIR)
   $(CC) -c $(CFLAGS) $(DEPFLAGS) -o $@ $<

<rest of the rules/recipies>

$(DEPDIR):
   @mkdir -p $(DEPDIR)

$(DEPFILES):
   # some recipies

include $(wildcard $(DEPFILES))
```

- Make integrates with the compiler

- Dependency files contain information:
   - __-MT__: Name of the target
   - __-MMD__: List user header files
   - __-MP__: Add phony targets
   - __-MFT__: Name of the file

- The DEPFILES recipe and the include line __must__ be the last lines of hte file.
- Make will only rebuild preprequisites which have a newer timestamp than the generated dependecy file.

__Note__: The "@" symbol in the like ```@mkdir -p $(DEPDIR)``` will suppress the output when it is run.

### Keywords

- _wildcard_ allows for wildcard expansion in functions.
- _shell_ allows for (bash) shell commands to be run.
- _patsubst_ ?






## Unit testing

The [Criterion framework](https://github.com/Snaipe/Criterion) is used in this example. Used this [video](https://youtu.be/JarMkGWTF8Y?si=QexhSTRI7c8ywzLt) as an example.

## Sources

- https://earthly.dev/blog/make-flags/
- https://jsandler18.github.io/explanations/makefile.html

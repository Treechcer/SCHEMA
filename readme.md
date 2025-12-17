# SCHEMA

Schema is a small C++ script to generate your basic file for any programming language or specific project types you want.

## How does it work?

You need a directory called "builds" in the location where you run this C++ script where you can add / delete any directories you want,
that directory has to have some files, the files you want to copy into your next project. For example if you run:

```bash
SCHEMA C
#or you can use, whatever suits you more
SCHEMA -C
```

with the basic files, it will create:

```bash
your-project-directory/
├─ cFiles/
│  └─ main.c
├─ headers/
│  └─ ... 
├─ .clang-format
├─ .gitignore
└─ README.md
```

The file `main.c` will contain:

```c
#include <stdio.h>

int main(){
    printf("%s", "Hello World!");
    return 0;
}
```

This creates a small C starter project that prints "Hello World!".

## Customization

You can delete any directory there is in `./builds/`, all of them are my presets, however you
can change the files to anything you like for any language and then use it the same way, it'll
then build your project structure you've changed it into. You can add any other directory and it'll be
callable by the name of the directory, so if you want to add directory for `Malbolge` you would
just add made this structure of directories: `.\builds\Malbolge` where you can add any kind of
files, the difference would be for language / project types that have more words, to achieve this
you would do the same but you would be calling it like:

```bash
SCHEMA "HOLY C"
#or
SCHEMA 'HOLY C'
```

This should work for `HOLY C` or any other language with more words.

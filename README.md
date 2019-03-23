# InquireC

Easily make user list forms in C with a header file.

## To use:
Move inquire.h to the project directory

Include using:
```C
#include "inquire.h"
```
Create a list by:
``` C
struct inquire_list i_list;
char *list[5] = {"Hello1", "Hello2", "Hello3", "Hello4", "Hello5"};
i_list.list = list;
i_list.len = LEN(list);
```
Change the contents of list to whatever desired

And call it by:
```C
singleChoice(i_list)
```

The position in the list array of what is selected is returned

Whole Example code:
```C
#include "inquire.h"

int main(int argc, char *argv[])
{
    struct inquire_list i_list;
    char *list[5] = {"Hello1", "Hello2", "Hello3", "Hello4", "Hello5"};
    i_list.list = list;
    i_list.len = LEN(list);

    printf("Selected option: %s\n", list[singleChoice(i_list)]);
}
```

## Libraries
Libraries required in inquire are all standard:
```C
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <assert.h>
#include <string.h>
```

## All Functions included

```C
int getch(void)
struct inquire_list
int singleChoice(struct inquire_list <list>)
```
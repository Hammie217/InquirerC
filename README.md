# InquirerC

Easily make user list forms in C with a header file.

## To use:
Move inquire.h to the project directory

Include using:
```C
#include "inquire.h"
```

Create a list by:
Defining options to be listed plus a terminating `NULL` as such:
``` C
char *list[] = {"Hello1", "Hello2", "Hello3", "Hello4", "Hello5", NULL};
```

Change the contents of list to whatever desired

And call it by:
```C
singleChoice(list)
```

The position in the list array of what is selected is returned

Whole Example code:
```C
#include "inquire.h"

int main(int argc, char *argv[])
{
    char *list[5] = {"Hello1", "Hello2", "Hello3", "Hello4", "Hello5", NULL};

    printf("Selected option: %s\n", list[singleChoice(list)]);
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
int singleChoice(char *array[])
int *multiChoice(char *array[])
```

## Examples:
### SingleChoice
```C
#include "inquire.h"

int main(int argc, char *argv[])
{
    char *list[5] = {"Hello1", "Hello2", "Hello3", "Hello4", "Hello5", NULL};

    printf("Selected option: %s\n", list[singleChoice(list)]);
}
```
### MultiChoice

```C
#include "inquire.h"

int main(int argc, char *argv[])
{
    int *response;
    char *list[] = {"Hello1", "Hello2", "Hello3", "Hello4", "Hello5", NULL};

    response = multiChoice(list);

    printf("Choices:\n");
    for (int i = 0; response[i] >= 0; i++)
    {
        printf("%s\n", list[response[i]]);
    }
}
```
![MultiChoice GIF Example](http://www.giphy.com/gifs/1mhkfFVxovHLa2ojrW.gif)


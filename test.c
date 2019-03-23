#include "inquire.h"

int main(int argc, char *argv[])
{
    char *list[] = {"Hello1", "Hello2", "Hello3", "Hello4", "Hello5", NULL};

    printf("Selected option: %s\n", list[singleChoice(list)]); //print out selected option from list
}
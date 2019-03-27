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
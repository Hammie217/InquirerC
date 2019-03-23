#include "inquire.h"

int main(int argc, char *argv[])
{
    struct inquire_list i_list;
    char *list[5] = {"Hello1", "Hello2", "Hello3", "Hello4", "Hello5"};
    i_list.list = list;
    i_list.len = LEN(list);

    printf("Selected option: %s\n", list[singleChoice(i_list)]); //print out selected option from list
}
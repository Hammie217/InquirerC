#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

/*------------------------------------------------*/
int getch(void)
{
    int c = 0;

    struct termios org_opts, new_opts;
    int res = 0;
    //-----  store old settings -----------
    res = tcgetattr(STDIN_FILENO, &org_opts);
    assert(res == 0);
    //---- set new terminal parms --------
    memcpy(&new_opts, &org_opts, sizeof(new_opts));
    new_opts.c_lflag &= ~(ICANON | ECHO | ECHOE | ECHOK | ECHONL | ECHOPRT | ECHOKE | ICRNL);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_opts);
    c = getchar();
    //------  restore old settings ---------
    res = tcsetattr(STDIN_FILENO, TCSANOW, &org_opts);
    assert(res == 0);
    return (c);
}

int *multiChoice(char *arr[])
{
    int position = 1;   // variable to store list position
    int maxPos = 0;     // variable to store max possible position to stop overflow
    while (arr[maxPos]) //not NULL
    {                   //print all list items
        maxPos++;
    }
    int *choiceArr = malloc((maxPos + 1) * sizeof(int *));
    int checkedArray[maxPos];
    for (int i = 0; i < maxPos; i++)
    {
        checkedArray[i] = 0;
    }
    int currentChoice = 0;

    for (int i = 0; i < maxPos; i++)
    { //print all list items
        printf("   %s\n", arr[i]);
    }
    printf("   %s\n", "Done");

    printf("\e[?25l\033[38;2;51;102;255m"); //hide cursor and set arrow to blue(51,102,255)

    printf("\033[%dA\u25B6\033[1D", maxPos + 1); //move cursor to top value and draw arrow
    do
    {
        char c = getch();
        if (c == '\033')
        {            // if the first value is esc
            getch(); // skip the [
            switch (getch())
            { // the real value
            case 'A':
                if (position > 1)
                {
                    printf(" \033[1D");      //clear arrow from current space
                    printf("\033[1A");       //move up a row
                    printf("\u25B6\033[1D"); //draw arrow and move cursor backwords
                    position--;
                }
                break;
            case 'B':
                if (position <= maxPos)
                {
                    printf(" \033[1D");      //clear arrow
                    printf("\033[1B");       //move down row
                    printf("\u25B6\033[1D"); //draw arror and move cursor to start
                    position++;
                }
                break;
            }
        }
        else if (c == '\n')
        { //when pressed enter

            if (position == maxPos + 1) //if on done
            {
                for (int i = position; i <= maxPos + 1; i++)
                { //move beneath bottom row
                    printf("\033[1B");
                }
                printf("\e[?25h\033[38;2;255;255;255m"); //turn cursor on and set color back to white

                break;
            }
            else
            {
                if (checkedArray[position - 1] == 0)
                {
                    checkedArray[position - 1] = 1;
                    choiceArr[currentChoice] = position - 1; //add position to array
                    currentChoice++;                         //increase position of array
                    printf("\033[1C\033[38;2;67;188;100m\u2714\033[2D\033[38;2;51;102;255m");
                    //
                }
                else if (checkedArray[position - 1] == 1)
                {
                    int ii = 0;
                    int temp[currentChoice];
                    for (int i = 0; i < currentChoice; i++)
                    {
                        if (choiceArr[i] != (position - 1))
                        {
                            temp[ii] = choiceArr[i];
                            ii++;
                        }
                    }
                    for (int i = 0; i < currentChoice - 1; i++)
                    {
                        choiceArr[i] = temp[i];
                    }
                    currentChoice--;
                    checkedArray[position - 1] = 0;
                    printf("\033[1C \033[2D");
                }
            }
        }

    } while (1);

    choiceArr[currentChoice] = -1;
    return (choiceArr);
}

int singleChoice(char *arr[])
{

    int position = 1;   // variable to store list position
    int maxPos = 0;     // variable to store max possible position to stop overflow
    while (arr[maxPos]) //not NULL
    {                   //print all list items
        maxPos++;
    }

    for (int i = 0; i < maxPos; i++)
    { //print all list items
        printf("   %s\n", arr[i]);
    }

    printf("\e[?25l\033[38;2;51;102;255m"); //hide cursor and set arrow to blue(51,102,255)

    printf("\033[%dA\u25B6\033[1D", maxPos); //move cursor to top value and draw arrow

    do
    {
        char c = getch();
        if (c == '\033')
        {            // if the first value is esc
            getch(); // skip the [
            switch (getch())
            { // the real value
            case 'A':
                if (position > 1)
                {
                    printf(" \033[1D");      //clear arrow from current space
                    printf("\033[1A");       //move down a row
                    printf("\u25B6\033[1D"); //draw arrow and move cursor backwords
                    position--;
                }
                break;
            case 'B':
                if (position < maxPos)
                {
                    printf(" \033[1D");      //clear arrow
                    printf("\033[1B");       //move down row
                    printf("\u25B6\033[1D"); //draw arror and move cursor to start
                    position++;
                }
                break;
            }
        }
        else if (c == '\n')
        { //when pressed enter
            for (int i = position; i <= maxPos; i++)
            { //move beneath bottom row
                printf("\033[1B");
            }
            printf("\e[?25h\033[38;2;255;255;255m"); //turn cursor on and set color back to white

            break;
        }

    } while (1);
    return (position - 1);
}

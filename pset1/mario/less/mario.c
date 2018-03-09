#include <stdio.h>
#include <cs50.h>

//libraries header files

int main(void)
{
    int num; //declaration

    //loop until the input is positive integer

    do
    {
        num = get_int("Height: ");
    }
    while (!(num >= 0 && num <= 23));

    //loop for the pyramid

    for (int i = 0; i < num; i++)
    {
        //loop for printing space
        for (int j = num - i - 2; j >= 0; j--)
        {
            printf("%s", " ");
        }

        //loop for #

        for (int k = 1; k  <= 2 + i; k++)
        {
            printf("%s", "#");
        }

        //newline
        printf("%s\n", "");
    }
}
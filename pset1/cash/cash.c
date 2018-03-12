#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    //declare and initialize variables
    float n;
    int count = 0;

    //looping if the value < 0
    do
    {
        n = get_float("Change owed: ");
    }
    while (!(n > 0));


    //rounding

    n = round(n * 100);

    //checking for 25cents
    while (n >= 25)
    {
        count++;
        n = n - 25;
    }

    //for 10

    while (n >= 10)
    {
        count++;
        n = n - 10;
    }

    //for 5

    while (n >= 5)
    {
        count++;
        n = n - 5;
    }

    //for 1

    while (n >= 1)
    {
        count++;
        n = n - 1;
    }


    //printing the count

    printf("%i\n", count);
}

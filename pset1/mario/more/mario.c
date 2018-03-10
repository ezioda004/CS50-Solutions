#include <stdio.h>
#include <cs50.h>

int main(void)
{

    int n = get_int("Height:");
    int hashNumber = 1;
    char hash = '#';
    while (!(n >= 0 && n <= 23))
    {
        n = get_int("Height:");
    }
    for (int i = n; i > 0; i--)
    {
        printf("%*s", i - 1, "");
        for (int j = 1; j <= hashNumber; j++)
        {
            printf("%c", hash);
        }
        printf("%s", "  ");

        for (int k = 1; k <= hashNumber; k++)
        {
            printf("%c", hash);
        }
        printf("%s\n", "");
        hashNumber++;

    }
}
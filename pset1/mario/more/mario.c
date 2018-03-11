#include <stdio.h>
#include <cs50.h>

//libraries header files

int main(void) //main function
{

    int n = get_int("Height:");  //getting height from user
    int hashNumber = 1;         //initializing hash
    char hash = '#';           // initializing the char
    while (!(n >= 0 && n <= 23)) // checking for number in b/w 0 and 23
    {
        n = get_int("Height:");
    }
    for (int i = n; i > 0; i--) // looping through
    {
        printf("%*s", i - 1, ""); //adding space before
        for (int j = 1; j <= hashNumber; j++) 
        {
            printf("%c", hash); // printing hashes
        }
        printf("%s", "  "); //2 spaces in b/w

        for (int k = 1; k <= hashNumber; k++)
        {
            printf("%c", hash); //printing hashes other side
        }
        printf("%s\n", ""); //prints spaces at the end
        hashNumber++; //increment number by 1

    }
}
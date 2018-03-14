#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

//adding library header

int main(int argc, string argv[]) //argument length and argument string array
{

    if (argc == 2) //checking if argument length is 2
    {
        for (int i = 0; i < strlen(argv[1]); i++) //looping to check if every char in in the argument is alpha
        {
            if (!isalpha(argv[1][i]))
            {
                return 1;
            }
        }

        string p = get_string("plaintext: "); //prompt user for input
        printf("ciphertext: ");

        for (int j = 0, k = 0; j < strlen(p); j++) //looping through the input string, initialized k to track string argv[1] characters

        {
            //checking if last char of argv is reached, if you make it first
            if (strlen(argv[1]) == k)
            {
                k = 0;
            }

            //checking if prompt strings character is alpha
            if (isalpha(p[j]))
            {
                //if lower
                if (islower(p[j]))
                {
                    char l = tolower(argv[1][k]);
                    int diff = l - 'a'; //creating a varibale for the relative char diff
                    printf("%c", ((p[j] - 'a') + diff) % 26 + 'a');
                    //adding both of their relative ASCII code and modding by 26 in case their sum is past `z` and finally adding a

                }
                // else make it upper
                else
                {
                    char u = toupper(argv[1][k]);
                    int diff = u - 'A';
                    printf("%c", ((p[j] - 'A') + diff) % 26 + 'A');
                }

                k++;
            }
            else
            {
                printf("%c", p[j]);
            }

        }
        printf("%s\n", "");
    }
    //print error and returning 1
    else
    {
        printf("%s", "Error error");
        return 1;
    }
}
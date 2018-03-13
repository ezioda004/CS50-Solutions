#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//libraries header files

int main(int argc, string argv[])
{
    //checks length of arguments, should be 2, 1st is the filename itself while 2 is the cypher key
    if (argc == 2)
    {
        int converted = atoi(argv[1]); //converting string to int
        string text = get_string("plaintext: "); //grabbing text to cypher

        printf("ciphertext: ");
        for (int i = 0; i < strlen(text); i++) //looping through the string
        {
            if (isalpha(text[i]))  //checking if the char is alphabet
            {
                if (islower(text[i])) //checking if text is lowercase
                {
                    //text[i] % a, making alphabatical index then adding key to the alpha index % 26 so
                    //that the text isnt overflowed and finally getting the value back to the ASCII
                    printf("%c", ((text[i] % 'a') + converted) % 26 + 'a');
                }

                else //for upercases
                {
                    printf("%c", ((text[i] % 'A') + converted) % 26 + 'A');
                }

            }
            else
            {
                printf("%c", text[i]);
            }

        }
        printf("%s\n", "");
    }
    else  //To exit if argument is not 2
    {
        printf("Error, please input 1 argument\n");
        return 1;
    }

}
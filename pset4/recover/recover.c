#include <stdio.h>
#include <cs50.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: recover filename\n");
        return 1;
    }

    char *filename = argv[1];

    FILE *inptr = fopen(filename, "r");

    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", filename);
        return 2;
    }

}
#include <stdio.h>
//including standard library

int main(int argc, char *argv[])
{
    //making sure if the argument length is 2 else throwing error
    if (argc != 2)
    {
        fprintf(stderr, "Usage: recover filename\n");
        return 1;
    }

    //assigning the filename to filename pointer
    char *filename = argv[1];

    FILE *inptr = fopen(filename, "r");

    //if for some reason unable to reason then throw error
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", filename);
        return 2;
    }

    //initialize/declaring variables
    //buffer 512 bytes
    unsigned char buffer[512];

    //jpegFilename
    char jpegFilename[8] = {0};

    //counter for how many JPEGs have been made yet
    int jpegCounter = 0;

    //initializing NULL to img pointer, ini here cause scope
    FILE *img = NULL;

    //to keep track if the old file is open
    int isOldFileOpen = 0;


    //loop over blocks
    while (fread(buffer, 512, 1, inptr))
    {
        //check if the first 3 bytes are JPEG and the 4th bytes first 4 bits are JPEGS
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            //found a jpeg

            //closing the old file if opened
            if (isOldFileOpen == 1)
            {
                fclose(img);
                img = NULL;
            }

            //create a jpeg
            sprintf(jpegFilename, "%03i.jpg", jpegCounter);

            //open the file
            img = fopen(jpegFilename, "w");

            //write in jpeg
            fwrite(buffer, 512, 1, img);

            //incrementing jpeg counter
            jpegCounter++;

            isOldFileOpen = 1;

        }
        else if (isOldFileOpen == 1) //continue writing to old file
        {
            fwrite(buffer, 512, 1, img);
        }

    }


    //closing files
    if (NULL != img)
    {
        fclose(img);
    }

    if (NULL != inptr)
    {
        fclose(inptr);
    }


    return 0;

}

//Pseudo code
//open mem card
// find beginning of jpeg
// open a new jpeg
// write 512 bytes untill new jpeg is found
// eof
// Helper functions for music
#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "helpers.h"
//All the library header files required.


// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    // TODO
    //converting char to int, subtracting boths ASCII and getting relative int.
    int nume =  fraction[0] - '0';
    int deno =  fraction[2] - '0';

    //deno * x = 8

    return nume * (8 / deno);

}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    // TODO
    //o: integer i: string
    //A4 is 440, 2^1/12 for +1 semitone
    //variables initialized
    char no = note[0];
    char hash = '#';
    int acc = 0;     //modifier values +1 for #, -1 for b
    int oct;
    double freq_pow; //double for keeping decimal values
    int def_oct;     //default octave
    int freq;

    //checking notes length and assigning chars to variable accordingly
    if (strlen(note) == 2)
    {
        oct = note[1] - '0';
        acc = 0;
    }
    else
    {
        if (note[1] == hash)
        {
            acc++;
        }
        else
        {
            acc--;
        }
        oct = note[2] - '0';
    }

    //Made everything relative to 'A'
    if (no == 'A')
    {
        freq_pow = 0;
        def_oct = oct - 4; //by 4 because A4 = 440, everything is relative to that
    }
    else if (no == 'B')
    {
        freq_pow = 2;
        def_oct = oct - 4;
    }
    else if (no == 'C')
    {
        freq_pow = 3;
        def_oct = oct - 5; //^above reason relative to A4
    }
    else if (no == 'D')
    {
        freq_pow = 5;
        def_oct = oct - 5;
    }
    else if (no == 'E')
    {
        freq_pow = 7;
        def_oct = oct - 5;
    }
    else if (no == 'F')
    {
        freq_pow = 8;
        def_oct = oct - 5;
    }
    else if (no == 'G')
    {
        freq_pow = 10;
        def_oct = oct - 5;
    }
    else
    {
        freq_pow = 0;
        def_oct = oct - 4;
    }
    freq_pow = freq_pow + acc; //adding modifier to frequency power

    if (freq_pow < 0)
    {
        freq_pow = 11;
        def_oct--;
    }

    freq = round(440.00 * pow(2, freq_pow / 12) * pow(2, def_oct));
    return freq;

}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    // TODO
    if (strlen(s) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

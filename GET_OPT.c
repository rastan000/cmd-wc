#include <stdio.h>
#include <getopt.h>
#include <stdlib.h>
#include <system.h>
#include "WC.h"



void get_opt(FILE* stream, int argNum, char* const *argvalue)
{
    int nextopt;

    const char *optShort = "lLwmh";
    
    const struct option opt_long[] = {
    
        { "line",                    0, NULL, 'l' },
        { "max-line-length",         0, NULL, 'L' },
        { "word",                    0, NULL, 'w' },
        { "chars",                   0, NULL, 'm' },
        { "help",                    0, NULL, 'h' },
        { NULL,                      0, NULL, 0   }
    
    };

    do
    {
        nextopt = getopt_long(argNum, argvalue, optShort, opt_long, NULL);

        switch (nextopt)
        {
        case 'h':
            print_help(stdout, 0, argvalue[0]);
            rewind(stream);
            break;
        case 'm':
            printf("%d " ,charMax(stream));
            rewind(stream);
            break;
        case 'w':
            printf("%d ", countWord(stream));
            rewind(stream);
            break;
        case 'L':
            printf ("%d ", maxCharLine(stream));
            rewind(stream);
            break;
        case 'l':
            printf("%d ", countLine(stream));
            rewind(stream);
            break;
        case '?':
            print_help(stderr, 1, argvalue[0]);
        //case '1':
            //break;
        //default:
            //abort();
            //break;
        }
    } while (nextopt != -1);
    

    return;
}

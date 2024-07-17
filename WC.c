#include <stdio.h>
#include <stdlib.h>
#include <string.h>




void print_help(FILE *stream, int exitCode, const char *programName)
{
    fprintf(stream, "Utiliation : %s [cmd__opt__arg...........]\n", programName);
    
    fprintf(stream, 
                "-l, --lines                        print the newline counts\n"
                "-L, --max-line-length              print the maximum display width\n"
                "-w, --words                        print the word counts\n"
                "-m, --chars                        print the character counts\n"
                "-h  --help                         display this help and exit\n");
}

int maxArray(int *array, int size)
{
    int i;
    int max;
    max = array[0];

    for ( i = 0; i < size; i++)
    {
        if (max < array[i])
            max = array[i];
        else
            ;
    }

    return max;
}

int charMax(FILE *stream)
{
    char c;
    int count;

    count = 0;

    while ((c = fgetc(stream)) != EOF)
        count++;
    
    return count;
}


int countLine(FILE *stream)
{
    char c;
    int line;
    line = 0;


    while ((c = fgetc(stream)) != EOF)
    {
        if (c == '\n')
            line++;
    }
    return (line);
}

int countWord(FILE *stream)
{
    int word;
    char c;
    char *wc;
    wc = malloc(sizeof(char)*255);
    
    word = 0;
    while ((c = fgetc(stream)) != EOF)
    {
        if (fscanf(stream, "%s", wc))
            word++;
    }   

    return (word-1);
}

int maxCharLine(FILE *stream)
{
    int max;
    int line;
    int *array;
    int nbr = 0;
    int i = 0;
    char c;

    line = countLine(stream);
    if (line <= 0) {
        fprintf(stdout, "NULL\n");
        exit(EXIT_SUCCESS);
    }

    array = malloc(sizeof(int) * line);
    if (array == NULL) {
        fprintf(stderr, "Erreur sur l'allocation du tableau \"array\"\n");
        exit (EXIT_FAILURE);
    }

    rewind(stream);

    while ((c = fgetc(stream)) != EOF) {
        nbr++;
        if (c == '\n') {
            array[i] = nbr;
            nbr = 0;
            i++;
        }
    }

    max = maxArray(array, line);


    free(array);

    return (max-1);
}





/*int main(int argc, const char *argv[])
{
    FILE *fic = fopen(argv[1], "r");

    printf("%d", countWord(fic));
    printf("%d\n", countLine(fic));
    printf("%d", maxCharLine(fic));


    fclose(fic);
    return 0;
}*/
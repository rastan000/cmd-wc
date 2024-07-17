#include "WC.h"
#include "GET_OPT.h"


int main(int argc, char *const argv[])
{

    FILE *fic = fopen(argv[2], "r");

    get_opt(fic, argc, argv);

    fclose(fic);

    return 0;
}



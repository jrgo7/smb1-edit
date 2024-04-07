/*
Read Super Mario Bros. ROM data

For every byte in `ROM_FILENAME`:
    If the byte can be interpreted as a number or letter,
        The program prints it out as such.
    Otherwise,
        The program prints out a space.

*/
#include <stdio.h>
#include "consts.h"
#include "funcs.c"


int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Usage: reader <path to Mario 1(-based) NES file>");
        return 1;
    }
    FILE *fp = fopen(argv[1], "rb");
    unsigned __int8 cur;
    __int8 cur_conv;
    int ctr = 0;
    while (fread(&cur, sizeof(__int8), 1, fp) != 0)
    {
        cur_conv = marioToAscii(cur);
        if (cur_conv != -1)
            printf("%c", cur_conv);
        else
            printf("_");
        ctr++;
    }
    fclose(fp);
    return 0;
}
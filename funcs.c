#include <stdio.h>

/*
    @retval `c` mapped to the Super Mario Bros CHR table if it is mappable.
    @retval `-1` if it is unmappable.
*/
__int8 asciiToMario(char c)
{
    if ('A' <= c && c <= 'Z')
        return c - 55;
    else if ('a' <= c && c <= 'z')
        return c - 32 - 55;
    else if ('0' <= c && c <= '9')
        return c - '0';
    switch (c)
    {
        case ' ':
            return BLANK_SYMBOL;
        case '@':
            return COPYRIGHT_SYMBOL;
        case '-':
            return DASH_SYMBOL;
        case '*':
            return X_COUNTER_SYMBOL;
        case '!':
            return EXCLAMATION_SYMBOL;
        case '.':
            return PERIOD_SYMBOL;
    }
    return BLANK_SYMBOL;
}

int marioToAscii(unsigned __int8 c)
{
    if ('A' - 55 <= c && c <= 'Z' - 55)
        return c + 55;
    else if ('0' - '0' <= c && c <= '9' - '0')
        return c + '0';
    switch (c)
    {
        case BLANK_SYMBOL:
            return ' ';
        case COPYRIGHT_SYMBOL:
            return '@';
        case DASH_SYMBOL:
            return '-';
        case X_COUNTER_SYMBOL:
            return '*';
        case EXCLAMATION_SYMBOL:
            return '!';
        case PERIOD_SYMBOL:
            return '.';
    }
    return -1;
}
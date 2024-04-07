/*
This is the main text editor program.
To compile:
    `gcc -Wall edit.c -o edit`
*/
#include <stdio.h>
#include <string.h>
#include "consts.h"
#include "funcs.c"

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        printf("Usage: edit <path to input file> <path to output file>\n");
        return 1;
    }

    FILE *in_fp = fopen(argv[1], "rb");
    FILE *out_fp = fopen(argv[2], "wb");

    str32 choices[] = {
        // HUD
        "MARIO", "LUIGI", "WORLD", "TIME",
        // BLACK SCREEN
        "WORLD", "TIME UP", "GAME OVER",
        // ANOTHER CASTLE
        "THANK YOU MARIO!", "THANK YOU LUIGI!",
        "BUT OUR PRINCESS IS IN", "ANOTHER CASTLE",
        // MISC
        "WELCOME TO WARP ZONE!", "@1985 NINTENDO",
        "1 PLAYER GAME", "2 PLAYER GAME",
        "TOP-"
        };
    int offsets[] = {
        MARIO, LUIGI, HUD_WORLD, TIME,
        INTRO_WORLD, TIME_UP, GAME_OVER,
        THANK_YOU_MARIO, THANK_YOU_LUIGI,
        BUT_OUR_PRINCESS_IS_IN, ANOTHER_CASTLE,
        WARP_ZONE, COPYRIGHT,
        ONE_PLAYER_GAME, TWO_PLAYER_GAME,
        TOP
        };
    int choice = -1;
    int max_len;
    int actual_len;
    int too_long;
    str32 new;
    unsigned __int8 byte;

    // Copy original ROM data to output ROM
    while (fread(&byte, sizeof(__int8), 1, in_fp) != 0)
        fwrite(&byte, sizeof(__int8), 1, out_fp);

    for (int i = 0, len = sizeof(choices)/sizeof(str32); i < len; i++)
    {
        switch (i)
        {
            case HUD_ELEMENTS:
                printf("HUD Elements:\n");
                break;
            case BLACK_SCREEN:
                printf("Black Screen:\n");
                break;
            case THANKS:
                printf("Toadstool's Retainers:\n");
                break;
            case MISC:
                printf("Miscellaneous:\n");
                break;
        }
        printf("\t[%2d] %s (Offset: 0x%04x)\n", i+1, choices[i], offsets[i]);
    }

    while (choice != 0)
    {
        printf("Which text do you want to edit? (0 to quit): ");
        scanf("%d", &choice);
        while (getchar()!='\n');

        if (choice != 0)
        {
            choice--;
            max_len = strlen(choices[choice]);
            do
            {
                printf("\tPlease enter new text. (Max %d chars): ", max_len);
                gets(new);
                actual_len = strlen(new);
                too_long = actual_len > max_len;
                if (too_long)
                    printf("\tSorry, string is too long!\n");
            } while (too_long);
            printf("\tWriting %s to %x...\n", new, offsets[choice]);

            for (int i = 0; i < max_len; i++)
            {
                if (i >= actual_len)
                    new[i] = BLANK_SYMBOL;
                else
                    new[i] = asciiToMario(new[i]);
            }

            // Write custom data to output ROM
            fseek(out_fp, offsets[choice], SEEK_SET);
            fwrite(new, sizeof(__int8), max_len, out_fp);
        }
    }

    fclose(in_fp);
    fclose(out_fp);

    return 0;
}
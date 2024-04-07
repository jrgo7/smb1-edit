#ifndef CONSTS

// CHR Table Conversions
#define BLANK_SYMBOL 36
#define COPYRIGHT_SYMBOL 207
#define DASH_SYMBOL 40
#define X_COUNTER_SYMBOL 41
#define EXCLAMATION_SYMBOL 43
#define PERIOD_SYMBOL 175

// Text memory addresses
// HUD
#define MARIO 0x0765
#define HUD_WORLD 0x076D
#define TIME 0x0774
#define LUIGI 0x07FD
// BLACK SCREEN
#define INTRO_WORLD 0x0796
#define TIME_UP 0x07B3
#define GAME_OVER 0x07C6
// ANOTHER CASTLE
#define THANK_YOU_MARIO 0x0D67
#define THANK_YOU_LUIGI 0x0D81
#define BUT_OUR_PRINCESS_IS_IN 0x0D8F
#define ANOTHER_CASTLE 0x0DA8
// MISC
#define WARP_ZONE 0x07D3
#define COPYRIGHT 0x9FB5
#define ONE_PLAYER_GAME 0x9FC6
#define TWO_PLAYER_GAME 0x9FD6
#define TOP 0x9FE6

enum headers
{
    HUD_ELEMENTS,
    BLACK_SCREEN = 4,
    THANKS = 7,
    MISC = 11
};

typedef char str32[33];
#endif
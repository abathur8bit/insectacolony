// ANSI colors https://en.wikipedia.org/wiki/ANSI_escape_code#Colors
//
// Not in standard, but works on Mac and RPi:
//  90–97	Set foreground text color, high intensity
//  100–107	Set background color, high intensity

#ifndef _UTIL_H
#define _UTIL_H

#define ESCAPE  0x1b
#define S_CLS   "\x1b[2J"
#define S_HOME  "\x1b[H"

#define UP      1
#define DOWN    2
#define RIGHT   3
#define LEFT    4
#define TAB     9

#define BLACK   0
#define RED     1
#define GREEN   2
#define YELLOW  3
#define BLUE    4
#define MAGENTA 5
#define CYAN    6
#define WHITE   7

#define MAX_NAME 20
#define MAX_INSECTS 5

#define DATA_WIDTH      500
#define DATA_HEIGHT     15
#define DATA_SIZE       (DATA_WIDTH*DATA_HEIGHT)

#define BLOCK_PIECE     "     "
#define BLOCK_SIZE      5

#define BLOCK_EMPTY     1   //empty
#define BLOCK_TREE      2   //tree
#define BLOCK_WALL      3   //wall
#define BLOCK_INVISIBLE 4   //invisible and kills player
#define BLOCK_CRUMBLE   5   //desctructable
#define BLOCK_EXIT      6   //open exit
#define BLOCK_CLOSED    7   //exit that is still locked
#define BLOCK_SLOW      8   //slows the player
#define BLOCK_DEATH     9   //Death trap
#define BLOCK_COUNT     9

void home();
void cls();
void gotoxy(int x,int y);       /// x=1 is left edge.
void setColors(int fg,int bg);
void setFGColor(int fg);
void setBGColor(int bg);
void setFGColorBright(int fg);
void setBGColorBright(int bg);
void resetColors();
void loadData(char* fname);
int dataAt(int x,int y);
int dataIndex(int x,int y);
void initData();
int levelWidth();
void showMap(int xoff);
void setData(int x,int y,int ch);
int random(int min,int max);    ///< Returns a number between min and max inclusive.
void randomize(int seed);       ///< Reseed the random generator.
int kbhit();
int waitkey();
int inkey();
void flushout();                ///< Flush the stdout stream
#endif


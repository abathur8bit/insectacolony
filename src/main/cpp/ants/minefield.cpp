#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <ssobjects/stopwatch.h>

#include "util.h"

using namespace ssobjects;

#define NOMINE      0
#define COVERED     '#'
#define HINT        '+'
#define EMPTY       '-'
#define MINE        '*'
#define QUESTION    '?'

#define EASY_NUM_MINES  10

char* minefield = NULL;
char* minelocations = NULL;
int numMines = 0;

int width = 9;
int height = 9;
int fieldx = 35;
int fieldy = 5;
int playerx = 0;
int playery = 0;
StopWatch gameTimer;
bool running = true;
bool alwaysShowMines = false;

int checkLocation(int x, int y)
{
    if(x>=0 && y>=0 && x<width && y<height)
        return minelocations[y*width+x];
    return 0;
}

/**
 * @brief findMines
 *
 *      ???
 *      ?X?
 *      ???
 *
 * @param x center position
 * @param y center position.
 *
 * @return The number of mines found around the specified location.
 */
int countAdjacentMines(int x, int y)
{
    int count=0;
    //?--
    //- -
    //---
    if(checkLocation(x-1,y-1)==MINE)
        ++count;
    //-?-
    //- -
    //---
    if(checkLocation(x,y-1)==MINE)
        ++count;
    //--?
    //- -
    //---
    if(checkLocation(x+1,y-1)==MINE)
        ++count;
    //---
    //? -
    //---
    if(checkLocation(x-1,y)==MINE)
        ++count;
    //---
    //- ?
    //---
    if(checkLocation(x+1,y)==MINE)
        ++count;
    //---
    //- -
    //?--
    if(checkLocation(x-1,y+1)==MINE)
        ++count;
    //---
    //- -
    //-?-
    if(checkLocation(x,y+1)==MINE)
        ++count;
    //---
    //- -
    //--?
    if(checkLocation(x+1,y+1)==MINE)
        ++count;

    return count;
}

void layCounters()
{
    for(int y=0; y<height; ++y)
    {
        for(int x=0; x<width; ++x)
        {
            if(!minelocations[y*width+x])
            {
                int count = countAdjacentMines(x,y);
                if(count)
                    minelocations[y*width+x] = '0'+count;
            }
        }
    }
}

void layMines()
{
    //sprinkle the mines
    printf("laying %d mines\n",numMines);
    for(int i=0; i<numMines; ++i)
    {
        printf("laying mine %d ...",i);
        // pick a place and make sure it isn't already occupied
        int loc=0;
        do
        {
            loc = random(1,width*height-1);
            printf("loc %d contains %d\n",loc,minelocations[loc]);
        } while(minelocations[loc]);
        assert(loc < width*height && loc > 0);
        minelocations[loc] = MINE;
    }
}

/**
 * @brief createMinefield
 *
 * Default mine field:
 *
 * 00 -------- 11---111
 * 08 *-----*- *1--12*1
 * 16 -----*-- 22--1*21
 * 24 *------- *1--111-
 * 32 -------- 11------
 * 40 -------- ---111--
 * 48 ----*--- ---1*111
 * 56 -------* ---1111*
 *
 * @param w
 * @param h
 */
void createMinefield(int w, int h)
{
    if(minefield)
        free(minefield);
    if(minelocations)
        free(minelocations);

    numMines = EASY_NUM_MINES;
    minefield = (char*)calloc(w*h,sizeof(char));
    minelocations = (char*)calloc(w*h,sizeof(char));

    for(int y=0; y<height; ++y)
    {
        for(int x=0; x<width; ++x)
        {
            minefield[y*width+x] = COVERED;
            minelocations[y*width+x] = NOMINE;
        }
    }


    layMines();
    layCounters();
}

void showMineLocations()
{
    gotoxy(1,1);
    resetColors();
    printf("M i n e    F i e l d\n");
    printf("http://8BitCoder.com\n");
    printf("Time: %04lu",gameTimer.seconds());
    setFGColor(BLACK);
    setBGColorBright(CYAN);
    for(int y=0; y<height; ++y)
    {
        gotoxy(fieldx,fieldy+y);
        for(int x=0; x<width; ++x)
        {
            if(minelocations[y*width+x])
                printf("%c",minelocations[y*width+x]);
            else
                printf(" ");
        }
    }
    //TODO draw a shadow

}

//void showMinefield2(bool showMines)
//{
//    cls();
//    printf("M i n e    F i e l d\n");
//    printf("http://8BitCoder.com\n");
//    printf("Time: %04lu\n\n",gameTimer.seconds());
//    for(int y=0; y<height; ++y)
//    {
//        for(int x=0; x<width; ++x)
//        {
//            printf("%c",minefield[y*width+x]);
//        }
//        printf("\n");
//    }
//}

void showMinefield(bool showMines)
{
//    gotoxy(1,1);
    resetColors();
    printf("M i n e    F i e l d\n");
    printf("http://8BitCoder.com\n");
    printf("Time: %04lu\n",gameTimer.seconds());
    setFGColor(BLACK);
    setBGColorBright(CYAN);
    for(int y=0; y<height; ++y)
    {
        //gotoxy(fieldx,fieldy+y);
        for(int x=0; x<width; ++x)
        {
            if(minelocations[y*width+x] && (showMines || alwaysShowMines))
                setFGColorBright(RED);
            else
                setFGColor(BLACK);
            printf("%c",minefield[y*width+x]);
        }
        printf("\n");
    }
    //TODO draw a shadow
}

void showPlayer(bool showMines)
{
    gotoxy(fieldx+playerx,fieldy+playery);
    if(minelocations[playery*width+playerx] && (showMines || alwaysShowMines))
        setFGColorBright(RED);
    else
        setFGColor(BLACK);
    setBGColorBright(YELLOW);
    printf("%c",minefield[playery*width+playerx]);
}

int kbhittest()
{
    char c;
        //setbuf(stdout, NULL); // Optional: No buffering.
        //setbuf(stdin, NULL);  // Optional: No buffering.
        printf("Press key\n");
        while (!kbhit()) {
//            printf(".");
//            fflush(stdout);
//            sleep(1);
        }
        c = inkey();

        printf("\nChar received:%u\n", c);
        printf("Done.\n");

        return 0;
}

/**
 * @brief floodExpose Flips all empty squares that connect to tile at x,y, up to and including
 * any tiles that have a number under them.
 *
 * @return  The number of additional tiles exposed.
 */
int floodExpose(int startx,int starty,int dirx,int diry)
{
    int count = 0;

    return count;
}

/**
 * @brief Flips the current square over, and starts the game timer if not already running.
 *
 * If the piece flipped was an EMPTY square, then all other empty squares will be opened.
 * When opened, it will open any connecting empty squares, up to a number.
 *
 * If the piece has a number, then only that piece is flipped.
 *
 * If the piece has a bomb, the players game is over.
 *
 * @return Returns 1 if the player was safe, 0 otherwise.
 */
int flipPiece()
{
    int safe = 1;
    const int index = playery*width+playerx;
    if(minelocations[index] == MINE)
    {
        safe = 0;
        gameTimer.stop();
        running = false;
        minefield[index] = MINE;
        showMinefield(true);
        showPlayer(true);
        flushout();
        waitkey();
    }
    else
    {
        if(!gameTimer.isRunning())
            gameTimer.start();

        int c = minelocations[index];
        if(c)
            minefield[index] = c;
        else
        {
            minefield[index] = EMPTY;
            floodExpose(playerx,playery,0,0);
        }
    }
    return safe;
}

int processInput()
{
    int ch = inkey();
    if('s' == ch)
    {
        alwaysShowMines = !alwaysShowMines;
//        for(int i=0; i<width*height; ++i)
//        {
//            minefield[i] = minelocations[i];
//        }
    }
    else if('q' == ch)
    {
        running = false;
    }
    else if(LEFT == ch && playerx-1 >= 0)
    {
        --playerx;
    }
    else if(RIGHT == ch && playerx+1 < width)
    {
        ++playerx;
    }
    else if(UP == ch && playery-1 >= 0)
    {
        --playery;
    }
    else if(DOWN == ch && playery+1 < height)
    {
        ++playery;
    }
    else if(' ' == ch)
    {
        flipPiece();
    }
    else if(TAB == ch)
    {
//        TODO tab key
    }
    return ch;
}

int main(int argc,char* argv[])
{
//    kbhittest();
//    exit(0);

    //check if user is passing in the seed
    int seed = 1;
    if(argc > 1)
        seed = atoi(argv[1]);

    randomize(seed);    // reseed the random generator
//    cls();
    createMinefield(width,height);
    StopWatch timer;
    timer.start();

    showMinefield(false);
    showPlayer(false);
    flushout();
    do
    {
//        if(timer.milliseconds() > 100 || processInput())
        while(!processInput())
        {
            //do nothing
        }
        {
            timer.reset();
            timer.start();
            if(alwaysShowMines)
                showMineLocations();
            else
            {
                showMinefield(false);
                showPlayer(false);
            }
            resetColors();
        }
        gotoxy(1,20);

    } while(running);
    //cls();
    printf("\nDone\n");
    printf("timer: %lu seconds %lu ms\n",timer.seconds(),timer.milliseconds());
}


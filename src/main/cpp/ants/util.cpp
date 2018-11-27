#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <stdbool.h>
#include <unistd.h>

#include "util.h"

int data[DATA_SIZE];
int screenWidth;
int screenHeight;
int xoffset;    //scrolled position
int cursorx;    //position of the editing corsor
int cursory;
char statusMessage[100];
int keysRequired;
int maxTime;
int currentBlock;

void home()
{
    printf("%s",S_HOME);
}

void cls()
{
    printf("%s%s",S_CLS,S_HOME);
}

void gotoxy(int x, int y)
{
    printf("\x1b[%d;%dH",y,x);
}

void setColors(int fg, int bg)
{
    printf("\x1b[3%d;4%dm",fg,bg);
}

void setFGColor(int fg)
{
    printf("\x1b[3%dm",fg);
}

void setBGColor(int bg)
{
    printf("\x1b[4%dm",bg);
}

void setFGColorBright(int fg)
{
    printf("\x1b[9%dm",fg);
}

void setBGColorBright(int bg)
{
    printf("\x1b[10%dm",bg);
}

void resetColors()
{
    printf("\x1b[0m");
}

void loadData(char* fname)
{
    char filename[255];
    sprintf(filename,"%s.block",fname);
    FILE* fp = fopen(filename,"r");
//    int ch;
//    int i=0;
    //int x,y;
    if(!fp)
    {
        return;
    }

    memset(data,0,DATA_SIZE);
    fread(data,sizeof(int),DATA_SIZE,fp);
    fread(&xoffset,sizeof(int),1,fp);
    fread(&cursorx,sizeof(int),1,fp);
    fread(&cursory,sizeof(int),1,fp);
    fread(&currentBlock,sizeof(int),1,fp);
    fread(&keysRequired,sizeof(int),1,fp);
    fread(&maxTime,sizeof(int),1,fp);
    fclose(fp);
}

int dataAt(int x,int y)
{
    return data[y*DATA_WIDTH+x];
}

int dataIndex(int x,int y)
{
    return y*DATA_WIDTH+x;
}

void initData()
{
    for(int i=0; i<(int)(sizeof(data)/sizeof(data[0])); i++)
    {
        data[i] = BLOCK_EMPTY;
    }
}

int levelWidth()
{
    int maxWidth = 0;
    int x,y;
    for(y=0; y<DATA_HEIGHT; y++)
    {
        for(x=0; x<DATA_WIDTH; x++)
        {
            if(BLOCK_EMPTY != data[y*DATA_WIDTH+x] && x > maxWidth)
                maxWidth = x;
        }
    }
    return maxWidth+1;
}

void setData(int x,int y,int ch)
{
    int index = dataIndex(x,y);
    data[index] = ch;
}

void showMap(int xoff)
{
    
    int width = screenWidth;
    int x,y;
    int dataIndex;
    char dataMap[] = "0 .#456789";
    cls();
    for(y=0; y<DATA_HEIGHT; y++)
    {
        for(x=0; x<width; x++)
        {
            dataIndex = y*DATA_WIDTH+(xoff+x);
            int ch = dataAt(x,y);

            printf("%c",dataMap[ch]);
            printf("%c",dataMap[ch]);
        }
        printf("\n");
    }
}


//v1 = rand() % 100;         // v1 in the range 0 to 99
//v2 = rand() % 100 + 1;     // v2 in the range 1 to 100
//v3 = rand() % 30 + 1985;   // v3 in the range 1985-2014
int random(int min, int max)
{
    return rand()%(max+1-min)+min;
}

void randomize(int seed)
{
    if(0==seed)
        srand(time(NULL));
    else
        srand(seed);
}

int kbhit(void) {
    static bool initflag = false;
    static const int STDIN = 0;

    if (!initflag) {
        // Use termios to turn off line buffering
        struct termios term;
        tcgetattr(STDIN, &term);
        term.c_lflag &= ~ICANON;
        tcsetattr(STDIN, TCSANOW, &term);
        setbuf(stdin, NULL);
        initflag = true;
    }

    int nbbytes;
    ioctl(STDIN, FIONREAD, &nbbytes);  // 0 is STDIN
    return nbbytes;
}

int waitkey()
{
    int c=0;
    do
    {
        c = kbhit();
    }
    while(!c);
    return c;
}
int inkey()
{
    if(!kbhit())
        return 0;

    int c = getchar();
    if(27 == c && kbhit() && getchar() == '[')
    {
        c = getchar() & 7;  // read the actual data
    }
    return c;
}

void flushout()
{
    fflush(stdout);
}

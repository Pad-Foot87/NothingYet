#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "GOTOXY.h"
#include "SetColor.h"


void AniMenu()
{
    int i,RanDomX,RanDomY,RanDomColor,RanDomChar;
    for (i=0; i<100; i++)
    {
        SetColor(RanDomColor);

        gotoxy(50,12);
        printf("                    ");

        gotoxy(50,13);
        printf("    Welcome To...    ");

        gotoxy(50,14);
        printf("    << SPOTiFAy >>    ");

        gotoxy(50,15);
        printf("                    ");

        RanDomColor=1+rand() % 255;

        SetColor(RanDomColor);

        RanDomX=1+rand() % (118);
        RanDomY=1+rand() % (30);
        gotoxy(RanDomX,RanDomY);

        RanDomChar=50+rand() % (100);
        printf("%c",RanDomChar);

        //Sleep(100);
    }
    SetColor(255);
    gotoxy(45,31);
    system("pause");
    gotoxy(1,1);
}

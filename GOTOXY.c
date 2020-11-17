#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "GOTOXY.h"

void gotoxy(int x , int y)
{
    HANDLE ventana;
    ventana = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coordenadas;
    coordenadas.X = x;
    coordenadas.Y = y;
    SetConsoleCursorPosition(ventana,coordenadas);
}

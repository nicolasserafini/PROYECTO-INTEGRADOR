#include<iostream>
using namespace std;
#include "Utilidades.h"

void Utilidades::limpiarPantalla()
{
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

#include<iostream>
#include "ArchivoTipoProducto.h"
using namespace std;

bool ArchivoTipoProducto::guardar(TipoProducto reg)
{
    FILE* p = fopen(_nombre, "ab");

    if(p == NULL)
    {
        cout<<"Error de archivo"<<endl;
        return false;
    }

    bool ok = fwrite(&reg, sizeof(TipoProducto), 1, p);
    fclose(p);
    return ok;
}

TipoProducto ArchivoTipoProducto::leer(int pos)
{
    TipoProducto reg;

    FILE* p = fopen(_nombre, "rb");
    if (p == NULL)
    {
        cout << "Error de archivo" << endl;
        return reg;  //devuelve el registro pero vacio
    }

    fseek(p, pos * sizeof(TipoProducto), SEEK_SET);
    fread(&reg, sizeof(TipoProducto), 1, p);
    fclose(p);

    return reg;
}

int ArchivoTipoProducto::cantidadRegistros()
{
    FILE* p = fopen(_nombre, "rb");
    if (p == NULL)
    {
        cout << "Error de archivo" << endl;
        return 0;
    }

    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);

    return bytes / sizeof(TipoProducto);
}

bool ArchivoTipoProducto::sobrescribir(TipoProducto reg, int pos)
{
    FILE* p = fopen(_nombre, "rb+");
    if (p == NULL)
    {
        cout << "Error de archivo" << endl;
        return false;
    }

    fseek(p, pos * sizeof(TipoProducto), SEEK_SET);
    bool ok = fwrite(&reg, sizeof(TipoProducto), 1, p);
    fclose(p);

    return ok;
}


#include<iostream>
#include "ArchivoCliente.h"
using namespace std;

bool ArchivoCliente::guardar(Cliente reg)
{
    FILE* p = fopen(_nombre, "ab");

    if(p==NULL)
    {
        cout<<"Error de archivo"<<endl;
        return false;
    }

    bool ok = fwrite(&reg, sizeof(Cliente), 1, p);

    fclose(p);

    return ok;
}

Cliente ArchivoCliente::leer(int pos)
{
    Cliente reg;

    FILE* p = fopen(_nombre, "rb");

    if(p==NULL)
    {
        cout<<"Error de archivo"<<endl;
        return reg; //devuelve el registro vacio
    }

    fseek(p, pos * sizeof(Cliente), SEEK_SET);
    fread(&reg, sizeof(Cliente), 1, p);

    fclose(p);

    return reg;
}

int ArchivoCliente::cantidadRegistros()
{

    FILE* p = fopen(_nombre, "rb");

    if(p==NULL)
    {
        cout<<"Error de archivo"<<endl;
        return 0;
    }

    fseek(p, 0, SEEK_END);

    int bytes = ftell(p);

    fclose(p);
    return bytes / sizeof(Cliente);
}

bool ArchivoCliente::sobrescribir(Cliente reg, int pos)
{
    FILE* p = fopen(_nombre, "rb+");

    if(p==NULL)
    {
        cout<<"Error de archivo"<<endl;
        return false;
    }

    fseek(p, pos * sizeof(Cliente), SEEK_SET);
    bool ok = fwrite(&reg, sizeof(Cliente), 1, p);
    fclose(p);
    return ok;
}

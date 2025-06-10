#include<iostream>
#include "ArchivoCliente.h"
using namespace std;

bool ArchivoCliente::guardar(Cliente reg)
{
    FILE* p = fopen(_nombre, "ab");

    if(p==NULL)
    {
        cout<<"Error de archivo"<<endl;
        exit(1);
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
        exit(1);
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
        exit(1);
    }

    fseek(p, 0, SEEK_END);

    int bytes = ftell(p);

    fclose(p);
    return bytes / sizeof(Cliente);
}

#include<iostream>
#include "TipoCliente.h"
using namespace std;

int TipoCliente::getTipo()
{
    return _tipo;
}

void TipoCliente::setTipo(int t)
{
    if(t == 1 || t==2)
    {
        _tipo = t;
    }
    else
    {
        _tipo = 1; //si el usuario ingresa un valor invalido entonces es 1 por defecto
    }
}

const char* TipoCliente::getDescripcion() {
    return (_tipo == 1) ? "Particular" : "Empresa";
}

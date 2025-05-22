#ifndef CLIENTE_H
#define CLIENTE_H
#pragma once
#include "TipoCliente.h"

class Cliente
{
    private:
        int _cuit;
        char _nombre[20];
        char _apellido[20];
        char _telefono[20];
        char _email[60];
        char _direccion[100];
        TipoCliente _tipoCliente;

    public:


};

#endif // CLIENTE_H

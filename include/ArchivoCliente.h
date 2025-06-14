#ifndef ARCHIVOCLIENTE_H
#define ARCHIVOCLIENTE_H
#include "Cliente.h"
#pragma once

class ArchivoCliente
{
    private:
        const char* _nombre = "clientes.dat";

    public:
        bool guardar(Cliente reg);
        Cliente leer(int pos);
        int cantidadRegistros();
        bool sobrescribir(Cliente reg, int pos);
};

#endif // ARCHIVOCLIENTE_H

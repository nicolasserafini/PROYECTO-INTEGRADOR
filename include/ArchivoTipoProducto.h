#ifndef ARCHIVOTIPOPRODUCTO_H
#define ARCHIVOTIPOPRODUCTO_H
#pragma once
#include "TipoProducto.h"

class ArchivoTipoProducto
{
private:
    const char* _nombre;

public:
    ArchivoTipoProducto(const char* nombre = "tiposProductos.dat")
    {
        _nombre = nombre;
    }

    bool guardar(TipoProducto);
    TipoProducto leer(int pos);
    int cantidadRegistros();
    bool sobrescribir(TipoProducto, int pos);
};

#endif // ARCHIVOTIPOPRODUCTO_H

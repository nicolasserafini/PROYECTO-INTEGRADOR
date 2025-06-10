#ifndef VENTA_H
#define VENTA_H
#pragma once
#include "Fecha.h"

class Venta
{
    private:
        int _numeroVenta;
        int _idProducto;
        int _cuitCliente;
        int _cantVendida;
        float _importeVenta;
        Fecha fechaVenta;

    public:
        Venta();


};

#endif // VENTA_H
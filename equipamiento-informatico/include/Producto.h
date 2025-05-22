#ifndef PRODUCTO_H
#define PRODUCTO_H
#pragma once

class Producto
{
    private:
        int _idProducto;
        char _descripcion[100];
        char _marca[30];
        char _tipoProducto[30];
        int _stock;
        float _importe;

    public:
        Producto();

    protected:

};

#endif // PRODUCTO_H

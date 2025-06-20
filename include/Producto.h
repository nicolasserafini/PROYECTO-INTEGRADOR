#ifndef PRODUCTO_H
#define PRODUCTO_H
#pragma once
#include "TipoProducto.h"

class Producto
{
    private:
        int _idProducto;
        char _descripcion[100];
        char _marca[30];
        TipoProducto _tipoProducto;
        int _stock;
        float _importe;

    public:
        int getIdProducto();
        void setIdProducto(int);

        const char* getDescripcion();
        void setDescripcion(const char*);

        const char* getMarca();
        void setMarca(const char*);

        TipoProducto getTipoProducto();
        void setTipoProducto(TipoProducto);

        int getStock();
        void setStock(int);

        float getImporte();
        void setImporte(float);

        void cargarProducto();
};

#endif // PRODUCTO_H

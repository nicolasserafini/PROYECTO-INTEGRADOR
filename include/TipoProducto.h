#ifndef TIPOPRODUCTO_H
#define TIPOPRODUCTO_H
#pragma once

class TipoProducto
{
    private:
        int _idTipo;
        char _descripcion[50];
        bool _activo;

    public:
        int getIdTipo();
        void setIdTipo(int);

        const char* getDescripcion();
        void setDescripcion(const char*);

        bool getActivo();
        void setActivo(bool);

        void cargar();
        void mostrar();
        void listarProductos();
};

#endif // TIPOPRODUCTO_H

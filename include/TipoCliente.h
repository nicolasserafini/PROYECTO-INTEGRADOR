#ifndef TIPOCLIENTE_H
#define TIPOCLIENTE_H
#pragma once

class TipoCliente
{
    private:
        int _tipo;

    public:
        int getTipo();
        void setTipo(int);

        const char* getDescripcion();

};

#endif // TIPOCLIENTE_H

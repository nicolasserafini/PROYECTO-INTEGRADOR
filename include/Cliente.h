#ifndef CLIENTE_H
#define CLIENTE_H
#pragma once
#include "TipoCliente.h"

class Cliente
{
    private:
        char _cuit[20];
        char _nombre[20];
        char _apellido[20];
        char _telefono[20];
        char _email[60];
        char _direccion[100];
        TipoCliente _tipoCliente;
        bool _activo = true;

    public:
        const char* getCuit();
        void setCuit(const char*);

        const char* getNombre();
        void setNombre(const char*);

        const char* getApellido();
        void setApellido(const char*);

        const char* getTelefono();
        void setTelefono(const char*);

        const char* getEmail();
        void setEmail(const char*);

        const char* getDireccion();
        void setDireccion(const char*);

        TipoCliente getTipoCliente();
        void setTipoCliente(TipoCliente);

        bool getActivo();
        void setActivo(bool);

        void cargarCliente();
        void listarClientes();
        void mostrarCliente();
        void buscarCliente(const char*);
        void borrarCliente(const char*);
};

#endif // CLIENTE_H

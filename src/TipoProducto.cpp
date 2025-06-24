#include<iostream>
#include <cstring>
#include "TipoProducto.h"
#include "ArchivoTipoProducto.h"
#include "Utilidades.h"
using namespace std;

//Getters y setters
int TipoProducto::getIdTipo()
{
    return _idTipo;
}
void TipoProducto::setIdTipo(int id)
{
    _idTipo = id;
}

const char* TipoProducto::getDescripcion()
{
    return _descripcion;
}
void TipoProducto::setDescripcion(const char* d)
{
    strncpy(_descripcion, d, sizeof(_descripcion));
}

bool TipoProducto::getActivo()
{
    return _activo;
}
void TipoProducto::setActivo(bool a)
{
    _activo = a;
}


//Funciones
void TipoProducto::cargar()
{
    char desc[50];
    ArchivoTipoProducto arch;
    Utilidades ut;

    cout << "Descripcion del tipo de producto: ";
    cin.ignore();
    cin.getline(desc, sizeof(desc));

    setDescripcion(desc);
    setActivo(true);

    int id = arch.cantidadRegistros() + 1;
    setIdTipo(id);

    if (arch.guardar(*this))
    {
        ut.limpiarPantalla();
        cout << "Tipo de producto guardado con éxito. ID asignado: " << id << endl;
    }
    else
    {
        ut.limpiarPantalla();
        cout << "Error al guardar el tipo de producto." << endl;
    }

    cout << endl;
    system("pause");
}

void TipoProducto::mostrar()
{
    cout << "ID: " << _idTipo << endl;
    cout << "Descripcion: " << _descripcion << endl;
}

void TipoProducto::listarTipoProducto()
{
    ArchivoTipoProducto arch;
    int cant = arch.cantidadRegistros();

    cout << "======= TIPOS DE PRODUCTO =======" << endl << endl;

    for (int i = 0; i < cant; i++)
    {
        TipoProducto tp = arch.leer(i);
        if (tp.getActivo())
        {
            tp.mostrar();
            cout << "-----------------------------" << endl;
        }
    }

    cout << endl;
    system("pause");
}

bool TipoProducto::buscarTipoProducto(int idBuscado, TipoProducto &tipoEncontrado, int &posEncontrado)
{
    ArchivoTipoProducto arch;
    int cant = arch.cantidadRegistros();

    for (int i = 0; i < cant; i++)
    {
        TipoProducto t = arch.leer(i);
        if (t.getActivo() && t.getIdTipo() == idBuscado)
        {
            tipoEncontrado = t;
            posEncontrado = i;
            return true;
        }
    }

    return false;
}

void TipoProducto::editarTipoProducto()
{
    char nuevaDesc[50];

    ArchivoTipoProducto arch;

    cout << "Nueva descripcion: ";
    cin.ignore();
    cin.getline(nuevaDesc, sizeof(nuevaDesc));
    cout << endl;
    setDescripcion(nuevaDesc);

    cout << "======================================" << endl << endl;
    cout << "Tipo de producto actualizado:" << endl << endl;

    mostrar();

    system("pause");
}

void TipoProducto::borrarTipoProducto(int pos)
{
    ArchivoTipoProducto arch;

    setActivo(false);

    if (arch.sobrescribir(*this, pos))
    {
        cout << "Tipo de producto eliminado correctamente" << endl << endl;
    }
    else
    {
        cout << "Error al eliminar el tipo de producto" << endl << endl;
    }
}

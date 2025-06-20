#include<iostream>
#include <cstring>
#include "Producto.h"
#include "Utilidades.h"
using namespace std;

//Getters y Setters
int Producto::getIdProducto()
{
    return _idProducto;
}
void Producto::setIdProducto(int id)
{
    _idProducto = id;
}

const char* Producto::getDescripcion()
{
    return _descripcion;
}
void Producto::setDescripcion(const char* d)
{
    strncpy(_descripcion, d, sizeof(_descripcion));
}

const char* Producto::getMarca()
{
    return _marca;
}
void Producto::setMarca(const char* m)
{
    strncpy(_marca, m, sizeof(_marca));
}

TipoProducto Producto::getTipoProducto()
{
    return _tipoProducto;
}
void Producto::setTipoProducto(TipoProducto t)
{
    _tipoProducto = t;
}

int Producto::getStock()
{
    return _stock;
}
void Producto::setStock(int s)
{
    _stock = s;
}

float Producto::getImporte()
{
    return _importe;
}
void Producto::setImporte(float importe)
{
    _importe = importe;
}


//Funciones
/**
void Producto::cargarProducto()
{
    int id, stock = 0, tipo = 0;
    char desc[100], marca[30];
    float importe = 0;
    Utilidades ut;


    cout << "======= CARGA DE PRODCUTO =======" << endl;
    cout<<"Ingrese descripcion del producto: ";
    cin.ignore();
    cin.getline(desc, sizeof(desc));
    cout<<"Ingrese marca: ";
    cin.ignore();
    cin.getline(marca, sizeof(marca));
    cout<<"Ingrese stock: ";
    cin>>stock;
    cout<<"Ingrese importe: ";
    cin>>importe;

    ut.limpiarPantalla();

    cout << "======= TIPOS DISPONIBLES =======" << endl;
    cout<<"Ingrese tipo de producto: ";
    cin>>tipo;
}
 */

#include<iostream>
#include <cstring>
#include "Cliente.h"
#include "TipoCliente.h"
#include "ArchivoCliente.h"
using namespace std;

//Getters y Setters
const char* Cliente::getCuit()
{
    return _cuit;
}
void Cliente::setCuit(const char* c)
{
    strncpy(_cuit, c, sizeof(_cuit));
}

const char* Cliente::getNombre()
{
    return _nombre;
}
void Cliente::setNombre(const char* n)
{
    strncpy(_nombre, n, sizeof(_nombre));
}

const char* Cliente::getApellido()
{
    return _apellido;
}
void Cliente::setApellido(const char* a)
{
    strncpy(_apellido, a, sizeof(_apellido));
}

const char* Cliente::getTelefono()
{
    return _telefono;
}
void Cliente::setTelefono(const char* t)
{
    strncpy(_telefono, t, sizeof(_telefono));
}

const char* Cliente::getEmail()
{
    return _email;
}
void Cliente::setEmail(const char* e)
{
    strncpy(_email, e, sizeof(_email));
}

const char* Cliente::getDireccion()
{
    return _direccion;
}
void Cliente::setDireccion(const char* d)
{
    strncpy(_direccion, d, sizeof(_direccion));
}

TipoCliente Cliente::getTipoCliente()
{
    return _tipoCliente;
}

void Cliente::setTipoCliente(TipoCliente t)
{
    _tipoCliente = t;
}

bool Cliente::getActivo()
{
    return _activo;
}

void Cliente::setActivo(bool activo)
{
    _activo = activo;
}


//Funciones
void Cliente::cargarCliente()
{
    char c[20], n[20], a[20], t[20], e[60], d[100];
    int tipo;

    cout << "======= CARGA DE CLIENTES =======" << endl;
    cout<<"Ingrese el numero de cuit: ";
    cin>>c;
    cout<<"Ingrese nombre de cliente: ";
    cin>>n;
    cout<<"Ingrese apellido de cliente: ";
    cin>>a;
    cout<<"Ingrese telefono de cliente: ";
    cin>>t;
    cout<<"Ingrese email de cliente: ";
    cin>>e;
    cout<<"Ingrese direccion de cliente: ";
    cin.ignore();
    cin.getline(d, sizeof(d));
    cout<<"Ingrese tipo de cliente (1 o 2): ";
    cin>>tipo;


    // Crea objeto nuevo tipoC y lo setea segun ingreso de usuario
    TipoCliente tipoC;
    tipoC.setTipo(tipo);


    setCuit(c);
    setNombre(n);
    setApellido(a);
    setTelefono(t);
    setEmail(e);
    setDireccion(d);
    setTipoCliente(tipoC);//recibe el objeto para guardarlo en la variable
}

void Cliente::listarClientes()
{
    int cant;
    ArchivoCliente arch;

    cant = arch.cantidadRegistros();

    for (int i = 0; i < cant; i++)
    {
        Cliente c = arch.leer(i);

        if(c.getActivo())
        {
            c.mostrarCliente();
            cout << "-----------------------------" << endl << endl;
        }
    }

    system("pause");
}

void Cliente::mostrarCliente()
{
    cout << "CUIT: " << _cuit << endl;
    cout << "Nombre: " << _nombre << endl;
    cout << "Apellido: " << _apellido << endl;
    cout << "Telefono: " << _telefono << endl;
    cout << "Email: " << _email << endl;
    cout << "Direccion: " << _direccion << endl;
    cout << "Tipo de cliente: " << _tipoCliente.getDescripcion() << endl;
}

bool Cliente::buscarCliente(const char* cuit, Cliente &clienteEncontrado, int &posEncontrado)
{
    ArchivoCliente arch;
    int cant = arch.cantidadRegistros();

    for(int i=0; i < cant; i++)
    {
        Cliente c = arch.leer(i);

        if(c.getActivo() && strcmp(c.getCuit(), cuit) == 0) //compara el contenido de ambas cadenas
        {
            clienteEncontrado = c;
            posEncontrado = i;
            return true;
        }
    }

    return false;
}

void Cliente::editarCliente(int opcion)
{
    char nuevoValor[100];
    int nuevoTipo;
    ArchivoCliente arch;

    switch(opcion)
    {
    case 1:
        cout << "Nuevo CUIT: ";
        cin >> nuevoValor;
        cout << endl;
        setCuit(nuevoValor);
        break;
    case 2:
        cout << "Nuevo nombre: ";
        cin >> nuevoValor;
        cout << endl;
        setNombre(nuevoValor);
        break;
    case 3:
        cout << "Nuevo apellido: ";
        cin >> nuevoValor;
        cout << endl;
        setApellido(nuevoValor);
        break;
    case 4:
        cout << "Nuevo telefono: ";
        cin >> nuevoValor;
        cout << endl;
        setTelefono(nuevoValor);
        break;
    case 5:
        cout << "Nuevo mail: ";
        cin >> nuevoValor;
        cout << endl;
        setEmail(nuevoValor);
        break;
    case 6:
        cin.ignore();
        cout << "Nueva direccion: ";
        cin.getline(nuevoValor, sizeof(nuevoValor));
        cout << endl;
        setDireccion(nuevoValor);
        break;
    case 7:
        cout << "Nuevo tipo de cliente (1 o 2): ";
        cin >> nuevoTipo;
        TipoCliente tc;
        cout << endl;
        tc.setTipo(nuevoTipo);
        setTipoCliente(tc);
        break;
    default:
        cout << "Opcion invalida." << endl;
        return;
    }

    cout << "======================================" << endl << endl;
    cout << "Cliente actualizado:" << endl << endl;

    mostrarCliente();

    system("pause");
}

void Cliente::borrarCliente(const char* cuit)
{
    ArchivoCliente arch;
    int cant = arch.cantidadRegistros();
    bool encontrado = false;

    for(int i=0; i < cant; i++)
    {
        Cliente c = arch.leer(i);

        if(c.getActivo() && strcmp(c.getCuit(), cuit) == 0) //compara el contenido de ambas cadenas
        {
            c.setActivo(false);
            arch.sobrescribir(c, i);

            cout << "Cliente eliminado correctamente" << endl << endl;

            encontrado = true;
            break;
        }
    }

    if (!encontrado)
    {
        cout << "No se encontro ningun cliente con el CUIT ingresado." << endl;
    }

    cout << endl;
    system("pause");
}

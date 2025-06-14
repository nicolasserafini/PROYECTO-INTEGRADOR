#include<iostream>
#include "Menu.h"
#include "Cliente.h"
#include "ArchivoCliente.h"
using namespace std;

void limpiarPantalla()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}


void Menu::menuPrincipal()
{
    int opcion;

    do
    {
        limpiarPantalla();
        cout << "======= MENU PRINCIPAL =======" << endl;
        cout << "1. Clientes" << endl;
        cout << "2. Equipos / Productos" << endl;
        cout << "3. Ventas" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cout << endl;

        switch(opcion)
        {
        case 1:
            menuClientes();
            break;
        case 2:
            // mostrarMenuProductos();
            break;
        case 3:
            // mostrarMenuVentas();
            break;
        case 0:
            cout << "Saliendo del programa..." << endl;
            break;
        default:
            cout << "Opcion invalida. Intente de nuevo." << endl << endl;
            system("pause");
            cout<<endl;
        }
    }
    while(opcion != 0);
}

void Menu::menuClientes()
{
    int opcion;

    do
    {
        limpiarPantalla();
        cout << "======= MENU CLIENTES =======" << endl;
        cout << "1. Cargar cliente" << endl;
        cout << "2. Ver clientes" << endl;
        cout << "3. Buscar cliente" << endl;
        cout << "4. Editar cliente" << endl;
        cout << "5. Eliminar cliente" << endl;
        cout << "0. Ir atras" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cout << endl;

        switch(opcion)
        {
        case 1:
            {
                Cliente c;
                c.cargarCliente();

                ArchivoCliente arch;
                if(arch.guardar(c)) //guarda datos del cliente
                {
                    cout << "Cliente guardado con exito" << endl << endl;
                }
                else
                {
                    cout << "Error al guardar el cliente" << endl << endl;
                }
                system("pause");
                break;
            }
        case 2:
            {
                Cliente c;
                c.listarClientes();
                break;
            }
        case 3:
            menuClientesBuscar();
            break;
        case 4:

            break;
        case 5:
            menuClientesBorrar();
            break;
        case 0:
            break;
        default:
            cout << "Opcion invalida. Intente de nuevo." << endl << endl;
            system("pause");
            cout<<endl;
        }
    }
    while(opcion != 0);
}

void Menu::menuClientesBuscar()
{
    char cuit[20];

    limpiarPantalla();

    cout << "======= MENU BUSQUEDA DE CLIENTE =======" << endl;
    cout << "Ingrese el CUIL del cliente a buscar: ";
    cin >> cuit;
    cout << endl;

    limpiarPantalla();

    Cliente c;
    c.buscarCliente(cuit);
}

void Menu::menuClientesBorrar()
{
    char cuit[20];

    limpiarPantalla();

    cout << "======= MENU ELIMINACION DE CLIENTE =======" << endl;
    cout << "Ingrese el CUIL del cliente a eliminar: ";
    cin >> cuit;
    cout << endl;

    limpiarPantalla();

    Cliente c;
    c.borrarCliente(cuit);
}

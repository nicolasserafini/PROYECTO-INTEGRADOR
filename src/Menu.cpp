#include<iostream>
#include "Menu.h"
#include "Cliente.h"
#include "ArchivoCliente.h"
#include "Utilidades.h"
#include "TipoProducto.h"
#include "ArchivoTipoProducto.h"
using namespace std;

void Menu::menuPrincipal()
{
    int opcion;
    Utilidades ut;

    do
    {
        ut.limpiarPantalla();

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
            menuProductos();
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
    Utilidades ut;

    do
    {
        ut.limpiarPantalla();
        cout << "======= MENU CLIENTES =======" << endl;
        cout << "1. Cargar cliente" << endl;
        cout << "2. Ver clientes" << endl;
        cout << "3. Buscar cliente" << endl;
        cout << "4. Editar cliente" << endl;
        cout << "5. Eliminar cliente" << endl;
        cout << "0. Volver" << endl;
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
            ut.limpiarPantalla();
            menuClientesBuscar();
            break;
        case 4:
            ut.limpiarPantalla();
            menuClientesEditar();
            break;
        case 5:
            ut.limpiarPantalla();
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
    bool res;
    int pos;

    Utilidades ut;

    cout << "======= MENU BUSQUEDA DE CLIENTE =======" << endl;
    cout << "Ingrese el CUIL del cliente a buscar: ";
    cin >> cuit;
    cout << endl;

    ut.limpiarPantalla();

    Cliente c, encontrado;
    res = c.buscarCliente(cuit, encontrado, pos);

    if(res)
    {
        cout << "======= ¡Cliente encontrado! =======" << endl << endl;
        encontrado.mostrarCliente();
    }
    else
    {
        cout << "No se encontro ningun cliente con el CUIT ingresado." << endl;
    }

    system("pause");
}

void Menu::menuClientesBorrar()
{
    char cuit[20];

    Utilidades ut;

    cout << "======= MENU ELIMINACION DE CLIENTE =======" << endl;
    cout << "Ingrese el CUIL del cliente a eliminar: ";
    cin >> cuit;
    cout << endl;

    ut.limpiarPantalla();

    Cliente c;
    c.borrarCliente(cuit);
}

void Menu::menuClientesEditar()
{
    char cuit[20];
    int opcion, pos;
    bool res;

    cout << "======= EDICION DE CLIENTE =======" << endl;
    cout << "Ingrese el CUIL del cliente a editar: ";
    cin >> cuit;
    cout << endl;

    Cliente c, encontrado;
    res = c.buscarCliente(cuit, encontrado, pos);

    if(res)
    {
        cout << "======= ¡Cliente encontrado! =======" << endl << endl;

        cout << "¿Que quiere editar?" << endl;

        cout << "1. CUIL" << endl;
        cout << "2. Nombre" << endl;
        cout << "3. Apellido" << endl;
        cout << "4. Telefono" << endl;
        cout << "5. Mail" << endl;
        cout << "6. Direccion" << endl;
        cout << "7. Tipo de cliente" << endl;

        cout<< "Elija una opcion: ";
        cin >> opcion;


        encontrado.editarCliente(opcion);

        ArchivoCliente arch;
        arch.sobrescribir(encontrado, pos);
    }
    else
    {
        cout << "No se encontro ningun cliente con el CUIT ingresado." << endl;
    }

}

void Menu::menuProductos()
{
    int opcion;
    Utilidades ut;

    do
    {
        ut.limpiarPantalla();
        cout << "======= MENU PRODUCTOS =======" << endl;
        cout << "1. Cargar producto" << endl;
        cout << "2. Listar productos" << endl;
        cout << "3. Buscar producto" << endl;
        cout << "4. Editar producto" << endl;
        cout << "5. Eliminar producto" << endl;
        cout << "6. Tipo de productos" << endl;
        cout << "0. Volver" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cout << endl;

        switch(opcion)
        {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            ut.limpiarPantalla();
            menuTipoProductos();
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

void Menu::menuTipoProductos()
{
    int opcion;
    Utilidades ut;

    do
    {
        ut.limpiarPantalla();
        cout << "======= TIPO DE PRODUCTOS =======" << endl;
        cout << "1. Agregar tipo de producto" << endl;
        cout << "2. Listar tipos de producto" << endl;
        cout << "3. Editar tipo de producto" << endl;
        cout << "4. Eliminar tipo de producto" << endl;
        cout << "0. Volver" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cout << endl;

        switch(opcion)
        {
        case 1:
            {
                ut.limpiarPantalla();
                TipoProducto tp;
                tp.cargar();
                break;
            }
        case 2:
            {
                ut.limpiarPantalla();

                TipoProducto tp;
                tp.listarTipoProducto();
                break;
            }
        case 3:
            {
                ut.limpiarPantalla();

                menuTipoPrEditar();
                break;
            }
        case 4:
            ut.limpiarPantalla();

            menuTipoPrBorrar();
            break;
        case 0:
            break;
        default:
            cout << "Opcion invalida." << endl;
            system("pause");
        }
    }
    while(opcion != 0);
}

void Menu::menuTipoPrEditar()
{
    int id, pos, opcion;

    cout << "======= EDICION DE TIPO DE PRODUCTO =======" << endl;
    cout << "Ingrese el ID del tipo de producto a editar: ";
    cin >> id;
    cout << endl;

    TipoProducto encontrado;
    TipoProducto tp;

    if (tp.buscarTipoProducto(id, encontrado, pos))
    {
        cout << "Tipo encontrado:" << endl << endl;
        cout << "-----------------------------" << endl;
        encontrado.mostrar();
        cout << "-----------------------------" << endl << endl;
    }
    else
    {
        cout << "No se encontró el tipo con ese ID." << endl;
        system("pause");
        return;
    }

    cout << "¿Quiere continuar con la edicion?" << endl;
    cout << "1. Si - 2. No" << endl;
    cout << "Ingrese opcion: ";
    cin >> opcion;

    switch(opcion)
    {
    case 1:
    {
        ArchivoTipoProducto arch;

        encontrado.editarTipoProducto();

        arch.sobrescribir(encontrado, pos);

        break;
    }
    case 2:
        break;
    default:
        cout << "Opcion incorrecta." << endl;
        system("pause");
    }
}

void Menu::menuTipoPrBorrar()
{
    int id, pos;
    bool res = false;

    cout << "======= ELIMINACION DE TIPO DE PRODUCTO =======" << endl;
    cout << "Ingrese el ID del tipo a eliminar: ";
    cin >> id;
    cout << endl;

    TipoProducto tp;
    TipoProducto encontrado;

    res = tp.buscarTipoProducto(id, encontrado, pos);

    if(res)
    {
        encontrado.borrarTipoProducto(pos);
    }
    else
    {
        cout << "ID no encontrado" << endl;
    }
    system("pause");
}

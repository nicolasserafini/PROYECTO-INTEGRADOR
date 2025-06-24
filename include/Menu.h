#ifndef MENU_H
#define MENU_H
#pragma once

class Menu
{
    public:
        void menuPrincipal();

        void menuClientes();
        void menuClientesBuscar();
        void menuClientesEditar();
        void menuClientesBorrar();

        void menuProductos();

        void menuTipoProductos();
        void menuTipoPrEditar();
        void menuTipoPrBorrar();

        void menuVentas();
};

#endif

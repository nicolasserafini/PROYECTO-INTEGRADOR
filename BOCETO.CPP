#include <iostream>   // Incluir la librería para operaciones de entrada y salida (como cout y cin)
#include <cstdlib>    // Incluir la librería para funciones de utilidades generales, como rand()
#include <ctime>      // Incluir la librería para obtener la hora actual y usarla como semilla en rand()

using namespace std;  // Usar el espacio de nombres estándar para evitar escribir "std::" constantemente

// Función para tirar un dado (retorna un número aleatorio entre 1 y 6)
int tirarDado() {
    return rand() % 6 + 1;  // rand() genera un número aleatorio, % 6 limita el rango a 0-5, y sumando 1 se obtiene 1-6
}

// Función para jugar una ronda en el modo de un solo jugador
void jugarRondaUnJugador(int ronda) {
    int puntosAcumulados = 0;  // Variable para almacenar los puntos acumulados en esta ronda
    char respuesta;  // Variable para almacenar la respuesta del jugador (si quiere seguir o no)

    // Imprimir el mensaje indicando qué ronda se está jugando
    cout << "Ronda " << ronda << " (Jugador 1)" << endl;

    // Bucle para tirar el dado mientras el jugador quiera seguir jugando
    while (true) {
        int tirada = tirarDado();  // Llamar a la función tirarDado para obtener un número aleatorio
        cout << "Tiraste un " << tirada << endl;  // Mostrar el número obtenido en la tirada
        puntosAcumulados += tirada;  // Sumar la tirada al total de puntos acumulados

        // Mostrar los puntos acumulados hasta el momento en esta ronda
        cout << "Puntos acumulados en esta ronda: " << puntosAcumulados << endl;
        
        // Preguntar al jugador si desea seguir tirando o no
        cout << "¿Deseas seguir tirando? (s/n): ";
        cin >> respuesta;  // Leer la respuesta del jugador

        // Si la respuesta es 'n' o 'N', termina la ronda
        if (respuesta == 'n' || respuesta == 'N') {
            cout << "Ronda terminada. Puntos acumulados en esta ronda: " << puntosAcumulados << endl;
            break;  // Romper el bucle y terminar la ronda
        }
    }
    // Mostrar los puntos acumulados al final de la ronda
    cout << "Puntos totales al final de la ronda " << ronda << ": " << puntosAcumulados << endl;
}

// Función para jugar una ronda en el modo de dos jugadores
void jugarRondaDosJugadores(int ronda) {
    int puntosJugador1 = 0, puntosJugador2 = 0;  // Puntos acumulados por cada jugador
    int puntosRonda1 = 0, puntosRonda2 = 0;  // Puntos acumulados en esta ronda para cada jugador
    char respuesta;  // Variable para almacenar la respuesta de cada jugador

    // Turno del jugador 1
    cout << "Ronda " << ronda << " (Jugador 1)" << endl;
    while (true) {
        int tirada = tirarDado();  // Llamar a la función tirarDado para obtener un número aleatorio
        cout << "Tiraste un " << tirada << endl;  // Mostrar el número obtenido en la tirada
        puntosRonda1 += tirada;  // Sumar la tirada al total de puntos de la ronda de jugador 1

        cout << "Puntos acumulados en esta ronda: " << puntosRonda1 << endl;  // Mostrar los puntos acumulados en esta ronda
        cout << "¿Deseas seguir tirando? (s/n): ";
        cin >> respuesta;  // Leer la respuesta del jugador

        // Si la respuesta es 'n' o 'N', termina la ronda para el jugador 1
        if (respuesta == 'n' || respuesta == 'N') {
            puntosJugador1 += puntosRonda1;  // Sumar los puntos de esta ronda a los puntos totales del jugador 1
            cout << "Jugador 1 termina su ronda con " << puntosRonda1 << " puntos acumulados.\n";
            break;  // Romper el bucle y pasar al siguiente jugador
        }
    }

    // Turno del jugador 2
    cout << "Ronda " << ronda << " (Jugador 2)" << endl;
    while (true) {
        int tirada = tirarDado();  // Llamar a la función tirarDado para obtener un número aleatorio
        cout << "Tiraste un " << tirada << endl;  // Mostrar el número obtenido en la tirada
        puntosRonda2 += tirada;  // Sumar la tirada al total de puntos de la ronda de jugador 2

        cout << "Puntos acumulados en esta ronda: " << puntosRonda2 << endl;  // Mostrar los puntos acumulados en esta ronda
        cout << "¿Deseas seguir tirando? (s/n): ";
        cin >> respuesta;  // Leer la respuesta del jugador

        // Si la respuesta es 'n' o 'N', termina la ronda para el jugador 2
        if (respuesta == 'n' || respuesta == 'N') {
            puntosJugador2 += puntosRonda2;  // Sumar los puntos de esta ronda a los puntos totales del jugador 2
            cout << "Jugador 2 termina su ronda con " << puntosRonda2 << " puntos acumulados.\n";
            break;  // Romper el bucle y pasar a la siguiente ronda
        }
    }

    // Mostrar los puntos totales de ambos jugadores al final de la ronda
    cout << "\nPuntos Totales al Final de la Ronda " << ronda << ":\n";
    cout << "Jugador 1: " << puntosJugador1 << " puntos\n";
    cout << "Jugador 2: " << puntosJugador2 << " puntos\n";
}

int main() {
    // Inicializar el generador de números aleatorios usando la hora actual como semilla
    srand(time(0));

    int opcion;  // Variable para almacenar la opción del jugador (modo de juego)
    int puntosTotalesJugador1 = 0, puntosTotalesJugador2 = 0;  // Puntos totales de cada jugador

    // Mostrar el menú para que el jugador elija el modo de juego
    cout << "Bienvenido al juego de Dados!" << endl;
    cout << "Seleccione el modo de juego:" << endl;
    cout << "1. Un jugador" << endl;
    cout << "2. Dos jugadores" << endl;
    cout << "Opción: ";
    cin >> opcion;  // Leer la opción seleccionada

    // Ejecutar el juego según la opción seleccionada
    if (opcion == 1) {
        // Modo un jugador, 3 rondas
        for (int ronda = 1; ronda <= 3; ronda++) {  // Bucle para 3 rondas
            jugarRondaUnJugador(ronda);  // Llamar a la función para jugar una ronda de un jugador
        }
    } else if (opcion == 2) {
        // Modo dos jugadores, 3 rondas
        for (int ronda = 1; ronda <= 3; ronda++) {  // Bucle para 3 rondas
            jugarRondaDosJugadores(ronda);  // Llamar a la función para jugar una ronda de dos jugadores
        }
    } else {
        cout << "Opción inválida, saliendo del juego." << endl;  // Si la opción es inválida, mostrar mensaje de error
    }

    return 0;  // Terminar el programa
}

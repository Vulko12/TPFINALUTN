#include <iostream>
#include "juego.h"
#include "tienda.h"
#include "batalla.h"
using namespace std;

void iniciarJuego()
{
    int casaSeleccionada, oro = 0, soldados = 0, comida = 0, nivelHabilidad = 0;
    int batalla_actual = 0, derrotas = 0;

    cout << "----------------------------------" << endl;
    cout << "      BIENVENIDO A JUEGO DE TRONOS" << endl;
    cout << "----------------------------------" << endl;

    string nombreCasa = "";
    cout << "Elige tu casa:\n1 - Lannister\n2 - Stark\n3 - Targaryen\n4 - Baratheon\n";
    cin >> casaSeleccionada;

    switch(casaSeleccionada)
    {
    case 1:
        nombreCasa = "Lannister";
        oro = 75000;
        break;
    case 2:
        nombreCasa = "Stark";
        oro = 50000;
        break;
    case 3:
        nombreCasa = "Targaryen";
        oro = 50000;
        break;
    case 4:
        nombreCasa = "Baratheon";
        oro = 50000;
        break;
    default:
        nombreCasa = "Desconocida";
        break;
    }

    int opcion;
    do
    {
        system("cls");
        cout << "----------------------------------\nESTADO ACTUAL\n----------------------------------\n";
        cout << "Casa: " << nombreCasa << endl;
        cout << "Batallas: " << batalla_actual << "\nOro: " << oro << "\nComida: " << comida << "\nSoldados: " << soldados << "\nNivel Habilidad: " << nivelHabilidad << endl;
        cout << "----------------------------------\n1 - Batalla\n2 - Tienda\n3 - Salir\nOpcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            if (batalla_actual >= 10)
            {
                cout << "No quedan mas batallas!\n";
                system("pause");
            }
            else if (soldados <= 0 || comida <= 0)
            {
                cout << "No tienes tropas o comida suficiente!\n";
                system("pause");
            }
            else
            {
                bool victoria = combatir(batalla_actual, casaSeleccionada, oro, soldados, comida, nivelHabilidad);
                batalla_actual++;
                if (!victoria) derrotas++;
                if (derrotas >= 4)
                {
                    cout << "Perdiste la guerra!\n";
                    return;
                }
            }
            break;
        case 2:
            abrirTienda(oro, soldados, comida, nivelHabilidad, casaSeleccionada);
            break;
        }
    }
    while (opcion != 3);

    cout << "Juego finalizado.\n";
}

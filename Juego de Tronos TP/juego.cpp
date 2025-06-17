#include <iostream>
#include "juego.h"
#include "tienda.h"
#include "batalla.h"
#include "utilidades.h"

using namespace std;

void iniciarJuego() {
    int casaSeleccionada;
    int oro = 0;
    int soldados = 0;
    int comida = 0;
    float pasiva_probabilidad = 0.0;
    int batalla_actual = 0;
    int derrotas = 0;

    cout << "Elige tu casa:" << endl;
    cout << "1 - Lannister" << endl;
    cout << "2 - Stark" << endl;
    cout << "3 - Targaryen" << endl;
    cout << "4 - Baratheon" << endl;
    cin >> casaSeleccionada;

    if (casaSeleccionada == 1) {
        oro = 75000;
        pasiva_probabilidad = 0.15;
    } else if (casaSeleccionada == 2) {
        oro = 50000;
        pasiva_probabilidad = 0.30;
    } else if (casaSeleccionada == 3) {
        oro = 50000;
        pasiva_probabilidad = 0.10;
    } else if (casaSeleccionada == 4) {
        oro = 50000;
        pasiva_probabilidad = 0.05;
    }

    int opcion;
    do {
        system("cls");
        cout << "---------------------------------------" << endl;
        cout << "            Juego de Tronos            " << endl;
        cout << "---------------------------------------" << endl;
        cout << "|Batallas jugadas : " << batalla_actual << endl;
        cout << "|Oro              : " << oro << endl;
        cout << "|Comida           : " << comida << endl;
        cout << "|Soldados         : " << soldados << endl;
        cout << "|Habilidad nivel  : " << pasiva_probabilidad << endl;
        cout << "---------------------------------------" << endl;
        cout << "1 - Ir a la batalla" << endl;
        cout << "2 - Tienda" << endl;
        cout << "3 - Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                if (batalla_actual >= 10) {
                    cout << "No quedan mas batallas!" << endl;
                    system("pause");
                } else {
                    bool victoria = combatir(batalla_actual, casaSeleccionada, oro, soldados, comida, pasiva_probabilidad);
                    batalla_actual++;
                    if (!victoria) {
                        derrotas++;
                    }
                    if (derrotas >= 4) {
                        cout << "Perdiste la guerra!" << endl;
                        return;
                    }
                }
                break;
            case 2:
                abrirTienda(oro, soldados, comida, pasiva_probabilidad, casaSeleccionada);
                break;
        }
    } while (opcion != 3);

    cout << "Juego finalizado." << endl;
}

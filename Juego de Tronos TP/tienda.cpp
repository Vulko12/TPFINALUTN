#include <iostream>
#include "tienda.h"
using namespace std;

void abrirTienda(int &oro, int &soldados, int &comida, int &nivelHabilidad, int casaSeleccionada) {
    int costo_soldado, costo_comida, costo_mejora;


    if (casaSeleccionada == 1) { // Lannister
        costo_soldado = 10000;
        costo_comida = 5000;
        costo_mejora = 10000;
    } else if (casaSeleccionada == 2) { // Stark
        costo_soldado = 8500;
        costo_comida = 5000;
        costo_mejora = 8500;
    } else if (casaSeleccionada == 3) { // Targaryen
        costo_soldado = 12500;
        costo_comida = 5000;
        costo_mejora = 25000;
    } else if (casaSeleccionada == 4) { // Baratheon
        costo_soldado = 10000;
        costo_comida = 3000;
        costo_mejora = 5000;
    }

    int opcion;
    do {
        system("cls");
        cout << "---------- TIENDA ----------" << endl;
        cout << "1 - Comprar soldados (" << costo_soldado << " de oro por 10.000 soldados)" << endl;
        cout << "2 - Comprar comida (" << costo_comida << " de oro por 10.000 comida)" << endl;
        cout << "3 - Mejorar habilidad (" << costo_mejora << " de oro por nivel)" << endl;
        cout << "4 - Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                if (oro >= costo_soldado) {
                    soldados += 10000;
                    oro -= costo_soldado;
                } else {
                    cout << "No hay suficiente oro." << endl;
                    system("pause");
                }
                break;
            case 2:
                if (oro >= costo_comida) {
                    comida += 10000;
                    oro -= costo_comida;
                } else {
                    cout << "No hay suficiente oro." << endl;
                    system("pause");
                }
                break;
            case 3:
                if (oro >= costo_mejora) {
                    oro -= costo_mejora;
                    nivelHabilidad++;
                    cout << "Mejora aplicada!" << endl;
                    system("pause");
                } else {
                    cout << "No hay suficiente oro." << endl;
                    system("pause");
                }
                break;
        }
    } while (opcion != 4);
}

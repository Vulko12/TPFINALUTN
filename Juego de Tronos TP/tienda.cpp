#include <iostream>
#include "tienda.h"
using namespace std;

void abrirTienda(int &oro, int &soldados, int &comida, int &nivelHabilidad, int casaSeleccionada)
{
    int costo_soldado, costo_comida, costo_mejora;

    if (casaSeleccionada == 1)
    {
        costo_soldado=10000;
        costo_comida=5000;
        costo_mejora=10000;
    }
    else if (casaSeleccionada == 2)
    {
        costo_soldado=8500;
        costo_comida=5000;
        costo_mejora=8500;
    }
    else if (casaSeleccionada == 3)
    {
        costo_soldado=12500;
        costo_comida=5000;
        costo_mejora=25000;
    }
    else if (casaSeleccionada == 4)
    {
        costo_soldado=10000;
        costo_comida=3000;
        costo_mejora=5000;
    }

    int opcion;
    do
    {
        system("cls");
        cout << "---------- TIENDA ----------\nOro disponible: " << oro << "\n";
        cout << "1 - Soldados (" << costo_soldado << " oro por 10k soldados)\n";
        cout << "2 - Comida (" << costo_comida << " oro por 10k comida)\n";
        cout << "3 - Mejorar habilidad (" << costo_mejora << " oro)\n4 - Salir\nOpcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            if (oro >= costo_soldado)
            {
                soldados += 10000;
                oro -= costo_soldado;
                cout << "Soldados: " << soldados << ", Oro restante: " << oro << endl;
                system("pause");
            }
            else
            {
                cout << "No hay suficiente oro.\n";
                system("pause");
            }
            break;
        case 2:
            if (oro >= costo_comida)
            {
                comida += 10000;
                oro -= costo_comida;
                cout << "Comida: " << comida << ", Oro restante: " << oro << endl;
                system("pause");
            }
            else
            {
                cout << "No hay suficiente oro.\n";
                system("pause");
            }
            break;
        case 3:
            if (oro >= costo_mejora)
            {
                oro -= costo_mejora;
                nivelHabilidad++;
                if (casaSeleccionada == 1) cout << "Lannister: habilidad ahora +" << (30 + nivelHabilidad*5) << "%\n";
                else if (casaSeleccionada == 2) cout << "Stark: ahora -" << (20 - nivelHabilidad*5) << "%\n";
                else if (casaSeleccionada == 3) cout << "Targaryen: ahora +" << (35 + nivelHabilidad*10) << "%\n";
                else if (casaSeleccionada == 4) cout << "Baratheon: chance " << nivelHabilidad*5 << "%\n";
                system("pause");
            }
            else
            {
                cout << "No hay suficiente oro.\n";
                system("pause");
            }
            break;
        }
    }
    while (opcion != 4);
}

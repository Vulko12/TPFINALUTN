#include <iostream>
#include <cstdlib>
#include <ctime>
#include "batalla.h"

using namespace std;

bool combatir(int ronda, int casaSeleccionada, int &oro, int &soldados, int &comida, int nivelHabilidad) {
    int chances[10] = {50, 45, 40, 35, 30, 25, 20, 15, 10, 5};
    int perdidas[10] = {5,10,15,20,25,30,35,40,45,50};
    int oroGanado[10] = {15000,20000,25000,30000,35000,40000,45000,50000,55000,60000};

    cout << "Batalla #" << ronda+1 << endl;
    cout << "Soldados disponibles: " << soldados << endl;

    if (soldados <= 0 || comida < soldados) {
        cout << "No hay tropas o comida suficiente!" << endl;
        return false;
    }

    srand(time(0));
    int chanceBatalla = chances[ronda];


    if (casaSeleccionada == 3) {
        chanceBatalla += 35 + (nivelHabilidad * 10);
    } else if (casaSeleccionada == 2) {
        chanceBatalla -= 20 - (nivelHabilidad * 5);
        if (chanceBatalla < 0) chanceBatalla = 0;
    }

    int random = rand() % 100 + 1;
    cout << "Chance de victoria: " << chanceBatalla << "%" << endl;

    bool victoria = (random <= chanceBatalla);

    if (victoria) {
        cout << "¡Victoria!" << endl;

        int oroExtra = 0;
        if (casaSeleccionada == 1) {
            int porcentajeExtra = 30 + (nivelHabilidad * 5);
            oroExtra = oroGanado[ronda] * porcentajeExtra / 100;
            cout << "Lannister habilidad activa: +" << oroExtra << " oro extra" << endl;
        }
        oro += oroGanado[ronda] + oroExtra;
    } else {
        cout << "Derrota..." << endl;
    }

    int perdidaBase = perdidas[ronda];
    if (casaSeleccionada == 2) {
        perdidaBase -= ronda;
        if (perdidaBase < 0) perdidaBase = 0;
    }

    int perdidasBatalla = soldados * perdidaBase / 100;
    soldados -= perdidasBatalla;

    if (casaSeleccionada == 1) {
        int recupero = (perdidasBatalla * 10000 / 10000) * 0.5;
        oro += recupero;
        cout << "Lannister pasiva: recupera +" << recupero << " de oro." << endl;
    }

    int comidaConsumida = soldados;
    comida -= comidaConsumida;

    if (casaSeleccionada == 4) {
        int chanceBaratheon = 5 * (nivelHabilidad + 1);
        int prob = rand() % 100 + 1;
        if (prob <= chanceBaratheon) {
            comida += comidaConsumida / 2;
            cout << "Baratheon habilidad activa: recupera 50% comida!" << endl;
        }
        comida += comidaConsumida * 30 / 100; // pasiva
    }

    cout << "Perdiste " << perdidasBatalla << " soldados." << endl;

    system("pause");
    return victoria;
}

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "batalla.h"

using namespace std;

bool combatir(int ronda, int casaSeleccionada, int &oro, int &soldados, int &comida, float pasiva_probabilidad) {
    int chances[10] = {50, 45, 40, 35, 30, 25, 20, 15, 10, 5};
    int perdidas[10] = {5,10,15,20,25,30,35,40,45,50};
    int oroGanado[10] = {15000,20000,25000,30000,35000,40000,45000,50000,55000,60000};

    cout << "Batalla #" << ronda+1 << endl;
    cout << "Soldados disponibles: " << soldados << endl;

    // Verificación mínima de soldados
    if (soldados <= 0 || comida < soldados) {
        cout << "No tenes suficientes tropas o comida para combatir." << endl;
        return false;
    }

    // APLICAR PASIVAS ANTES DE COMBATIR (ej: Targaryen)
    int chanceBatalla = chances[ronda];
    if (casaSeleccionada == 3) { // Targaryen
        chanceBatalla = chanceBatalla + (chanceBatalla * 35 / 100);
    }

    srand(time(0));
    int random = rand() % 100 + 1;

    cout << "Chance de victoria: " << chanceBatalla << "%" << endl;

    bool victoria = (random <= chanceBatalla);

    if (victoria) {
        cout << "¡Victoria!" << endl;
        oro += oroGanado[ronda];
    } else {
        cout << "Derrota..." << endl;
    }

    // CALCULO DE PERDIDAS
    int perdidaBase = perdidas[ronda];

    if (casaSeleccionada == 2) { // Stark
        perdidaBase -= ronda;  // - (nro ronda * 1%)
        if (perdidaBase < 0) perdidaBase = 0;
    }

    int perdidasBatalla = soldados * perdidaBase / 100;
    soldados -= perdidasBatalla;

    // APLICAR PASIVA LANNISTER
    if (casaSeleccionada == 1) {
        int oroRecuperado = (perdidasBatalla * 10000) / 10000 * 0.5; // 50% oro de las perdidas
        oro += oroRecuperado;
        cout << "Lannister recupera oro por sus soldados caidos: +" << oroRecuperado << endl;
    }

    // CONSUMO DE COMIDA
    int comidaConsumida = soldados;
    comida -= comidaConsumida;

    // APLICAR PASIVA BARATHEON
    if (casaSeleccionada == 4) {
        int comidaRecuperada = comidaConsumida * 30 / 100;
        comida += comidaRecuperada;
        cout << "Baratheon recupera comida: +" << comidaRecuperada << endl;
    }

    cout << "Perdiste " << perdidasBatalla << " soldados." << endl;

    system("pause");
    return victoria;
}

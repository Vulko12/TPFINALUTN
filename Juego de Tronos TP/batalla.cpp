#include <iostream>
#include <cstdlib>
#include "batalla.h"
using namespace std;

bool combatir(int ronda, int casaSeleccionada, int &oro, int &soldados, int &comida, int nivelHabilidad) {
    int chances[10] = {50, 45, 40, 35, 30, 25, 20, 15, 10, 5};
    int perdidas[10] = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50};
    int oroGanado[10] = {15000, 20000, 25000, 30000, 35000, 40000, 45000, 50000, 55000, 60000};

    cout << "----- BATALLA #" << ronda + 1 << " -----\n";

    if (soldados <= 0 || comida <= 0) {
        cout << "No tienes tropas o comida suficiente\n";
        system("pause");
        return false;
    }

    int soldadosCombatientes = min(soldados, comida);
    bool victoria = false;
    bool dragonActivado = false;

    // Targaryen – habilidad activa automatica
    if (casaSeleccionada == 3) {
        int chanceDragon = 10 + nivelHabilidad * 10;
        int tirada = rand() % 100 + 1;
        if (tirada <= chanceDragon) {
            dragonActivado = true;
            victoria = true;

            int quemados = soldadosCombatientes * 20 / 100;
            soldados -= quemados;

            cout << "Invocaste al dragon. Victoria automatica.\n";
            cout << "Perdiste " << quemados << " soldados (20% quemados).\n";
        }
    }

    if (!dragonActivado) {
        int chanceBatalla = chances[ronda];
        if (casaSeleccionada == 3) {
            chanceBatalla += 35 + nivelHabilidad * 10;
        }

        int random = rand() % 100 + 1;
        cout << "Soldados enviados: " << soldadosCombatientes << endl;
        cout << "Chance de victoria: " << chanceBatalla << "%\n";

        victoria = (random <= chanceBatalla);

        if (victoria) {
            cout << "VICTORIA\n";
        } else {
            cout << "DERROTA\n";
        }
    }

    if (victoria) {
        int extra = 0;
        if (casaSeleccionada == 1) {
            extra = oroGanado[ronda] * (30 + nivelHabilidad * 5) / 100;
            cout << "Bonus por casa Lannister: +" << extra << " oro\n";
        }
        cout << "Ganancia base: " << oroGanado[ronda] << " oro\n";
        cout << "Total ganado: " << (oroGanado[ronda] + extra) << " oro\n";
        oro += oroGanado[ronda] + extra;
    }

    if (!dragonActivado) {
        float perdidaBase = perdidas[ronda];
        if (casaSeleccionada == 2) {
            float reduccion = ronda * 0.01f;
            perdidaBase *= (1.0f - reduccion);
            cout << "Stark: pasiva aplicada, perdida reducida a " << perdidaBase << "%\n";
        }

        int perdidasBatalla = static_cast<int>(soldadosCombatientes * (perdidaBase / 100.0f));
        soldados -= perdidasBatalla;

        if (casaSeleccionada == 1) {
            int recup = perdidasBatalla * 0.5;
            oro += recup;
            cout << "Lannister: recupera +" << recup << " oro por soldados caidos\n";
        }

        cout << "Soldados perdidos: " << perdidasBatalla << "\n";
    }

    // Gasto de comida y habilidades de Baratheon
    if (casaSeleccionada == 4) {
        int chanceHabilidad = 5 + nivelHabilidad * 5;
        bool habilidadActiva = (rand() % 100 + 1 <= chanceHabilidad);

        int comidaUsada = soldadosCombatientes;
        if (habilidadActiva) {
            comidaUsada = soldadosCombatientes / 2;
            cout << "Baratheon (habilidad activa): solo se consumio la mitad de la comida\n";
        }

        comida -= comidaUsada;

        int recuperada = comidaUsada * 30 / 100;
        comida += recuperada;
        cout << "Baratheon (pasiva): recupera +" << recuperada << " comida\n";

        if (comida < 0) comida = 0;
    } else {
        // Otras casas: gasto total de comida
        comida -= soldadosCombatientes;
        if (comida < 0) comida = 0;
    }

    cout << "Comida restante: " << comida << "\n";
    cout << "------------------------------\n";
    system("pause");
    return victoria;
}

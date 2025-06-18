#include <iostream>
#include <cstdlib>
#include "batalla.h"
using namespace std;

bool combatir(int ronda, int casaSeleccionada, int &oro, int &soldados, int &comida, int nivelHabilidad)
{
    int chances[10]= {50,45,40,35,30,25,20,15,10,5};
    int perdidas[10]= {5,10,15,20,25,30,35,40,45,50};
    int oroGanado[10]= {15000,20000,25000,30000,35000,40000,45000,50000,55000,60000};

    cout << "----- BATALLA #" << ronda+1 << " -----\n";

    int chanceBatalla = chances[ronda];
    if (casaSeleccionada == 3) chanceBatalla += 35 + nivelHabilidad*10;

    int random = rand() % 100 + 1;
    cout << "Chance: " << chanceBatalla << "%\n";

    bool victoria = (random <= chanceBatalla);
    if (victoria)
    {
        cout << "¡VICTORIA!\n";
        int extra=0;
        if (casaSeleccionada==1)
        {
            extra = oroGanado[ronda]*(30 + nivelHabilidad*5)/100;
            cout << "Lannister: +" << extra << " oro extra.\n";
        }
        oro += oroGanado[ronda] + extra;
    }
    else cout << "DERROTA...\n";

    int perdidaBase = perdidas[ronda];
    if (casaSeleccionada==2)
    {
        perdidaBase -= ronda;
        if (perdidaBase<0) perdidaBase=0;
    }
    int perdidasBatalla = soldados*perdidaBase/100;
    soldados -= perdidasBatalla;

    if (casaSeleccionada==1)
    {
        int recup=perdidasBatalla*0.5;
        oro+=recup;
        cout<<"Lannister: recupera +"<<recup<<" oro.\n";
    }

    int comidaConsumida = soldados;
    comida -= comidaConsumida;

    if (casaSeleccionada==4)
    {
        int chanceBar = nivelHabilidad * 5;
        if (rand() % 100 + 1 <= chanceBar)
        {
            comida += comidaConsumida / 2;
            cout << "Baratheon: recupera 50% comida!\n";
        }
        comida += comidaConsumida * 30 / 100;
    }

    cout << "Perdiste " << perdidasBatalla << " soldados.\n------------------------------\n";
    system("pause");
    return victoria;
}

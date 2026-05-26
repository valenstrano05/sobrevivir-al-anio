#include <iostream>
#include <locale>
#include "funciones.h"
#include <string>
#include <windows.h>
#include <cstdlib>
#include <ctime>

///agregar dificultades. distintos dialogos dependiendo al dificultad. añadir explicacion del juego y tutorial opcional.

using namespace std;

int main(){
    setlocale(LC_ALL,"");
    string nombre;
    cout<<"=====================================";
    cout<<endl;
    cout<<"          SOBREVIVIR AL AÑO          ";
    cout<<endl;
    cout<<"=====================================";
    cout<<endl;
    cout<<" Presione enter para continuar...";
    system("pause > nul");
    menuPrincipal();

return 0;
}

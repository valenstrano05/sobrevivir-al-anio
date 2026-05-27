#include <iostream>
#include <locale>
#include "funciones.h"
#include <string>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include "rlutil.h"

///agregar dificultades. distintos dialogos dependiendo al dificultad. añadir tutorial opcional antes de iniciar juego.

using namespace std;

int main(){
    setlocale(LC_ALL,"");
    string nombre;
    cout<<"====================================="<<endl;
    cout<<endl;
    cout<<"          SOBREVIVIR AL AÑO          "<<endl;
    cout<<endl;
    cout<<"====================================="<<endl;
    cout<<endl;
    cout<<" Presione enter para continuar...";
    system("pause > nul");
    menuPrincipal();

return 0;
}

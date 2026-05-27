#include <iostream>
#include <locale>
#include "funciones.h"
#include <string>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include "rlutil.h"

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

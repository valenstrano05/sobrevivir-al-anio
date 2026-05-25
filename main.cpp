#include <iostream>
#include <locale>
#include "funciones.h"
#include <string>
#include <windows.h>

using namespace std;

int main(){
    setlocale(LC_ALL,"");
    string nombre;
    int opcion;
    char salida;
    escribirLento("=====================================", 1);
    cout<<endl;
    escribirLento("          SOBREVIVIR AL AÑO          ", 1);
    cout<<endl;
    escribirLento("=====================================", 1);
    cout<<endl;
    escribirLento("Presione enter para continuar...", 50);
    system("pause > nul");

    do{
        opcion=menuPrincipal();
        switch (opcion){
        case 1:
            crearPartidaNueva();
            break;
        case 2:
            highscoreDeLaSesion();
            break;
        case 3:
            glosarioFinanciero();
            break;
        case 0:
            escribirLento("¿Está seguro/a que quiere salir?", 40);
            cout<<endl;
            escribirLento("¿s/n?", 40);
            cout<<endl;
            cin>>salida;
                switch(salida){
                case 's':
                    escribirLento("Saliendo del juego", 40);
                    Sleep(100);
                    escribirLento("...", 500);
                    return 0;
                    break;
                case 'n':
                    escribirLento("Regresando al menú", 40);
                    Sleep(100);
                    escribirLento("...", 500);
                    opcion=1;
                    break;
                }
            break;
        default:
            escribirLento("Opción inválida... Regresando al menú", 40);
            escribirLento("...", 500);
            break;
        }
    }while(opcion!=0);

return 0;
}

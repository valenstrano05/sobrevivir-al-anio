#include <iostream>
#include <locale>
#include "funciones.h"
#include <string>
#include <windows.h>

using namespace std;

void escribirLento(string texto, int velocidad){
    for(int i=0;i<texto.length();i++){
        cout<<texto[i];
        cout.flush();
        Sleep(velocidad);
    }
}

int menuPrincipal(){
    int opcion;
        system("cls");
        cout<<"====================================="<<endl;
        cout<<"            MENÚ PRINCIPAL           "<<endl;
        cout<<"====================================="<<endl;
        cout<<"1. Crear nueva partida"<<endl;
        cout<<"2. Highscore de la sesion"<<endl;
        cout<<"3. Glosario financiero"<<endl;
        cout<<"0. Salir"<<endl;
        cout<<"====================================="<<endl;
        cout<<"Ingrese una opción: ";
        cin>>opcion;
        return opcion;
}


void crearPartidaNueva(){
    system("cls");
    string nombre;
    int rondas;
    int velocidad=40;
    cout<<"====================================="<<endl;
    cout<<"            NUEVA PARTIDA            "<<endl;
    cout<<"====================================="<<endl;
    Sleep(500);
    escribirLento("Sistema: ¿Cómo es su nombre?", velocidad);
    cout<<endl;
    Sleep(700);
    escribirLento("???: Yo me llamo... ", velocidad);
    cin>>nombre;
    Sleep(400);
    escribirLento("Sistema: ¡Que lindo nombre! Bienvenido/a a mí juego, ", velocidad);
    escribirLento(nombre, velocidad);
    cout<<"."<<endl;
    Sleep(400);
    escribirLento("Sistema: ¿Cuantas meses deseas jugar? Solo se puede de 1 a 12 rondas.", velocidad);
    cout<<endl;
    Sleep(400);
    escribirLento(nombre, velocidad);
    escribirLento(": ", velocidad);
    cin>>rondas;
    while(rondas<1||rondas>12){
        escribirLento("Sistema: La cantidad de rondas es inválida. Por favor, ingresela nuevamente.", 50);
        cout<<endl;
        Sleep(400);
        escribirLento(nombre, velocidad);
        escribirLento(": ", velocidad);
        cin>>rondas;
    }

    jugarPartida(nombre, rondas);
}

float jugarPartida(string nombre, int rondas){
    return 0;
}

int highscoreDeLaSesion(){
}

int glosarioFinanciero(){
}

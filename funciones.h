#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <string>

void jugarPartida(std::string nombre, int rondas);
void escribirLento(std::string texto, int velocidad);
void menuPrincipal();
void crearPartidaNueva();
int highscoreDeLaSesion();
void glosarioFinanciero();
void cargarDatos(float economia[], float inversiones[], float preciosInversiones[], float eventosFijos[], float contadoresAcumuladores[]);
void glosario();

#endif // FUNCIONES_H_INCLUDED

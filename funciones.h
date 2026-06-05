#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <string>

void jugarPartida(std::string nombre, int rondas);
void escribirLento(std::string texto, int velocidad);
void menuPrincipal();
void crearPartidaNueva();
int highscoreDeLaSesion();
void glosarioFinanciero();
void cargarDatos(double datos[]);
void glosario();
void eventosFijos(int mes, double datos[]);
void imprevistos(double datos[]);
void aumentoAlquiler(int indice, double datos[]);
void aumentoPorInflacion(double datos[]);
void mostrarResumen(double datos[]);
void inversiones(double datos[]);
void opcionesDeInversion(double datos[]);
void cartelInversion(double datos[], int opcion);

#endif // FUNCIONES_H_INCLUDED

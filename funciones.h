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
void aumentoPorInflacion(double datos[], int rondas);
void mostrarResumen(double datos[], bool gameOver);
void inversiones(double datos[]);
void opcionesDeInversion(double datos[]);
void comprarInstrumento(double datos[], int opcion);
void venderInstrumento(double datos[], int opcion);
void comprarVender(double datos[]);

#endif // FUNCIONES_H_INCLUDED

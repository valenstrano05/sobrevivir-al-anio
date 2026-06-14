#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <string>

void jugarPartida(int contadorPartida, std::string nombre[], int rondas, double patrimonioReal[]);
void escribirLento(std::string texto, int velocidad);
void escribirLentoArcoiris(std::string texto, int velocidad);
void menuPrincipal(std::string nombre[], double patrimonioReal[]);
void crearPartidaNueva(int contadorPartida, std::string nombre[], double patrimonioReal[]);
void highscoreDeLaSesion(double patrimonioReal[], std::string nombre[], int contadorPartida);
void glosarioFinanciero();
void cargarDatos(double datos[]);
void glosario();
void eventosFijos(int mes, double datos[]);
void imprevistos(double datos[]);
void aumentoAlquiler(int indice, double datos[]);
void aumentoPorInflacion(double datos[], int rondas);
void mostrarResumen(int contadorPartida, std::string nombre[], double datos[], bool gameOver, double patrimonioReal[]);
void inversiones(int contadorPartida, double datos[], std::string nombre[], int rondas, int i);
void opcionesDeInversion(int contadorPartida, double datos[], std::string nombre[], int rondas, int i);
void comprarInstrumento(int contadorPartida, double datos[], int opcion, std::string nombre[], int rondas, int i);
void venderInstrumento(int contadorPartida, double datos[], int opcion, std::string nombre[], int rondas, int i);
void comprarVender(int contadorPartida, double datos[], std::string nombre[], int rondas, int i);
void cartelJugador(int contadorPartida, std::string nombre[], int rondas, int i);
void cartelIntro(int contadorPartida, std::string nombre[], int rondas);


#endif // FUNCIONES_H_INCLUDED

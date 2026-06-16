#include <iostream>
#include <locale>
#include "funciones.h"
#include <string>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include "rlutil.h"
#include <iomanip>
#include <conio.h>

using namespace std;

void escribirLentoArcoiris(string texto, int velocidad)
{
    int colores[] =
    {
        rlutil::RED,
        rlutil::YELLOW,
        rlutil::GREEN,
        rlutil::CYAN,
        rlutil::BLUE,
        rlutil::MAGENTA
    };
    int cantColores = 6;

    bool saltar = false;

    for(size_t i=0; i<texto.length(); i++)
    {
        rlutil::setColor(colores[i % cantColores]);
        cout<<texto[i];
        cout.flush();

        if (!saltar)
        {
            if (kbhit())
            {
                saltar = true;
            }
            else
            {
                Sleep(velocidad);
            }
        }
    }

    rlutil::resetColor();
}

void cartelParpadeante(string titulo)
{
    int colores[] =
    {
        rlutil::RED,
        rlutil::YELLOW,
        rlutil::GREEN,
        rlutil::CYAN,
        rlutil::BLUE,
        rlutil::MAGENTA
    };

    int offset = 0;

    while(!kbhit())
    {
        rlutil::locate(1,1);

        int colorActual = offset;

        for(char c : titulo)
        {
            if(c == '\n')
            {
                cout << '\n';
                continue;
            }

            if(c != ' ')
            {
                rlutil::setColor(colores[colorActual % 6]);
                colorActual++;
            }

            cout << c;
        }
        cout<<endl;
        rlutil::setColor(rlutil::WHITE);
        cout<<""<<endl;
        cout<<" Presione una tecla para jugar"<<endl;
        cout.flush();

        offset++;
        Sleep(100);
    }
    getch();

}

void escribirLento(string texto, int velocidad)
{
    bool saltar = false; // se activa cuando el usuario presiona una tecla

    for (size_t i = 0; i < texto.length(); i++)
    {
        cout << texto[i];
        cout.flush();

        if (!saltar)
        {
            if (kbhit()) // ¿hay una tecla esperando?
            {
                saltar = true;
                rlutil::getkey(); // la "consumimos" para que no quede pendiente
            }
            else
            {
                Sleep(velocidad);
            }
        }
        // si saltar == true, ya no se llama a Sleep -> se imprime todo rápido
    }
}

void glosario()
{
    cout<<"========================================================================="<<endl;
    cout<<"                           GLOSARIO FINANCIERO                           "<<endl;
    cout<<"========================================================================="<<endl;
}

void cartelTutorial()
{
    cout<<"========================================================================="<<endl;
    cout<<"                                 TUTORIAL                                "<<endl;
    cout<<"========================================================================="<<endl;
}

void cartelJugador(int contadorPartida, string nombre[], int rondas, int i)
{
    cout<<" ======================================"<<endl;
    cout<<"|  MES "<<i<<"/"<<rondas<<endl;
    rlutil::locate(40, 2);
    cout<<"|"<<endl;
    cout<<"|  JUGADOR: "<<nombre[contadorPartida]<<endl;
    rlutil::locate(40, 3);
    cout<<"|"<<endl;
    cout<<" ======================================"<<endl;
}

void cartelIntro(int contadorPartida, string nombre[], int rondas)
{
    int velocidad=10;
    int velocidadTexto=30;
    rlutil::hidecursor();
    escribirLento(" ======================================", velocidad);
    cout<<endl;
    cout<<"|";
    escribirLento("  MES ", velocidad);
    cout<< "1/"<< rondas;
    Sleep(200);
    escribirLento("       JUGADOR: ", velocidad);
    cout<<nombre[contadorPartida]<<endl;
    rlutil::locate(38, 2);
    cout<<"|"<<endl;
    escribirLento(" ======================================", velocidad);
    cout<<endl;
    Sleep(200);

    escribirLento(" La fecha es 16 de Enero.", velocidadTexto);
    cout<<endl;
    Sleep(300);
    escribirLento(" Luego de una larga búsqueda, ", velocidadTexto);
    Sleep(200);
    escribirLento("lograste",velocidadTexto);
    cout<<endl;
    escribirLento(" conseguir tu primer empleo y por fin", velocidadTexto);
    cout<<endl;
    escribirLento(" podrás independizarte.", velocidadTexto);
    cout<<endl;
    Sleep(300);
    cout<<""<<endl;
    escribirLento(" Aparte de tu sueldo de $500000, ", velocidadTexto);
    Sleep(200);
    escribirLento("tus",velocidadTexto);
    cout<<endl;
    escribirLento(" viejos te dieron $150000 para ayudarte",velocidadTexto);
    cout<<endl;
    escribirLento(" en tus primeros meses en el mundo real.",velocidadTexto);
    cout<<endl;
    Sleep(300);
    cout<<""<<endl;
    escribirLento(" Al irte de casa, ",velocidadTexto);
    Sleep(200);
    escribirLento("te despiden deseandote",velocidadTexto);
    cout<<endl;
    escribirLento(" mucha suerte. ",velocidadTexto);
    Sleep(200);
    escribirLento("La necesitarás.",velocidadTexto);
    cout<<endl;
    Sleep(200);
    cout<<""<<endl;
    escribirLento(" SALDO INICIAL: ",velocidadTexto);
    Sleep(200);
    cout<<"$650000";
    Sleep(600);
    cout<<endl;
    cout<<""<<endl;
    escribirLento(" Presiona [Enter] para comenzar",50);
    rlutil::showcursor();
    system("pause > nul");
}

void tutorial()
{
    int opcion;
    string entrada;
    bool mostrarMenu=1;
    while(true)
    {
        if(mostrarMenu)
        {
            rlutil::showcursor();
            system("cls");
            cartelTutorial();
            cout<<" 1. Sinopsis del juego"<<endl;
            cout<<" 2. Objetivo del juego"<<endl;
            cout<<" 3. ¿Cómo jugar?"<<endl;
            cout<<""<<endl;
            cout<<" 0. Volver a la partida"<<endl;
            cout<<""<<endl;
            cout<<" Ingrese una opción: "<<endl;
            cout<<"=========================================================================";
            rlutil::locate(2,13);
            cin >> entrada;
            try
            {
                opcion = stoi(entrada);
            }
            catch (...)
            {
                opcion = -1;
            }


        }
        mostrarMenu=1;
        if(opcion==0)
        {
            return;
        }
        if(opcion>=1&&opcion<=5)
        {
            system("cls");
        }
        switch (opcion)
        {
        case 1:
            system("cls");
            cartelTutorial();
            cout<<" 1. Sinopsis del juego"<<endl;
            cout<<"   En este juego sos un recién recibido que comienza su primer trabajo en "<<endl;
            cout<<" Enero. ¿Podrás ganarle a la inflación y recibirte como adulto funcional,"<<endl;
            cout<<" o vas a tener que volver a la casa de tus viejos?"<<endl;
            cout<<" ¡Todo depende de vos! "<<endl;
            cout<<"  Navegando tu nueva realidad te vas a encontrar con varias sorpresas"<<endl;
            cout<<" y vas a tener que aprender en el camino. ¿Cómo se invierte? ¿Por qué"<<endl;
            cout<<" está tan caro todo? ¿Cómo hago para no endeudarme?"<<endl;
            cout<<"  Y lo más importante... ¿Cómo le gano a la inflación?"<<endl;
            cout<<" "<<endl;
            cout<<" ¡Buena suerte en tus intentos!"<<endl;
            break;
        case 2:
            system("cls");
            cartelTutorial();
            cout<<" 2. Objetivo del juego"<<endl;
            cout<<"  El objetivo principal del juego es terminar la cantidad de rondas seleccionadas"<<endl;
            cout<<" sin haber estado 'en rojo' económicamente. "<<endl;
            cout<<" ¡Pero no te relajes con solo sobrevivir! si terminas las rondas con un patrimonio real"<<endl;
            cout<<" mayor al que tenías al iniciar, realmente ganaste."<<endl;
            cout<<" "<<endl;
            cout<<"  Aunque en la superficie el juego se trata de sobrevivir la "<<endl;
            cout<<" economía, se debe destacar el hecho de que esto es un juego medianamente"<<endl;
            cout<<" educacional. Aunque no consigas un Highscore, ¡Lo importante es aprender!"<<endl;
            break;
        case 3:
            system("cls");
            cartelTutorial();
            cout<<" 3. ¿Cómo jugar?"<<endl;
            cout<<"  ¡Este juego es bastante simple! Una vez que elegís cuantas rondas querés jugar,"<<endl;
            cout<<" inicia el juego. "<<endl;
            cout<<" Arriba de todo se encuentra el número de ronda/mes, además del nombre de usuario."<<endl;
            cout<<" En cada ronda (mes) suceden eventos fijos e imprevistos, tales como cobrar"<<endl;
            cout<<" el aguinaldo o tener que arreglar la heladera. "<<endl;
            cout<<"  Ademas de esto, podes ver fácilmente tus tenencias actuales (dólares,"<<endl;
            cout<<" fondo de emergencia, Bitcoin y SP500), tu sueldo y tu saldo luego de pagar"<<endl;
            cout<<" los gastos del mes. "<<endl;
            cout<<" "<<endl;
            cout<<"  Una vez concluido el mes, tenés la opcion de invertir cierta cantidad de tu saldo"<<endl;
            cout<<" restante y/o ponerlo en un fondo de emergencia."<<endl;
            cout<<" En el evento de querer invertir en algún instrumento, solo se debe ingresar"<<endl;
            cout<<" el número que le corresponde, lo que te permitirá ver cuánto sale la unidad del"<<endl;
            cout<<" instrumento seleccionado. Luego de apretar 'enter' podés ingresar cuánto dinero"<<endl;
            cout<<" querés utilizar para comprar dicho instrumento."<<endl;
            cout<<" "<<endl;
            cout<<"  Una vez termine la última ronda, podrás ver cómo te fue. Si tu patrimonio real es mayor al"<<endl;
            cout<<" inicial, ¡Muy bien!, esto significa que realmente le ganaste a la inflación."<<endl;
            cout<<" Por otro lado, si este es igual al inicial, solo sobreviviste. ¡No te desanimes!"<<endl;
            cout<<" podes intentar otra vez."<<endl;
            cout<<" Si tu patrimonio real es menor al inicial, ¡Que dolor! Perdiste y te comió la inflación."<<endl;
            cout<<" Puede suceder que no llegues a la última ronda si vas 3 meses consecutivos con las"<<endl;
            cout<<" finanzas en rojo."<<endl;
            cout<<" "<<endl;
            cout<<"  En todo caso, se recomienda leer el glosario si hay algún término económico que no"<<endl;
            cout<<" te quedó muy claro."<<endl;
            cout<<" El conocimiento es lo mas valioso que hay."<<endl;
            break;
        case 0:
            return;
            break;
        default:
            break;
        }
        if(opcion>0&&opcion<4)
        {
            cout<<endl<<"    [<] Pág. Anterior   [>] Pág. Siguiente   [Esc] Volver al menu"<<endl;
            cout<<"========================================================================="<<endl;
            rlutil::hidecursor();
            int tecla=rlutil::getkey();
            if(tecla==rlutil::KEY_LEFT)
            {
                opcion = (opcion > 1)?opcion-1:3;
                mostrarMenu=0;
            }
            else if(tecla==rlutil::KEY_RIGHT)
            {
                opcion=(opcion<3)?opcion+1:1;
                mostrarMenu=0;
            }
            else if(tecla==rlutil::KEY_ESCAPE)
            {
                mostrarMenu=1;
            }
            if(tecla != rlutil::KEY_ESCAPE && tecla != rlutil::KEY_LEFT && tecla != rlutil::KEY_RIGHT)
            {
                mostrarMenu = 0;
            }
        }
    }
}

void tipsEducativos(int mes)
{
    cout << " -------------------------------------" << endl;
    cout << "          ~CONSEJO DEL MES~           " << endl;

    switch (mes)
    {
    case 1:
        cout << " La INFLACION es el aumento sostenido de" << endl;
        cout << " los precios. Tus $500k de hoy valen menos" << endl;
        cout << " cada mes que pasa." << endl;
        break;
    case 2:
        cout << " El FONDO DE EMERGENCIA cubre imprevistos" << endl;
        cout << " sin tener que vender inversiones a perdida." << endl;
        cout << " Se recomienda tener 3-6 meses de gastos." << endl;
        break;
    case 3:
        cout << " El COSTO DE OPORTUNIDAD es lo que resignas" << endl;
        cout << " al elegir. Dejar plata en pesos 'sin hacer" << endl;
        cout << " nada' tiene un costo: la inflacion." << endl;
        break;
    case 4:
        cout << " Tu sueldo subio 15% pero la inflacion" << endl;
        cout << " acumulada ya supera ese numero. Eso se" << endl;
        cout << " llama caida del SALARIO REAL." << endl;
        break;
    case 5:
        cout << " DIVERSIFICAR es distribuir el dinero en" << endl;
        cout << " varios instrumentos para no depender de uno" << endl;
        cout << " solo. No pongas todos los huevos en una" << endl;
        cout << " canasta." << endl;
        break;
    case 6:
        cout << " El AGUINALDO (SAC) es un derecho laboral." << endl;
        cout << " Existe porque el sueldo no ajusta" << endl;
        cout << " continuamente. Si la inflacion es alta," << endl;
        cout << " igual perdes poder adquisitivo." << endl;
        break;
    case 7:
        cout << " La VOLATILIDAD mide cuanto varia el precio" << endl;
        cout << " de un activo. Bitcoin es muy volatil: puede" << endl;
        cout << " hacerte rico o dejarte en cero en un mes." << endl;
        break;
    case 8:
        cout << " La LIQUIDEZ es que tan facil podes convertir" << endl;
        cout << " un activo en efectivo. El cash es lo mas" << endl;
        cout << " liquido; una propiedad, lo menos." << endl;
        break;
    case 9:
        cout << " La INDEXACION ajusta contratos segun la" << endl;
        cout << " inflacion. Tu alquiler se actualizo asi." << endl;
        cout << " Protege al duenio pero te afecta a vos." << endl;
        break;
    case 10:
        cout << " El S&P 500 es un indice de las 500 empresas" << endl;
        cout << " mas grandes de EE.UU. Invertir en su ETF es" << endl;
        cout << " apostar al crecimiento del capitalismo." << endl;
        break;
    case 11:
        cout << " El BITCOIN tuvo un mes extremo. Asi es la" << endl;
        cout << " ESPECULACION: ganancias y perdidas enormes" << endl;
        cout << " en poco tiempo. No es para todos los perfiles." << endl;
        break;
    case 12:
        cout << " El PATRIMONIO REAL es lo que vale tu dinero" << endl;
        cout << " ajustado por inflacion. No alcanza con tener" << endl;
        cout << " mas pesos: hay que ganarle a la inflacion." << endl;
        break;
    }
}

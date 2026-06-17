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

void menuPrincipal(string nombre[], double patrimonioReal[])
{
    rlutil::showcursor();
    int opcion=1;
    int contadorPartida=0;
    string entrada;
    char salida;
    while(opcion!=0)
    {
        system("cls");
        cout<<" ======================================"<<endl;
        cout<<"|            MENÚ PRINCIPAL            |"<<endl;
        cout<<" ======================================"<<endl;
        cout<<"|                                      |"<<endl;
        cout<<"| 1. Crear nueva partida               |"<<endl;
        cout<<"| 2. Highscore de la sesion            |"<<endl;
        cout<<"| 3. Glosario financiero               |"<<endl;
        cout<<"| 4. Detalles de la sesión             |"<<endl;
        cout<<"|                                      |"<<endl;
        cout<<"| 0. Salir                             |"<<endl;
        cout<<"|                                      |"<<endl;
        cout<<" ======================================"<<endl;
        cout<<" Ingrese una opción: ";
        cin>>entrada;
        try
        {
            opcion = stoi(entrada);
        }
        catch (...)
        {
            opcion = -1;
        }

        switch (opcion)
        {
        case 1:
            crearPartidaNueva(contadorPartida, nombre, patrimonioReal);
            contadorPartida++;
            break;
        case 2:
            if(contadorPartida==0)
            {
                rlutil::hidecursor();
                system("cls");
                cout<<" =================================================="<<endl;
                cout<<"|                  * HIGHSCORE *                   |"<<endl;
                cout<<"|                                                  |"<<endl;
                cout<<"|                    ╰(*°v°*)╯                     |"<<endl;
                cout<<" =================================================="<<endl;
                cout<<"|          ?                                       |"<<endl;
                cout<<"|                     ?                 ?          |"<<endl;
                cout<<"|                                                  |"<<endl;
                cout<<"|  ?                                             ? |"<<endl;
                cout<<"|           --------------------------             |"<<endl;
                cout<<"|       ?  |Aún no se jugaron partidas|            |"<<endl;
                cout<<"|           --------------------------     ?       |"<<endl;
                cout<<"|                             ?                    |"<<endl;
                cout<<"|                                                  |"<<endl;
                cout<<"|     ?          ?                                 |"<<endl;
                cout<<"|                                               ?  |"<<endl;
                cout<<" =================================================="<<endl;
                cout<<" Presione una tecla para regresar al menú"<<endl;
                rlutil::locate(42, 18);
                system("pause >nul");
                rlutil::showcursor();
            }
            else
            {
                highscoreDeLaSesion(patrimonioReal, nombre, contadorPartida);
            }
            break;
        case 3:
            glosarioFinanciero();
            break;
        case 4:
            if(contadorPartida==0){
                rlutil::hidecursor();
                system("cls");
                cout<<" =================================================="<<endl;
                cout<<"|            DETALLES DE LAS PARTIDAS              |"<<endl;
                cout<<" ================================================== "<<endl;
                cout<<"|       ?                         ?                |"<<endl;
                cout<<"|             ?                                    |"<<endl;
                cout<<"|                       ?                 ?        |"<<endl;
                cout<<"|                                                  |"<<endl;
                cout<<"|           --------------------------          ?  |"<<endl;
                cout<<"|   ?      |Aún no se jugaron partidas|            |"<<endl;
                cout<<"|           --------------------------             |"<<endl;
                cout<<"|                                                  |"<<endl;
                cout<<"|                               ?             ?    |"<<endl;
                cout<<"|    ?         ?                                   |"<<endl;
                cout<<"|                                                  |"<<endl;
                cout<<" =================================================="<<endl;
                cout<<"| Presione una tecla para regresar al menú         |"<<endl;
                cout<<" =================================================="<<endl;
                rlutil::locate(42, 18);
                system("pause > nul");
                rlutil::showcursor();
            }
            else{
                detallesSesion(patrimonioReal, nombre, contadorPartida);
            }
            break;
        case 0:
            system("cls");
            cout<<" ======================================"<<endl;
            cout<<"|            MENÚ PRINCIPAL            |"<<endl;
            cout<<" ======================================"<<endl;
            cout<<"|                                      |"<<endl;
            cout<<"| 1. Crear nueva partida               |"<<endl;
            cout<<"| 2. Highscore de la sesion            |"<<endl;
            cout<<"| 3. Glosario financiero               |"<<endl;
            cout<<"| 4. Detalles de la sesión             |"<<endl;
            cout<<"|                                      |"<<endl;
            cout<<"| 0. Salir                             |"<<endl;
            cout<<" ======================================"<<endl;
            cout<<"|                                      |"<<endl;
            cout<<"|                                      |"<<endl;
            cout<<"|                                      |"<<endl;
            cout<<" ======================================"<<endl;
            rlutil::locate(2, 12);
            escribirLento(" ¿Está seguro/a que quiere salir?", 20);
            cout<<endl;
            rlutil::locate(2, 13);
            escribirLento(" ¿s/n?", 20);
            rlutil::locate(9, 13);
            cin>>salida;
            switch(salida)
            {
            case 's':
                rlutil::locate(2, 14);
                escribirLento(" Saliendo del juego", 20);
                Sleep(100);
                escribirLento("...", 200);
                rlutil::locate(2, 15);
                return;
                break;
            case 'n':
                rlutil::locate(2, 14);
                escribirLento(" Regresando al menú", 20);
                Sleep(100);
                escribirLento("...", 200);
                opcion=1;
                break;
            }
            break;
        default:
            escribirLento(" Opción inválida", 40);
            escribirLento("...", 500);
            break;
        }
    }
}

void detallesSesion(double patrimonioReal[], string nombre[], int contadorPartida){
    rlutil::hidecursor();
    system("cls");
    cout<<" =================================================="<<endl;
    cout<<"|            DETALLES DE LAS PARTIDAS              |"<<endl;
    cout<<"|                    (máx. 5)                      |"<<endl;
    cout<<" ================================================== "<<endl;
    cout<<"|                                                  |"<<endl;
    cout<<"| 1."<<nombre[0]<<": $"<<patrimonioReal[0];
    rlutil::locate(52, 6);
    cout<<"|                                         "<<endl;
    cout<<"| 2."<<nombre[1]<<": $"<<patrimonioReal[1];
    rlutil::locate(52, 7);
    cout<<"|                                         "<<endl;
    cout<<"| 3."<<nombre[2]<<": $"<<patrimonioReal[2];
    rlutil::locate(52, 8);
    cout<<"|                                         "<<endl;
    cout<<"| 4."<<nombre[3]<<": $"<<patrimonioReal[3];
    rlutil::locate(52, 9);
    cout<<"|                                         "<<endl;
    cout<<"| 5."<<nombre[4]<<": $"<<patrimonioReal[4];
    rlutil::locate(52, 10);
    cout<<"|                                         "<<endl;
    cout<<"|                                                  |"<<endl;
    cout<<" =================================================="<<endl;
    cout<<" Presione una tecla para regresar al menú"<<endl;
    rlutil::locate(42, 18);
    system("pause > nul");
    rlutil::showcursor();
}

void highscoreDeLaSesion(double patrimonioReal[], string nombre[], int contadorPartida)
{
    system("cls");
    rlutil::hidecursor();
    int maximo=0;
    for(int i=0; i<contadorPartida; i++)
    {
        if(i!=0)
        {
            if(patrimonioReal[i]>patrimonioReal[maximo])
            {
                maximo=i;
            }
        }
    }
    cout<<" ==================================================="<<endl;
    cout<<"|    $$$           * HIGH SCORE *           $$      |"<<endl;
    cout<<"|                                                   |"<<endl;
    cout<<"|            $        ╰(*°v°*)╯      $$$       $    |"<<endl;
    cout<<"|     $$                                            |"<<endl;
    cout<<" ==================================================="<<endl;
    cout<<"| Jugador estrella: "<<nombre[maximo]<<endl;
    rlutil::locate(53, 7);
    cout<<"|"<<endl;
    cout<<"| Patrimonio real: $"<<patrimonioReal[maximo]<<endl;
    rlutil::locate(53, 8);
    cout<<"|"<<endl;
    cout<<" ==================================================="<<endl;
    cout<<" Presione una tecla para regresar al menú"<<endl;
    rlutil::locate(42, 18);
    system("pause > nul");
    rlutil::showcursor();
}

void glosarioFinanciero()
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
            glosario();
            cout<<" 1. Costo de oportunidad"<<endl;
            cout<<" 2. Diversificación"<<endl;
            cout<<" 3. ETF (Exchange-Traded Fund)"<<endl;
            cout<<" 4. Fondo de Emergencia"<<endl;
            cout<<" 5. Indexación"<<endl;
            cout<<" 6. Inflación"<<endl;
            cout<<" 7. Liquidez"<<endl;
            cout<<" 8. Poder Adquisitivo"<<endl;
            cout<<" 9. Salario Real"<<endl;
            cout<<" 10. Salario Nominal"<<endl;
            cout<<" 11. Volatilidad"<<endl;
            cout<<""<<endl;
            cout<<" 0. Volver al menu"<<endl;
            cout<<""<<endl;
            cout<<" Ingrese una página: "<<endl;
            cout<<"=========================================================================";
            rlutil::locate(22,18);
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
        if(opcion>=1&&opcion<=11)
        {
            system("cls");
        }
        switch (opcion)
        {
        case 1:
            system("cls");
            glosario();
            cout<<"1. Costo de Oportunidad:"<<endl;
            cout<<"El valor perdido que se resigna al tomar una decisión al momento de invertir,"<<endl;
            cout<<"o también el valor de la opción no realizada. Sirve para hacer valoraciones"<<endl;
            cout<<"contrastando el riesgo de las inversiones o la inmovilidad del activo."<<endl;
            cout<<""<<endl;
            cout<<"Ejemplos:"<<endl;
            cout<<"-Pagar una deuda en vez de inverir tiene el costo de oportunidad"<<endl;
            cout<<"de la ganancia que podrías haver generado."<<endl;
            cout<<"-Guardar plata en pesos tiene el costo de oportunidad de invertirla."<<endl;
            break;
        case 2:
            system("cls");
            glosario();
            cout<<"2. Diversificación"<<endl;
            cout<<"Proceso de distribuir el dinero entre distintos instrumentos o activos para"<<endl;
            cout<<"reducir posibles riesgos y así no depender de una sola fuente en el "<<endl;
            cout<<"posible caso de que algo suceda. 'No poner todos los huevos en la misma canasta.'"<<endl;
            cout<<""<<endl;
            cout<<"Ejemplos"<<endl;
            cout<<"-Invertir en diferentes acciones o cedears, así reduciendo el riesgo de perder dinero"<<endl;
            cout<<"si una inversión no resulta rentable."<<endl;
            break;
        case 3:
            system("cls");
            glosario();
            cout<<"3. ETF (Exchange-Traded Fund)"<<endl;
            cout<<"Un Exchange-traded Fung (ETF) o Fondo Cotizado en bolsa (FCB)"<<endl;
            cout<<"Permite invertir en muchas empresas a la vez con bajo costo,"<<endl;
            cout<<"y es un buen lugar en donde diversificar las inversiones."<<endl;
            break;
        case 4:
            system("cls");
            glosario();
            cout<<"4. Fondo de Emergencia"<<endl;
            cout<<"Un fondo de emergencia es como un colchón financiero con el cual"<<endl;
            cout<<"se pueden cubrir gastos imprevistos y así evitar endeudarse"<<endl;
            cout<<"o vender inversiones antes de tiempo."<<endl;
            cout<<""<<endl;
            cout<<"Ejemplo:"<<endl;
            cout<<"-Al principio de este mes, guardé $50.000 en un fondo de emergencia, "<<endl;
            cout<<"lo cual más adelante me salvó de tener que endeudarme cuando tuve un gasto imprevisto."<<endl;
            break;
        case 5:
            system("cls");
            glosario();
            cout<<"5. Indexación"<<endl;
            cout<<"Mecanismo por el cual el valor de un contrato (como un alquiler)"<<endl;
            cout<<"se ajusta periódicamente según un índice de precios, "<<endl;
            cout<<"para mantener el valor real y el poder adquisitivo del público"<<endl;
            cout<<""<<endl;
            cout<<"Ejemplo:"<<endl;
            cout<<"-Al aumenta la inflación, y respectivamente el costo de vida,"<<endl;
            cout<<" los precios de alquileres aumentan, tomando como índice el costo de vida."<<endl;
            break;
        case 6:
            system("cls");
            glosario();
            cout<<"6. Inflación"<<endl;
            cout<<"Aumento generalizado y sostenido de los precios de bienes y servicios."<<endl;
            cout<<"Reduce el valor/poder adquisitivo del dinero con el tiempo"<<endl;
            break;
        case 7:
            system("cls");
            glosario();
            cout<<"7. Liquidez"<<endl;
            cout<<"Representa la cualidad de los activos para convertirse en dinero"<<endl;
            cout<<"sin sufrir una pérdida significativa de su valor."<<endl;
            cout<<"El efectivo es el activo más líquido; los inmuebles, el menos."<<endl;
            cout<<""<<endl;
            cout<<"Ejemplo:"<<endl;
            cout<<"-Un monitor usado no es muy 'Líquido' ya que al intentar venderlo y"<<endl;
            cout<<" así convertirlo en dinero, este sufre una pérdida significativa de valor."<<endl;
            break;
        case 8:
            system("cls");
            glosario();
            cout<<"8. Poder Adquisitivo"<<endl;
            cout<<"Es determinado por la cantidad de bienes y servicios que pueden ser"<<endl;
            cout<<"comprados con determinada suma de dinero. Disminuye cuando hay inflación,"<<endl;
            cout<<"ya que la moneda utilizada pierde su valor."<<endl;
            break;
        case 9:
            system("cls");
            glosario();
            cout<<"9. Salario Real"<<endl;
            cout<<"El salario real es el salario en sí, descontando la inflación."<<endl;
            cout<<"Si este no se ajusta a la inflación, pierde poder adquisitivo."<<endl;
            cout<<""<<endl;
            cout<<"Ejemplo"<<endl;
            cout<<"-Teniendo un salario de $1.000.000 y un nivel de inflación anual"<<endl;
            cout<<" del 7%, tu salario real al final del año es de $930.000, aunque"<<endl;
            cout<<" tu salario nominal no haya disminuido."<<endl;
            break;
        case 10:
            system("cls");
            glosario();
            cout<<"10. Salario Nominal"<<endl;
            cout<<"El salario nominal es el número en el recibo de sueldo.";
            break;
        case 11:
            system("cls");
            glosario();
            cout<<"11. Volatilidad"<<endl;
            cout<<"Medida de cuánto varía el precio de un activo. Un instrumento muy"<<endl;
            cout<<"volátil (como el Bitcoin) puede subir o bajar mucho en poco tiempo."<<endl;
            break;
        case 0:
            return;
            break;
        default:
            break;
        }
        if(opcion>0&&opcion<12)
        {
            cout<<endl<<"    [<] Pág. Anterior   [>] Pág. Siguiente   [Esc] Volver al menu"<<endl;
            cout<<"========================================================================="<<endl;
            rlutil::hidecursor();
            int tecla=rlutil::getkey();
            if(tecla==rlutil::KEY_LEFT)
            {
                opcion = (opcion > 1)?opcion-1:11;
                mostrarMenu=0;
            }
            else if(tecla==rlutil::KEY_RIGHT)
            {
                opcion=(opcion<11)?opcion+1:1;
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

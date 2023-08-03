#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>
#include "math.h"
#include <time.h>
#include <conio.h>
#include <ctype.h>


using namespace std;

#include "Funciones.h"

int main() {
int RONDA,APUESTA,APUESTA1,APUESTA2,mp1=0,puntajeHistorico=0;
char NOMBRE[20],NOMBRE1[20],NOMBRE2[20],NombreMax[20];
int puntajeJugadorDos=0,putajeJugadorUno=0,puntajeSimulado=0,pp,E=0;
bool Empate=false;
system ("color 37");
int opc;
    while (true){
            if (Empate==false){
     system("cls");
     cout<<endl;
     cout<<"1-        JUEGO NUEVO PARA UN JUGADOR "<<endl;
     cout<<endl;
     cout<<"2-      JUEGO NUEVO PARA DOS JUGADORES"<<endl;
     cout<<endl;
     cout<<"3-        MOSTRAR PUNTUACION MAS ALTA"<<endl;
     cout<<endl;
     cout<<"4-    MODO SIMULADO (CARGA DE DADOS MANUAL)"<<endl;
     cout<<endl;
     cout<<"0-             FIN DEL PROGRAMA"<<endl;
     cout<<endl;
     cin>>opc;
            }
     system("cls");
     switch (opc){
         case 1:
                saludo(opc);
                //system("pause");
                 cout<<"INGRESE SU NOMBRE SIN ESPACIOS: ";
                 cin>>NOMBRE;
                 cout<<endl;
                 cout<<"INDIQUE CUANTOS PUNTOS QUIERE APOSTAR: ";
                 cin>>APUESTA;
                 cout<<endl;
                 cout<<"CANTIDAD DE RONDAS QUE DESEA JUGAR: ";
                 cin>>RONDA;
                 system("cls");
                 mp1=player(NOMBRE,RONDA,APUESTA,true);
                    if (mp1>puntajeHistorico){
                        puntajeHistorico=mp1;
                        strcpy(NombreMax,NOMBRE);
                    }
             break;
         case 2:{

                 saludo(opc);
                 //system("pause");
                 int puntajeJugadorDos=0,puntajeJugadorUno =0;
                 cout<<"INGRESE EL PRIMER NOMBRE SIN ESPACIOS: ";
                 cin>>NOMBRE1;
                 cout<<endl;
                 cout<<"INGRESE EL SEGUNDO NOMBRE SIN ESPACIOS: ";
                 cin>>NOMBRE2;
                 cout<<endl;
                 cout<<"INDIQUE CUANTOS PUNTOS QUIERE APOSTAR EL PRIMER JUGADOR: ";
                 cin>>APUESTA1;
                 cout<<endl;
                 cout<<"INDIQUE CUANTOS PUNTOS QUIERE APOSTAR EL SEGUNDO JUGADOR: ";
                 cin>>APUESTA2;
                 cout<<endl;
                 cout<<"CANTIDAD DE RONDAS QUE DESEAN JUGAR: ";
                 cin>>RONDA;
                 cout<<endl;
                 system("cls");
                 puntajeJugadorUno = puntajeJugadorUno+player(NOMBRE1,RONDA,APUESTA1);
                    if (puntajeJugadorUno>puntajeHistorico){
                        puntajeHistorico=puntajeJugadorUno;
                        strcpy(NombreMax,NOMBRE1);
                        }
                 system("cls");
                 puntajeJugadorDos = puntajeJugadorDos + player(NOMBRE2,RONDA,APUESTA2);
                    if (puntajeJugadorDos>puntajeHistorico){
                         puntajeHistorico=puntajeJugadorDos;
                         strcpy(NombreMax,NOMBRE2);
                        }
                 E=mayorP2(puntajeJugadorUno,puntajeJugadorDos,NOMBRE1,NOMBRE2);
                 system("pause");
                 if (E==-1){
                     Empate=true;
                    }
                    else {
                         Empate=false;
                        }
             break;}
         case 3:
                saludo(opc);
                system("pause");
                 cout<< "EL PUNTAJE MAYOR HISTORICO ES : "<<puntajeHistorico<< "DEL JUGADOR : "<<NombreMax<<endl;
                 system("pause");
             break;
         case 4:{
                 saludo(opc);
                 cout<<"INGRESE SU NOMBRE SIN ESPACIOS: ";
                 cin>>NOMBRE;
                 cout<<endl;
                 cout<<"INDIQUE CUANTOS PUNTOS QUIERE APOSTAR: ";
                 cin>>APUESTA;
                 cout<<endl;
                 cout<<"CANTIDAD DE RONDAS QUE DESEA JUGAR: ";
                 cin>>RONDA;
                 cout<<endl;
                 puntoSimulado(NOMBRE,APUESTA,RONDA);
             break;}
         case 0:
                saludo(opc);
             break;
        }
    }
     return 0;
    }








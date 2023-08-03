#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED



void cargarAleatorio(int v[], int tam, int limite);
int player(char nombre[],int ronda, int apuesta,char*NOMBREMAX[],bool jugadorSolo);
int player2(char nombre[],int ronda, int apuesta);
void DadosAzar (int dado[], int g);
void DadoXronda(int dado[], int dado2[],int g);
void LlamarDadosXronda (int dado2[],int g);
void Visual (char n[],int r,int i, int pt, int a, int g);
void Visual2 (char n[],int rcp,int rCero, int pAc);
int SumaDadosXronda(int dado2[]);
int NumeroGenerador(int TR);
int tiroPuntaje(int d[],int NG );
int puntoSimulado(char NOMBRE[],int APUESTA,int RONDA);
void cargaDadosManual(int vDados[]);
void muestraDadosManual(int vDados[]);
void saludo (int n);



int player(char nombre[],int ronda,int apuesta,bool jugadorSolo=false){

int i=0,C=0, punt=0,dadoRonda[5]{0}, vueltas=0,TotalRonda=0, vDados[5]={0} ,cuentaPerdida=0,CuentaCeros=0;
//int h=0;
char NomPunt[20];
strcpy (NomPunt,nombre);

    while (i!=ronda){
        vueltas=0;
        while (vueltas!=5){
        int dado[5]{0};
         cout<<"********************************************************"<<endl;
         cout<<endl;
          Visual (nombre,ronda,i,punt,apuesta,vueltas);
          cout<<endl;
          cout<<"--------------------------------------------------------"<<endl;
            if (vueltas!=0){
                LlamarDadosXronda (dadoRonda,vueltas);
            }
         cout<<endl<<endl;
         cout<<"TIRA LOS DADOS "<<endl;
         DadosAzar (dado,vueltas);
         DadoXronda(dado,dadoRonda,vueltas);
         vueltas++;
         system("pause");
         system("cls");
        }
     system("cls");
     TotalRonda=SumaDadosXronda(dadoRonda);
     if (TotalRonda>=20){
     int dadox[5]{0},NG=0;
        NG=NumeroGenerador (TotalRonda);
        cout<<"------------------------------------------------------------------------"<<endl;
        cout<<endl;
        cout<<"FELICIDADES TU PUNTAJE ES !!!! : "<< TotalRonda<<" POR ENDE TU NUMERO GENERADOR ES: "<<NG<<endl;
        cout<<endl;
        cout<<"************************************************************************"<<endl;
        cout<<endl;
        cout<< "TIRO PUNTAJE: ";
        system("pause");
        system("cls");
        cout<<"-------------------------------------------------------------"<<endl;
        cout<< "VALORES DEL TIRO DE PUNTAJE: "<<endl;
        DadosAzar (dadox,0);
        cout<<endl;
        C=tiroPuntaje(dadox,NG);
        cout<<"*************************************************************"<<endl;
        cout<<endl;
        cout<< "NUMERO GENERADOR DE ESTA RONDA :"<<NG<<endl;
        cout<<endl;
        cout<< "CANTIDAD DE VECES QUE SE REPITE TU NUMERO GENERADOR: "<<C<<endl;
        cout<<endl;
        cout<<"-------------------------------------------------------------------------------"<<endl;
            if (C==0){
                    CuentaCeros++;
                    punt=punt;
                    cout<<endl;
                cout<< "TU NUMERO GENERADOR NO SE REPITE, NO SUMA PUNTOS ESTA RONDA,SU PUNTAJE ES: "<<punt<<endl;
            }
               else {
                 punt+=(apuesta*C);
            }
        }
        else {
            cuentaPerdida++;
            punt=punt-apuesta;
        }
     i++;
     cout<<endl;
     system("pause");
     system("cls");

    }
        if (jugadorSolo==true){
          Visual2(nombre,cuentaPerdida,CuentaCeros,punt);
          system("pause");
     }
return punt;
}

void saludo (int n){
int opc;
opc=n;
   switch(opc){
     case 1:
         cout<<"------------------------------------------------------"<<endl;
         cout<<endl;
         cout<<"BIENVENIDOS AL JUEGO DE DADOS 20 para un solo jugador "<<endl;
         cout<<endl;
         cout<<"------------------------------------------------------"<<endl;
    break;
    case 2:
         cout<<"------------------------------------------------------"<<endl;
         cout<<endl;
         cout<<" BIENVENIDOS AL JUEGO DE DADOS 20 para dos jugadores "<<endl;
         cout<<endl;
         cout<<"------------------------------------------------------"<<endl;
    break;
    case 3:
         cout<<"--------------------------------------------------"<<endl;
         cout<<endl;
         cout<<"PUNTAJE MAXIMO DE TODAS LAS PARTIDAS ";
         cout<<endl;
         cout<<"--------------------------------------------------"<<endl;
         cout<<endl;
    break;
    case 4:
         cout<<"--------------------------------------------------"<<endl;
         cout<<endl;
         cout<<" ESTA POR INGRESAR A JUGAR EL MODO SIMULADO  "<<endl;
         cout<<endl;
         cout<<"--------------------------------------------------"<<endl;
         cout<<endl;
    break;
    case 0:
         cout<<"--------------------------------------------------"<<endl;
         cout<<endl;
         cout<< " GRACIAS POR ELEGIR DIVERTIRSE CON NOSOTROS : "<<endl;
         cout<<endl;
         cout<<"--------------------------------------------------"<<endl;
    break;

        }
        cout<<endl;
         system("pause");
         system("cls");
   }





void Visual (char n[],int r,int i, int pt, int a, int g){  ///datos que se mostraran por pantalla. NOMBRE|RONDA|PUNTOS ACUMULADOS|PUNTOS APOSTADOS.
      cout<<"NOMBRE: "<<n<<"  |  "<<"RONDA "<<i+1<<"  |  "<<"RONDAS POR JUGAR: "<<r<<"  |  "<<"PUNTOS ACUMULADOS: "<<pt<<endl;
      cout<<endl;
      cout<<"PUNTOS APOSTADOS: "<<a<<"\t";
      cout<<endl;

    }


void Visual2 (char n[],int rcp,int rCero,int pAc){
    cout<<endl;
    cout<< "*****************FIN DEL JUEGO*****************"<<endl;
    cout<<endl;
    cout<<"---------------------------------------------------------------------------"<<endl;
    cout<< "NOMBRE: "<<n<< " | "<<"CANTIDAD DE RONDAS CON PERDIDA DE PUNTOS: "<<rcp<<endl;
    cout<<endl;
    cout<<"CANTIDAD DE RONDAS DE SIN GANAR PUNTOS: "<<rCero<<endl;
    cout<<endl;
    cout<<"PUNTOS GANADOS : "<<pAc<<"\t"<<endl;
    cout<<endl;
    cout<<"---------------------------------------------------------------------------"<<endl;
}



void DadosAzar (int dado[],int g){   ///aqui se tiran los 5 dados al azar y se va sacando un dado a medida que se tiran las 5 veces.
int a=0;

srand(time(NULL));

for (a=0;a<=4-g;a++){
dado[a]=1+rand()%(6+1-1);
cout<<dado[a]<<"\t";
}}



void DadoXronda(int dado[], int dado2[], int g){  /// dadoRonda vendria a ser el dado con el valor mas alto de la tirada por cada ronda.
int a=0;
for (a=0;a<=4-g;a++){

if(dado[a]>dado2[g]){
    dado2[g]=dado[a];
    }
}
cout<<endl;
cout<<dado2[g];}



void LlamarDadosXronda (int dado2[],int g){    /// muestra por pantalla los dados maximos de las tiradas.
int a=0;
cout<<"DADOS CON RANGO MAS ALTO: ";
        for (a=0;a<g;a++){
            dado2[a];
            cout<<dado2[a]<<"\t";
        }
     cout<<endl;
}
void LlamarDadosXronda2 (int dado2[]){    /// muestra por pantalla los dados maximos de las tiradas.
int a=0;
cout<<"DADOS CON RANGO MAS ALTO: ";
        for (a=0;a<=5;a++){
             if (dado2[a]>0&&dado2[a]<=6){
            cout<<dado2[a]<<"\t";
            }
            else {
                cout<<"EL VALOR DEL DADO: "<<a+1<< "ESTA FUERA DE RANGO";
            }
        }
     cout<<endl;
}


int SumaDadosXronda(int dado2[]){
int a=0,DT=0;
for (a=0;a<5;a++){
DT+=dado2[a];
}
return DT;
}


int NumeroGenerador (int TR){
    int NG=0;
    switch (TR){
    case 20: NG=1;
    break;
    case 21: NG=2;
    break;
    case 22: NG=3;
    break;
    case 23: NG=4;
    break;
    case 24: NG=5;
    break;
    default: NG=6;

    }
return NG;
}



void cargarAleatorio(int v[], int tam, int limite){
  int i;
  srand(time(NULL));
  for( i=0; i<tam; i++ ){
        v[i]=(rand()%limite)+1;
  }
}



int tiroPuntaje(int d[],int NG ){
int i=0,c=0;
    for (i=0;i<5;i++){
        if (d[i]==NG){
            c++;
        }
    }
    return c;
}



int mayorP2(int p1,int p2,char n1[],char n2[]){ /// devuelve el ganador de los dos jugadores en la partida
  int mayor=0;
    if (p1>p2){
        mayor=p1;
        cout<< "EL GANADOR ES : "<<"\t"<<n1<<"\t"<< " CON : "<<mayor<<endl;
    }
        else if(p2>p1){
            mayor=p2;
            cout<< "EL GANADOR ES : "<<"\t"<<n2<<"\t" "CON : "<<mayor<<endl;
        }
        else{
         cout<<endl;
         cout<< "HA OCURRIDO UN EMPATE ";
         cout<<endl;
         cout<< "JUEGAN UNA NUEVA PARTIDA PARA DETERMINAR EL GANADOR:";
         system("pause");
         system("cls");
         mayor =-1;
        }
return mayor;
}


int puntoSimulado(char NOMBRE[],int APUESTA,int RONDA){
    int dadoManual[5]={};
    int i=0,x=0,puntajesimulado=0,vueltas=0,TOTALRONDA=0,C=0;
    int CuentaCeros=0,cuentaPerdida=0;
     system("cls");
        while(x!=RONDA) {
            Visual (NOMBRE,RONDA,x,puntajesimulado,APUESTA,vueltas);
            cout<<endl;
            cargaDadosManual(dadoManual);
            system("pause");
            system("cls");
            muestraDadosManual(dadoManual);
            system("pause");
            system("cls");
            TOTALRONDA=SumaDadosXronda(dadoManual);
     if (TOTALRONDA>=20){
     int dadox[5]{0},NG=0;
        NG=NumeroGenerador (TOTALRONDA);
        cout<<"------------------------------------------------------------------------"<<endl;
        cout<<endl;
        cout<<"FELICIDADES TU PUNTAJE ES !!!! : "<< TOTALRONDA<<" POR ENDE TU NUMERO GENERADOR ES: "<<NG<<endl;
        cout<<endl;
        cout<<"************************************************************************"<<endl;
        cout<<endl;
        cout<< "TIRO PUNTAJE: ";
        system("pause");
        system("cls");
        cout<<"-------------------------------------------------------------"<<endl;
        cout<< "VALORES DEL TIRO DE PUNTAJE: "<<endl;
        DadosAzar (dadox,0);
        system("pause");
        C=tiroPuntaje(dadox,NG);
        cout<<"*************************************************************"<<endl;
        cout<<endl;
        cout<< "NUMERO GENERADOR DE ESTA RONDA :"<<NG<<endl;
        cout<<endl;
        cout<< "CANTIDAD DE VECES QUE SE REPITE TU NUMERO GENERADOR: "<<C<<endl;
        cout<<endl;
        system("pause");

        cout<<"-------------------------------------------------------------------------------"<<endl;
            if (C==0){
                    CuentaCeros++;
                    puntajesimulado=puntajesimulado;
                    cout<<endl;
                cout<< "TU NUMERO GENERADOR NO SE REPITE, NO SUMA PUNTOS ESTA RONDA,SU PUNTAJE ES: "<<puntajesimulado<<endl;
            }
               else {
                 puntajesimulado+=(APUESTA*C);
            }
        }
        else {
            cuentaPerdida++;
            puntajesimulado=puntajesimulado-APUESTA;
        }
            x++;
            system("cls");
            }
         Visual2(NOMBRE,cuentaPerdida,CuentaCeros,puntajesimulado);
         system("pause");
        }


void cargaDadosManual(int vDados[]){
int i=0;
    while (i<5){
     cout<< "INGRESE UN VALOR PARA EL DADO :"<<i+1<<" : ";
     cin>>vDados[i];
        if (vDados[i]<0||vDados[i]>6){
        cout<<endl;
        cout<< "HA INGRESADO UN VALOR INCORRECTO PARA EL DADO"<<i+1<<endl;
        cout<<endl;
        system("pause");
        system("cls");
        cout<<"INGRESE UN VALOR DEL 1 AL 6 :";
        }
        else {
            i++;
        }
         cout<<endl;
    }
}

void muestraDadosManual(int vDados[]){
int i=0;
     for (i=0;i<5;i++){
        cout<< "VALOR ELEJIDO PARA EL DADO : "<<i+1<<" :"<<vDados[i]<<endl;
        cout<<endl;

    }
}
#endif  FUNCIONES_H_INCLUDED


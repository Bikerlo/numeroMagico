#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <math.h>

using namespace std;

int numeroMaquina=0,numeroUsuario=0,distancia=0;
int contadorIntentos=0;
int variable=20;
int opcion=0;
int intentosTotales=0;

void juego(){
    system("cls");
    system("COLOR B");
    cout<<"Digite un numero: ";
    cin>>numeroUsuario;

    distancia=fabs(numeroMaquina-numeroUsuario);

    if(distancia<2 && distancia!=0)cout<<"Caliente...";
    else if(distancia<=5 && distancia!=0)cout<<"Tibio...";
    else if(distancia!=0) cout<<"Frio...";
    contadorIntentos++;
    Beep(500,100);
    if(distancia!=0)Sleep(2000);
}

void menu(){
    cout<<"1.Modificar Rango\n";
    cout<<"2.Iniciar Juego\n";
    cout<<"3.Salir\n";
    cin>>opcion;
        switch(opcion){
            case 1:
                cout<<"digite el rango: ";
                cin>>variable;
                numeroMaquina=(rand())%variable+1;
            break;
            case 2:
                numeroMaquina=(rand())%variable+1;
                contadorIntentos=0;
                do{juego();}while(numeroMaquina!=numeroUsuario);
                cout<<"Felicidades hallaste el numero"<<endl;
                cout<<"en "<<contadorIntentos<<" intentos"<<endl;
                intentosTotales=intentosTotales+contadorIntentos;
            break;
            case 3:
                cout<<"bye bye sayonara..."<<endl;
            break;
        }
}

int main(){
    srand(time(NULL));
    numeroMaquina=(rand())%variable+1;
    do{
        menu();
    }while(opcion!=3);
    return 0;
}

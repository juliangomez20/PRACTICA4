#include <iostream>
#include "red.h"
#include "enrutador.h"
#include<map>

using namespace std;

int main()
{
    int opc=0;
    Red redbase;



    do{

        cout<<"MENU."<<endl;
        cout<<"1.Para crear los enrutadores de la red "<<endl;
        cout<<"2.Para crear las conexiones de los enrutadores "<<endl;
        cout<<"3.Para eliminar un enrutador "<<endl;
        cout<<"4.Para conocer las conexiones de un enrutador "<<endl;
        cout<<"5.Para conocer la red completa"<<endl;
        cout<<"0.Para salir "<<endl;
        cout<<"Ingrese la opcion que desea: ";
        cin>>opc;

        switch (opc) {
        case 1:
            system("clear");
        redbase.agregarNodo();
            break;
        case 2:
            system("clear");
            redbase.agregarconexion();
            break;
        case 3:
            system("clear");
            redbase.eliminarEnrutador();
            break;
        case 4:
            system("clear");
            redbase.imprimirconexiones();
            break;
        case 0:
            break;
        default:
            cout<<"Ingrese una opcion valida"<<endl;
            break;
        }

    }while(opc);





    return 0;
}

#include "red.h"


Red::Red()
{

}

void Red::agregarNodo()
{
    cout<<"Ingrese el numero de enrutadores que va tener la red: ";
    cin>>num;
    for(int i=0; i<num; i++){
        cout<<"Ingrese el nombre para el enrutador "<<i+1<<": ";
        cin>>this->nombre;
        nombre2=this->nombre;
        Enrutador nombre (nombre2);
        red[nombre2]=nombre;
        cin.ignore();
    }
}

void Red::agregarconexion()
{
    cout<<"Ingrese el nombre del enrutador para agregar conexiones: ";
    cin>>nombre2;
    cout<<"Ingrese el numero de conexiones que desea agregar: ";
    cin>>num;

    for(int i=0; i<num;){
        if(ban){cout<<"El enrutador "<<nombre<<" no fue creado, por favor ingrese un enrutador valido."<<endl;}
        ban=true;

        cout<<"Ingrese el nombre de la conexion "<<i+1<<": ";
        cin>>nombre;


        for (it=red.begin(); it!=red.end(); it++){  //si el enrutador no esta en la red no lo agrega y pide nuevamente un nombre
            if(it->first==nombre){
                cout<<"Ingrese el costo de la conexion: ";
                cin>>costo;
                red[nombre2].agregarNodo(&(red[nombre]),costo);
                red[nombre2].crearTabla();
                i++;
                ban=false;
                break;
            }

        }

    }
}

void Red::eliminarEnrutador()
{
    cout<<"Ingrese el nombre del enrutador que desea eliminar: ";
    cin>>nombre;
    red[nombre].~Enrutador();
}
void Red::imprimirconexiones()
{
    cout<<"Ingrese el nombre del enrutador para mostrar sus conexiones: ";
    cin>>nombre;
    red[nombre].crearTabla();
    red[nombre].imprimirNodos();
    cout<<endl<<endl;
    red[nombre].imprimirNodosAccesibles();

}
void Red::imprimirRed()
{

}



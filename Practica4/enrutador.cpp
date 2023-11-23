#include "enrutador.h"

Enrutador::Enrutador()
{

}

Enrutador::Enrutador(string nombre)
{
    cout << "Enrutador " << nombre << " creado." << endl;
    this->nombreNodo = nombre;
}


void Enrutador::agregarNodo(Enrutador* nodo, int costo)
{
    this->listaDeNodos.push_back(nodo);
    this->listaCostos.push_back(costo);
}

void Enrutador::imprimirNodos()
{
    cout << "Las conexiones directas de " << this->nombreNodo << " son: "<< endl;
    for(int i=0; i < this->listaDeNodos.size() ; i++){
        cout << "  - " << this->listaDeNodos[i]->nombreNodo << " con costo: " << this->listaCostos[i] << endl;
    }
}

void Enrutador::crearTabla()
{
    this->MirarVecinos(this, 0);
}

void Enrutador::MirarVecinos(Enrutador* nodo, int costo)
{
    for(int i=0; i < nodo->listaDeNodos.size() ; i++){
        if(!nodoYaEstaAgregado(nodo->listaDeNodos[i]) && !(nodo->listaDeNodos[i] == this)){
            this->headerTabla.push_back(nodo->listaDeNodos[i]);
            this->tablaEnrutamiento.push_back(costo + nodo->listaCostos[i]);
            MirarVecinos(listaDeNodos[i], nodo->listaCostos[i]);
        }
    }
}

bool Enrutador::nodoYaEstaAgregado(Enrutador *nodo)
{
    bool flag = false;
    for(int i=0; i < this->headerTabla.size() ; i++){
        if(this->headerTabla[i] == nodo){
            flag = true;
        }
    }
    return flag;
}

void Enrutador::imprimirNodosAccesibles()
{
    cout << "Al enrutador " << this->nombreNodo << " estan conectados los enrutadores"<< endl;
    for(int i=0; i < this->headerTabla.size() ; i++){
        cout << "  - " << this->headerTabla[i]->nombreNodo << " costo: "<< this->tablaEnrutamiento[i] << endl;
    }
}






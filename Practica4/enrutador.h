#ifndef ENRUTADORES_H
#define ENRUTADORES_H
#include <iostream>
#include <vector>

using namespace std;

class Enrutador
{
public:
    Enrutador();
    Enrutador(string nombre);
    string nombreNodo;
    vector<Enrutador*> listaDeNodos;
    vector<int> listaCostos;
    vector<int> tablaEnrutamiento;
    vector<Enrutador*> headerTabla;


    // Métodos
    void agregarNodo(Enrutador* nodo, int costo);
    void imprimirNodos();
    void crearTabla();

    void MirarVecinos(Enrutador* nodo, int costo);
    bool nodoYaEstaAgregado(Enrutador* nodo);

    void imprimirNodosAccesibles();
};




#endif // ENRUTADORES_H

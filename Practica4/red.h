#ifndef RED_H
#define RED_H
#include "enrutador.h"
#include <iostream>
#include<map>

using namespace std;


class Red
{
private:
    int num,costo=0;
    bool ban=false;
    map<string,Enrutador> red;
    string nombre,nombre2,conexion;
    map<string,Enrutador>::iterator it;
public:
    Red();
    void agregarNodo();
    void agregarconexion();
    void eliminarEnrutador();
    void imprimirconexiones();
    void imprimirRed();

};

#endif // RED_H

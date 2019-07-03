//
// Created by ruben on 6/10/19.
//

#ifndef AGREGACION_OBJETO_H
#define AGREGACION_OBJETO_H


#include <iostream>
#include "Tipos.h"

using namespace std;

class Objeto {
private:
public:
    string        nombre;
    TipoCaracter  color;
    TipoEntero    posX;
    TipoEntero    posY;
    TipoCaracter  tipo;
    TipoEntero calificacion;
    Objeto();
    Objeto(const TipoString& nombre,TipoCaracter tipo, TipoCaracter color,
           TipoEntero posX, TipoEntero posY, TipoEntero& calificacion);
    virtual ~Objeto();
    void setNombre(const TipoString& nombre);
    string     getNombre();
    TipoEntero getPosX();
    TipoEntero getPosY();
    char getTipo();
    TipoEntero getCalificacion();
    char getColor();
    void moverse(TipoEntero x, TipoEntero y);
    string mostrarPosicion();
};
#endif //AGREGACION_OBJETO_H

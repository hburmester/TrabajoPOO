//
// Created by ruben on 6/10/19.
//

#include "Objeto.h"

Objeto::Objeto(): color{}, tipo{}, posX{}, posY{} {}

Objeto::Objeto(const TipoString& nombre,TipoCaracter tipo, TipoCaracter color, TipoEntero posX, TipoEntero posY, TipoEntero& calificacion):
nombre{nombre},tipo{tipo}, color{color},  posX{posX}, posY{posY}, calificacion{calificacion} {}

Objeto::~Objeto() {}

void Objeto::setNombre(const TipoString& nombre) { this->nombre = nombre; }

void Objeto::moverse(TipoEntero x, TipoEntero y) {posX=x,posY=y;}

TipoString   Objeto::getNombre() { return nombre; }
TipoEntero   Objeto::getPosX()   { return posX; }
TipoEntero   Objeto::getPosY()   { return posY; }
TipoCaracter Objeto::getColor()  { return color; }
TipoEntero   Objeto::getCalificacion() {return calificacion;}
TipoCaracter Objeto::getTipo() {return tipo;}
TipoString Objeto::mostrarPosicion() {
    return "X= " + to_string(posX) + " Y= " + to_string(posY);
}






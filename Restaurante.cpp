//
//  Restaurante.cpp
//  prueba1
//
//  Created by Wolker Burmester on 6/29/19.
//  Copyright © 2019 Wolker Burmester. All rights reserved.
//

#include "Restaurante.hpp"

Restaurante::Restaurante(): especialDelDia{}, tipoDeComida{} {}

Restaurante::Restaurante(const TipoString& nombre, TipoCaracter tipo, TipoCaracter& color, TipoEntero& posX, TipoEntero& posY,TipoEntero& calificacion, TipoString& especialDelDia, TipoString& tipoDeComida):  especialDelDia{especialDelDia}, tipoDeComida{tipoDeComida}, Objeto(nombre,tipo,color,posX,posY,calificacion) {}


void Restaurante::setEspecialDelDia(TipoString &especialDelDia) { 
    this->especialDelDia=especialDelDia;}

TipoString Restaurante::getEspecialDelDia() {
    return especialDelDia;}

TipoString Restaurante::getTipoDeComida(){return tipoDeComida;}


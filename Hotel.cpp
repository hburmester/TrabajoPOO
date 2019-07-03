//
//  Hotel.cpp
//  prueba1
//
//  Created by Wolker Burmester on 6/30/19.
//  Copyright © 2019 Wolker Burmester. All rights reserved.
//

#include "Hotel.hpp"

Hotel::Hotel(): estrellas{}, disponibilidad{}, Objeto{} {}

Hotel::Hotel(const TipoString& nombre, TipoCaracter tipo, TipoCaracter& color, TipoEntero& posX, TipoEntero& posY, TipoEntero& calificacion, TipoEntero& estrellas, TipoBool& disponibilidad): estrellas{estrellas}, disponibilidad{disponibilidad}, Objeto(nombre,tipo,color,posX,posY,calificacion) {}

void Hotel::setDisponibilidad(TipoBool& disponibilidad) {
    this->estrellas=disponibilidad;}

TipoEntero Hotel::getEstrellas() {return estrellas;}
TipoBool Hotel::getDisponibilidad() {return disponibilidad;}



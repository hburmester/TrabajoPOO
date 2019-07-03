//
//  Museo.cpp
//  prueba1
//
//  Created by Wolker Burmester on 6/30/19.
//  Copyright © 2019 Wolker Burmester. All rights reserved.
//

#include "Museo.hpp"

Museo::Museo(): exposicionActual{}, Objeto{} {}

Museo::Museo(const TipoString& nombre, TipoCaracter tipo, TipoCaracter& color, TipoEntero& posX, TipoEntero& posY, TipoEntero& calificacion, TipoString& exposicionActual): exposicionActual{exposicionActual}, Objeto(nombre,tipo,color,posX,posY,calificacion) {}

void Museo::setExposicionActual(TipoString& exposicionActual) {
    this->exposicionActual=exposicionActual;
}
TipoString Museo::getExposicionActual() {return exposicionActual;}


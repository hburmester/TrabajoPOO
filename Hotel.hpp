//
//  Hotel.hpp
//  prueba1
//
//  Created by Wolker Burmester on 6/30/19.
//  Copyright © 2019 Wolker Burmester. All rights reserved.
//

#ifndef Hotel_hpp
#define Hotel_hpp

#include <stdio.h>
#include "Objeto.h"
class Hotel : public Objeto{
public:
    TipoEntero estrellas;
    TipoBool disponibilidad;
    Hotel();
    Hotel(const TipoString& nombre, TipoCaracter tipo, TipoCaracter& color, TipoEntero& posX, TipoEntero& posY, TipoEntero& calificacion, TipoEntero& estrellas, TipoBool& disponibilidad);
    
    void setDisponibilidad(TipoBool& disponibilidad);
    TipoEntero getEstrellas();
    TipoBool getDisponibilidad();
};
#endif /* Hotel_hpp */

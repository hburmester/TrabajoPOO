//
//  Restaurante.hpp
//  prueba1
//
//  Created by Wolker Burmester on 6/29/19.
//  Copyright © 2019 Wolker Burmester. All rights reserved.
//

#ifndef Restaurante_hpp
#define Restaurante_hpp

#include <stdio.h>
#include "Objeto.h"

class Restaurante : public Objeto{
public:
    TipoString especialDelDia;
    TipoString tipoDeComida;
    Restaurante();
    Restaurante(const TipoString& nombre, TipoCaracter tipo, TipoCaracter& color, TipoEntero& posX, TipoEntero& posY, TipoEntero& calificacion, TipoString& especialDelDia, TipoString& tipoDeComida);

    void setEspecialDelDia(TipoString& especialDelDia);
    TipoString getEspecialDelDia();
    TipoString getTipoDeComida();
};

    

#endif /* Restaurante_hpp */

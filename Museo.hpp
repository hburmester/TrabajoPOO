//
//  Museo.hpp
//  prueba1
//
//  Created by Wolker Burmester on 6/30/19.
//  Copyright © 2019 Wolker Burmester. All rights reserved.
//

#ifndef Museo_hpp
#define Museo_hpp

#include <stdio.h>
#include "Objeto.h"
class Museo : public Objeto{
public:
    TipoString exposicionActual;
    Museo();
    Museo(const TipoString& nombre, TipoCaracter tipo, TipoCaracter& color, TipoEntero& posX, TipoEntero& posY, TipoEntero& calificacion, TipoString& exposicionActual);
    
    void setExposicionActual(TipoString& exposicionActual);
    TipoString getExposicionActual();
};
#endif /* Museo_hpp */

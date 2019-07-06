//
// Created by utec on 21/06/19.
//

#ifndef GAME_TIERRA_H
#define GAME_TIERRA_H

#include <iostream>
#include <vector>
#include "Tipos.h"
#include "Objeto.h"
#include <SFML/Graphics.hpp>
#include "Restaurante.hpp"
#include "Museo.hpp"
#include "Hotel.hpp"

using namespace std;

// Valores constantes
const TipoEntero ALTURA = 21;
const TipoEntero ANCHO  = 21;
const TipoCaracter COLOR ='.';

class Tierra {
private:
    int altura;
    int ancho;
    sf::RenderWindow* plano;
    vector<Objeto*> objetos;
    void capturarEventos();
public:
    Tierra();
    Tierra(TipoEntero altura, TipoEntero ancho);
    virtual ~Tierra();
    void actualizarTierra();
    void adicionarObjeto(Objeto* objeto);
    Objeto* editarObjeto(string& nombre);
    Objeto* removerObjeto(string& nombre);
    void imprimirObjetos();
    TipoEntero getAltura();
    TipoEntero getAncho();
    TipoEntero getCantidadObjetos();
    void dibujarTierra();
    void ubicarObjetos(Objeto* nombre);
    Objeto* buscarObjeto(string& nombre);
    Objeto* buscarTipo(TipoCaracter& tipo);
    void get3mejoresTipo(TipoCaracter tipoBuscar);
    void get3mejoresTotal();
    TipoString comprobarNombre(TipoString nombre);
    double cantidadObjetosClase(TipoCaracter& tipo);
    void moverObjeto(TipoString& nombre, TipoEntero& nuevaX, TipoEntero& nuevaY);
};

#endif //AGREGACION_TIERRA_H

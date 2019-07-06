//
// Created by utec on 21/06/19.
//

#ifndef GAME_CONTROLADOR_H
#define GAME_CONTROLADOR_H

#include <limits>
#include "Tipos.h"
#include "Tierra.h"

template <typename T>
T input(string label) {
    T value;
    cout << label;
    cin >> value;
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    return value;
}

/*
 //--- Esta seria la funcion para leer un string,
 //--- esta funcion si se quiere generalizar para colocar un label
 //--- y leer cualquier tipo de dato se tendria que convertir al template anterior
 
 string&& input(string label) {
 string value;
 cout << label;
 cin >> value;
 return move(value);
 }
 */


class Menu {
    TipoEntero opcion;
    Tierra tierra;
    void mostrarMenu();
    void seleccionarOpcion();
    void agregarObjeto();
    void removerObjeto();
    void dibujarMapa();
    void listarObjetos();
    void editarObjeto();
    void ubicarCercania();
    void calificar3Mejores();
    void calificar3DeMejorClase();
    bool verificarCantidad();
    void moverObjeto();
public:
    Menu(int largo, int altura);
    void ejecutar();
};
#endif //GAME_CONTROLADOR_H


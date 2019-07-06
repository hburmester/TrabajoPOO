//
// Created by utec on 21/06/19.
//

#include "Menu.h"
#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

enum class Opciones {Agregar=1, Remover, Mover, Mostrar, Listar, Editar, Ubicar, MejoresTotal, MejoresTipo};


void limpiar() {
    cout << "";
}

void esperar() {
    char w;
    do {
        w = input<TipoCaracter>("Presione C y Enter para continuar...");
    }while (toupper(w) != 'C');
}

Menu::Menu(int altura, int ancho): tierra(altura, ancho), opcion{} {}

void Menu::mostrarMenu() {
    limpiar();
    cout << "MENU\n";
    cout << string(4, '-') << "\n\n";
    cout << "1. Agregar un nuevo objeto\n";
    cout << "2. Remover Objeto\n";
    cout << "3. Mover Objeto\n";
    cout << "4. Dibujar Mapa\n";
    cout << "5. Mostrar Objetos\n";
    cout << "6. Editar Objetos\n";
    cout << "7. Ubicar 3 objetos cercanos\n";
    cout << "8. Mostrar top 3 total\n";
    cout << "9. Mostrar top 3 un tipo\n";
    cout << "0. Para Salir\n\n";
}


void Menu::agregarObjeto() {
    auto i = 1;
    while (i==1){
    auto tipo = input<TipoCaracter>("Ingrese caracter de objeto (R=Restaurante, H=Hotel, M=Museo): ");
    if (tipo == 'R'){
        auto tipo = 'R';
        auto nombre = input<TipoString>("Ingrese Nombre : ");
        auto color  = input<TipoCaracter>("Ingrese color (Un caracter): ");
        auto x = input<TipoEntero>("Ingrese posicion X : ");
        while (x < 0 || x >= 800) {
            cout << "Posicion X Incorrecta, los limites son: 0, "
            << 800 - 1 << "\n";
            x = input<TipoEntero>("Ingrese posicion X : ");
        }
        auto y = input<TipoEntero>("Ingrese posicion Y : ");
        while (y < 0 || y >= 1200) {
            cout  << "Posicion Y Incorrecta, los limites son: 0, "
            << 1200 - 1 << "\n";
            y = input<TipoEntero>("Ingrese posicion Y : ");
        }
        auto especial = input<TipoString>("Ingrese especial del dia: ");
        auto tipoComida = input<TipoString>("Ingrese tipo de comida: ");
        auto calificacion = input<TipoEntero>("Ingrese calificacion de Restaurante(0-10): ");
        while (calificacion < 0 || calificacion >= 11) {
            cout << "Calificacion incorrecta, de 0-10\n";
            calificacion = input<TipoEntero>("Ingrese calificacion de Restaurante: ");
        }
        cout<<"\n";
        tierra.adicionarObjeto(new Restaurante(nombre, tipo, color, x, y,calificacion, especial, tipoComida));
        
        i = 0;
    } else if (tipo=='M'){
        auto tipo = 'M';
        auto nombre = input<TipoString>("Ingrese Nombre : ");
        auto color  = input<TipoCaracter>("Ingrese color (Un caracter): ");
        auto x = input<TipoEntero>("Ingrese posicion X : ");
        while (x < 0 || x >= 800) {
            cout << "Posicion X Incorrecta, los limites son: 0, "
            << 800 - 1 << "\n";
            x = input<TipoEntero>("Ingrese posicion X : ");
        }
        auto y = input<TipoEntero>("Ingrese posicion Y : ");
        while (y < 0 || y >= 1200) {
            cout  << "Posicion Y Incorrecta, los limites son: 0, "
            << 1200 - 1 << "\n";
            y = input<TipoEntero>("Ingrese posicion Y : ");
        }
        auto exposicion = input<TipoString>("Ingrese exposicion hoy: ");
        auto calificacion = input<TipoEntero>("Ingrese calificacion de Museo(1-10): ");
        while (calificacion < 0 || calificacion >= 11) {
            cout << "Calificacion incorrecta, de 0-10\n";
            calificacion = input<TipoEntero>("Ingrese calificacion de Museo: ");
        }
        cout<<"\n";
        tierra.adicionarObjeto(new Museo(nombre,tipo,color,x,y,calificacion, exposicion));
        i = 0 ;
    } else if (tipo=='H'){
        auto tipo = 'H';
        auto nombre = input<TipoString>("Ingrese Nombre : ");
        auto color  = input<TipoCaracter>("Ingrese color (Un caracter): ");
        auto x = input<TipoEntero>("Ingrese posicion X : ");
        while (x < 0 || x >= 800) {
            cout << "Posicion X Incorrecta, los limites son: 0, "
            << 800 - 1 << "\n";
            x = input<TipoEntero>("Ingrese posicion X : ");
        }
        auto y = input<TipoEntero>("Ingrese posicion Y : ");
        while (y < 0 || y >= 1200) {
            cout  << "Posicion Y Incorrecta, los limites son: 0, "
            << 1200 - 1 << "\n";
            y = input<TipoEntero>("Ingrese posicion Y : ");
        }
        auto estrellas = input<TipoEntero>("Numero de estrellas: ");
        while (estrellas < 1 || estrellas > 5){
            cout << "Numero de estrellas incorrecto, de 1-5: \n";
            estrellas = input<TipoEntero>("Ingrese calificacion de Hotel: ");
        }
        auto disponibilidad = input<TipoBool>("Disponibilidad (true,false): ");
        auto calificacion = input<TipoEntero>("Ingrese calificacion de Hotel(1-10): ");
        while (calificacion < 0 || calificacion >= 11) {
            cout << "Calificacion incorrecta, de 0-10\n";
            calificacion = input<TipoEntero>("Ingrese calificacion de Hotel: ");
        }
        cout<<"\n";
        tierra.adicionarObjeto(new Hotel(nombre,tipo,color,x,y,calificacion,estrellas,disponibilidad));
            i = 0;
        } else {
        cout << "Tipo de objeto invalido\n";
        auto i = 0;
    }
    }
}

void Menu::removerObjeto() {
    limpiar();
    tierra.imprimirObjetos();
    auto nombre = input<TipoString>("Ingrese Nombre: ");
    auto condicion = input<TipoString>("Ingrese cancelar para salir o ingrese continuar: ");
    if (condicion == "continuar"){
    Objeto* obj = tierra.removerObjeto(nombre);
        if (obj == nullptr) {
            cout << "Objeto No existe\n";}
        else{
            delete obj;
            cout << "Objeto: " << nombre << " ha sido removido\n";
        }
    }
    else if (condicion == "cancelar") {
        ;
    }
    esperar();
}
void Menu::editarObjeto(){
    limpiar();
    tierra.imprimirObjetos();
    auto nombre = input<TipoString>("Ingrese nombre de objeto a editar: ");
    auto tipo = input<TipoCaracter>("Ingrese caracter de lo que desea editar(R=restaurante, M=museo, H= hotel): ");
    Objeto* obj = tierra.editarObjeto(nombre);
    if (obj == nullptr) {
        cout << "Objeto No existe\n";
    }
    else {
        auto nombreTemp = obj->getNombre();
        auto colorTemp = obj->getColor();
        auto posXTemp = obj->getPosX();
        auto posYTemp = obj->getPosY();
        auto tipoTemp = obj ->getTipo();
        auto calificacionTemp = obj->getCalificacion();
        if (tipo == 'R'){
            cout << "Nombre: "<<obj->getNombre()<<"\n";
            cout << "Color: "<<obj->getColor()<<"\n";
            cout << "Pos X: "<<obj->getPosX()<<"\n";
            cout << "Pos Y: "<<obj->getPosY()<<"\n";
            cout << "Tipo: "<<obj->getTipo()<<"\n";
            cout << "Calificacion: "<<obj->getCalificacion()<<"\n";
            auto especialTemp = input<TipoString>("Ingrese nuevo especial del dia: ");
            auto tipoDeComidaTemp = input<TipoString>("Ingrese tipo de comida, porfavor: ");
            Objeto* obj =tierra.removerObjeto(nombre);
            delete obj;
            tierra.adicionarObjeto(new Restaurante(nombreTemp,tipoTemp, colorTemp, posXTemp, posYTemp,calificacionTemp,especialTemp,tipoDeComidaTemp));
        }
        else if (tipo=='H'){
            cout << "Nombre: "<<obj->getNombre()<<"\n";
            cout << "Color: "<<obj->getColor()<<"\n";
            cout << "Pos X: "<<obj->getPosX()<<"\n";
            cout << "Pos Y: "<<obj->getPosY()<<"\n";
            cout << "Tipo: "<<obj->getTipo()<<"\n";
            cout << "Calificacion: "<<obj->getCalificacion()<<"\n";
            auto dispTemp = input<TipoBool>("Ingrese nueva disponibilidad: ");
            auto estrellasTemp = input<TipoEntero>("Ingrese cantidad de estrellas: ");
            Objeto* obj =tierra.removerObjeto(nombre);
            delete obj;
            tierra.adicionarObjeto(new Hotel(nombreTemp,tipoTemp,colorTemp,posXTemp,posYTemp,calificacionTemp,estrellasTemp,dispTemp));
        }
        else if (tipo=='M'){
            cout << "Nombre: "<<obj->getNombre()<<"\n";
            cout << "Color: "<<obj->getColor()<<"\n";
            cout << "Pos X: "<<obj->getPosX()<<"\n";
            cout << "Pos Y: "<<obj->getPosY()<<"\n";
            cout << "Tipo: "<<obj->getTipo()<<"\n";
            cout << "Calificacion: "<<obj->getCalificacion()<<"\n";
            auto expoTemp = input<TipoString>("Ingrese exposicion nueva: ");
            Objeto* obj =tierra.removerObjeto(nombre);
            delete obj;
            tierra.adicionarObjeto(new Museo(nombreTemp,tipoTemp,colorTemp,posXTemp,posYTemp,calificacionTemp, expoTemp));
        }
    }
    esperar();
}

void Menu::dibujarMapa() {
    limpiar();
    tierra.actualizarTierra();
    tierra.dibujarTierra();
    cout << '\n';
    esperar();
}
void Menu::listarObjetos(){
    limpiar();
    tierra.imprimirObjetos();
    cout << '\n';
    esperar();
}

void Menu::ejecutar() {
    do {
        mostrarMenu();
        cin >> opcion;
        seleccionarOpcion();
    } while (opcion != 0);
    cout << "Fin del programa...\n";
}

void Menu::seleccionarOpcion() {
    limpiar();
    switch(Opciones(opcion)) {
        case Opciones::Agregar:  // Agregar Objeto
            agregarObjeto();
            break;
        case Opciones::Remover:  // Remover Objeto
            removerObjeto();
            break;
        case  Opciones::Mover: // Dibujando Tierra
            moverObjeto();
            break;
        case  Opciones::Mostrar: // Dibujando Tierra
            dibujarMapa();
            break;
        case Opciones::Listar: // Listar todos los objetos
            listarObjetos();
            break;
        case Opciones::Editar:
            editarObjeto();
            break;
        case Opciones::Ubicar:
            ubicarCercania();
            break;
        case Opciones::MejoresTotal:
            calificar3Mejores();
            break;
        case Opciones::MejoresTipo:
            calificar3DeMejorClase();
            break;
    }
}
void Menu::ubicarCercania(){
    limpiar();
    tierra.imprimirObjetos();
    auto nombre = input<TipoString>("Ingrese nombre de objeto para ubicar 3 cercanos: ");
    auto si = tierra.buscarObjeto(nombre);
    if (si == nullptr){
        esperar();
    }else
    {tierra.ubicarObjetos(si);}
    esperar();
}


void Menu::calificar3DeMejorClase(){
    limpiar();
    auto tipo = input<TipoCaracter>("Seleccione tipo de mejores locales a buscar(R = restaurante, M = Museo, H = Hotel): ");
    if (tierra.getCantidadObjetos()<4){
        if (tierra.cantidadObjetosClase(tipo)<3){
            cout<<"Necesita 3 o mas objetos de la misma clase para utilizar esta funcion";
            esperar();
        }
    }else{
       auto tipoBuscar = tipo;
    auto si = tierra.buscarTipo(tipoBuscar);
        if (si == nullptr){
            esperar();
        } else{
            tierra.get3mejoresTipo(tipoBuscar);
        }
    }
    esperar();
}
    
void Menu::calificar3Mejores(){
    limpiar();
    if (tierra.getCantidadObjetos()<4){
        cout<<"Necesita 3 o mas objetos para utilizar esta funcion";
        esperar();
    } else{
        tierra.get3mejoresTotal();
        esperar();
    }
}

void Menu::moverObjeto(){
    limpiar();
    tierra.imprimirObjetos();
    auto nombre = input<TipoString>("Ingrese nombre de objeto a mover: ");
    auto nuevaX = input<TipoEntero>("Ingrese nueva posicion en X: ");
    auto nuevaY = input<TipoEntero>("Ingrese nueva posicion en Y:");
    tierra.moverObjeto(nombre, nuevaX, nuevaY);
    cout << nombre << "movido a " << nuevaX << ", " << nuevaY<<"\n";
    esperar();
}

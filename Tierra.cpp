//
// Created by utec on 21/06/19.
//
#include <string>
#include <iomanip>
#include <map>
#include <algorithm>
#include "Objeto.h"
#include "Tierra.h"
#include <cmath>
#include <random>

std::random_device rd;
auto a = 24;
auto b = 160+rd()%(236-160);
auto c = 137+rd()%(236-137);

sf::Color color1(a,b,c);
map<char, sf::Color> listaColores = {
        {'R', sf::Color::Red},
        {'G', sf::Color::Green},
        {'B', sf::Color::Blue},
        {'Y', sf::Color::Yellow},
        {'W', sf::Color::White},
        {'C', sf::Color::Cyan},
        {'M', sf::Color::Magenta},
        {'O', color1},
};

using namespace std;

Tierra::Tierra() : altura{}, ancho{} {
    plano = nullptr;
}

Tierra::Tierra(TipoEntero altura, TipoEntero ancho) : altura{altura}, ancho{ancho} {
    plano = new sf::RenderWindow();
}

Tierra::~Tierra() {
    delete plano;
}

void Tierra::adicionarObjeto(Objeto* objeto) {
    objetos.emplace_back(objeto);
}

Objeto *Tierra::removerObjeto(string &nombre) {
// Si vector esta vacio
    if (objetos.size() == 0)
        return nullptr;
// Buscando objeto
    auto iter = find_if(begin(objetos), end(objetos),
                        [&nombre](Objeto *obj) { return obj->getNombre() == nombre; });
    if (iter != end(objetos)) {
// Eliminando la referencia al puntero objeto dentro del vector objetos
        objetos.erase(iter);
//-- si encuentra al objeto lo separa del vector,
//-- (no libera de memoria el objeto encontrado), esto se hará en el menú,
//-- donde fue asignado, debido a que el objeto no es parte sino el objeto es un visitante.
        return *iter;
    }
// Si vector esta vacio
    return nullptr;
}
Objeto* Tierra::editarObjeto(string& nombre){

    for (auto& item: objetos) {
        if (item->getNombre()==nombre){
            return item;
        } else if (objetos.size()==0){
            return nullptr;
        }
    }
}

Objeto* Tierra::buscarObjeto(string& nombre){
    if (objetos.size()<4){
        cout << "Deben de haber 4 o mas objetos\n\n";
        return nullptr;
    }
    if (objetos.size() == 0)
        return nullptr;
    
    auto iter = find_if(begin(objetos), end(objetos),
                        [&nombre](Objeto* obj){ return obj->getNombre() == nombre; });
    if (iter == end(objetos))
        return nullptr;
    return *iter;
}

double Tierra::cantidadObjetosClase(TipoCaracter& tipo){
    for (auto& item: objetos){
        auto i = 0;
        if (item->getTipo()==tipo){
            i += 1;
        }
        if (i<=2){
            return 0;
        } else{
            return i;
        }
    }
}
Objeto* Tierra::buscarTipo(TipoCaracter& tipo){
    if (objetos.size() <4)
        return nullptr;
    
        auto iter = find_if(begin(objetos), end(objetos),
                        [&tipo](Objeto* obj){ return obj->getTipo() == tipo; });
    
    if (iter == end(objetos))
        
        return nullptr;
    return *iter;
}

void Tierra::imprimirObjetos() {
    if (objetos.size()==0){
        return nullptr;
    } else{
    cout<< "\n";
    int i = 0;
    for (auto& item: objetos) {
        cout << "Objeto[" << i << "]\n";
        cout << "Nombre= " << item->getNombre() << "\n";
        cout << "Direccion: X=" << item->getPosX() << " Y="<< item->getPosY()<<"\n";
        cout << "Su calificacion: " << item->getCalificacion()<<"\n";
        cout << "Color= " << item->getColor() << "\n";
        if (item->getTipo()=='R'){
            cout<< "Bienvenido al Restaurante.\n\n";
        } else if (item->getTipo()=='H'){
            cout<< "Bienvenido al Hotel.\n\n";
        } else if (item->getTipo()=='M'){
            cout<< "Bienvenido al Museo\n\n";
        }
        i++;
        }
    }
}

void Tierra::actualizarTierra() {
    plano->clear();
    for (auto obj: objetos) {
        sf::CircleShape shape(10);
        shape.setPosition(obj->getPosX(), obj->getPosY());
        shape.setFillColor(listaColores[obj->getColor()]);
        plano->draw(shape);
    }
    plano->display();
}
void Tierra::dibujarTierra() {
    // Verifica si plano ha sido creado anteriormente
    if (!plano->isOpen())
        plano->create(sf::VideoMode(ancho, altura), "Proyecto Final - Presione [ESC] para salir... ");
    else
        plano->display();

    // Bucle principal
    while (plano->isOpen()) {
        capturarEventos();
        actualizarTierra();
    }
}

void Tierra::ubicarObjetos(Objeto* nombre){
    auto a = 0;
    string primerObjeto;
    auto b = 0;
    string segundoObjeto;
    auto c = 0;
    string tercerObjeto;
    auto xBuscado = nombre->getPosX();
    auto yBuscado = nombre->getPosY();
    int i=0;
    for (auto& item: objetos){
        auto lx = xBuscado - item->getPosX();
        auto ly = yBuscado - item->getPosY();
        auto l = sqrt((lx*lx) + (ly*ly));
        if (l == 0 || item->getNombre()==nombre->getNombre()){
            l = 0;
        } else if (a==0){
            a = l;
            primerObjeto = item->getNombre();
        } else if (b==0){
            b = l;
            segundoObjeto = item->getNombre();
        } else if (c==0){
            c = l;
            tercerObjeto = item->getNombre();
        } else if (l<a || l<b || l<c){
            if (a-l>b-l && a-l>c-l){
                a = l;
                primerObjeto = item->getNombre();
            } else if (b-l>a-l && b-l>c-l){
                b = l;
                segundoObjeto = item->getNombre();
            } else if (c-l>b-l && c-l>a-l){
                c = l;
                tercerObjeto = item->getNombre();
            }
        }
        i++;
    }
    cout << primerObjeto << " esta a: " << a << " de distancia\n";
    cout << segundoObjeto << " esta a: " << b << " de distancia\n";
    cout << tercerObjeto << " esta a: " << c << " de distancia\n\n";
}
void Tierra::get3mejoresTipo(TipoCaracter tipoBuscar){
    auto valorC1 = 0;
    auto valorC2 = 0;
    auto valorC3 = 0;
    Objeto* objeto1;
    Objeto* objeto2;
    Objeto* objeto3;
    for (auto& item: objetos) {
        if (item->getTipo()==tipoBuscar){
            auto evaluar = item->getCalificacion();
            if (valorC1 == 0){
                valorC1 = evaluar;
                objeto1 = item;
            } else if (valorC2==0){
                valorC2 = evaluar;
                objeto2 = item;
            } else if (valorC3==0){
                valorC3 = evaluar;
                objeto3 = item;
            } else if (evaluar>valorC1 || evaluar>valorC2 || evaluar>valorC3){
                if (valorC3<valorC2 && valorC3<valorC1){
                    valorC3 = evaluar;
                    objeto3 = item;
                } else if (valorC2<valorC3 && valorC2<valorC1){
                    valorC2 = evaluar;
                    objeto2 = item;
                } else if (valorC1<valorC2 && valorC1<valorC3){
                    valorC1 = evaluar;
                    objeto1 = item;
                }
            }
        }
    }
    cout << objeto1->getNombre() << " tiene una calificacion de " << valorC1 << "\n";
    cout << objeto2->getNombre() << " tiene una calificacion de " << valorC2 << "\n";
    cout << objeto3->getNombre() << " tiene una calificacion de: " << valorC3 << "\n\n";
}

void Tierra::get3mejoresTotal(){
    auto valorC1 = 0;
    auto valorC2 = 0;
    auto valorC3 = 0;
    Objeto* objeto1;
    Objeto* objeto2;
    Objeto* objeto3;
    for (auto& item: objetos) {
            auto evaluar = item->getCalificacion();
            if (valorC1 == 0){
                valorC1 = evaluar;
                objeto1 = item;
            } else if (valorC2==0){
                valorC2 = evaluar;
                objeto2 = item;
            } else if (valorC3==0){
                valorC3 = evaluar;
                objeto3 = item;
            } else if (evaluar>valorC1 || evaluar>valorC2 || evaluar>valorC3){
                if (valorC3<valorC2 && valorC3<valorC1){
                    valorC3 = evaluar;
                    objeto3 = item;
                } else if (valorC2<valorC3 && valorC2<valorC1){
                    valorC2 = evaluar;
                    objeto2 = item;
                } else if (valorC1<valorC2 && valorC1<valorC3){
                    valorC1 = evaluar;
                    objeto1 = item;
                }
            }
        }
    cout << objeto1->getNombre() << " tiene una calificacion de " << valorC1 <<" y es un";
    if(objeto1->getTipo()=='R'){
        cout<<" Restaurante\n";}
    else if(objeto1->getTipo()=='M'){
        cout<< " Museo\n";
        }
    else if(objeto1->getTipo()=='H'){
        cout<< " Hotel\n";
    }
    cout << objeto2->getNombre() << " tiene una calificacion de " << valorC2 << " y es un";
    if(objeto2->getTipo()=='R'){
        cout<<" Restaurante\n";}
    else if(objeto2->getTipo()=='M'){
        cout<< " Museo\n";
    }
    else if(objeto2->getTipo()=='H'){
        cout<< " Hotel\n";
    }
    cout << objeto3->getNombre() << " tiene una calificacion de " << valorC3 << " y es un";
    if(objeto3->getTipo()=='R'){
        cout<<" Restaurante\n";}
    else if(objeto3->getTipo()=='M'){
        cout<< " Museo\n";
    }
    else if(objeto3->getTipo()=='H'){
        cout<< " Hotel\n";
    }
    cout<<"\n";
}

TipoEntero Tierra::getAltura() {
    return altura;
}

TipoEntero Tierra::getAncho() {
    return ancho;
}

TipoEntero Tierra::getCantidadObjetos(){
    return objetos.size();
}

TipoString Tierra::comprobarNombre(TipoString nombre){
//    for (auto& item: objetos){
//        if (objetos.size()==0){
//            ;
//        } else {
//        auto prueba = item->getNombre();
//            if (prueba == nombre){;
//            return prueba+"(1)";
//            }
//            else{
//            return nombre;
//        }
//    }
//    }      POR MEJORAR
}

void Tierra::capturarEventos() {
    sf::Event event{};

    while (plano->pollEvent(event)) {

        switch (event.type) {
            case sf::Event::Closed:
                plano->close();
                break;
            case sf::Event::KeyPressed:
                if (event.key.code==sf::Keyboard::Escape)
                    plano->close();
                break;
            default:
                break;
        }
    }
}

void Tierra::moverObjeto(TipoString& nombre,TipoEntero& nuevaX,TipoEntero& nuevaY){
    Objeto* buscar;
    for (auto& item: objetos){
        if (item->getNombre()==nombre){
            buscar = item;
            break;
        }
    }
    buscar->moverse(nuevaX, nuevaY);
}


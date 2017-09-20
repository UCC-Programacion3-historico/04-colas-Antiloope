#ifndef COLAPRIORIDAD_H
#define COLAPRIORIDAD_H

#include <iostream>

template<class T>
class Nodo {
private:
    T dato;
    int prioridad;
    Nodo<T> *next;
public:
    Nodo(T dato, Nodo<T> *next, int prioridad) : dato(dato), next(next), prioridad(prioridad) {}

    Nodo(T dato, int prioridad) : dato(dato), prioridad(prioridad) {
        this->next = NULL;
    }

    int getPrioridad() {
        return prioridad;
    }

    void setPrioridad(int p) {
        prioridad = p;
    }

    T getDato() const {
        return dato;
    }

    void setDato(T dato) {
        Nodo::dato = dato;
    }

    Nodo<T> *getNext() const {
        return next;
    }

    void setNext(Nodo<T> *next) {
        Nodo::next = next;
    }

};


/**
 * Clase que implementa una Cola generica, ya que puede
 * almacenar cualquier tipo de dato T
 * @tparam T cualquier tipo de dato
 */
template<class T>
class Cola {
private:
    Nodo<T> *frente;

public:
    Cola();

    ~Cola();

    void encolar(T dato,int prioridad);

    T desencolar();

    bool esVacia();

    void vaciar();

    T verFrente();
};


/**
 * Constructor de la clase Cola
 * @tparam T
 */
template<class T>
Cola<T>::Cola() {
    frente = NULL;
}


/**
 * Destructor de la clase Cola, se encarga de liberar la memoria de todos los nodos
 * utilizados en la Cola
 * @tparam T
 */
template<class T>
Cola<T>::~Cola() {
    vaciar();
}


/**
 * Inserta un dato en la Cola
 * @tparam T
 * @param dato  dato a insertar
 */
template<class T>
void Cola<T>::encolar(T dato,int prioridad) {
    Nodo<T> *aux = new Nodo<T>(dato,prioridad);
    Nodo<T> *tmp = frente;

    if (frente == NULL) {
        frente = aux;
        return;
    }

    if (frente->getPrioridad() > aux->getPrioridad()) {
        aux->setNext(frente);
        frente = aux;
        return;
    }
    
    while (tmp->getNext() != NULL && tmp->getNext()->getPrioridad() <= tmp->getPrioridad()) {
        tmp = tmp->getNext();
    }

    aux->setNext(tmp->getNext());
    tmp->setNext(aux);
}


/**
 * Obtener el dato de la Cola
 * @tparam T
 * @return dato almacenado en el nodo
 */
template<class T>
T Cola<T>::desencolar() {

    if (esVacia())
        throw 1;

    // si no es vacia.
    T tmp;
    Nodo<T> *aux = frente;

    frente = frente->getNext();
    tmp = aux->getDato();
    delete aux;

    return tmp;
}

/**
 * Responde si la Cola se encuentra Vacía
 * @tparam T
 * @return
 */
template<class T>
bool Cola<T>::esVacia() {
    return frente == NULL;
}


/**
 * Vaciamos y liberamos memoria.
 */
template<class T>
void Cola<T>::vaciar() {

    while(frente != NULL)
        desencolar();

}


/**
 * Mostrar el dato del frente
 */
template<class T>
T Cola<T>::verFrente() {
    if(esVacia())
        throw 404;
    return frente->getDato();
}




#endif //COLAPRIORIDAD_H

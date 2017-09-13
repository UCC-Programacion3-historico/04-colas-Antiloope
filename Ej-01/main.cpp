#include <iostream>
#include "../Cola/Cola.h"

using namespace std;

bool comparar(Cola<char> *A,Cola<char> *B);

int main() {
    Cola<char> A,B;
    int c, salir=0;
    char t;
    do {
        do {
            cout << "Desea ingresar un valor a la lista o salir?" << '\n';
            cout << "  1)Ingresar en A\n  2)Ingresar en B\n  3)Salir" << '\n';
            cin >> c;
        } while(c>3 || c<1);
        switch (c) {
          case 1:
            cout << "Ingrese el caracter: ";
            cin >> t;
            A.encolar(t);
            break;
          case 2:
            cout << "Ingrese el caracter: ";
            cin >> t;
            B.encolar(t);
            break;
          case 3:
            salir = 1;
        }
    } while(salir == 0);

    salir = comparar(&A,&B);
    cout << salir << '\n';
    return 0;
}
bool comparar(Cola<char> *A,Cola<char> *B) {
    if (A->esVacia() && B->esVacia()) {
        return 1;
    }
    if ((!A->esVacia() && B->esVacia()) || (A->esVacia() && !B->esVacia())) {
        return 0;
    }
    if (A->desencolar() == B->desencolar()) {
        return comparar(A,B);
    }
    return 0;
}

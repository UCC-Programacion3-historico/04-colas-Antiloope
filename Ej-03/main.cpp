#include <iostream>
#include "colaPrioridad.h"

using namespace std;

int main() {
    Cola<int> A;
    int b,p;

    do {
        cout << "Ingrese un dato: ";
        cin >> b;
        cout << "Ingrese la prioridad: ";
        cin >> p;
        A.encolar(b,p);
    } while(b != 0);
    while (!A.esVacia()) {
        cout << A.desencolar() << '\n';
    }
    return 0;
}

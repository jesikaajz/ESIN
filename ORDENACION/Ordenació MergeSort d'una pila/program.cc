#include <stack>

// Procedimiento para ordenar una pila usando MergeSort
template <typename T>
void ordena(std::stack<T> &p) {
    // Caso base: una pila con 0 o 1 elementos ya está ordenada
    if (p.size() <= 1)
        return;

    // Dividir la pila original en dos pilas auxiliares: izquierda y derecha
    std::stack<T> izquierda, derecha;
    int n = p.size();
    for(int i = 0; i < n / 2; ++i) {
        izquierda.push(p.top());
        p.pop();
    }
    while(!p.empty()) {
        derecha.push(p.top());
        p.pop();
    }

    // Ordenar recursivamente las pilas izquierda y derecha
    ordena(izquierda);
    ordena(derecha);

    // Fusionar las dos pilas ordenadas en una pila temporal
    std::stack<T> temporal;
    while(!izquierda.empty() && !derecha.empty()) {
        if(izquierda.top() < derecha.top()) {
            temporal.push(izquierda.top());
            izquierda.pop();
        }
        else {
            temporal.push(derecha.top());
            derecha.pop();
        }
    }

    // Si quedan elementos en la pila izquierda, agregarlos a la pila temporal
    while(!izquierda.empty()) {
        temporal.push(izquierda.top());
        izquierda.pop();
    }

    // Si quedan elementos en la pila derecha, agregarlos a la pila temporal
    while(!derecha.empty()) {
        temporal.push(derecha.top());
        derecha.pop();
    }

    // Transferir los elementos de la pila temporal de vuelta a la pila original
    // Esto asegura que la pila original esté ordenada de menor a mayor con el menor en la cima
    while(!temporal.empty()) {
        p.push(temporal.top());
        temporal.pop();
    }
}


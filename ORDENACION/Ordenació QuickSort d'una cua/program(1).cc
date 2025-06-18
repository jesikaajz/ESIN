#include <queue>
// Procedimiento para ordenar una cola utilizando QuickSort
template <typename T>
void ordena(std::queue<T> &c) {
    // Caso Base: Si la cola está vacía o tiene un solo elemento, ya está ordenada
    if (c.empty() || c.size() == 1) {
        return;
    }

    // Elegir el pivote: el primer elemento de la cola
    T pivote = c.front();
    c.pop(); // Remover el pivote de la cola original

    // Colas auxiliares para particionar los elementos
    std::queue<T> menores;
    std::queue<T> mayores;

    // Particionar los elementos en menores y mayores o iguales al pivote
    while (!c.empty()) {
        T elemento = c.front();
        c.pop();
        if (elemento < pivote) {
            menores.push(elemento);
        } else {
            mayores.push(elemento);
        }
    }

    // Recursivamente ordenar las colas de menores y mayores
    ordena(menores);
    ordena(mayores);

    // Combinar las colas ordenadas en la cola original
    // Primero, insertar los elementos de la cola de menores
    while (!menores.empty()) {
        c.push(menores.front());
        menores.pop();
    }

    // Insertar el pivote
    c.push(pivote);

    // Finalmente, insertar los elementos de la cola de mayores o iguales
    while (!mayores.empty()) {
        c.push(mayores.front());
        mayores.pop();
    }
}


#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <sstream>

// Estructura para almacenar la información del cliente
struct Customer {
    std::string name;
    float age;

    // Constructor
    Customer(const std::string& n, float a) : name(n), age(a) {}
};

// Comparador para la priority_queue
struct Compare {
    bool operator()(const Customer& a, const Customer& b) const {
        return a.age < b.age; // Max heap basado en edad
    }
};

int main(){
    int n;
    std::cin >> n;
    std::cin.ignore(); // Ignorar el salto de línea después de leer n

    // Vector de priority_queues, una para cada cola del supermercado
    std::vector<std::priority_queue<Customer, std::vector<Customer>, Compare>> queues;
    queues.reserve(n);
    for(int i = 0; i < n; ++i){
        queues.emplace_back();
    }

    std::string line;

    // Leer las n colas iniciales
    for(int i = 0; i < n; i++){
        std::getline(std::cin, line);
        if(line.empty()){
            continue; // Si la línea está vacía, la cola está vacía
        }
        std::stringstream ss(line);
        std::string name;
        float age;
        while(ss >> name >> age){
            queues[i].emplace(name, age);
        }
    }

    // Leer la línea vacía que separa las colas de los eventos
    std::getline(std::cin, line); // Línea vacía

    // Vector para almacenar los nombres de los clientes que salen
    std::vector<std::string> departures;

    // Procesar los eventos hasta el final de la entrada
    while(std::getline(std::cin, line)){
        if(line.empty()){
            continue; // Ignorar líneas vacías
        }
        std::stringstream ss(line);
        std::string action;
        ss >> action;
        if(action == "ENTERS"){
            std::string name;
            float age;
            int q;
            ss >> name >> age >> q;
            if(q >= 1 && q <= n){
                queues[q-1].emplace(name, age);
            }
        }
        else if(action == "LEAVES"){
            int q;
            ss >> q;
            if(q >= 1 && q <= n){
                if(!queues[q-1].empty()){
                    Customer customer = queues[q-1].top();
                    queues[q-1].pop();
                    departures.push_back(customer.name);
                }
            }
        }
    }

    // Imprimir los clientes que han salido
    std::cout << "DEPARTS\n-------\n";
    for(const auto & name : departures){
        std::cout << name << "\n";
    }

    // Imprimir el contenido final de las colas
    std::cout << "\nFINAL CONTENTS\n--------------\n";
    for(int i = 0; i < n; i++){
        std::cout << "queue " << (i+1) << ":";
        if(!queues[i].empty()){
            // Extraer los clientes restantes en orden de salida (edad descendente)
            std::vector<Customer> remaining;
            std::priority_queue<Customer, std::vector<Customer>, Compare> temp = queues[i];
            while(!temp.empty()){
                remaining.push_back(temp.top());
                temp.pop();
            }
            // Ordenar los clientes por edad descendente
            // (ya están en orden, pero para imprimir en orden de salida)
            for(const auto &cust : remaining){
                std::cout << " " << cust.name;
            }
        }
        std::cout << "\n";
    }

    return 0;
}


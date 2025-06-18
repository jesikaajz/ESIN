#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <unordered_map>

// Mapeo de graduaciones a valores numéricos para facilitar la comparación
std::unordered_map<std::string, int> rank_map = {
    {"soldado", 1},
    {"sargento", 2},
    {"capitan", 3},
    {"coronel", 4}
};

// Estructura para almacenar la información de cada cliente
struct Customer {
    std::string name;
    int rank;
    long long arrival_time;

    // Constructor
    Customer(const std::string& n, const std::string& r, long long t) : name(n), rank(rank_map[r]), arrival_time(t) {}
};

// Comparador personalizado para la priority_queue
struct Compare {
    bool operator()(const Customer& a, const Customer& b) const {
        if (a.rank != b.rank)
            return a.rank < b.rank; // Mayor graduación tiene mayor prioridad
        return a.arrival_time > b.arrival_time; // Si igual graduación, el que llegó primero tiene mayor prioridad
    }
};

int main(){
    int n;
    std::cin >> n;
    std::cin.ignore(); // Ignorar el salto de línea después de leer n

    // Vector de priority_queues, una por cada cola
    std::vector<std::priority_queue<Customer, std::vector<Customer>, Compare>> queues;
    queues.reserve(n);
    for(int i = 0; i < n; ++i){
        queues.emplace_back();
    }

    std::string line;
    long long current_timestamp = 0; // Para mantener el orden de llegada

    // Leer las n colas iniciales
    for(int i = 0; i < n; i++){
        std::getline(std::cin, line);
        if(line.empty()){
            continue; // Si la línea está vacía, la cola está vacía
        }
        std::stringstream ss(line);
        std::string name, rank;
        while(ss >> name >> rank){
            // Añadir cliente a la cola correspondiente
            queues[i].emplace(name, rank, current_timestamp++);
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
        if(action == "ENTRA"){
            std::string name, rank;
            int q;
            ss >> name >> rank >> q;
            if(q >= 1 && q <= n){
                queues[q-1].emplace(name, rank, current_timestamp++);
            }
        }
        else if(action == "SALE"){
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
    std::cout << "SALIDAS\n--------\n";
    for(const auto & name : departures){
        std::cout << name << "\n";
    }

    // Imprimir el contenido final de las colas
    std::cout << "\nCONTENIDO FINAL\n-----------------\n";
    for(int i = 0; i < n; i++){
        std::cout << "cua " << (i+1) << ":";
        if(!queues[i].empty()){
            // Extraer los clientes restantes en orden de salida
            std::vector<Customer> remaining;
            std::priority_queue<Customer, std::vector<Customer>, Compare> temp = queues[i];
            while(!temp.empty()){
                remaining.push_back(temp.top());
                temp.pop();
            }
            // Ordenar los clientes por graduación descendente y luego por llegada ascendente
            std::sort(remaining.begin(), remaining.end(), [&](const Customer &a, const Customer &b) -> bool {
                if(a.rank != b.rank)
                    return a.rank > b.rank; // Mayor graduación primero
                return a.arrival_time < b.arrival_time; // Si igual graduación, el que llegó primero
            });
            // Imprimir los nombres de los clientes en orden
            for(const auto &cust : remaining){
                std::cout << " " << cust.name;
            }
        }
        std::cout << "\n";
    }

    return 0;
}


#include <vector>
using namespace std;

typedef unsigned int nat;

void ordena(vector<nat>& v) {
    if(v.empty()) return;
    
    const int num_bits = sizeof(nat) * 8;
    vector<nat> aux(v.size());
    
    for(int r = 0; r < num_bits; ++r) {
        // Contar los bits 0 y 1
        int count0 = 0, count1 = 0;
        for(auto num : v) {
            if(((num & (1 << r)) >> r) == 0) count0++;
            else count1++;
        }
        
        // Posiciones de los bits
        int pos0 = 0;
        int pos1 = count0;
        
        // Distribuir en el vector auxiliar
        for(auto num : v) {
            if(((num & (1 << r)) >> r) == 0) {
                aux[pos0++] = num;
            }
            else {
                aux[pos1++] = num;
            }
        }
        
        // Copiar de vuelta al vector original
        v = aux;
    }
}


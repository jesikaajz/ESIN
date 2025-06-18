#include <vector>
#include<iostream>
using namespace std;
typedef unsigned int nat;

class graf {
  // Graf dirigit i no etiquetat.
  // Les arestes es guarden en una matriu d’adjacència.
  public:
    // Constructora per defecte. Crea un graf buit.
    graf();

    // Destructora
    ~graf();

    // Llegeix les dades del graf del canal d’entrada
    void llegeix();

    vector<nat> quantes_arestes_es_visiten() const;
    // Pre: Cert
    // Post: Retorna quantes arestes diferents es poden visitar (hi ha un camí)
    // des de cada vèrtex del graf.

  private:
    nat n; // Nombre de vèrtexs
    nat m; // Nombre d’arestes
    vector<vector<bool> > a; // Matriu d’adjacència	
    void dfs(nat ini, vector<bool>& visitat) const;
    // Aquí va l’especificació dels mètodes privats addicionals

};

// Aquí va la implementació del mètode públic quantes_arestes_es_visiten i privats addicionals
vector<nat> graf::quantes_arestes_es_visiten() const {
    vector<nat> res(n, 0);
    // Precomputem el nombre d'arestes sortints de cada vèrtex
    vector<nat> out_degree(n, 0);
    for(nat i = 0; i < n; i++) {
        for(nat j = 0; j < n; j++) {
            if(a[i][j]) {
                out_degree[i]++;
            }
        }
    }

    // Vector per emmagatzemar els vèrtexs visitats

    for(nat i = 0; i < n; i++) {
        // Reinicialitzem el vector de visitats
    vector<bool> visited(n, 0);
        // Realitzem DFS des del vèrtex i
        dfs(i, visited);
        // Comptem les arestes sortints dels vèrtexs accessibles
        nat count = 0;
        for(nat j = 0; j < n; j++) {
            if(visited[j]) {
                count += out_degree[j];
            }
        }
        res[i] = count;
    }
    return res;
}

void graf::dfs(nat i, vector<bool>& visited) const {
    // Marquem el vèrtex actual com visitat
    visited[i] = true;
    // Recorrem tots els vèrtexs adjacents
    for(nat j = 0; j < n; j++) {
        if(a[i][j] && !visited[j]) {
            dfs(j, visited); // Crida recursiva
        }
    }
}



#include <iostream>
using namespace std;

graf::graf() : n(0), m(0) {}

graf::~graf() {
  for(nat i = 0; i < n; i++) {
    node_succ *p = a[i];
    while (p != nullptr) {
      node_succ *aux = p;
      p = p->_seg;
      delete aux;
    }
  }
}

void graf::llegeix() {
  // Llegim el nombre de vèrtexs i arestes
  cin >> n >> m;

  // Creem les llistes d'adjacència (vectors amb els successors dels n vèrtexs)
  a = vector<node_succ *>(n, nullptr);

  // Llegim les m arestes
  nat u, v;
  for(nat i = 0; i < m; i++) {
    cin >> u >> v; // Aresta que connecta vèrtex u amb vèrtex v
    node_succ *p = new node_succ;
    p->_succ = v;
    p->_seg = a[u];
    a[u] = p;
  }
}

int main() {
  graf g;
  g.llegeix();
  vector<nat> resultat = g.quantes_arestes_es_visiten();
  for(nat i=0; i<resultat.size(); i++) {
    cout << resultat[i] << " ";
  }
  cout << endl;
  return 0;
}

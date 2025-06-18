#include <sstream>
using namespace std;


template <typename Clau>
mfset<Clau>::mfset() : _arrel(NULL) {}

template <typename Clau>
void mfset<Clau>::esborra_nodes(node* m) {
  if (m != NULL) {
    esborra_nodes(m->_esq);
    esborra_nodes(m->_dret);
    delete m;
  }
}

template <typename Clau>
mfset<Clau>::~mfset() {
  esborra_nodes(_arrel);
}

template <typename Clau>
mfset<Clau>::node::node (const Clau &k, node* esq, node* dret) :
	_k(k), _esq(esq), _dret(dret), _pare_mfset(nullptr) {
}

template <typename Clau>
void mfset<Clau>::insereix(const Clau &k) {
  _arrel = insereix_bst(_arrel, k);
}

template <typename Clau>
typename mfset<Clau>::node* mfset<Clau>::insereix_bst (node *n, const Clau &k) {
  if (n == NULL) {
    return new node(k);
  }
  else {
    if (k < n->_k) {
      n->_esq = insereix_bst(n->_esq, k);
    }
    else if (k > n->_k) {
      n->_dret = insereix_bst(n->_dret, k);
    }
    return n;
  }
}

template <typename Clau>
void mfset<Clau>::merge(const Clau &k1, const Clau &k2) {
  // Cerquem els punters que apunten als representants de k1 i k2
  node *n1 = find_aux(k1), *n2 = find_aux(k2);
  // Si k1 i k2 existeixen i no estan en el mateix bloc, els fusiona amb l'estratègia Quick-union
  if (n1 != nullptr and n2 != nullptr and n1 != n2)
    n1->_pare_mfset = n2;
}

template <typename Clau>
pair<bool, Clau> mfset<Clau>::find(const Clau &k) const {
  pair<bool, Clau> res;
  // Cerquem el punter que apunta al representant de k
  node *n = find_aux(k);
  if (n != nullptr)
    res = pair<bool, Clau>(true, n->_k);
  else 
    res = pair<bool, Clau>(false, k);
  return res;
}

int main() {
  string linea, comanda;
  int k1, k2;
  while (getline(cin, linea)) {
    mfset<int> mfs;

    // Obtenim elements 1er mfset
    nat c(0);
    istringstream ss1(linea);
    while (ss1 >> k1) {
      mfs.insereix(k1);
      c++;
    }
    cout << c << endl;

    // Processem comandes
    while (getline(cin, linea) and linea != "----------") {
      cout << linea << ": ";
      istringstream ss2(linea);
      ss2 >> comanda;

      if (comanda == "find") {
        ss2 >> k1;
        pair<bool, int> res = mfs.find(k1);
        if (res.first)
          cout << res.second;
        cout << endl;
      }

      if (comanda == "merge") {
        ss2 >> k1 >> k2;
        mfs.merge(k1, k2);
        cout << endl;
      }
    }
    if (linea == "----------")
      cout << linea << endl;
  }
  return 0;
}

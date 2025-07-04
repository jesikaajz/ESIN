#include <iostream>
using namespace std;
typedef unsigned int nat;


template <typename Clau>
class mfset {
  // Partició on les operacions find i merge s’han implementat amb l’estratègia 
  // Quick-union. Les claus de la partició es guarden en un BST.

  public:
    // Constructora per defecte. Crea una partició buida.
    mfset();

    // Destructora
    ~mfset();

    // Pre: cert
    // Post: Insereix la clau k en la partició posant-la en un nou bloc.
    // Si ja hi era, no fa res.
    void insereix(const Clau &k);

    // Pre: cert
    // Post: Fusiona els blocs de les claus k1 i k2 amb l’estratègia Quick-union.
    // Si k1 o k2 no hi és, no fa res.
    void merge(const Clau &k1, const Clau &k2);

    // Pre: cert
    // Post: Si k hi és, retorna true i la clau del representant del bloc al que pertany k.
    // Si k no hi és, retorna false i la clau k.
    pair<bool, Clau> find(const Clau &k) const;

  private:
    struct node {
      Clau _k;      // Clau
      node* _esq;   // fill esquerre del BST
      node* _dret;  // fill dret del BST
      node* _pare_mfset;  // pare de la partició, apunta a nullptr si és el representant del bloc
      node(const Clau &k, node* esq = nullptr, node* dret = nullptr);
    };
    node *_arrel;   // punter a l’arrel del BST

    static void esborra_nodes(node* m);
    static node* insereix_bst(node *n, const Clau &k);

    // Pre: cert
    // Post: Si k hi és, retorna un punter al node representant del bloc al que pertany k.
    // Si k no hi és, retorna nullptr.
    node* find_aux(const Clau &k) const;
    node* find_aux_rec(node *actual, const Clau &k) const;
    // Aquí va l’especificació dels mètodes privats addicionals

};

template <typename Clau>
typename mfset<Clau>::node* mfset<Clau>::find_aux(const Clau &k) const {
    node* found = find_aux_rec(_arrel, k);
    if (found == nullptr) return nullptr;

    // Encontrar el representant del bloc
    node* rep = found;
    while (rep->_pare_mfset != nullptr) {
        rep = rep->_pare_mfset;
    }
    return rep;
}

template <typename Clau>
typename mfset<Clau>::node* mfset<Clau>::find_aux_rec(node *actual, const Clau &k) const {
    if (actual == nullptr) return nullptr;
    if (k == actual->_k) return actual;
    if (k < actual->_k) {
        return find_aux_rec(actual->_esq, k); // Agregado 'return' aquí
    }
    else {
        return find_aux_rec(actual->_dret, k); // Agregado 'return' aquí
    }
}




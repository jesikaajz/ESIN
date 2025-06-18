#include <iostream>
 using namespace std;
 typedef unsigned int nat;
 
 template <typename Clau>
 class dicc {
 
   public:
     // Constructora per defecte. Crea un diccionari buit.
     dicc();
 
     // Destructora
     ~dicc();
 
     // Insereix la clau k en el diccionari. Si ja hi era, no fa res.
     void insereix(const Clau &k);
 
     // Retorna quants elements (claus) té el diccionari.
     nat quants() const;
 
     // Retorna la segona clau.
     // Pre: El diccionari té com a mínim 2 claus.
     Clau segona() const;
 
   private:
     struct node {
       Clau _k;      // Clau
       node* _esq;   // fill esquerre
       node* _dret;  // fill dret
       nat _n;       // Nombre de nodes del subarbre
       node(const Clau &k, node* esq = NULL, node* dret = NULL);
     };
     node *_arrel;
 
     static void esborra_nodes(node* m);
     static node* insereix_bst(node *n, const Clau &k, bool &ins);
     Clau segona_rec(node* n, node* parent) const;
     Clau trobar_minim(node* n) const;
          // Aquí va l’especificació dels mètodes privats addicionals
 };
 
 template <typename Clau>
Clau dicc<Clau>::segona() const {
    return segona_rec(_arrel, nullptr);
}

template <typename Clau>
Clau dicc<Clau>::segona_rec(node* n, node* parent) const {
    // Caso base: encontramos el nodo más pequeño
    if (n->_esq == nullptr) {
        // Si tiene un subárbol derecho, buscamos el más pequeño en él
        if (n->_dret != nullptr) {
            return trobar_minim(n->_dret);
        }
        // Si no tiene subárbol derecho, la segunda clave es su padre
        return parent->_k;
    }
    // Recurre hacia la izquierda
    return segona_rec(n->_esq, n);
}

// Función auxiliar para encontrar el nodo más a la izquierda de un subárbol
template <typename Clau>
Clau dicc<Clau>::trobar_minim(node* n) const {
    if (n->_esq == nullptr) return n->_k;
    return trobar_minim(n->_esq);
}

 
 
 
 // Aquí va la implementació dels mètodes públics i privats

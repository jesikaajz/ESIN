#include <iostream>
 using namespace std;
 typedef unsigned int nat;
 
 class dicc {
   public:
     dicc();  // Constructora per defecte. Crea un diccionari buit.
 
     ~dicc(); // Destructora
 
     // Insereix la clau k en el diccionari. Si ja hi era, no fa res.
     void insereix(const string &k);
 
     nat quantes_comencen(string inicials) const;
     // Pre: inicials no conté el char ’#’
     // Post: Retorna el nº de claus que comencen per algun dels caràcters que conté inicials
 
   private:
     struct node {
       char _c;   // Símbol posició i-èssima de la clau
       node* _pf; // Primer fill, apunta a símbols de la següent posició
       node* _sg; // Següent germà, apunta a símbols de la mateixa posició
       node(const char &c, node* pf = NULL, node* sg = NULL);
     };
     node* _arrel;
     static void esborra_nodes(node* t);
     static node* insereix(node *t, nat i, const string &k);
     void busca_finals(node* n, nat& contador) const;
     void quantes_comencen_rec(node* n, nat& contador, char inicial) const;
 
     // Aquí va l’especificació dels mètodes privats addicionals
 };
nat dicc::quantes_comencen(string inicials) const {
    nat contador = 0;
    for (char c : inicials) {
        quantes_comencen_rec(_arrel, contador, c);
    }
    return contador;
}
 // Aquí va la implementació del mètode públic quantes_comencen i privats addicionals
 void dicc::quantes_comencen_rec(node* n, nat& contador, char inicial) const {
    if (n == nullptr) return;

    // Busca en el subárbol izquierd

    // Si el carácter coincide con el inicial
    if (n->_c == inicial) {
        // Recorre todo el subárbol central buscando '#' (final de clave)
        busca_finals(n->_pf, contador);
    }

    // Busca en el subárbol derecho
    quantes_comencen_rec(n->_sg, contador, inicial);
}

void dicc::busca_finals(node* n, nat& contador) const {
    if (n == nullptr) return;

    // Incrementa el contador si llegas al final de una clave
    if (n->_c == '#') {
        contador++;
    }

    // Recorre todas las ramas del trie
    busca_finals(n->_pf, contador);
    busca_finals(n->_sg, contador);
}


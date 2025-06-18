#include <iostream>
using namespace std;
typedef unsigned int nat;

class dicc {
  public:
    dicc();  // Constructora per defecte. Crea un diccionari buit.

    ~dicc(); // Destructora

    // Insereix la clau k en el diccionari. Si ja hi era, no fa res.
    void insereix(const string &k);

    nat quantes_comencen(string prefix) const;
    // Pre: cert
    // Post: Retorna el nº de claus que comencen amb el prefix donat

  private:
    struct node {
      char _c;    // Símbol posició i-èssima de la clau
      node* _esq; // Fill esquerra, apunta a símbols mateixa posició formant un BST
      node* _cen; // Fill central, apunta a símbols següent posició
      node* _dre; // Fill dret, apunta a símbols mateixa posició formant un BST
      node(const char &c, node* esq = nullptr, node* cen = nullptr, node* dre = nullptr);
    };
    node* _arrel;
    static void esborra_nodes(node* t);
    static node* insereix(node *t, nat i, const string &k);
void buscar_prefix(string prefix, node *p, nat& contador, const string& pref, nat i) const;
void busca_paraules(node *p, nat &count) const;
    // Aquí va l’especificació dels mètodes privats addicionals
};

// Aquí va la implementació del mètode públic i dels mètodes privats addicionals
nat dicc::quantes_comencen(string prefix) const {
 nat contador = 0;
    if(prefix.empty()) {
        busca_paraules(_arrel, contador);
    }
    else {
        buscar_prefix("", _arrel, contador, prefix, 0);
    }
    return contador;
}


void dicc::buscar_prefix(string prefix, node *p, nat& contador, const string& pref, nat i) const {
    if(p == nullptr) return;
    // Buscar en el subárbol izquierdo
    buscar_prefix(prefix, p->_esq, contador, pref, i);
    
    // Comprobar si el carácter actual coincide con el prefijo
    if(i < pref.length() && p->_c == pref[i]) {
        string new_prefix = prefix + p->_c;
        nat new_i = i + 1;
        if(new_prefix == pref) {
            busca_paraules(p->_cen, contador);
        }
        // Continuar buscando en el subárbol central
        buscar_prefix(new_prefix, p->_cen, contador, pref, new_i);
    }
    
    // Buscar en el subárbol derecho
    buscar_prefix(prefix, p->_dre, contador, pref, i);
}

void dicc::busca_paraules(node *p, nat &count) const  {
if(p == nullptr) return;
else {
	if(p->_c == '#') count++;
	busca_paraules(p->_esq, count);
	busca_paraules(p->_cen, count);
	busca_paraules(p->_dre, count);
}
}


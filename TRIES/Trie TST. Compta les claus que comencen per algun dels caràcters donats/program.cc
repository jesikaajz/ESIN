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
       char _c;    // Símbol posició i-èssima de la clau
       node* _esq; // Fill esquerra, apunta a símbols mateixa posició formant un BST
       node* _cen; // Fill central, apunta a símbols següent posició
       node* _dre; // Fill dret, apunta a símbols mateixa posició formant un BST
       node(const char &c, node* esq = NULL, node* cen = NULL, node* dre = NULL);
     };
     node* _arrel;
     static void esborra_nodes(node* t);
     static node* insereix(node *t, nat i, const string &k);
      void quantes_comencen_rec(node *p, char inicio, nat& contador) const;
 	void auxiliar(node *p, nat& contador) const;
     // Aquí va l’especificació dels mètodes privats addicionals
 };
 
 // Aquí va la implementació del mètode públic quantes_comencen i privats addicionals
 
 nat dicc::quantes_comencen(string inicials) const{
 	nat contador = 0;
 	for(nat i = 0; i < inicials.size(); i++) {
 	quantes_comencen_rec(_arrel, inicials[i], contador);
 	}
 	return contador;
 }
 
 
 void dicc::quantes_comencen_rec(node *p, char inicio, nat& contador) const{
 if(p == nullptr) return; 
 quantes_comencen_rec(p->_esq, inicio, contador);
 if(p->_c == inicio) {
 	auxiliar(p->_cen, contador);
 }
  quantes_comencen_rec(p->_dre, inicio, contador);
 }
 
 void dicc::auxiliar(node *p, nat& contador) const {
 	if(p== nullptr) return;
 	else{
 		if(p -> _c == '#') {
 			contador +=1;
 		}
 		auxiliar(p->_esq, contador);
 		auxiliar(p->_cen, contador);
 		auxiliar(p->_dre, contador);
 	}
 }
 
 
 
 
 
 
 

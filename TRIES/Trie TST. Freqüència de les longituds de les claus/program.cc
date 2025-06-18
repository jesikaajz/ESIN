 #include <iostream>
 #include <vector>
 using namespace std;
 typedef unsigned int nat;
 
 class dicc {
   public:
     // Constructora per defecte. Crea un diccionari buit.
     dicc();
 
     // Destructora
     ~dicc();
 
     // Insereix la clau k en el diccionari. Si ja hi era, no fa res.
     void insereix(const string &k);
 
     vector<nat> freq_longituds() const;
     // Pre: True
     // Post: Retorna un vector amb les freqüències de les longituds de les claus.
     // La mida del vector és igual a la longitud de la clau més llarga més un. 
 
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
     void freq_longituds_rec(node *p, nat contador, vector<nat>& freq) const;
     // Aquí va l’especificació dels mètodes privats addicionals
 };
 
 // Aquí va la implementació del mètode públic freq_longituds i privats addicionals
  vector<nat> dicc::freq_longituds() const{
  
  vector<nat> res;
  nat contador = 0;
  freq_longituds_rec(_arrel, contador, res);
  return res;

  }
  
 void dicc::freq_longituds_rec(node *p, nat contador, vector<nat>& freq) const {
 if(p == nullptr) return;
 if(p -> _c== '#') {
 	if(contador >= freq.size()) freq.resize(contador+1, 0);
 	freq[contador]++;
 }
 freq_longituds_rec(p->_esq, contador, freq); 
 freq_longituds_rec(p->_cen, contador+1, freq);
 freq_longituds_rec(p->_dre, contador, freq);
 }
 
 

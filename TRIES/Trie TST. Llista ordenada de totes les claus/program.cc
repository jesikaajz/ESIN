 #include <iostream>
 #include <list>
 using namespace std;
 typedef unsigned int nat;
 
 class dicc {
   public:
     // Constructora per defecte. Crea un diccionari buit.
     dicc();
 
     // Destructora
     ~dicc();
 
     void insereix(const string &k);
     // Pre: True
     // Post: Insereix la clau k en el diccionari. Si ja hi era, no fa res.
 
     list<string> llista_ordenada_dec() const;
     // Pre: True
     // Post: Retorna una llista amb totes les claus ordenades decreixentment.
 
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
     void hacer_lista(node *p, list<string>& res, string rest) const;
     // Aquí va l’especificació dels mètodes privats addicionals
 };
 
 // Aquí va la implementació del mètode llista_ordenada_dec i privats addicionals
      list<string> dicc::llista_ordenada_dec() const{
      list <string> res;
      hacer_lista(_arrel, res, "");
      return res;
      }

      void dicc::hacer_lista(node *p, list<string>& res, string rest) const{
      if(p == nullptr) return;
      else {
        hacer_lista(p->_dre, res, rest);
      	if(p -> _c == '#') {
      	res.push_back(rest);
      	}
      	else {

      	string new_res = rest + p->_c;
      	hacer_lista(p->_cen, res, new_res);
      	}
      	hacer_lista(p->_esq, res, rest);
      }
      }
      
      
            
      
      
      

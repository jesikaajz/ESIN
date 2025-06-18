 #include <iostream>
 #include <vector>
 using namespace std;
 typedef unsigned int nat;
 
 template <typename Clau>
 class dicc {
   public:
     dicc() : _arrel(NULL) {};
     // Pre: Cert
     // Post: El resultat és un dicc sense cap element
 
     ~dicc();
     // Pre: Cert
     // Post: El dicc ha estat destruït
 
     vector<Clau> insereix(const Clau &k);
     // Pre: Cert
     // Post: La clau k s’ha inserit en el diccionari si no hi era. Retorna un vector amb 
     // les claus dels nodes visitats on hi ha un desequilibri desprès de la inserció,
     // començant per la més propera a les fulles i acabant per la més propera a l’arrel.
 
   private:
     struct node {
       Clau _k;      // Clau
       node* _esq;   // fill esquerre
       node* _dret;  // fill dret
       nat _h;       // Altura del subarbre
     };
     node *_arrel;
 
     static void esborra_nodes(node* m);
      void insereix_aux(node *&p, const Clau &k, vector<Clau>& res);
 
     // Aquí va l’especificació dels mètodes privats addicionals
 };
 
 // Aquí va la implementació dels mètodes públics i privats
  template <typename Clau>
     vector<Clau> dicc<Clau>::insereix(const Clau &k){
     vector<Clau> rep;
     insereix_aux(_arrel, k, rep);
     return rep;
     }
     
     template <typename Clau>
     void dicc<Clau>::insereix_aux(node *&p, const Clau &k, vector<Clau>& res) {

     	if(p == nullptr) {
     		p = new node;
     		p->_k = k;
     		p->_esq = nullptr;
     		p->_dret = nullptr;
     		p-> _h = 1;
     	}
     	
     	else if(p->_k > k) insereix_aux(p->_esq, k, res);
     	else if(p->_k < k) insereix_aux(p->_dret, k, res);
     	else {}
     	
     	nat h_esq = 0;
     	if(p->_esq != nullptr) h_esq = p->_esq->_h;
     	nat h_dret = 0;
     	if(p->_dret != nullptr) h_dret = p->_dret->_h;
     	p->_h = max(h_esq, h_dret) + 1;
     	
     	int factor = h_esq - h_dret;
     	
     	if(p != nullptr) {
     		if(factor < -1) {
     			res.push_back(p->_k);
     		}
     		else if (factor > 1) res.push_back(p->_k);
     	}
     
     }
     
     

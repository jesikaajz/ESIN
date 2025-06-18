 #include <iostream>
 #include <vector>
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
 
     vector<Clau> interseccio(const dicc<Clau> &d2) const;
     // Pre: True
     // Post: Retorna un vector amb les claus de la intersecció del p.i. amb d2
     // ordenades de menor a major
 
   private:
     struct node {
       Clau _k;      // Clau
       node* _esq;   // fill esquerre
       node* _dret;  // fill dret
       node(const Clau &k, node* esq = NULL, node* dret = NULL);
     };
     node *_arrel;
 
     static void esborra_nodes(node* m);
     static node* insereix_bst(node *n, const Clau &k);
     bool busca_en_d2(node *p, const Clau& k) const;
     void interseccio_rec(node *p,  vector<Clau>& res, const dicc<Clau> &d2) const;
 
     // Aquí va l’especificació dels mètodes privats addicionals
 };
 
 // Aquí va la implementació dels mètodes públics i privats
 template <typename Clau>
 vector<Clau> dicc<Clau>::interseccio(const dicc<Clau> &d2) const{
 vector<Clau> res;
 interseccio_rec(_arrel, res, d2);
 return res;
 }
 
 template <typename Clau>
 void dicc<Clau>::interseccio_rec(node *p,  vector<Clau>& res, const dicc<Clau> &d2) const {
 	if(p == nullptr) return;
 	else {
 		interseccio_rec(p->_esq, res, d2);
 		 		
 		if(busca_en_d2(d2._arrel, p->_k)) {
			res.push_back(p->_k);
 		}
 		
 		interseccio_rec(p->_dret, res, d2);

 		
 	}
 }
 
 template <typename Clau> 
 bool dicc<Clau>::busca_en_d2(node *p, const Clau& k) const{
 	if(p == nullptr) return false;
 	else { 	
 		if(p->_k > k) return busca_en_d2(p->_esq, k);
 		if(p->_k < k) return busca_en_d2(p->_dret, k);
 		if(p->_k == k) return true;
 	return false;
 	}
 	
 }
 
 

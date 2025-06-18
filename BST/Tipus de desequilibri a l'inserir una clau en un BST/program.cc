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
 
     pair<Clau, char> insereix(const Clau &k);
     // Pre: Cert
     // Post: La clau k s’ha inserit en el diccionari si no hi era. Retorna la clau dels nodes
     // visitats a on hi ha el desequilibri més proper a les fulles i un caràcter amb el seu
     // tipus de desequilibri: ’E’: Esquerre, ’D’: Dret, ’ ’: No s’ha trobat cap desequilibri
 
   private:
     struct node {
       Clau _k;      // Clau
       node* _esq;   // fill esquerre
       node* _dret;  // fill dret
       nat _h;       // Altura del subarbre
     };
     node *_arrel;
 
     static void esborra_nodes(node* m);
     static nat factorEquilibrio(node *p);
     pair<Clau, char> insert_bst_amb_altures(node* &n, const Clau&k);
     // Aquí va l’especificació dels mètodes privats addicionals
 };
template <typename Clau>
nat dicc<Clau>::factorEquilibrio(node *n) {
    if (n == nullptr) return 0;
  
    nat hesq = 0;
    if(n->_esq == nullptr) hesq = 0;
    else hesq = n->_esq->_h;
    
    nat hdret = 0;
    if(n->_dret == nullptr) hdret = 0; // es necesario, si hacemos n->dret->_h esta vacia, dara error
    else hdret = n->_dret->_h;
    
    return hesq - hdret;
} 

template <typename Clau>
pair<Clau, char> dicc<Clau>::insereix(const Clau &k) {
pair<Clau, char> result = insert_bst_amb_altures(_arrel, k);
return result;
}    
    
 // Aquí va la implementació dels mètodes públics i privats
template <typename Clau>
pair<Clau, char> dicc<Clau>::insert_bst_amb_altures(node* &n, const Clau&k) {
	pair<Clau, char> deseq = {Clau(),' '}; // constructor vacio de una clave
	if(n == nullptr) {
		n= new node;
		n -> _k = k; 
		n-> _esq = nullptr;
		n -> _dret = nullptr;
		n->_h = 1;
		return deseq;
	}
	
		else if(n->_k < k) deseq = insert_bst_amb_altures(n-> _dret, k);
		else if(n->_k > k) deseq = insert_bst_amb_altures(n-> _esq, k);
		else { }
	
	
	nat hesq = 0;
	if(n->_esq == nullptr) hesq = 0;
	else hesq = n->_esq->_h;
	
	nat hdret = 0;
	if(n->_dret == nullptr) hdret = 0;
	else hdret = n->_dret->_h;
	
	n->_h = max(hesq, hdret) + 1;
	
	int fe = factorEquilibrio(n);
	if(deseq.second == ' ') {
		if(fe > 1) {
		deseq = {n->_k,'E'};
		}
		else if(fe<-1) {
		deseq = {n->_k,'D'};
		}
	}
	
	 return deseq;

}




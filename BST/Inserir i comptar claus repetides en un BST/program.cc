 #include <iostream>
 using namespace std;
 typedef unsigned int nat;
 
 template <typename Clau>
 class dicc {
   // Diccionari implementat en un BST on les claus poden estar repetides.
 
   public:
     // Constructora per defecte. Crea un diccionari buit.
     dicc();
 
     // Destructora
     ~dicc();
 
     // Imprimeix el contingut del diccionari: Nombre d’elements i
     // totes les claus de més petita a més gran separades per un espai
     void print() const;
 
     void insereix(const Clau &k);
     // Pre: Cert
     // Post: Insereix la clau k en el diccionari.
 
     nat quantes(const Clau &k) const;
     // Pre: Cert
     // Post: Retorna el nombre de claus iguals a k
 
   private:
     struct node {
       Clau _k;      // Clau
       node* _esq;   // fill esquerre
       node* _dret;  // fill dret
     };
     node *_arrel;
     nat _n;       // Nombre d’elements del diccionari
 
     // Elimina els nodes del subarbre apuntat per p
     static void esborra_nodes(node* p);
     // Imprimeix ordenades les claus del subarbre apuntat per p
     static void print(node* p);
     void quantes_aux(node *p, const Clau &k, nat& contador) const;
     void insereix_aux(node *&p, const Clau &k);
 
     // Aquí va l’especificació dels mètodes privats addicionals
 };
 
 template <typename Clau>
nat dicc<Clau>::quantes(const Clau &k) const{
    nat contador = 0;
    quantes_aux(_arrel, k, contador);
    return contador;
}

template <typename Clau>
void dicc<Clau>::quantes_aux(node *p, const Clau &k, nat& contador) const{
    if(p == nullptr) return;
    if(p->_k == k){
        contador++;
        quantes_aux(p->_esq, k, contador);
    }
    if(p->_k < k){
        quantes_aux(p->_dret, k, contador);
    }
    else if(p->_k > k){
        quantes_aux(p->_esq, k, contador);
    }
}

// Insereix
template <typename Clau>
void dicc<Clau>::insereix(const Clau &k){      
    insereix_aux(_arrel, k);
}

// Insereix Auxiliar
template <typename Clau>
void dicc<Clau>::insereix_aux(node *&p, const Clau &k) { // Passar per referència
    if(p == nullptr) {
        p = new node;
        p->_k = k;
        p->_esq = nullptr;   // fill esquerre
        p->_dret = nullptr;  // fill dret
        _n = _n + 1;
    }
    else {
        if(p->_k < k) {
            insereix_aux(p->_dret, k);
        }
        else { // Duplicats a l'esquerra
            insereix_aux(p->_esq, k);
        }
    }
}




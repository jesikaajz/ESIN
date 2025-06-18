#include <cstdlib>
 #include <iostream>
 using namespace std;
 typedef unsigned int nat;
 
 template <typename T>
 class Abin {
   public:
     Abin(): _arrel(NULL) {};
     // Pre: cert
     // Post: el resultat és un arbre sense cap element
     Abin(Abin<T> &ae, const T &x, Abin<T> &ad);
     // Pre: cert
     // Post: el resultat és un arbre amb un element i dos subarbres
 
     // Les tres grans
     Abin(const Abin<T> &a);
     ~Abin();
     Abin<T>& operator=(const Abin<T>& a);
 
     // operador << d’escriptura
     template <class U> friend std::ostream& operator<<(std::ostream&, const Abin<U> &a);
 
     // operador >> de lectura
     template <class U> friend std::istream& operator>>(std::istream&, Abin<U> &a);
 
     // Modifica l’arbre del p.i. posant-hi el seu simètric
     void arbre_simetric();
 
   private:
     struct node {
       node* f_esq;
       node* f_dret;
       T info;
     };
     node* _arrel;
     static node* copia_nodes(node* m);
     static void esborra_nodes(node* m);
     static void print_nodes(node* m, ostream &os, string d1);
     void arbre_simetric(node *p);
     
     // Aquí va l’especificació dels mètodes privats addicionals
 };
 
 // Aquí va la implementació del mètode arbre_simetric
 
template<typename T>
void Abin<T> :: arbre_simetric(node *p) {
	if(p == nullptr) return;
	else  {
	node *paux = p->f_esq;
	p->f_esq = p->f_dret;
	p->f_dret = paux;
	arbre_simetric(p->f_esq);
	arbre_simetric(p->f_dret);
	}

} 
 
 
template<typename T>
void Abin<T> :: arbre_simetric(){
arbre_simetric(_arrel);
}
 

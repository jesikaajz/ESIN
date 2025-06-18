 #include <cstdlib>
 using namespace std;
 typedef unsigned int nat;
 
 template <typename T>
 class heap {
   public:
     heap(): _arrel(NULL), _nelems(0) {};
     // Pre: Cert
     // Post: El resultat és un heap sense cap element
 
     heap(heap<T> &he, const T &x, heap<T> &hd);
     // Pre: Cert
     // Post: El resultat és un heap amb x com arrel, he com a fill
     // esquerre i hd com a fill dret. No fa còpia dels heaps he i hd
 
     heap(const heap<T> &h);
     // Pre: Cert
     // Post: Crea un heap que és una còpia de h
 
     ~heap();
     // Pre: Cert
     // Post: El heap ha estat destruït
 
     bool empty() const;
     // Pre: Cert
     // Post: Retorna un booleà indicant si el heap està buit
 
     T min() const;
     // Pre: El heap no és buit
     // Post: Retorna l’element mínim del heap
 
     void elim_min();
     // Pre: El heap no és buit
     // Post: S’ha eliminat l’element mínim del heap o qualsevol d’ells si està repetit
 
   private:
     struct node {
       node* fesq;  // Punter al fill esquerre
       node* fdret; // Punter al fill dret
       node* pare;  // Punter al pare
       T info;
     };
     node* _arrel; // Arrel de l’arbre binari del heap
     int _nelems;  // Nombre d’elements del heap
 
     static node* copia_nodes(node* m, node *n_pare);
     static void esborra_nodes(node* m);
 
     void ultim(node* &ult, node* &pare_ult) const;
      void heapify(node *pact);
     // Pre: Cert
     // Post: ult conté el punter de l’últim element del heap (NULL si està buit)
     // pare_ult conté el punter del pare de l’últim element del heap (NULL si no en té)
 
     // Aquí va l’especificació dels mètodes privats addicionals
 };
 
 // Aquí va la implementació del mètode elim_min
 template <typename T>
 void heap<T>::elim_min(){
 if(_nelems == 0) return;

 node *ult = nullptr;
 node *ult_pare = nullptr;
 ultim(ult, ult_pare);
 
 
 if(_arrel == ult) {
 delete _arrel;
 _arrel = nullptr;
 }
 
 else {
 	_arrel -> info = ult->info;
 	if(ult_pare ->fesq == ult) ult_pare->fesq = nullptr;
 	else ult_pare->fdret = nullptr;
 	
 	delete ult;
}
 	_nelems--;
 	heapify(_arrel);
 }




 template <typename T>
 void heap<T>::heapify(node *p){
 if(!p) return;
 else {
 	node *peque = p;
 	if(p->fesq && p->fesq->info < peque->info) peque = p->fesq;
 	if(p->fdret && p->fdret ->info < peque->info) peque = p->fdret;
 	
 	if(peque != p) {
 	T temp = peque->info;
 	peque->info = p->info;
 	p->info = temp;
 	heapify(peque);
 	}
 
 
 }
 }


#include <vector>
 using namespace std;
 typedef unsigned int nat;
 
 class graf {
   // Graf dirigit i no etiquetat.
   // Les arestes es guarden en multillistes d’adjacència en memòria dinàmica.
   public:
     // Constructora per defecte. Crea un graf buit de n vèrtexs.
     graf(nat n);
 
     // Destructora
     ~graf();
 
     // Retorna un vector amb els successors del vèrtex v
     vector<nat> successors(nat v) const;
 
     // Retorna un vector amb els predecessors del vèrtex v
     vector<nat> predecessors(nat v) const;
 
     void insereix(nat orig, nat dest);
     // Pre: orig i dest són menors que el número de vèrtexs
     // Post: Insereix una aresta que connecta des del vèrtex orig cap al vèrtex dest.
           // Si l’aresta ja existia no fa res.
 
   private:
     nat nv; // Nombre de vèrtexs
     struct node {
       nat orig; // Vèrtex origen 
       nat dest; // Vèrtex destí 
       node *seg_succ; // Punter al següent successor
       node *seg_pred; // Punter al següent predecessor
     };
     vector<node *> prim_succ; // Punters al primer successor de cada vèrtex.
                               // La llista de successors està ordenada.
     vector<node *> prim_pred; // Punters al primer predecessor de cada vèrtex.
                               // La llista de predecessors està ordenada.
 
     // Aquí va l’especificació dels mètodes privats addicionals
 };
 
 // Aquí va la implementació del mètode públic insereix i privats addicionals
 void graf::insereix(nat orig, nat dest){
 
	 node *ant = nullptr;
	 node *p = prim_succ[orig];
	
	//por si encuentra que la arista ya existia en el grafo, en la lista de sucesores

	while(p != nullptr && p ->dest < dest) {
		ant = p;
		p = p->seg_succ;
	}
	
		
	node *ant1 = nullptr;
	node *p1 = prim_pred[dest];
	//por si encuentra que la arista ya existia en el grafo, en la lista de predecesores
	while(p1 != nullptr && p1->orig < orig) {
		ant1 = p1;
		p1 = p1->seg_pred;
	}
	if(p != nullptr && p->dest == dest) return;//no encontro la arista existente en el grafo
	
		node *nuevo = new node;
		nuevo->orig = orig;
		nuevo->dest = dest;
		nuevo -> seg_succ = p;
		nuevo -> seg_pred = p1;
		
		//para insertarlo en la lista de succesores
		if(ant == nullptr) { 
		prim_succ[orig] = nuevo;
		}
		else {
		ant ->seg_succ = nuevo;
		}
		//para insertarlo en la lista de predecesores
		if(ant1 == nullptr) { 
		prim_pred[dest] = nuevo;
		}
		else {
		ant1 ->seg_pred = nuevo;
		}
	
 }
 
 

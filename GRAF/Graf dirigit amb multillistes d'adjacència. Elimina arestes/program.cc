 #include <iostream>
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
 
     void insereix(nat orig, nat dest);
     // Pre: orig i dest són més petits que el número de vèrtexs
     // Post: Insereix una aresta que connecta des del vèrtex orig cap al vèrtex dest.
     // Si l’aresta ja existia no fa res.
 
     vector<nat> successors(nat v) const;
     // Pre: v és més petit que el número de vèrtexs
     // Post: Retorna un vector amb els successors del vèrtex v
 
     vector<nat> predecessors(nat v) const;
     // Pre: v és més petit que el número de vèrtexs
     // Post: Retorna un vector amb els predecessors del vèrtex v
 
     void elimina(nat orig, nat dest);
     // Pre: orig i dest són més petits que el número de vèrtexs
     // Post: Elimina una aresta que connecta des del vèrtex orig cap al vèrtex dest.
     // Si l’aresta no existia no fa res.
 
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
 
 // Aquí va la implementació del mètode elimina i privats addicionals
 
 // Pre: orig i dest són més petits que el número de vèrtexs
 // Post: Elimina una aresta que connecta des del vèrtex orig cap al vèrtex dest.
 // Si l’aresta no existia no fa res.void elimina(nat orig, nat dest);
// Eliminar arista
// Cost: O(d_s + d_p) donde d_s es el grado de salida de 'orig' y d_p es el grado de entrada de 'dest'
void graf::elimina(nat orig, nat dest){
    node *ant_s = nullptr;
    node *p_s = prim_succ[orig];
    
    // Buscar en la lista de sucesores
    while(p_s != nullptr && p_s->dest != dest) {
        ant_s = p_s;
        p_s = p_s->seg_succ;
    }

    node *ant_p = nullptr;
    node *p_p = prim_pred[dest];
    
    // Buscar en la lista de predecesores
    while(p_p != nullptr && p_p->orig != orig) {
        ant_p = p_p;
        p_p = p_p->seg_pred;
    }

    // Verificar si el nodo existe en ambas listas y es el mismo nodo
    if(p_s != nullptr && p_p != nullptr && p_s == p_p){
        // Eliminar de la lista de sucesores
        if(ant_s == nullptr){
            prim_succ[orig] = p_s->seg_succ;
        }
        else{
            ant_s->seg_succ = p_s->seg_succ;
        }

        // Eliminar de la lista de predecesores
        if(ant_p == nullptr){
            prim_pred[dest] = p_p->seg_pred;
        }
        else{
            ant_p->seg_pred = p_p->seg_pred;
        }

        // Eliminar el nodo una sola vez
        delete p_s;
    }
}

    

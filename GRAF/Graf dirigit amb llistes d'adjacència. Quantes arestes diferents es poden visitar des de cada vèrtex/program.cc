 #include <vector>
 using namespace std;
 typedef unsigned int nat;
 
 class graf {
   // Graf dirigit i no etiquetat.
   // Les arestes es guarden en llistes d’adjacència (vector amb els successors).
   public:
     // Constructora per defecte. Crea un graf buit.
     graf();
 
     // Destructora
     ~graf();
 
     // Llegeix les dades del graf del canal d’entrada
     void llegeix();
 
     vector<nat> quantes_arestes_es_visiten() const;
     // Pre: Cert
     // Post: Retorna quantes arestes diferents es poden visitar (hi ha un camí)
     // des de cada vèrtex del graf.
 
   private:
     nat n; // Nombre de vèrtexs
     nat m; // Nombre d’arestes
 
     struct node_succ {
       nat _succ;        // Vèrtex successor
       node_succ* _seg;  // Següent successor
     };
     vector<node_succ *> a; // Vector amb llistes simplement encadenades
                            // dels successors de cada vèrtex
 
     // Aquí va l’especificació dels mètodes privats addicionals
      void dfs(nat i, vector<bool>& visitados) const;
 
 };
 
 // Aquí va la implementació del mètode públic quantes_arestes_es_visiten i privats addicionals
      vector<nat> graf::quantes_arestes_es_visiten() const{
      //cuenta el numero de aristas de cada vertice
      
      	vector<nat> aristas(n, 0);
      	for(nat i = 0; i < n; i++) {
      		node_succ *p = a[i];
      		nat count = 0;
      			while(p != nullptr) {
      				count++;
      				p = p->_seg;
      			}
      	aristas[i] = count;
      }
      
      vector<nat> res(n, 0);
      
      for(nat i = 0; i < n; i++) {
      vector<bool> visitados(n, 0);
      dfs(i, visitados);
      	nat count = 0;
      		for(nat j = 0; j < n; j++) {
      			if(visitados[j]) {
      			count += aristas[j];
      			} 
      		}
      	res[i] = count;
      }
       
      return res;
      
      
      }
      
      
      void graf::dfs(nat i, vector<bool>& visitados) const{
      	visitados[i] = true;
      	node_succ *p = a[i];
      	while(p != nullptr) {
      		nat succ = p->_succ;
      		if(!visitados[succ]) dfs(succ, visitados); 
      		 p = p->_seg;
      	}
      }

      
      

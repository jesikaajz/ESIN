 #include <vector>
// #include<iostream>
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
 
     vector<nat> quants_vertexs_es_visiten() const;
     // Pre: Cert
     // Post: Retorna quants vèrtexs diferents es poden visitar (hi ha un camí)
     // des de cada vèrtex del graf, incloent a ell mateix.
 
   private:
     nat n; // Nombre de vèrtexs
     nat m; // Nombre d’arestes
     vector<vector<nat> > a; // Vectors amb els successors de cada vèrtex
 void dfs(nat i, vector<bool>& visited) const;
     // Aquí va l’especificació dels mètodes privats addicionals
 
 };
 
 // Aquí va la implementació del mètode públic quants_vertexs_es_visiten i privats addicionals

vector<nat> graf::quants_vertexs_es_visiten() const{

vector<nat> res(n, 0);

	for(nat i = 0; i < n; i++) {
		vector<bool> visitados(n, false);
		dfs(i, visitados);
		nat count = 0;
		for(nat j = 0; j< n; j++) {
			if(visitados[j] == true) count++;
		}
		
		res[i] = count;
	
	}


return res;

}


//Obtienes las posiciones visitadas     
void graf::dfs(nat i, vector<bool>& visited) const{

	visited[i] = true;
	//cout << a[i].size() << endl;
	for(nat j = 0; j < a[i].size(); j++) {
		nat n = a[i][j];
		if(!visited[n]) dfs(n, visited);
	}	

}


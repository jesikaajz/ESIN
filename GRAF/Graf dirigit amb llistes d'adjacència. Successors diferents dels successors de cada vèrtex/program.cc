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
 
     vector<nat> quants_succ_succ() const;
     // Pre: Cert
     // Post: Retorna quants successors diferents tenen els successors de cada vèrtex
     // del graf
 
   private:
     nat n; // Nombre de vèrtexs
     nat m; // Nombre d’arestes
     vector<vector<nat> > a; // Vectors amb els successors de cada vèrtex
 
     // Aquí va l’especificació dels mètodes privats addicionals
 };
 
      vector<nat> graf::quants_succ_succ() const{
      	vector<nat> res(n, 0);
      	for(nat i = 0; i < n; i++) {
      	vector<bool> visited(n, false);
      		for(nat j = 0; j < a[i].size(); j++) {
      			nat n = a[i][j];
      			for(nat k = 0; k < a[n].size(); k++) {
      			visited[a[n][k]] = true;
      			}
      		}
      	nat count = 0;
      	for(nat l = 0; l < n; l++) {
      	if(visited[l]) count++;
      	}
      	res[i] = count;
      	
      	}
      	return res;	
      }
 
 
 
 

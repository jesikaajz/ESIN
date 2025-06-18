#include <iostream>
 #include <vector>
 using namespace std;
 typedef unsigned int nat;
 
 template <typename T>
 class cua { // Cua no circular en memòria dinàmica
   public:
     cua();
     // Construeix una cua buida.
 
     ~cua();
     // Destrueix el p.i.
 
     cua(const vector<int> &v);
     // Crea cua amb els elements de v amb el mateix ordre.
 
     nat longitud() const;
     // Retorna el nombre d’elements del p.i.
 
     void mostra() const;
     // Mostra el p.i. pel canal estàndard de sortida.
 
     void elimina_majors_suma_anteriors();
     // Pre: c = C
     // Post: El resultat és C on s’han eliminat els elements que són majors
     // que la suma dels inserits abans que ells en la cua original C.
 
   private:
     struct node {
       T info;
       node* seg;
     };
     node* _pri; // Apunta al primer element de la cua
     node* _ult; // Apunta al darrer element de la cua
     nat _mida;
 
     // Aquí va l’especificació dels mètodes privats addicionals
 };
 
      template <typename T>
      void cua<T>:: elimina_majors_suma_anteriors(){
     // Pre: c = C
     // Post: El resultat és C on s’han eliminat els elements que són majors
     // que la suma dels inserits abans que ells en la cua original C.
     

   	  if(_pri == nullptr) return;
   	  int suma = 0;
   	  node *p = _pri;
   	  if(_pri == _ult) {
   	  	if(p->info > suma) {
   	  		_pri = _ult = nullptr;
   	  		delete p;
   	  		_mida--;
   	  	}
   	  	return;
   	  }
   	  else {
   	  		node *p = _pri;
   	  		int suma = 0;
   	  		node *pant = nullptr;
   	  		while(p != nullptr) {
   	  			node *temp = p;
   	  			p = p->seg;
   	  			int numT = temp->info;
   	  			if(numT > suma) {
   	  				if(temp == _pri) {
   	  					_pri = p;
   	  					 
   	  				}
   	  				else {
   	  					pant->seg = p;
   	  				}
   	  				 if(p == nullptr) _ult = pant;   		
   	  				delete temp;
   	  				_mida--;
   	  			}
   	  			else pant = temp;
   	  			suma += numT;	
   	  		} 
   	  }                                   
     }
 
 

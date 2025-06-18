 #include <iostream>
 using namespace std;
 typedef unsigned int nat;
 
 class dicc {
   public:
     // Constructora per defecte. Crea un diccionari buit.
     dicc();
 
     // Destructora
     ~dicc();
 
     // Insereix la clau k en el diccionari. Si ja hi era, no fa res.
     void insereix(const string &k);
 
     nat quantes_interval(string inicial, string final) const;
     // Pre: Les claus inicial i final estan en el diccionari
     // Post: Retorna el nombre de claus que compleixen: inicial <= clau <= final
 
   private:
     struct node {
       char _c;   // Símbol posició i-èssima de la clau
       node* _pf; // Primer fill, apunta a símbols de la següent posició
       node* _sg; // Següent germà, apunta a símbols de la mateixa posició
       node(const char &c, node* pf = NULL, node* sg = NULL);
     };
     node* _arrel;
 
     static void esborra_nodes(node* t);
     static node* insereix(node *t, nat i, const string &k);
nat compta_claus(node* t, const string &inicial, const string &final, string &actual) const;
     // Aquí va l’especificació dels mètodes privats addicionals
 };
 
 // Aquí va la implementació del mètode públic quantes_interval i privats addicionals
 
    // Mètode auxiliar per comptar les claus en l'interval
    nat dicc::compta_claus(node* t, const string &inicial, const string &final, string &actual) const {
        nat count = 0;
        if (t == nullptr) return 0;

        node* current = t;
        while (current != nullptr) {
            if (current->_c != '#') {
                actual += current->_c;
            }

            if (current->_c == '#') {
                // Compara 'actual' sense el '#'
                if (actual >= inicial && actual <= final) {
                    count += 1;
                }
            } else {
                // Continuar amb el primer fill si el prefix pot estar dins de l'interval
                if (actual <= final) {
                    count += compta_claus(current->_pf, inicial, final, actual);
                }
            }

            if (current->_c != '#') {
                // Retira el caràcter actual per continuar amb els germans
                actual.pop_back();
            }
            current = current->_sg;
        }
        return count;
    }
nat dicc::quantes_interval(string inicial, string final) const {
    string actual = "";
    return compta_claus(_arrel, inicial, final, actual);
}

 

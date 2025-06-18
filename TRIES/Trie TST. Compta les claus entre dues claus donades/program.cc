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
      char _c;    // Símbol posició i-èssima de la clau
      node* _esq; // Fill esquerra, apunta a símbols mateixa posició formant un BST
      node* _cen; // Fill central, apunta a símbols següent posició
      node* _dre; // Fill dret, apunta a símbols mateixa posició formant un BST
      node(const char &c, node* esq = NULL, node* cen = NULL, node* dre = NULL);
    };
    node* _arrel;

    static void esborra_nodes(node* t);
    static node* insereix(node *t, nat i, const string &k);
    void count_keys_in_range(node* t, string current, const string& inicial, const string& final, nat& count) const;

};


 nat dicc::quantes_interval(string inicial, string final) const {
        nat count = 0;
        count_keys_in_range(_arrel, "", inicial, final, count);
        return count;
    }
    
     // Funció auxiliar per comptar les claus dins de l'interval
    void dicc::count_keys_in_range(node* t, string current, const string& inicial, const string& final, nat& count) const {
        if (t == NULL) return;

        // Traverseix l'esquerra
        count_keys_in_range(t->_esq, current, inicial, final, count);

        if (t->_c == '#') {
            // Hem completat una clau
            if (inicial <= current && current <= final) {
                count++;
            }
        }
        else {
            // Afegim el caràcter actual a la clau i traverseix el centre
            string next = current + t->_c;
            count_keys_in_range(t->_cen, next, inicial, final, count);
        }

        // Traverseix la dreta
        count_keys_in_range(t->_dre, current, inicial, final, count);
    }


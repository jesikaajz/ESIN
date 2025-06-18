#include <iostream>
#include <vector>
using namespace std;
typedef unsigned int nat;

template <typename Clau>
class bst {
  public:
    // Constructora per defecte. Crea un BST buit.
    bst();

    // Destructora
    ~bst();
    
    // Insereix una clau al BST
    void inserir(const Clau &c);
    
    // Retorna un vector amb el recorregut in-ordre del BST
    void inordre(vector<Clau> &res) const;

  private:
    struct node {
      Clau _k;      // Clau
      node* _esq;   // fill esquerre
      node* _dret;  // fill dret
      node(const Clau &c, node *e=NULL, node *d=NULL) : _k(c), _esq(e), _dret(d) {}
    };
    node *_arrel;

    static void esborra_nodes(node* m);
    
    // Funcions auxiliars recursives
    static void inserir_node(node*& m, const Clau &c);
    static void inordre_node(node* m, vector<Clau> &res);
};

// Implementació del BST

template <typename Clau>
void bst<Clau>::inserir(const Clau &c) {
  inserir_node(_arrel, c);
}

template <typename Clau>
void bst<Clau>::inserir_node(node*& m, const Clau &c) {
  if (m == NULL) m = new node(c);
  else if (c < m->_k) inserir_node(m->_esq, c);
  else inserir_node(m->_dret, c);
}

template <typename Clau>
void bst<Clau>::inordre(vector<Clau> &res) const {
  inordre_node(_arrel, res);
}

template <typename Clau>
void bst<Clau>::inordre_node(node* m, vector<Clau> &res) {
  if (m != NULL) {
    inordre_node(m->_esq, res);
    res.push_back(m->_k);
    inordre_node(m->_dret, res);
  }
}

// Aquí va la implementació del procediment ordena
template <typename T>
void ordena(vector<T>& v) {
  bst<T> arbre;
  // Inserim tots els elements del vector al BST
  for (int i = 0; i < (int)v.size(); ++i) {
    arbre.inserir(v[i]);
  }

  // Ara fem el recorregut en in-ordre per tenir-los ordenats
  vector<T> res;
  arbre.inordre(res);

  // Assignem el resultat a v
  v = res;
}



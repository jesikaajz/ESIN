#include <cstdlib>
#include <vector>
using namespace std;
typedef unsigned int nat;

template <typename T>
class Arbre {

public:
  // Construeix un Arbre format per un únic node que conté a x.
  Arbre(const T &x);

  // Tres grans.
  Arbre(const Arbre<T> &a);
  Arbre& operator=(const Arbre<T> &a);
  ~Arbre() throw();

  // Col·loca l’Arbre donat com a darrer fill de l’arrel de l’arbre sobre el que s’aplica el mètode i l’arbre a queda invalidat; després de fer b.afegir_fill(a), a no és un arbre vàlid.
  void afegir_darrer_fill(Arbre<T> &a);

  static const int ArbreInvalid = 400;

  vector<T> compta_elements_nivells() const;
  // PRE: Cert
  // POST: Retorna un vector amb el nombre d’elements de cada nivell de l’arbre.

private:
  Arbre(): _arrel(nullptr) {};
  struct node {
    T info;
    node* primf;
    node* seggerm;
  };
  node* _arrel;
  static node* copia_arbre(node* p);
  static void destrueix_arbre(node* p) throw();
void compta_elements_nivells_rec(node *p, vector<T>& res, nat nivell) const;
  // Aquí va l’especificació dels mètodes privats addicionals

};

// Aquí va la implementació del mètode compta_elements_nivells i privats addicionals
 template <typename T>
 vector<T> Arbre<T>::compta_elements_nivells() const {
 vector<T> res;
 nat contador = 0;
 compta_elements_nivells_rec(_arrel, res, contador);
 return res;
 }
template <typename T>
void Arbre<T>::compta_elements_nivells_rec(node *p, vector<T>& res, nat nivell) const {
    // PRE: Cert
    // POST: Actualitza el vector `res` amb el nombre d'elements en cada nivell.

    if (p == nullptr) return;

    // Ens assegurem que el vector té prou espai per aquest nivell
    if (res.size() <= nivell) res.push_back(0);

    // Incrementem el comptador per aquest nivell
    res[nivell]++;

    // Processar els fills del node actual
    node *fill = p->primf;
    while (fill != nullptr) {
        compta_elements_nivells_rec(fill, res, nivell + 1);
        fill = fill->seggerm;
    }
}

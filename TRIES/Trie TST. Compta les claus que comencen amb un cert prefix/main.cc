#include <sstream>
using namespace std;

dicc::dicc() : _arrel(nullptr) {}

dicc::~dicc() {
  esborra_nodes(_arrel);
}

void dicc::esborra_nodes(node* t) {
  if (t != nullptr) {
    esborra_nodes(t->_esq);
    esborra_nodes(t->_cen);
    esborra_nodes(t->_dre);
    delete t;
  }
}

dicc::node::node(const char &c, node* esq, node* cen, node* dre) :
	_c(c), _esq(esq), _cen(cen), _dre(dre) {
}

typename dicc::node* dicc::insereix(node *t, nat i, const string &k) {
  if (t == nullptr) {
    t = new node(k[i]);
    try {
      if (i < k.length()-1) {
        t->_cen = insereix(t->_cen, i+1, k);
      }
    }
    catch (...) {
      delete t;
      throw;
    }
  } else {
    if (t->_c > k[i]) {
      t->_esq = insereix(t->_esq, i, k);
    }
    else if (t->_c < k[i]) {
      t->_dre = insereix(t->_dre, i, k);
    }
    else { // (t->_c == k[i])
      if (i < k.length()-1)
        t->_cen = insereix(t->_cen, i+1, k);
    }
  }
  return t;
}

void dicc::insereix (const string &k) {
  _arrel = insereix(_arrel, 0, k + '#'); // Símbol # és la marca de fi de clau
}

int main() {
  string input;
  dicc d;
  cin >> input;
  while (input != "----------") {
    d.insereix(input);
    cin >> input;
  }
  getline(cin, input); // Llegeix darrer canvi de línea (\n)

  while (getline(cin, input)) {
    cout << d.quantes_comencen(input) << " comencen per " << input << endl;
  }
  return 0;
}

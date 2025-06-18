#include <iostream>
#include <vector>
using namespace std;

void ordena(vector<nat>& v);

void mostra(vector<nat> v) {
  for (nat i=0; i < v.size(); ++i) {
    cout << v[i] << ' ';
  }
  cout << endl;
}

int main() {
  nat n;
  while (cin >> n) {
    vector<nat> v(n);
    for (nat i=0; i < n; ++i) {
      cin >> v[i];
    }

    ordena(v);

    mostra(v);
  }
  return 0;
}

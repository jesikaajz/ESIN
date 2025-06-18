#include <iostream>
#include <queue>
using namespace std;

template <typename T>
void ordena(queue<T>& c);

template <typename T>
void mostra(queue<T> c) {
  while (not c.empty()) {
    cout << c.front() << ' ';
    c.pop();
  }
  cout << endl;
}

int main() {
  int n;
  while (cin >> n) {
    queue<double> c;
    for (int i=0; i<n; ++i) {
      double x;
      cin >> x;
      c.push(x);
    }

    ordena<double>(c);

    mostra<double>(c);
  }
  return 0;
}

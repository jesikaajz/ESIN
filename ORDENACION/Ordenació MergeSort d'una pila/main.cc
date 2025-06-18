#include <iostream>
#include <stack>
using namespace std;

template <typename T>
void ordena(stack<T>& p);

template <typename T>
void mostra(stack<T> p) {
  while (not p.empty()) {
    cout << p.top() << ' ';
    p.pop();
  }
  cout << endl;
}

int main() {
  int n;
  while (cin >> n) {
    stack<double> p;
    for (int i=0; i<n; ++i) {
      double x;
      cin >> x;
      p.push(x);
    }

    ordena<double>(p);

    mostra<double>(p);
  }
  return 0;
}

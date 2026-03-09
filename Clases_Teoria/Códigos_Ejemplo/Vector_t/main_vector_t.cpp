#include "vector_t.hpp"

using namespace std;

int main() {

  vector_t v(6), w, z(v);
  v.SetVal(0,7);      // v[0] = 7;
  cout << v.GetVal(0) << endl;

  w.ReSize(20);
  v.Write();
  // 6: 7 0 0 0 0 0
  // vector_t<double> y(10);


  return 0;
}

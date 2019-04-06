#include <iostream>
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <memory.h>
#include <cmath>
using namespace std;

double T[20][20];
double v_a[20], v_b[20];
double l;
int n, t;
double Norm(double *v, int n)
{
  double len = 0.0;
  for(int i = 0; i < n; ++i)
    len += v[i] * v[i];
  return sqrt(len);
}

int main()
{
  cout << "Dimension: " << endl;
  cin >> n;
  for(int i = 0; i < n; ++i) {
    cout << "Row " << i+1 << ": " << endl;
    for(int j = 0; j < n; ++j)
      cin >> T[i][j];
  }
  cout << "Number of iterations: " << endl;
  cin >> t;
  cout << "Initial vector: " << endl;
  for(int i = 0; i < n; ++i) cin >> v_b[i];
  cout << "----------------------" << endl; 
  for(int i = 0; i < t; ++i) {
    cout << "Iteration " << i+1 << endl;
    memcpy(v_a, v_b, sizeof(v_b)); // v_a = v_b
    memset(v_b, 0, sizeof(v_b)); // clear v_b
    for(int i = 0; i < n; ++i) // matrix-vector multiplication of T*v
      for(int j = 0; j < n; ++j) 
        v_b[i] += T[i][j] * v_a[j];
    l = Norm(v_b, n); // k+1-th Eigenvalue
    for(int i = 0; i < n; ++i)
      v_b[i] /= l; // k+1-th Eigenvector
    printf("lambda[%d]:=%.4f\n", i, l);
    printf("v[%d]:=[ ", i);
    for(int i = 0; i < n; ++i) printf("%.4f ", v_b[i]);
    printf("]\n");
  }
  cout << "Final lambda = " << l << endl;
  cout << "Final vector = [ ";
  for(int i = 0; i < n; ++i) cout << v_a[i] << " ";
  cout << "] " << endl;
  return 0;
}


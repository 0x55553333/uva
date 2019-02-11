#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <utility>
#include <memory.h>
using namespace std;

double A[200][200];

void gaussian_elimination(int n)
{
  int i, j, k, r;
  for(i = 0; i < n; ++i) {
    // row exchanges (partial pivoting)
    r = i;
    // Find the row with the largest absolute pivot value
    for(j = i+1; j < n; ++j) 
      if (fabs(A[j][i]) > fabs(A[r][i])) r = j; 
    // Swap two rows
    if (r != i) for(j = 0; j <= n; ++j) swap(A[r][j], A[i][j]);

    // elimination: For each row k below row i,
    // subtract A[k][i] / A[i][i] * A[i][j]
    // to clear out the entries below A[i][i]
    for(k = i + 1; k < n; ++k) {
      double f = A[k][i] / A[i][i];
      for(j = i; j <= n; ++j) A[k][j] -= f * A[i][j];
    }
  }
}

void back_substitution(int n)
{
  int i, j;
  for(i = n-1; i >= 0; --i) {
    for(j = i+1; j < n; ++j) 
      A[i][n] -= A[j][n] * A[i][j];
    A[i][n] /= A[i][i];
  }
}

void print_matrix(int n)
{
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < n; ++j) 
      printf("%.3f ", A[i][j]);
    printf("\n");
  }
}

int main()
{
  int n;
  while (cin >> n) {
    for(int i = 0; i < n; ++i)
      for(int j = 0; j < n; ++j) 
        cin >> A[i][j];
    gaussian_elimination(n);
    printf(" - after gauss - \n");
    print_matrix(n);
    back_substitution(n);
    printf(" - after backsub - \n");
    print_matrix(n);
  }
  return 0;
}


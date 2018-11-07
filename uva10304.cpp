#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <utility>
#include <memory.h>
using namespace std;
#define MAXN 300
int M[MAXN][MAXN];
int W[MAXN];
int K[MAXN][MAXN];
int ch[MAXN][MAXN];
int n;

int w(int i, int j)
{
  if (i == 0) return W[j];
  else return W[j] - W[i - 1];
}

int opt(int i, int j);
int _opt(int i, int j)
{
  int s = 0xffff;
  opt(i, j-1); opt(i+1, j);
  int L = K[i][j-1] == -1 ? i : K[i][j-1],
      R = K[i+1][j] == -1 ? j : K[i+1][j];
  for(int k = L, ps; k <= R; ++k)
    if ((ps = opt(i, k-1) + opt(k+1, j) + w(i, k-1) + w(k+1, j)) < s) {
      s = ps;
      K[i][j] = k;
    }
  return s;
}
int opt(int i, int j)
{
  if (i == j || j < i) {
    K[i][j] = -1;
    return 0;
  }
  if (ch[i][j])
    return M[i][j];
  else {
    ch[i][j] = 1;
    return M[i][j] = _opt(i, j);
  }
}
int main()
{
  while (cin >> n) {
    if (n < 1 || n > 250)
      break;
    memset(M, 0, sizeof(M));
    memset(W, 0, sizeof(W));
    memset(K, 0, sizeof(K));
    memset(ch, 0, sizeof(ch));
    cin >> W[0];
    for(int i = 1; i < n; ++i) {
      cin >> W[i];
      W[i] += W[i - 1];
    }
    printf("%d\n", opt(0, n-1));
  }
  return 0;
}


#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <memory.h>
using namespace std;
#define MAXN 30
int n, A[MAXN], B[MAXN], M[MAXN][MAXN], ch[MAXN][MAXN];

int LCS(int i, int j);
int _LCS(int i, int j) 
{
  int k;
  if (A[i] != B[j]) {
    k = max(LCS(i-1, j), LCS(i, j-1));
//    printf("Match[%d][%d]=%d\n", i, j, k);
  } else {
    k = LCS(i-1, j-1) + 1;
  //  printf("Match[%d][%d]=%d\n", i, j, k);
  }
  return k;
}
int LCS(int i, int j)
{
  if (i < 0 || j < 0) 
    return 0;
  if (ch[i][j])
    return M[i][j];
  else {
    ch[i][j] = 1;
    return M[i][j] = _LCS(i, j);
  }
}

int main()
{
  cin >> n;
  for(int i = 0, r; i < n; ++i) {
    scanf("%d", &r);
    A[r-1] = i;
  }
  while (1) {
    memset(B, 0, sizeof(B));
    memset(M, 0, sizeof(M));
    memset(ch, 0, sizeof(ch));
    for(int i = 0, r; i < n; ++i) {
      if (scanf("%d", &r) != 1)
        goto _exit;
      B[r-1] = i;
    }
    printf("%d\n", LCS(n-1, n-1));
  }
_exit:
  return 0;
}


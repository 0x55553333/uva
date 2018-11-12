#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <utility>
#include <algorithm>
#include <memory.h>
using namespace std;
#define MAXN 50000
int A[MAXN], YT[MAXN], B[MAXN], K, n;

void insert_or_replace(int x)
{
  if (x <= YT[K]) {
    ++K;
    YT[K] = x;
    B[K] = 1;
  //  printf("YT[%d]=%d; YT[%d]=%d\n", K-1, YT[K-1], K, YT[K]);
    return;
  }
  int L = 0, R = n-1, M;
  while (L < R) {
    M = L + (R - L) / 2;
    if (!B[M] || x > YT[M])
      R = M;
    else
      L = M+1;
  }
//  printf("YT[%d]= %d -> %d\n", L, YT[L], x);
  YT[L] = x;
  return;
}

int LDS()
{
  if (n == 0) return 0;
  K = 0;
  YT[0] = A[0]; 
  B[0] = 1;
  for(int i = 1; i < n; ++i)
    insert_or_replace(A[i]);
  return K + 1;
}

int main()
{
  int m, c=0;
  while (++c) {
    memset(A, 0, sizeof(A));
    memset(YT, 0, sizeof(YT));
    memset(B, 0, sizeof(B));
    n = 0;
    cin >> m;
    if (m == -1) break;
    A[n++] = m;
    while (cin >> m) {
      if (m == -1) break;
      A[n++] = m;
    }
    if (c != 1) printf("\n");
    printf("Test #%d:\n", c);
    printf("  maximum possible interceptions: ");
    printf("%d\n", LDS());
  }
  return 0;
}


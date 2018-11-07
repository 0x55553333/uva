#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <utility>
#include <memory.h>
#include <memory.h>
using namespace std;

#define MAXN 1000
int A[MAXN];
int n, k;

int largest(int i, int s, int k)
{
  int partial = s + A[i] - A[i + k];
  if (i == 0)
    return partial;
  int accum = max(largest(i-1, partial, k), partial);
  return accum;
}

int main()
{
  while (cin >> n >> k) {
    memset(A, 0, sizeof(A));
    for(int i = 0; i < n; ++i)
      cin >> A[i];
    if (n < k) {
      cout << "N/A\n";
      continue;
    }
    int s = 0;
    for(int i = 0; i < k; ++i)
      s += A[n-1-i];
    printf("%d\n", max(largest(n-1-k, s, k), s));
  }
  return 0;
}


#include <iostream>
#include <cstdio>
#include <memory.h>
using namespace std;

/* O(n log n) time, O(n) space
   LIS implementation using the
   Young Tableau technique from
   (Fredman 1975) */

int* B, /* original array */
  *YT, /* The principle row of the Young Tableau */
  *H, /* Boolean array storing filled entries of YT */
  n, /* size of B */
  K; /* Max filled entry index in YT, also the LIS */

void insert_or_replace(int x)
{
    /* Insert */
    if (YT[K] < x) {
        ++K;
        H[K] = 1;
        YT[K] = x;
        return;
    }
    
    int L = 0, R = n-1, M = 0;

    /* Replace, using Lower bound binary search */
    while (L < R) {
        M = L + (R - L) / 2;
        if (!H[M] || x <= YT[M]) {
            R = M; 
        } else {
            L = M + 1;
        }
    } 
    YT[L] = x;
    return;
}

int solve()
{
    K = 0;
    YT[0] = B[0];
    H[0] = 1;
    for(int i = 1; i < n; ++i)
        insert_or_replace(B[i]);
    return K+1;     
}

int LIS(int* A, int len) 
{
    if (len == 0) return 0;
    B = A; n = len;
    YT = malloc(sizeof(int) * len);
    H = malloc(sizeof(int) * len);
    memset(YT, 0, sizeof(int) * len);
    memset(H, 0, sizeof(int) * len);
    int ans = solve();
    free(H); free(YT);
    return ans;
}

int main()
{ int N;
  while (cin>>N) {
    int *A = malloc(sizeof(int)*N);
    for(int i = 0; i < N; ++i)
      cin >> A[i];
    printf("%d\n", LIS(A, N));
    free(A);
  }
  return 0; 
}


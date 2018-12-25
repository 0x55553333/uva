#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <utility>
#include <memory.h>
using namespace std;
int M, C, Cs[30], Ks[30][30], memo[30][300], v[30][300];

int opt(int i, int m);
int _opt(int i, int m)
{
  int ans = 0xffffff;
  
  if (i == 0) {
    for(int k = 0; k < Cs[i]; ++k)
      if (Ks[i][k] <= m)
        ans = min(ans, m - Ks[i][k]);
    return ans;
  }

  for(int k = 0; k < Cs[i]; ++k) 
    if (Ks[i][k] <= m)
      ans = min(ans, opt(i-1, m-Ks[i][k]));
  return ans;
}
int opt(int i, int m)
{ 
  if (v[i][m]) return memo[i][m];
  else {
    v[i][m] = 1;
    return memo[i][m] = _opt(i, m);
  }
}

int main()
{
  int T;
  cin >> T;
  while (T--) {
    memset(Ks, 0, sizeof(Ks));
    memset(Cs, 0, sizeof(Cs));
    memset(memo, 0, sizeof(memo));
    memset(v, 0, sizeof(v));
    cin >> M >> C;
    for(int i = 0; i < C; ++i) {
      cin >> Cs[i];
      for(int j = 0; j < Cs[i]; ++j) 
        cin >> Ks[i][j];
    }
    if (opt(C-1, M)>M)
      printf("no solution\n");
    else {
      printf("%d\n", M-opt(C-1, M));
    }
  }
  return 0;
}


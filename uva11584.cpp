#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <utility>
#include <memory.h>
using namespace std;
string x;
int n, t;

int memo[2000];

int ispal(int l, int r)
{
  if (l > r) exit(1);
  for(int pl =l, pr = r; pl <= r; ++pl, --pr) {
    if (x[pl] != x[pr]) return 0;
  }
  return 1;
}

int solve(int k)
{
  int ans = 0xfffff;
  if (k == -1) return 0;
  if (k == 0) return 1;
  if (memo[k] != 0) return memo[k];
  for(int i = 0; i <= k; ++i) 
    if (ispal(i, k)) {
      ans = min(ans, solve(i - 1) + 1);
//      printf("x[%d...%d] is pal\n", i, k);
    }
  return memo[k] = ans;
}

int main()
{
  cin >> t;
  while (t--) {
    cin >> x;
    n = (int) x.size();
    memset(memo, 0, sizeof(memo));
    cout << solve(n-1) << endl;
  }
  return 0;
}


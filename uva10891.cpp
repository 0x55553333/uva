#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <utility>
#include <memory.h>
#include <cmath>
using namespace std;
int N;
long long A[120], ps[120], memo[2][120][120], vis[2][120][120];

long long rsq(int i, int j)
{
  return ps[j] - ps[i - 1];
}

long long playB(int i, int j);
long long playA(int i, int j);
// return searnings of player A
// under optimal strategy when
// player B plays first
long long _playB(int i, int j)
{
//  if (i > j) return 0;
  if (i == j) {
    // game over
    return 0;
  }
  int len = j - i + 1;
  long long ans = 0xffffffffffff;
  for(int k = 0; k < len; ++k) {
    ans = min(ans, min(playA(i+k+1, j), playA(i, j-k-1)));
  }
  ans = min(ans, 0LL);
  return ans;
}

// returns earnings of player A
// under optimal strategy when
// player A plays first
long long _playA(int i, int j)
{
  if (i == j) {
    // game over
    return A[i];
  }
  int len = j - i + 1;
  long long ans = -0xffffffffffff;
  for(int k = 0; k < len; ++k) {
    ans = max(ans, max(playB(i+k+1, j) + rsq(i, i+k),
          playB(i, j-k-1) + rsq(j-k, j)));
  }
  ans = max(ans, rsq(i, j));
  return ans;
}

long long playB(int i, int j)
{
  if (vis[1][i][j]) return memo[1][i][j];
  else {
    vis[1][i][j] = 1;
    return memo[1][i][j] = _playB(i, j);
  }
}

long long playA(int i, int j)
{
  if (vis[0][i][j]) return memo[0][i][j];
  else {
    vis[0][i][j] = 1;
    return memo[0][i][j] = _playA(i, j);
  }
}

int main()
{
  while (cin >> N) {
    memset(A, 0, sizeof(A));
    memset(ps, 0, sizeof(ps));
    memset(memo, 0, sizeof(memo));
    memset(vis, 0, sizeof(vis));
    if (N <= 0) break;
    for(int i = 1; i <= N; ++i) {
      cin >> A[i];
      ps[i] = A[i] + ps[i - 1];
    }
    long long pointsA = playA(1, N),
        pointsB = ps[N] - pointsA;
    printf("%lld\n",(pointsA -pointsB));
  }
  return 0;
}


#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <utility>
#include <memory.h>
#include <cmath>
using namespace std;
#define MAXN 20000
int n;
pair<double, double> SX[MAXN];
double dist(double x1, double y1, double x2, double y2)
{
  return sqrt( (y2-y1)*(y2-y1) + (x2-x1) * (x2-x1));
}
const static double eps = 0.000000001;
double solve(int si, int sj)
{
  double bestD = (double) 0xffff, 
         bestD_L, bestD_R;
  pair<double, double> xp;
  if (sj - si <= 3) {
    for(int i = si; i <= sj; ++i)
      for(int j = si; j <= sj; ++j)
        if (j != i)
          bestD = min(bestD, dist(SX[i].first, SX[i].second, SX[j].first, SX[j].second));
    return bestD;
  }
  bestD_L = solve(si, si + (sj-si)/2);
  bestD_R = solve(si + (sj-si)/2+1, sj);
  xp = SX[si+(sj-si)/2];
  bestD = min(bestD_L, bestD_R);
  // our pruning strategy is imperfect;
  // on carefully crafted inputs this becomes O(n^2).
  // If that's the case, we have to add SY[] sorted by increasing
  // Y coords and do the constant lookahead 
  for(int i = si + (sj - si) / 2; i >= 0; --i) {
    if (abs(SX[i].first - xp.first) >= bestD) break;
    for(int j = si + (sj - si) / 2 + 1; j < n; ++j) {
      if (abs(SX[j].first - SX[i].first) >= bestD) break;
      bestD = min(bestD, dist(SX[i].first, SX[i].second, SX[j].first, SX[j].second));
    }
  }
  return bestD;
}

int main()
{
  while (cin >> n) {
    if (n == 0) break;
    memset(SX, 0, sizeof(SX));
    for(int i = 0; i < n; ++i) {
      SX[i].first = SX[i].second = 0;
      cin >> SX[i].first >> SX[i].second;
    }
    sort(SX, SX + n,
        [](pair<double,double>& a, pair<double,double>& b) {return a.first < b.first;});
    double bestD = solve(0, n-1);
    if (bestD - eps >= 10000) printf("INFINITY\n");
    else printf("%.4f\n", bestD);
  } 
  return 0;
}


#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <utility>
#include <memory.h>
using namespace std;
int N;
vector<int> f;

pair<int,int> find_cycle(int x0)
{
  int t = f[x0], h = f[f[x0]];
  while (t != h) {
    t = f[x0]; h = f[f[x0]];
  }
  int lambda = 1, mu = 0; h = x0;
  while (t != h) {
    t = f[t]; h = f[h]; ++mu;
  }
  h = f[t];
  while (t != h) {
    h = f[h]; ++lambda;
  }
  return make_pair(lambda, mu);
}

int main()
{ cin >> N; 
  f.assign(N, 0);
  for(int i = 0; i < N; ++i) 
    cin >> f[i];
  pair<int,int> p = find_cycle(0);
  cout << p.first << p.second << endl;
  return 0;
}



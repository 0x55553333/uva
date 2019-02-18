#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <memory.h>
using namespace std;
int N, T;
vector< vector<int> > c;

int dfs(int u)
{
  if (c[u].size()==0) return 1;
  vector<int> as;
  int t = (c[u].size() * T - 1) / 100 + 1;
  for(int i = 0; i < c[u].size(); ++i) {
    as.push_back(dfs(c[u][i]));  
  }  
  sort(as.begin(), as.end());
  int s = 0;
  for(int i = 0; i < t; ++i) s += as[i];
  return s;
}

int main()
{
  while (cin >> N >> T) {
    if ( N == T && N == 0) break;
    c.assign(N+1, vector<int>());
    for(int i = 1, b; i <= N; ++i) {
      cin >> b;
      c[b].push_back(i); // b->i
    }
    cout << dfs(0) << endl;
  }
  return 0;
}


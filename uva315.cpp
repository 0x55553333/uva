#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <utility>
#include <sstream>
#include <memory.h>
using namespace std;

vector< vector<int> > g;
int N, cnt = 1, tot;

vector<int> pre, low, artpts;
void dfs (int u, int p)
{ int ch = 0;
  low[u] = pre[u] = cnt;
  ++cnt;
  for(int i = 0; i < g[u].size(); ++i) {
    int v = g[u][i];
    if (pre[v] == 0) {
      ++ch;
      dfs(v, u);
      low[u] = min(low[u], low[v]);
      if (low[v] >= pre[u]) {
        artpts[u] = 1; 
      }
    } else if (pre[v] < pre[u] && v != p) 
      low[u] = min(low[u], pre[v]);
  }
  if (p < 0 && ch == 1) {
    artpts[u] = 0;
  }
}


int main()
{ int k, v;
  string x;
  while (cin >> N) {
    if (N==0) break;
    tot = 0;
    g.clear(); pre.clear();
    low.clear(); artpts.clear();
    g.assign(N+1, vector<int>());
    pre.assign(N+1, 0); 
    low.assign(N+1, 0);
    artpts.assign(N+1, 0);
    while (1) {
      stringstream xs;
      getline(cin, x); 
      if (x == "0") break;
      xs << x << endl;
      xs >> v; 
      while (xs >> k) {
        g[v].push_back(k);
        g[k].push_back(v);
      }

    }
    for(int i = 1; i <= N; ++i) 
      if (pre[i] == 0) dfs(i, -1);
    for(int i = 1; i <= N; ++i) {
      tot += artpts[i];}
    cout << tot << endl;
  }
  return 0;
}

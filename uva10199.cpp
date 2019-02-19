#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <utility>
#include <vector>
#include <memory.h>
#include <map>
using namespace std;

struct Graph {
  vector< vector<int> > list;
  map<string, int> to;
  vector<string> from;
  vector<int> pre;
  vector<int> low;
  vector<int> artpts;
  int N; int R; int cnt;
  void reset()
  { list.clear(); artpts.clear();
    pre.clear(); low.clear();
    from.clear(); to.clear();
    cnt = 1; 
    list.assign(N, vector<int>());
    pre.assign(N, 0);
    low.assign(N, 0);
    artpts.assign(N, 0);
  }
};
Graph g;

void dfs(int u, int p)
{
  g.pre[u] = g.low[u] = g.cnt;
  g.cnt++;
  int ch = 0;
  for(int i = 0; i < g.list[u].size(); ++i) {
    int v = g.list[u][i];
    if (g.pre[v] == 0) {
      ++ch;
      dfs(v, u);
      g.low[u] = min(g.low[u], g.low[v]);
      if (g.low[v] >= g.pre[u]) 
        g.artpts[u] = 1;
    } else if (g.pre[v] < g.pre[u] && v != p) 
      g.low[u] = min(g.low[u], g.pre[v]);
  }
  if (p < 0 && ch == 1)
    g.artpts[u] = 0;
}

int main()
{ int d = 1; string s, t;
  while (cin >> g.N) {
    if (g.N==0) break;
    g.reset();
    for(int i = 0; i < g.N; ++i) {
      cin >> s; g.to[s] = i;
      g.from.push_back(s);
    }
    cin >> g.R;
    for(int i = 0; i < g.R; ++i) {
      cin >> s; cin >> t;
      g.list[g.to[s]].push_back(g.to[t]);
      g.list[g.to[t]].push_back(g.to[s]);
    }
    for(int i = 0; i < g.N; ++i) 
      if (g.pre[i] == 0) dfs(i, -1);
    vector<string> output;
    for(int i = 0; i < g.N; ++i)
      if (g.artpts[i]) 
        output.push_back(g.from[i]);
    sort(output.begin(), output.end());
    if (d != 1) printf("\n");
    printf("City map #%d: %lu camera(s) found\n", d, output.size());
    for(const string& x : output) cout << x << endl;
    ++d;
  }
}


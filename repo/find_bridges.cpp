#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#include <memory.h>
using namespace std;

vector< pair<int,int> > g;
vector<int> pre, low;
vector<int> is_bridge;
set<int> vertices;
int M, N, cnt = 1;

void find_bridges(int u, int p)
{
  pre[u] = low[u] = cnt;
  ++cnt;
  auto i = lower_bound(g.begin(), g.end(), make_pair(u,0));
  if ((*i).first != u) return;
  while ((*i).first == u) {
    int v = (*i).second;
    if (pre[v] == 0) {
      find_bridges(v, u);
      low[u] = min(low[u], low[v]);
      if (low[v] > pre[u]) 
        is_bridge[(i - g.begin())] = 1;
    } else if (pre[v] < pre[u] && v != p) 
      low[u] = min(low[u], pre[v]);
    ++i;
  }
}

int main()
{
  while (cin >> M) {
    cnt = 1;
    pre.clear(); low.clear();
    is_bridge.clear();
    g.clear();
    for(int i = 0; i < M; ++i) {
      int u, v; cin >> u >> v;
      g.push_back(make_pair(u,v));
      g.push_back(make_pair(v,u));
      vertices.insert(u); 
      vertices.insert(v);
    } 
    N = vertices.size();
    pre.assign(N, 0);
    low.assign(N, 0);
    is_bridge.assign(M, 0);
    sort(g.begin(), g.end());
    for(const int& u : vertices)
      if (pre[u] == 0) 
        find_bridges(u, -1);
    int bcount = 0;
    for(int i = 0; i < M; ++i) 
      if (is_bridge[i]) ++bcount;
    cout << bcount << endl;
  }
  return 0;
}

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <utility>
#include <memory.h>
#include <queue>
using namespace std;
// Bellman-Ford SSSP with Yen's improvement
// (using a queue)
struct Vtx { int to; int w;
  Vtx(int t, int w) : to(t), w(w) {}
  Vtx() {}};
struct AdjList {
  vector<int> inQ;
  vector<int> dist;
  vector<int> cnt; // for cycle detection
  vector<int> parent;
  vector< vector<Vtx> > list;
  AdjList(size_t n) 
  { this->inQ.assign(n, 0);
    this->dist.assign(n, 0xfffff);
    this->cnt.assign(n, 0);
    this->parent.assign(n, -1);
    this->list.assign(n, vector<Vtx>()); }
  void add_directed_edge(int u, int v, int w)
  { list[u].push_back(Vtx(v, w)); }
  void add_edge(int u, int v, int w)
  { add_directed_edge(u, v, w); 
    add_directed_edge(v, u, w); }
  // returns 1 if valid sssp found;
  // 0 otherwise
  int bellman_ford(int s)
  { queue<Vtx> Q;
    dist[s] = 0; inQ[s] = 1;
    Q.push(Vtx(s, 0));
    while (!Q.empty()) {
      Vtx curr = Q.front(); Q.pop();
      inQ[curr.to] = 0;
      for(const Vtx& next : list[curr.to]) 
        if (dist[curr.to] + next.w <= dist[next.to]) {
          dist[next.to] = dist[curr.to] + next.w;
          parent[next.to] = curr.to;
          if (!inQ[next.to]) {
            Q.push(next);
            inQ[next.to] = 1;
            ++cnt[next.to];
            if (cnt[next.to] > list.size())
              return 0;
          }
        }
    }
    return 1;
  }
};

int main()
{
  size_t nV, nE; cin >> nV >> nE;
  int src_vtx;
  AdjList G(nV);
  for(int i = 0; i < nE; ++i) {
    int u, v, w; cin >> u >> v >> w;
    G.add_edge(u, v, w);
  }
  cin >> src_vtx;
  if (!G.bellman_ford(src_vtx)) 
    printf("No SSSP: Graph has neg-weight cycle\n");
  else {
    for(int i = 0; i < nV; ++i) {
      if (G.dist[i] < 0xfffff)
        printf("from %d to %d: %d\n", src_vtx, i, G.dist[i]);
      else
        printf("from %d to %d: No route found\n", src_vtx, i);
    }
  }
  return 0;
}


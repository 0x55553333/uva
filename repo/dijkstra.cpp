#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <utility>
#include <memory.h>
#include <queue>
using namespace std;
// dijkstra's SSSP
struct Vtx { int to; int w; 
  Vtx(int t, int w): to(t), w(w) {}
  Vtx() {}};
auto VtxCmp = [](const Vtx& lhs, const Vtx& rhs)
  { if (lhs.w == rhs.w) return lhs.to > rhs.to;
    return lhs.w > rhs.w; };
struct AdjList {
  vector< vector<Vtx> > list;
  vector<int> dist;
  vector<int> parent;
  vector<int> taken;
  AdjList(size_t nV)
  { this->list.assign(nV, vector<Vtx>());
    this->dist.assign(nV, 0xfffff);
    this->taken.assign(nV, 0);
    this->parent.assign(nV, -1);}};

void dijkstra(AdjList& G, int s)
{
  if (s >= G.list.size()) return;
  G.dist[s] = 0;
  priority_queue<Vtx, vector<Vtx>, decltype(VtxCmp)> 
    Q(VtxCmp);
  Q.push(Vtx(s, 0));
  while (!Q.empty()) {
    Vtx curr = Q.top(); Q.pop();
    if (!G.taken[curr.to]) {
      G.taken[curr.to] = 1;
      for(const Vtx& next : G.list[curr.to]) 
        if (!G.taken[next.to] && 
            G.dist[curr.to] + next.w <= G.dist[next.to]) {
          G.dist[next.to] = G.dist[curr.to] + next.w;
          G.parent[next.to] = curr.to;
          Q.push(next);
        }
    }
  }
}

int main()
{
  size_t N, M; cin >> N >> M;
  int src_vtx;
  AdjList G(N);
  for(int i = 0; i < M; ++i) {
    int u, v, w; cin >> u >> v >> w;
    G.list[u].push_back(Vtx(v, w));
    G.list[v].push_back(Vtx(u, w));
  }
  cin >> src_vtx;
  dijkstra(G, src_vtx);
  for(int i = 0; i < N; ++i) 
    if (G.dist[i] >= 0xfffff)
      printf("%d to %d: No route\n", src_vtx, i);
    else 
      printf("%d to %d: cost %d\n", src_vtx, i, G.dist[i]);
  return 0;
}


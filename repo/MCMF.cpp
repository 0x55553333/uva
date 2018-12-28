#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <utility>
#include <memory.h>
#include <queue>
using namespace std;
// MCMF from Edmonds-Karp + Bellman-Ford

struct Edge {
  int from, to, cap, flow, cost;
  Edge(int u, int v, int c, int f, int w):
    from(u), to(v), cap(c), flow(f), cost(w) {}
};

struct MCMF {
  size_t n, m; // |V|, |E|
  vector<Edge> edges;
  vector< vector<int> > G;
  vector<int> inQ, d, p, a; 
  MCMF(size_t n)
  {
    this-> n = n;
    G.assign(n, vector<int>());
    inQ.assign(n, 0);
    d.assign(n, 0xfffff);
    p.assign(n, -1);
    a.assign(n, 0);
  }

  void add_edge(int from, int to, int cap, int cost)
  {
    edges.push_back(Edge(from, to, cap, 0, cost));
    edges.push_back(Edge(to, from, 0, 0, -cost));
    m = edges.size();
    G[from].push_back(m-2);
    G[to].push_back(m-1);
  }

  bool bellman_ford(int s, int t, int& flow, long long& cost)
  {
    this->inQ.assign(n, 0);
    queue<int> Q;
    while (!Q.empty()) {
      int u = Q.front(); Q.pop();
      inQ[u] = 0;
      for(int i = 0; i < G[u].size(); ++i) {
        Edge& e = edges[G[u][i]];
        if (e.cap > e.flow && d[e.to] > d[u] + e.cost) {
          d[e.to] = d[u] + e.cost;
          p[e.to] = G[u][i];
          a[e.to] = min(a[u], e.cap - e.flow);
          if (!inQ[e.to]) {
            Q.push(e.to); 
            inQ[e.to] = 1;
          }
        }
      }
    }
    if (d[t] >= 0xfffff) return 0;
    flow += a[t];
    cost += (long long) d[t] * (long long) a[t];
    for(int u = t; u != s; u = edges[p[u]].from) {
      edges[p[u]].flow += a[t];
      edges[p[u]^1].flow -= a[t];
    }
    return flow;
  }

  // prereq: no neg-weighted cycle
  int min_cost_max_flow(int s, int t, long long& cost) 
  {
    int flow = 0; 
    cost = 0;
    while (bellman_ford(s, t, flow, cost));
    return flow;
  }
};

int main()
{
  return 0;
}

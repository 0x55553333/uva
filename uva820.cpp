#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <utility>
#include <memory.h>
#include <queue>
using namespace std;

#define MAXN 50000
struct Edge {
  int from, to , cap, flow;
  Edge(int u, int v, int c, int f):
    from(u), to(v), cap(c), flow(f) {}
};

struct EdmondsKarp {
  size_t n, m; // |V|, |E|
  vector<Edge> edges; // 2*n
  vector< vector<int> > G;
  vector<int> a, p; // augment value & parent
  
  EdmondsKarp(size_t n) {
    this->G.assign(n, vector<int>());
    this->a.assign(n, 0); 
    this->p.assign(n, -1);
    this->n = n;
    this->m = 2*n;
  }

  void add_edge(int from, int to, int cap)
  { edges.push_back(Edge(from, to, cap, 0));
    edges.push_back(Edge(to, from, 0, 0)); // back edge
    m = edges.size(); 
    G[from].push_back(m-2); G[to].push_back(m-1);
  }

  int max_flow(int s, int t) 
  {
    int flow = 0;
    while (1) {
      this->a.assign(this->n, 0);
      queue<int> Q;
      Q.push(s);
      a[s] = 0xfffff;
      while (!Q.empty()) { // BFS
        int x = Q.front(); Q.pop();
        for(int i = 0; i < G[x].size(); ++i) {
          const Edge& e = edges[G[x][i]];
          if (a[e.to] == 0 && e.cap > e.flow) { // relaxation
            p[e.to] = G[x][i];
            a[e.to] = min(a[x], e.cap - e.flow);
            Q.push(e.to);
          }
        }
        if (a[t]) break;
      }
      if (a[t] == 0) break; // no more augmenting paths
      for(int u = t; u != s; u = edges[p[u]].from) {
        // backtrace
        edges[p[u]].flow += a[t];
        edges[p[u]^1].flow -= a[t];
      }
      flow += a[t];
    }
    return flow;
  }
};

int n, s, t, c, cnt;

int main()
{
  while (cin >> n) {
    if (n == 0) break;
    EdmondsKarp ek(n + 1);
    ++cnt;
    cin >> s >> t >> c;
    for(int i = 0; i < c; ++i) {
      int u, v, f;
      cin >> u >> v >> f;
      ek.add_edge(u, v, f);
      ek.add_edge(v, u, f);
    }
    printf("Network %d\n", cnt);
    printf("The bandwidth is %d.\n\n", ek.max_flow(s, t));
  }
  return 0;
}


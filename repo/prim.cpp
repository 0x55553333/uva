#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <utility>
#include <memory.h>
#include <queue>
// Prims' algorithm for MST
using namespace std;
struct Edge{ int u; int v; int w;
  Edge(int u, int v, int w):u(u),v(v),w(w){}};
struct Vtx{ int v; int w;
  Vtx(){}
  Vtx(int vv, int ww) : v(vv), w(ww) {}};
typedef vector< vector<Vtx> > AdjList;
auto VtxCmp = [](const Vtx& lhs, const Vtx& rhs)
  { if (lhs.w == rhs.w) return lhs.v > rhs.v; 
    return lhs.w > rhs.w; };

int prim_data[3][10000], *taken = prim_data[0], 
    *edge_cost = prim_data[1], 
    *parent = prim_data[2];
vector<Edge> MST_Edges;
int prim(AdjList& G)
{ priority_queue<Vtx, vector<Vtx>, decltype(VtxCmp)> Q(VtxCmp);
  int mst_cost = 0;
  memset(prim_data, 0, sizeof(prim_data));
  for(int i = 0; i < G.size(); ++i)
    edge_cost[i] = 0xfffff;
  taken[0] = 1;
  for(const Vtx& adj : G[0]) 
    if (!taken[adj.v] &&
        adj.w <= edge_cost[adj.v]) {
      parent[adj.v] = 0;
      edge_cost[adj.v] = adj.w;
      Q.push(adj);
    }
  while (!Q.empty()) {
    Vtx pt = Q.top(); Q.pop();
    if (!taken[pt.v]) {
      taken[pt.v] = 1;
      mst_cost += pt.w;
      MST_Edges.push_back(Edge(parent[pt.v], pt.v, pt.w));
      for(const Vtx& pt2 : G[pt.v]) 
        if (!taken[pt2.v] && 
            pt2.w <= edge_cost[pt2.v]) { // relaxation
          Q.push(pt2); parent[pt2.v] = pt.v;
          edge_cost[pt2.v] = pt2.w;
        }
    }
  }
  return mst_cost;
}
int main()
{ int nV, nE;
  cin >> nV >> nE;
  AdjList G(nV);
  // u v w
  for(int i = 0;  i < nE; ++i) {
    int u; Vtx v;
    cin >> u >> v.v >> v.w;
    G[u].push_back(v);
  }
  cout << "MST Cost: " << prim(G) << endl;
  cout << "MST Edges: "<<endl;
  for(const auto & e : MST_Edges) {
    printf("(%d, %d, %d)\n", e.u, e.v, e.w);
  }
  return 0;
}

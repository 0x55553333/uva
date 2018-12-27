#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <utility>
#include <algorithm>
#include <memory.h>
using namespace std;
// MST
// Kruskal's algorithm based on Union-Find
struct disjoint_set
{ vector<long> parent; vector<int> rank;
  long find(long i) // Find a parent of a set
  { if (parent[i] == i) return i;
    else return parent[i] = find(parent[i]);}
  bool eq(long i, long j){return find(i) == find(j);} // Test two parents
  void merge(long i, long j) // Merge two sets
  { long x = find(i), y = find(j);
    if (rank[x] > rank[y]) parent[y] = x;
    else { parent[x] = y;
      if (rank[x] == rank[y]) ++rank[y]; }}
  disjoint_set(long n) // n: size of set
  { this->rank.assign(n, 0); this->parent.assign(n, 0);
    for(long i = 0; i < n; ++i) this->parent[i] = i; }};
struct Edge { int u; int v; int w; 
  Edge(int uu, int vv, int ww) : u(uu),v(vv),w(vv){} 
  Edge() {}};
typedef vector<Edge> Graph;
Graph MST_Edges;
int kruskal(Graph& G)
{ // replace sort by stable_sort or
  // modify comparison function to generate
  // different MSTs of the same cost
  sort(G.begin(), G.end(), 
      [](Edge& lhs, Edge& rhs){ return lhs.w < rhs.w; });
  disjoint_set T(G.size());
  int Mst_Cost = 0;
  for(const Edge& e: G) {
    if (!T.eq(e.u, e.v)) {
      T.merge(e.u, e.v); Mst_Cost += e.w;
      MST_Edges.push_back(e);
    }
  }
  return Mst_Cost;
}
int main()
{ int E; // edge size
  cin >> E;
  Graph G( (long) E);
  for(int i = 0; i < E; ++i) {
    Edge e; cin >> e.u >> e.v >> e.w;
    G.push_back(e);
  }
  cout << "MST Cost" << kruskal(G) << endl;
  cout << "MST Edges: "<<endl;
  for(const Edge& e: MST_Edges) {
    cout << "(" << e.u << "," << e.v << "," << e.w << ")" << endl;
  }
	return 0;
}


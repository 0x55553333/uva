#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <utility>
#include <memory.h>
using namespace std;
/* DFS that finds all articulation points and bridges */

struct graph {
  vector< vector<int> > adj_list;
  vector<int> parents;
  vector<int> dfs_num;
  vector<int> min_dfs_num;
  vector<int> art_pts;
  vector< pair<int,int> > bdgs;
  size_t n; size_t cnt;
  /* adjacency list */
  graph(size_t n) 
  {
    this->adj_list.assign(n, vector<int>());
    this->dfs_num.assign(n, -1);
    this->min_dfs_num.assign(n, -1);
    this->parents.assign(n, -1);
    this->n = n;
    this->cnt = 0;
  }
  // v is parent of u
  void set_parent(int u, int v)
  {
    this->parents[u] = v;
  }
  // directed edge from u to v
  void add_edge(int u, int v)
  {
    this->adj_list[u].push_back(v);
  }
  // all neighbors of u
  vector<int>& neighbors(int u)
  {
    return this->adj_list[u];
  }
};

/* dfs starting from u */
int dfs(graph& G, int root, int u)
{
  int child_cnt = 0;
  G.min_dfs_num[u] = G.dfs_num[u] = G.cnt++;
  for(int& v : G.neighbors(u)) {
    if (G.dfs_num[v] == -1) {
      G.set_parent(v, u);
      if (u == root) ++child_cnt;
      child_cnt += dfs(G, root, v);
      if (G.min_dfs_num[v] >= G.dfs_num[u]) {
        G.art_pts.push_back(u); // found art pt
      }
      if (G.min_dfs_num[v] > G.dfs_num[u]) {
        G.bdgs.push_back(make_pair(u, v));
      }
      G.min_dfs_num[u] = min(G.min_dfs_num[u], G.dfs_num[v]);
    } else if (v != G.parents[u]) {
      G.min_dfs_num[u] = min(G.min_dfs_num[u], G.dfs_num[v]);
    }
  }
  return child_cnt;
}

/* 
 Input: adjacencies in an undirected graph
 first line: n, # of vertices
 2<=k<=n+1th line: neighbors of vertex k-2, 
  beginning with the total number of neighbors
 Precondition: input makes the graph undirected
Postcondition: 
  m lines, each line with an index of articulation
    point
  l lines, each line with two indices corresponding
    to a bridge
*/
int main()
{
  size_t n; cin >> n;
  graph G(n);
  for(size_t i = 0; i < n; ++i) {
    size_t ee, adj; cin >> ee;
    for(size_t j = 0; j < ee; ++j) {
      cin >> adj;
      G.add_edge(i, adj);
    }
  }
  for(int i = 0; i < G.n; ++i) {
    int rootchlds = 0; // # of root children
    if (G.dfs_num[i] != -1) continue;
    rootchlds = dfs(G, i, i);
    printf("Root: %d\n", i);
    if (rootchlds > 1) G.art_pts.push_back(i);
    printf("articulation points (%lu):\n", G.art_pts.size());
    for(const int& art : G.art_pts)
      printf("%d ", art);
    printf("\nbridges (%lu):\n", G.bdgs.size());
    for(const pair<int,int>& bdg : G.bdgs)
      printf("(%d,%d) ", bdg.first, bdg.second);
    printf("\n");
  }
  return 0;
}


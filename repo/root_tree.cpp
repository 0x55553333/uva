#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <utility>
#include <algorithm>
#include <memory.h>
using namespace std;
/* rootless tree to rooted tree using dfs */

vector<int> G[1000];
int p[1000];
/* subtree rooted at u */
void dfs(int u, int parent)
{
  int d = G[u].size();
  for(int i = 0; i < d; ++i) {
    int v = G[u][i];
    if (v != parent)
      dfs(v, p[v] = u);
  }
}

int main()
{
  int u, v, n;
  cin >> n;
  for(int i = 0; i < n-1; ++i) { /* a tree has n-1 edges */
    cin >> u >> v;
    G[u].push_back(v); G[v].push_back(u);
  }
  int root; cin >> root;
  p[root] = -1; dfs(root, -1);

  return 0;
}


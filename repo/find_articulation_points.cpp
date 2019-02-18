#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <utility>
#include <memory.h>
using namespace std;

vector< vector<int> > g;
int N, cnt = 1;

vector<int> pre, low, artpts;
void dfs (int u, int p)
{ int ch = 0;
  low[u] = pre[u] = cnt;
  ++cnt;
  for(int i = 0; i < g[u].size(); ++i) {
    int v = g[u][i];
    if (pre[v] == 0) {
      ++ch;
      dfs(v, u);
      low[u] = min(low[u], low[v]);
      if (low[v] >= pre[u]) /* descendant has back edge */
        artpts[u] = 1;
    } else if (pre[v] < pre[u] && v != p) /* is back edge */
      low[u] = min(low[u], pre[v]);
  }
  if (p < 0 && ch == 0) artpts[u] = 0;

}

int main()
{
  while (cin >> N) {
    if (N == 0) break;
    g.assign(N, vector<int>());
    for(int i = 0; i < N; ++i) {
      int k; cin >> k;
      for(int j = 0; j < k; ++j) {
        cin >> k; g[i].push_back(k);
      }
    }
    pre.assign(N, 0);
    low.assign(N, 0);
    artpts.assign(N, 0);
    for(int i = 0; i < N; ++i) 
      if (pre[i] == 0) dfs(i, -1);
  }
  return 0;
}

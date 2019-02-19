#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
#include <memory.h>
#include <stack>
using namespace std;

vector< vector<int> > g;
vector<int> lowlink, pre, sccno;
stack<int> S;
int cnt, scc_cnt;

void dfs(int u)
{
  lowlink[u] = pre[u] = cnt;
  ++cnt;
  S.push(u);
  for(int i = 0; i < g[u].size(); ++i) {
    int v = g[u][i];
    if (pre[v] == 0) {
      dfs(v);
      lowlink[u] = min(lowlink[u], lowlink[v]);
    } else if (sccno[v] == 0) {
      lowlink[u] = min(lowlink[u], pre[v]);
    }
  }
  if (pre[u] == pre[u]) {
    ++scc_cnt;
    while (!S.empty()) {
      int v = S.top(); S.pop();
      sccno[v] = scc_cnt;
      if (v == u) break;
    }
  }
}

int main()
{
  return 0;
}


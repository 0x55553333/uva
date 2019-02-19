#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <utility>
#include <memory.h>
#include <stack>
using namespace std;

vector<int> low, pre, artpts, bccno;
vector< vector<int> > g;
stack< pair<int,int> > S;
int cnt = 1, bcc_cnt;

void dfs(int u, int p)
{
  low[u] = pre[u] = cnt;
  ++cnt;
  int ch = 0;
  for(int i = 0; i < g[u].size(); ++i) {
    int v = g[u][i];
    if (pre[v] == 0) {
      S.push(make_pair(u, v));
      ++ch;
      dfs(v, u);
      low[u] = min(low[u], low[v]);
      if (low[v] >= low[u]) {
        artpts[u] = 1;
        ++bcc_cnt;
        while (!S.empty()) {
          pair<int,int> e = S.top(); S.pop();
          bcc[p.second] = bcc_cnt;
          bcc[p.first] = bcc_cnt;
          if (p.first == u && p.second == v) break;
        }
      }
    } else if (pre[v] < pre[u] && v != p) {
      S.push(make_pair(u, v));
      low[u] = min(low[u], pre[v]);
    }
  }
  if (p < 0 && ch == 1) artpts[u] = 0; 
}

int main()
{
  return 0;
}


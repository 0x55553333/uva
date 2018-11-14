#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <memory.h>
#include <queue>
using namespace std;
int coloring[300];
int main()
{
  int n, l;
  while (cin >> n) {
    memset(coloring, 0, sizeof(coloring));
    queue<int> Q;
    vector< vector<int> > graph;
    if (n == 0) break;
    cin >> l;
    graph.assign(n, vector<int>());
    for(int i = 0; i < l; ++i) {
      int a, b; cin >> a >> b;
      graph[a].push_back(b);
      graph[b].push_back(a);
    }
    Q.push(0); coloring[0] = 1;
    int ans = 1, v;
    while (!Q.empty()) {
      v = Q.front(); Q.pop();
      for(int& u : graph[v]) {
        if (coloring[u] == 0) {
          coloring[u] = 3 - coloring[v];
          Q.push(u);
        } else if (coloring[u] == coloring[v]) {
        //  printf("err: coloring[%d] = %d, coloring[%d] = %d\n", u, coloring[u], v, coloring[v]);
          ans = 0; goto bye;
        }
      }
    }
    bye:;
    if (ans) printf("BICOLORABLE.\n");
    else printf("NOT BICOLORABLE.\n");
  }
  return 0;
}

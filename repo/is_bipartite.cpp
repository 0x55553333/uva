#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#include <memory.h>
using namespace std;

typedef vector<vector<int> > graph;
map<int, int> coloring;
int n;
char s[500];
int test(graph& G, int v, int color)
{
  if (coloring[v] != 0) {
    return coloring[v] == color;
  }
  int ans = 1, nextcolor = (color == 1 ? 2 : 1);
  for(int i = 0; i < G[v].size(); ++i) {
    ans &= test(G, G[v][i], nextcolor);
  }
  return ans;
}
void read(graph& G)
{
  size_t st, k;
  for(int i = 0, j; i < n; ++i, memset(s, 0, sizeof(s)), k=0) {
    fgets(s, 500, stdin);
    st = strlen(s);
    do {
      j = atoi(s + k);
      G[i].push_back(j);
      G[j].push_back(i);
    } while (k < st && isdigit(s[k]));
  }
}

int main()
{
  while (cin >> n) {
    graph G(n);
    read(G);
    for(int i = 0; i < n; ++i) 
      coloring[i] = 0;
    int ans = 1;
    for(int i = 0; i < n; ++i) 
      ans &= (test(G, i, 1) | test(G, i, 2));
    printf("%d\n", ans);
  }
  return 0;
}

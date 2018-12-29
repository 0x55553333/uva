#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <utility>
#include <memory.h>
using namespace std;
// Floyd's algorithm for ASSP
// Warshall's algorithm for transitive closure
#define MAXN 1500
#define INF 0xffffff // subject to change
int d[MAXN][MAXN]; // distance matrix

// APSP
void floyd(int n)
{
  for(int k = 0; k < n; ++k)
    for(int i = 0; i < n; ++i)
      for(int j = 0; j < n; ++j)
        if (d[i][j] < INF &&
            d[k][j] < INF)
          d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}

// Transitive closure
void warshall(int n)
{
  for(int k = 0; k < n; ++k)
    for(int i = 0; i < n; ++i)
      for(int j = 0; j < n; ++j)
        d[i][j] = d[i][j] || (d[i][k] && d[k][j]);
}

int main()
{ // computes APSP by default
  int n, m; cin >> n >> m;
  for(int i = 0; i < n; ++i)
    for(int j = 0; j < n; ++j)
      if (i == j) d[i][j] = 0;
      else d[i][j] = INF;
  for(int i = 0; i < m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    d[u][v] = w; // undirected
    //d[v][u] = w;
  }
  floyd(n);
  printf("*\t");
  for(int i = 0; i < n; ++i) 
    printf("%d\t", i); 
  printf("\n");
  for(int i = 0; i < n; ++i) {
    printf("%d\t", i);
    for(int j = 0; j < n; ++j)
      if (d[i][j]>=INF)
        printf("INF\t");
      else printf("%d\t", d[i][j]);
    printf("\n");
  }
  return 0;
}


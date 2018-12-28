#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <utility>
#include <vector>
#include <memory.h>
#include <queue>
#define MAXN 100
using namespace std;
int N;
char grid[MAXN][MAXN];
int dirs[][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int dist[MAXN][MAXN];
int parent[MAXN][MAXN][2];
int bfs(char s, char t)
{
  memset(dist, 0, sizeof(dist));
  memset(parent, 0, sizeof(parent));
  queue< pair<int,int> > Q;
  for(int i = 0; i < N; ++i)
    for(int j = 0; j < N; ++j) {
      dist[i][j] = 0xfffff;
      parent[i][j][0] = parent[i][j][1] = -1;
      if (grid[i][j] == s) {
        dist[i][j] = 0;
        Q.push(make_pair(i, j));
      }
    }
  int minCost=0xfffff;
  while (!Q.empty()) {
    pair<int,int> u = Q.front(); Q.pop();
    if (grid[u.first][u.second]==t) {
      minCost = min(minCost, dist[u.first][u.second]);
      continue;
    }
    for(int i = 0; i < 4; ++i) { // all 4 directions
      int ii = u.first + dirs[i][0], jj = u.second + dirs[i][1];
      if (grid[ii][jj] == '.' || grid[ii][jj] == t) 
        if (dist[u.first][u.second] + 1 <= dist[ii][jj]) {
          parent[ii][jj][0] = u.first; parent[ii][jj][1] = u.second;
          dist[ii][jj] = dist[u.first][u.second] + 1;
          Q.push(make_pair(ii,jj));
        }
    }
  }
  for(int i = 0; i < N; ++i)
    for(int j = 0; j < N; ++j) 
      if (grid[i][j] == t && 
          dist[i][j] == minCost) {
        int pi = parent[i][j][0],
          pj = parent[i][j][1];
        grid[i][j] = '*';
        while (parent[pi][pj][0] != -1) {
          grid[pi][pj] = '>';
          pi = parent[pi][pj][0];
          pj = parent[pi][pj][1];
        }
        grid[pi][pj] = '*';
        return minCost;
      }
  return minCost;
}

int main()
{ char s, t;
  cin >> N;
  for(int i =0; i < N; ++i)
    scanf("%s", grid[i]);
  while (cin >> s >> t) {
    if (s == '$' || t == '$') break;
    int cost = bfs(s, t);
    for(int i = 0; i < N; ++i)
      printf("%s\n", grid[i]);
    if (cost >= 0xfffff) 
      printf("No route\n");
    else
      printf("%d\n", cost);
  }
  return 0;
}


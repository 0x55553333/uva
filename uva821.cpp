#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <utility>
#include <memory.h>
#include <cctype>
#include <queue>
#include <cstring>
using namespace std;

vector< vector<int> > g;
double tot, tot_path;

void reset()
{
  for(int i = 0; i < g.size(); ++i) g[i].clear();
  g.clear();
  g.assign(120, vector<int>());
  tot = tot_path = 0.0;
}

int read_in()
{ int m = 0;
  string s; size_t i = 0; char * p1, *p2;
  getline(cin, s);
  p1 = strtok((char*)s.c_str(), " ");
  p2 = strtok(NULL, " ");
  while (1) {
    int u = atoi(p1), v = atoi(p2);
    if (u == 0 && v == 0) break;
    g[u].push_back(v); ++m;
    p1 = strtok(NULL, " ");
    p2 = strtok(NULL, " ");
  } 
  return m > 0;
}

int bfs(int u, int v)
{ vector<int> dist;
  queue<int> q;
  dist.assign(g.size()+1, 0xfffff);
  dist[u] = 0;
  q.push(u);
  while (!q.empty()) {
    int p = q.front(); q.pop();
    for(int n : g[p]) 
      if (dist[p] + 1 < dist[n]) {
        dist[n] = dist[p] + 1;
        q.push(n);
      }
  }
  return dist[v];
}

void calculate_average()
{
  for(int i = 1; i <= 100; ++i) {
    for(int j = 1; j <= 100; ++j) {
      if (i != j) {
        int d = bfs(i, j);
        if (d < 0xfffff) {
          tot += (double) d;
          tot_path += 1.0;
        }
      }
    }
  }
}

int main()
{ int cnt = 0;
  g.assign(110, vector<int>());
  while (read_in()) {
    ++cnt;
    calculate_average();
    printf("Case %d: average length between pages = %.3f clicks\n",
        cnt, tot / tot_path);
    reset();
  }  
  return 0;
}


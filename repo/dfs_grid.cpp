#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <utility>
#include <memory.h>
using namespace std;
#define MAXN 100 

// DFS to find minimum distance 
// between two characters in
// a grid cell where 
// '.' denotes a valid path

int N, memo[700][MAXN][MAXN];
char grid[MAXN][MAXN];
char src, tgt;

int min_dist(int i, int j, char t);
int _min_dist(int i, int j, char t)
{
//  printf("called: %d, %d, %c, memo val=%d\n", i, j, t, memo[t][i][j]);
  if (grid[i][j] == t) return 1;
  if (grid[i][j] != '.') return 0xffff;
  grid[i][j] = '!';
  int north = min_dist(i+1, j, t),
      south = min_dist(i-1, j, t),
      east = min_dist(i, j+1, t),
      west = min_dist(i, j-1, t),
      best = min(north, min(south, min(east, west)));
  grid[i][j] = '.';
//  printf("min_dist at %d,%d=%c: best=%d\n", i, j, t, 1+ best);
  return 1 + best;
}
int min_dist(int i, int j, char t)
{
  if (i >= N || j >= N || i < 0 || j < 0) return 0xffff;
  if (memo[t][i][j] != -1) {
//    printf("hit: %c, %d, %d = %d\n", t, i, j, memo[t][i][j]);
    return memo[t][i][j];
  } else {
    return memo[t][i][j] = _min_dist(i, j, t);
  }
}

int main()
{
  cin >> N;
  for(int i = 0; i < N; ++i) 
    scanf("%s", grid[i]);
  for(int i = 0; i < N; ++i)
    for(int j = 0; j < N; ++j)
      for(int t = 0; t < 700; ++t)
        memo[t][i][j] = -1;
  while(cin >> src >> tgt) {
  //  printf("src=%c, tgt=%c\n", src, tgt);
    if (src == '$' || tgt == '$') break;
    int global_min_dist = 0xfffff;
    for(int i = 0; i < N; ++i)
      for(int j = 0; j < N; ++j) 
        if (grid[i][j] == src) {
          global_min_dist = min(global_min_dist, 
              min(min_dist(i+1, j, tgt),
                min(min_dist(i-1, j, tgt),
                  min(min_dist(i, j+1, tgt), min_dist(i, j-1, tgt)))));
   //       printf("%c->%c, At (%d,%d)=%c, global min =%d\n", src, tgt, i, j, grid[i][j], global_min_dist);
        }
    printf("%d\n", global_min_dist);
  }
  return 0;
}



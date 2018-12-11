#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <utility>
#include <memory.h>
using namespace std;

int grid[500][500], n, m;
char line[500];
int a, b, r = 3;

int floodfill(int i, int j, int dst, int rep)
{
  if (grid[i][j] != dst || grid[i][j] == 0) return 0;
  grid[i][j] = rep;
  return 1 + floodfill(i+1, j, dst, rep) +
    floodfill(i, j+1, dst, rep) +
    floodfill(i-1, j, dst, rep) + 
    floodfill(i, j-1, dst, rep) + 
    floodfill(i-1, j-1, dst, rep) + 
    floodfill(i+1, j+1, dst, rep) +
    floodfill(i+1, j-1, dst, rep) +
    floodfill(i-1, j+1, dst, rep);
}

void print()
{
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < m; ++j)
      printf("%c", grid[i][j] ? 'W' : 'L');
    printf("\n");
  }
}

void process()
{
  while (fgets(line, 500, stdin) != NULL) {
    if (line[0] == 'L' || line[0] == 'W') {
      if (m == 0) m = strlen(line) - 1;
      for(int i = 0; i < m; ++i) {
        grid[n][i] = (line[i] == 'W' ? 1 : 0);
      }
      ++n;
    } else if (isdigit(line[0])) {
      sscanf(line, "%d %d", &a, &b);
      --a; --b;
      printf("%d\n", floodfill(a, b, grid[a][b], r));
      ++r;
    } else return;
    memset(line, 0, sizeof(line));
  }  
}

int main()
{
  int T;
  fgets(line, 500, stdin);
  T = atoi(line);
  fgets(line, 500, stdin);
  while (T--) {
    m = n = r = a = b = 0; r = 3;
    memset(grid, 0, sizeof(grid));
    memset(line, 0, sizeof(line));
    process();
    if (T) printf("\n");
  }
  return 0;
}

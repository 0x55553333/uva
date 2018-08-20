#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <cstring>
#include <queue>
#include <memory.h>
using namespace std;

struct node {
  int x; int y; int d; int is_start;
  node(int x, int y, int d) : x(x), y(y), d(d)
  { this->is_start = 0; }
  node()
  { this->is_start = this->x = this->y = this->d = -1; }
};

int dy[] = {-1, 0, 1, 0}; /* N E S W */
int dx[] = {0, 1, 0, -1}; /* N E S W */

int M[10][10][4][3];
int d[10][10][10];
node p[10][10][10];
char s[30];

int d2i(char c)
{ switch (c) {
  case 'N': return 0;
  case 'E': return 1;
  case 'S': return 2;
  case 'W': return 3;
}}

int t2i(char c)
{ switch (c) {
  case 'L': return 0;
  case 'F': return 1;
  case 'R': return 2;
}}

char i2d(int i)
{ switch (i) {
    case 0: return 'N';
    case 1: return 'E';
    case 2: return 'S';
    case 3: return 'W';
}}

char i2t(int i)
{ switch (i) {
    case 0: return 'L';
    case 1: return 'F';
    case 2: return 'R';
}}

bool inside(int x, int y)
{ return x >= 1 && x <= 9 && y >= 1 && y <= 9; }

node next(node& u, int turn)
{ 
  switch (turn) {
    case 0: /* L */ return node(u.x+dx[(u.d+3)%4], u.y+dy[(u.d+3)%4], (u.d+3)%4);
    case 1: /* F */ return node(u.x+dx[u.d], u.y+dy[u.d], u.d);
    case 2: /* R */ return node(u.x+dx[(u.d+1)%4], u.y+dy[(u.d+1)%4], (u.d+1)%4);
  }
}

void init()
{ is_circular = 0;
  memset(M, 0, sizeof(M));
  for(int i = 0; i < 10; ++i)
  for(int j = 0; j < 10; ++j)
  for(int k = 0; k < 10; ++k)
  d[i][j][k] = -1; }

void print(node u, node start)
{ vector<node> path;
  while (1) {
    path.push_back(u);
    if (d[u.x][u.y][u.d] == 0) break;
    u = p[u.x][u.y][u.d];
  }
  path.push_back(start);
  for(int i = path.size() - 1, cnt = 0; i >= 0; --i) {
    if (cnt % 10 == 0) printf(" ");
    printf(" (%d,%d)", path[i].y, path[i].x);
    if (++cnt % 10 == 0) printf("\n");
  }
  if (path.size() % 10 != 0) printf("\n");
}

int main()
{ string name;
  while (cin >> name) {
    if (name == "END") break;
    char start_direction;
    int start_x, start_y, end_x, end_y;
    cin >> start_y >> start_x;
    cin >> start_direction;
    cin >> end_y >> end_x;
    init();
    while (1) {
      int x, y, k;
      cin >> y;
      if (y == 0) break;
      cin >> x;
      while (1) {
        memset(s, 0, 30);
        scanf("%s", s);
        size_t p = strlen(s);
        if (s[0] == '*') break;
        while (--p) {
          M[x][y][d2i(s[0])][t2i(s[p])] = 1;
        }
      }   
    }
    queue<node> bq;
    node start, entry;
    start.x = start_x; start.y = start_y; start.d = d2i(start_direction);
    entry = next(start, t2i('F'));
    d[entry.x][entry.y][entry.d] = 0;
    bq.push(entry);
    while (!bq.empty()) {
      node curr = bq.front(); bq.pop();
      if (curr.x == end_x && curr.y == end_y) {
        cout << name << endl;
        print(curr, start); goto success;
      }
      for(int i = 0; i < 3; ++i) { /* Left, Right, Front */
        node adj = next(curr, i);
        if (M[curr.x][curr.y][curr.d][i] && inside(adj.x, adj.y) &&
            d[adj.x][adj.y][adj.d] < 0) {
          d[adj.x][adj.y][adj.d] = 1;
          p[adj.x][adj.y][adj.d] = curr;
          bq.push(adj);           
        }
        if (curr.is_start) break;
      }
    }
    cout << name << endl;
    printf("  No Solution Possible\n");
    success:;
  }
  return 0;
}


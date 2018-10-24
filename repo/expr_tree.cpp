#include <cstdio>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
#include <memory.h>
using namespace std;

/* expression tree */

const int maxn = 1000;
int lch[maxn], rch[maxn];
char op[maxn];
int cnt = 0; // node count

int build(char* s, int x, int y)
{
  int i, c1 = -1, c2 = -1, p = 0, u;
  if (y-x == 1) {
    u = ++cnt;
    lch[u] = rch[u] = 0; op[u] = s[x];
    return u;
  }
  for(i = x; i < y; ++i) 
    switch (s[i]) {
      case '(': ++p; break;
      case ')': --p; break;
      case '+': 
      case '-': if (!p) c1 = i; break;
      case '*': 
      case '/': if (!p) c2 = i; break;
    }
  if (c1 < 0) c1 = c2;
  if (c1 < 0) return build(s, x+1, y-1);
  u = ++cnt;
  lch[u] = build(s, x, c1);
  rch[u] = build(s, c1+1, y);
  op[u] = s[c1];
  return u;
}

int main()
{
  return 0;
}


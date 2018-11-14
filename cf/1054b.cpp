#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
#include <memory.h>
#include <set>
using namespace std;
int n, a[100001];
int main()
{
  cin >> n;
  if (n < 0 || n > 100000) return 1;
  int step = -1;
  set<int> used;
  for(int i = 0; i < n; ++i) {
    cin >> a[i];
    if (used.find(a[i]-1) == used.end() && a[i] != 0) {
      step = i+1; break;
    }
    used.insert(a[i]);
  }
  printf("%d\n", step);
  return 0;
}


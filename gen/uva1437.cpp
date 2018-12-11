#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <utility>
#include <memory.h>
#include <cmath>
using namespace std;

char i2c(int i)
{ return (char) (i % 26 + 97); }

int main()
{ srand(time(NULL));
  int n, m;
  cin >> n;
  for(int i = 0; i < n; ++i) {
    m = rand() % 60 + 1;
    string x, y;
    for(int j = 0; j < m; ++j) {
      x += i2c(rand());
      y += i2c(rand());
    }
    cout << x << endl;
    cout << y << endl;
  }
  return 0;
}


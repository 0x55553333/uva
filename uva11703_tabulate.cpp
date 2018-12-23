#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
#include <memory.h>
using namespace std;

int x[1000001], N;

inline static int f1(int x)
{ return (int) floor(x - sqrt(x)); }

inline static int f2(int x)
{ return (int) floor(log(x)); }

inline static int f3(int x)
{ return (int) floor( x * sin(x) * sin(x) ); }

int F(int n);
int _F(int n) 
{
  if (n == 0) return 1;
  return (F(f1(n)) + F(f2(n)) + F(f3(n))) % 1000000;
}
int F(int n)
{
  if (x[n] != 0) return x[n];
  else return x[n] = _F(n);
}

int main()
{
  printf("int A[]={");
  int i;
  for(i = 0; i <= 5500; ++i) {
    printf("%d,", F(i));
  }
  printf("%d};\n", F(5501));
  return 0;
}


#include <cstdio>
#include <cstdlib>
#include <memory.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int L(int n)
{
  if (n==0) return 0;
  if (n==1) return 1;
  if (n==2) return 2;
  if (n==3) return 2;
  return L(n/2)+1;
}

int main()
{
  int N;
  while (cin >> N) {
    cout<<L(N)<<endl;  
  }
  return 0;
}


#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <utility>
#include <memory.h>
#include <cmath>
using namespace std;

int main()
{
  int x, y, z, t1, t2, t3;
  cin >> x >> y >> z >> t1 >> t2 >> t3;
  int floor_time = abs(y - x) * t1;
  int elevator_time = abs(x - z) * t2 + t3 * 3;
  elevator_time += abs(y - x) * t2;
//  printf("floor time = %d\n", floor_time);
//  printf("elevator time = %d\n", elevator_time);
  if (floor_time < elevator_time) printf("NO\n");
  else printf("YES\n");
  return 0;
}


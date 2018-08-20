#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;
// union-find-disjoint set

int find(int *p, int x)
{
	return p[x] != x ? p[x] = find(p, p[x]) : x;
}

int main()
{
	printf("ufd set\n");
	return 0;
}

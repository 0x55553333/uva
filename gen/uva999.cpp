#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <memory.h>
#include <ctime>
using namespace std;
// generator for UVa999
int main(int argc, char** argv)
{ srand(time(NULL));
	int k = atoi(argv[1]);
	while(k--) {
		int m = rand() % 32 + 1, n = rand() % 10000 + 1;
		printf("%d;%d\n", n, m);
	}
	return 0;
}

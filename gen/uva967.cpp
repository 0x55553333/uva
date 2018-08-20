#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <memory.h>
#include <ctime>
#include <cassert>
using namespace std;
int main(int argc, char** argv)
{	srand(time(NULL));
	int k = atoi(argv[1]);
	while (k--) {
		int R = rand() % (1000000-101) + 100, 
				L = rand() % (R - 101) + 100;
		assert(L <= R);
		printf("%d %d\n", L, R);
	}
	printf("-1\n");
	return 0;
}

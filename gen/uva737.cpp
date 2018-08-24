#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <memory.h>
using namespace std;
int main(int argc, char** argv)
{ srand(time(NULL));
	int k = atoi(argv[1]);
	while (k--) {
		int c = rand() % 500;
		printf("%d\n", c);
		if (rand()&1)
			while (c--) {
				int x = rand() % 100, y = rand() % 100, z = rand() % 100, d = rand() % 100;
				printf("%d %d %d %d\n", x, y, z, d);
			}
		else {
			int i = 250 + (-1*(rand()&1)) * (rand() % 30);
			while (c--) {
				int x = i - rand() % 200, y = i - rand() % 200, z = i - rand() % 200, d = 300;
				printf("%d %d %d %d\n", x, y, z, d);
			}
		}	
	}
	printf("0\n");
	return 0;
}


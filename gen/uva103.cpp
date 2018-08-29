#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <vector>
#include <utility>
#include <algorithm>
#include <memory.h>
using namespace std;

int main(int argc, char** argv)
{ srand(time(NULL));
	int T = atoi(argv[1]);
	while (T--) {
		int n = rand() % 9 + 1, k = rand() % 29 + 1;
		printf("%d %d\n", k, n);
		for(int i = 0; i < k; ++i) {
			for(int j = 0; j < n-1; ++j)
				printf("%d ", rand() % 49 + 1);
			printf("%d\n", rand() % 49 + 1);
		}
	}
	return 0;
}

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <utility>
#include <memory.h>
#include <ctime>
#include <cassert>
using namespace std;
const char *s = "*@";
int main(int argc, char** argv)
{ srand(time(NULL));
	int k = atoi(argv[1]), m, n;
	while (k--) {
		m = rand() % 9 + 1; n = rand() % 9 + 1;
		printf("%d %d\n", m, n);
		for(int i = 0; i < m; ++i) {
			for(int j = 0; j < n; ++j)
				printf("%c", s[rand() & 1]);
			printf("\n");
		}
	}
	return 0;
}

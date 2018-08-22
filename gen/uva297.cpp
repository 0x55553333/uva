#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <utility>
#include <algorithm>
#include <memory.h>
#include <ctime>
#include <cassert>
using namespace std;

void gen_tree(int h)
{
	for(int i = 0; i < 4; ++i) {
		/* p, e, f */
		int c = (h == 1) ? rand() & 1 : rand() % 3;
		switch (c) {
			case 0:
				printf("e"); break;
			case 1:
				printf("f"); break;
			case 2:
				assert(h != 1);
				printf("p"); gen_tree(h-1); break;
		}
	}	
}

int main(int argc, char** argv)
{ srand(time(NULL));
	int k = atoi(argv[1]);
	printf("%d\n", k);
	while (k--) {
		int height_a = rand() % 8 + 1, height_b = rand() % 8 + 1;
		printf("p"); gen_tree(height_a); printf("\n");
		printf("p"); gen_tree(height_b); printf("\n");
	}
	return 0;
}


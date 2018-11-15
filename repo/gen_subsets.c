
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
int* solution;
int* pos;
void generate(int* set, int size) {
	int N = 1<<size,i,j,c=0;
	solution = malloc(sizeof(int)*N*size);
	pos = malloc(sizeof(int)*N);
	memset(pos,0,sizeof(int)*N);
	memset(solution,0,sizeof(int)*N*size);
	for(i=0;i<N;++i) {           /* generate all 2^n bit permutations */
		for(j=0;j<size;++j) 	/* enumerate through all bit positions */
			if (i&(1<<j)) {
				solution[i*size+c]=set[j];
				++c;
				++pos[i];
			}		
		c=0;
	}

	for(i=0;i<N;++i) {
		for(j=0;j<pos[i];++j)
			printf("%d ", solution[i*size+j]);
		printf("\n");
	}
	free(pos);
	free(solution);
	return;
}

int main(void) {
	int set[5] = {1,2,3,4,5};
	generate(set,5);
	return 0;
}

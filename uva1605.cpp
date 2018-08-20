#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <memory.h>
using namespace std;
// construction method 2
unsigned N;
char *T="qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";

int main()
{
	bool A = 1;
	char buf[60];
	while (gets(buf)) {
		N=0;
		sscanf(buf,"%u",&N);
		if(N==0) return 0;
		if (!A) {
			printf("\n");
		} else A = 0;
		if(N==0) return 0;
		cout << 2 << " "; // height
		cout << N << " "; // width
		cout << N << endl; // length
		// building is N*N, 2 layers
		// floor 1: rows are the same
		for(unsigned i = 0; i < N; ++i) {
				for(unsigned j = 0; j < N; ++j)
					printf("%c",T[i]);
				printf("\n");
		}
		printf("\n");
		// floor 2: cols are the same
		for(unsigned i = 0; i < N; ++i) {
			for(unsigned j = 0; j < N; ++j)
				printf("%c",T[j]);
			printf("\n");
		}
		memset(buf,0,60);
	}
	return 0;
}

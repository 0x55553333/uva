#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <utility>
#include <vector>
#include <memory.h>
using namespace std;

int main()
{ int n, m;
	string x;
	bool first = 1;
	while (cin >> x) {
    if (x.size() <= 0) break;
		char * p = (char*) x.c_str();
		n = atoi(p); 
		while (*p != ';') ++p;
		++p; m = atoi(p);
		if (!first) printf("\n");
		else first = 0;
		if (n % 4) n = (n/4+1)*4;
		for(int i = 1, sig = 1; i < n; i += m*4, ++sig) {
			int j = i, k = i+m*4-1, sht = 1;
			printf("signature %d\n", sig);
			while (j < k) { 
				printf(" sheet %d: pages %d and %d (front); pages %d and %d (back)\n",
           sht, j+1, k-1, k, j);
				j += 2; k -= 2;
				++sht;
			}
		}	
	}
	return 0;
}


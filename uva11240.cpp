#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <utility>
#include <memory.h>
using namespace std;

int main()
{ int T, N, *V, *M, *MO, L, R, m, len;
	while (T--) {
		L = R = m = len = 0;
		cin >> N;
		M = new int[N + 1]; MO = new int[N + 1]; 
		M[0] = 0; MO[0] = '>';
		for(int i = 0; i < N; ++i) {
			cin >> V[i];
			L = 1; R = len;
			while (L <= R) {
				m = L + (R - L) / 2;
				if (V[M[m]] < V[i]) L = m+1;
				else R = m-1;
			}
		}
	}
	return 0;
}

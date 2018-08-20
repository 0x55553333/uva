#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <utility>
#include <memory.h>
using namespace std;

int main()
{ int N, k, *V, *M, *P, *S, len = 0;
	cin >> N;
	V = new int[N];
	M = new int[N + 1];
	P = new int[N];
	for(int i = 0; i < N; ++i) cin >> V[i];
	M[0] = 0;
	for(int i = 0; i < N; ++i) {
		int L = 1, R = len, m;
		while (L <= R) {
			m = L + (R - L) / 2;
			if (V[M[m]] < V[i]) L = m + 1;
			else R = m - 1;
		}
		M[L] = i;
		P[i] = M[L - 1];
		len = max(len, L);
	}
	S = new int[len];
	k = M[len];
	for(int i = len - 1; i >= 0; --i) {
		S[i] = V[k];
		k = P[k];
	}
	printf("Len=%d\n", len);
	for(int i = 0; i < len; ++i) printf("%d\t", S[i]);
	puts("");
	return 0;
}

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <algorithm>
#include <memory.h>
using namespace std;
int A[1000], B[1000], H[1000], p, G[1000][1000], M[1000];

int inside(int i, int j)
{ return A[i] < A[j] && B[i] < B[j]; }

void update(int a, int b, int c)
{ A[p] = a; B[p] = b; H[p++] = c; }

int longest(int i);
int _longest(int i)
{
	int ans = H[i];
	for(int j = 0; j < p; ++j)
		if (G[i][j]) {
			ans = max(ans, longest(j) + H[i]);
		}
	return ans;
}
int longest(int i)
{
	if (M[i] != 0) return M[i];
	else return M[i]=_longest(i);
}

int main()
{ int n, c = 0, ans;
	while (cin >> n && ++c) {
		if (n == 0) break;
		p = 0;
		memset(A, 0, sizeof(A)); memset(B, 0, sizeof(B));
		memset(H, 0, sizeof(H)); memset(G, 0, sizeof(G));
		memset(M, 0, sizeof(M));
		for(int i = 0; i < n; ++i) {
			int a , b, c; cin >> a >> b >> c;
			update(a, b, c); update(a, c, b);
			update(b, a, c); update(b, c, a);
			update(c, a, b); update(c, b, a);
		}
		
		for(int i = 0; i < p; ++i)
			for(int j = 0; j < p; ++j)
				if (inside(i, j)) {
					G[i][j] = 1;
//					printf("(%d, %d, %dh) in (%d, %d, %dh)\n", A[i], B[i], H[i], A[j], B[j], H[j]);
				}
		ans = 1;
		for(int i = 0; i < p; ++i, memset(M, 0, sizeof(M))) 
			ans = max(ans, longest(i));
		printf("Case %d: maximum height = %d\n", c, ans);
	}
	return 0;
}


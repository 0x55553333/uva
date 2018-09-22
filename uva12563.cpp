#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <utility>
#include <algorithm>
#include <memory.h>
int S[100], m[2000][2000], l[2000][2000];

int opt(int i, int v, int t);
int opt(int i, int v, int t)
{
	int ans = opt(i-1, v, t);
	if (v >= S[i]) {
		int i = opt(i-1, v+S[i], t) + 1;
	}
	return ans;
}

int opt(int i, int v, int t)
{
	if (v > t) return m[i][v]=-1;
	if (i == 0 && v <= t) return m[i][v]=v + 678;
	if (m[i][v] != 0) return m[i][v];
	else return m[i][v]=_opt(i, v, t);
}

int main()
{ int T, n, t, c = 0;
	while (T-- && ++c) {
		cin >> n >> t;
		memset(S, 0, sizeof(S));
		memset(m, 0, sizeof(m)); memset(l, 0, sizeof(l));
		for(int i = 1; i <= n; ++i) cin >> S[i];
		int 
	}
	return 0;
}

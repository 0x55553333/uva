#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#include <memory.h>
using namespace std;

void build(int *L, int T, int d)
{ if (T== -1) return;
	int l,r; 
	L[d] += T;
	cin >> l;
	build(L, l, d-1);
	cin >> r;
	build(L, r, d+1);
}

int main()
{ int t, L[4000], c = 1;
	do {
		vector<int> pr;
		memset(L, 0, sizeof(L));
		cin >> t;
		if (t == -1) break;
		build(L, t, 2000);
		for(int i = 0; i < 4000; ++i)
			if (L[i] > 0) pr.push_back(L[i]);
		printf("Case %d:\n", c);
		for(int i = 0; i < pr.size()-1; ++i) printf("%d ", pr[i]);
		printf("%d\n\n", pr[pr.size()-1]);
	} while (c++);
	return 0;
}


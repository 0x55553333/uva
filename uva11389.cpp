#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <utility>
#include <memory.h>
using namespace std;

int main()
{ int n,d,r,*M,*E;
	while (cin >> n >> d >> r) {
		if (n==0 && d==0 && r==0) break;
		M = new int[n]; E = new int[n];
		for(int i = 0; i < n; ++i) cin >> M[i];
		for(int i = 0; i < n; ++i) cin >> E[i];
		sort(M, M + n, less<int>());
		sort(E, E + n, less<int>());
		int i = 0, j = n - 1, k = 0;
		while (i < n && j >= 0) {
			if (M[i]+E[j]-d>0)
				k += r * (M[i] + E[j] - d);
			++i; --j;
		}
		cout << k << endl;
	}
	return 0;
}

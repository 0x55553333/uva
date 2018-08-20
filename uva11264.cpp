#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <utility>
#include <vector>
#include <memory.h>
using namespace std;

int main()
{ int T, n, *C;
	cin >> T;
	while (T--) {
		int k = 0, s = 0;
		cin >> n;
		C = new int[n];
		for(int i = 0; i < n; ++i) cin >> C[i];
		for(int i = 0; i < n; ++i) {
//			bool take = 1;
//			for(int j = i + 1; j < n; ++j) {
//				if (s + C[i] >= C[j]) take = 0;
//			}
//			if (take) { s += C[i]; ++k; }
			if (i < n-1 && s + C[i] < C[i+1]) { s += C[i]; ++k; }
			else if (i == n-1 && s + C[i] < C[i]*2) { ++k; }
		}
		printf("%d\n", k);
	} 
	return 0;
}

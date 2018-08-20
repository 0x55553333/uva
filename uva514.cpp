#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <memory.h>
#include <stack>
using namespace std;

int main()
{ int n;
	while (cin >> n) {
		if (n == 0) break;
		while (1) {
			int *C = new int[n];
			cin >> C[0];
			if (C[0] == 0) { delete[] C; goto _next; }
			for(int i = 1; i < n; ++i) cin >> C[i];
			stack<int> B;
			int A = 1, p = 0;
			while (p < n && (A <= n || !B.empty())) {
				if (A == C[p]) { 
					//printf("train %d: A->C\n", A); 
					++A; ++p;
				} else if (!B.empty() && B.top() == C[p]) {
					//printf("train %d: B->C\n", B.top());
					B.pop(); ++p; 
				} else if (A <= n) {
					//printf("train %d: A->B\n", A);
					B.push(A); ++A;
				} else break;
			}
			if (p < n || !B.empty()) printf("No\n");
			else printf("Yes\n");
			delete[] C;
		}
_next:
		printf("\n");
	}
	return 0;
}

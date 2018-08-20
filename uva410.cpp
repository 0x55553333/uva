#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <memory.h>
using namespace std;

int main()
{ int S = 0, C = 0, SS[20], Acnt=1;
	memset(SS,0,20);
	while (cin >> C >> S) {
		int cum = 0, L, R, cnt=0;
		double ans = 0, avg = 0;
		if (C < 1 || C > 10) break;
		for(int i = 0; i < S; ++i) { 
			cin >> SS[i];
			cum += SS[i];
		}
		avg = (double)cum / (double)C;
//		printf("avg: %lf\n", avg);
		if (S < 2*C) {
			for(unsigned i = S; i < 2*C; ++i)
				SS[i] = 0;
		}
		stable_sort(SS, SS + 2*C, [](const int& a, const int& b) { return a < b; });
//		for(unsigned i = 0; i < S; ++i)
//			printf(":%d=%d\n", i, SS[i]);

		L = 0; R = 2*C-1;
		printf("Set #%d\n", Acnt);
		while (L<R) {
			ans += abs((double)(SS[L]+SS[R])-(double)avg);	
//			printf("ans+=%lf\n",abs((double)(SS[L]+SS[R])-(double)avg));
			printf(" %d:", cnt);
			if (SS[L]==0 && SS[R]==0) printf("\n");
			else if (SS[L] == 0) printf(" %d\n", SS[R]);
			else printf(" %d %d\n", SS[L], SS[R]);
			++L; --R;
			++cnt;
		}
		printf("IMBALANCE = %.5lf\n\n", ans);
		memset(SS, 0, 20);
		++Acnt;
	}	
	return 0;
}

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
unsigned N;
unsigned K;
unsigned L;
unsigned A[100001];

void solve()
{ bool assigned = 0;
	unsigned nAssigned = 0, l=0,r=K-1;
	sort(A, A+K,[](const unsigned& a, const unsigned& b){return a<b;});
	while (l<r) {
			if (A[l] + A[r] <= L) {
				// can fit two in a box
				++nAssigned;
				--r,++l;
			} else {
				++nAssigned;
				--r;
			}
	}
	if (l==r) {
		++nAssigned;
	}
	printf("%d\n", nAssigned);
}

int main()
{
	cin >> N;
	for(unsigned i = 0; i < N; ++i) {
		cin >> K;
		cin >> L;
		for(unsigned i = 0; i < K; ++i) {
			cin >> A[i];
		}
		solve();		
		if (i!=N-1) printf("\n");
	}
	return 0;
}

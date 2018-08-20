#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <unordered_map>
using namespace std;
int *A, *B, *C, *D;
unsigned S=0;
int main()
{ int N, k;
	cin >> N;
	for(int i = 0; i < N; ++i) {
		S=0;
		unordered_map<int, unsigned> M;
		scanf("%d",&k);
		A = new int[k];
		B = new int[k];
		C = new int[k];
		D = new int[k];
		for(unsigned i = 0; i < k; ++i) {
			cin >> A[i];
			cin >> B[i];
			cin >> C[i];
			cin >> D[i];
		}
		for(unsigned i = 0; i < k; ++i)
			for(unsigned j = 0; j < k; ++j) {
				if (M.find(A[i]+B[j]) != M.end()) {
					M[A[i]+B[j]] += 1;
				} else
					M[A[i]+B[j]] = 1;
			}
		for(unsigned i = 0; i < k; ++i)
			for(unsigned j = 0; j < k; ++j) {
				if (M.find(-(C[i]+D[j])) != M.end()) {
					S += M[-(C[i]+D[j])];
				} 
			}
		cout << S << endl;
		delete[] A;
		delete[] B;
		delete[] C;
		delete[] D;
		if (i!=N-1) puts("");
	}
	return 0;
}

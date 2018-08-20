#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <utility>
#include <memory.h>
using namespace std;

int main()
{ int N, M;
	cin >> M;
	for(int c = 0; c < M; ++c) {
		cin >> N;
		vector<int> assignments;
		int S = 2, P = 3;
		assignments.push_back(2);
		while (1) {
			if (P + S <= N) {
//				printf("pushing back: %d\n", P);
				assignments.push_back(P);
				if (P + S == N) break;
				S += P;
				++P; 
			} else {
				int d = N - S;
//				printf("doubling: %d\n", assignments[d - 2]);
				while (d > 0) {
					for(int i = 1; i <= d && i <= assignments.size(); ++i)
						++assignments[assignments.size() - i];
					d -= assignments.size();
				}
				break;
			}
		}
		sort(assignments.begin(), assignments.end(), less<int>());
		for(int i = 0; i < assignments.size() - 1; ++i) cout << assignments[i] << " ";
		cout << assignments[assignments.size() - 1] << endl;
		if (c != M - 1) printf("\n");
	}
	return 0;
}

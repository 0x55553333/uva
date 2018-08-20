#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <memory.h>
using namespace std;
struct agency {
	string name;
	int A;
	int B;
	int cost;
};
const static double eps = 0.000000001;
int main()
{ int C, N, M, L, to;
	cin >> C;
	for(int testCase = 0; testCase < C; ++testCase) {
		cin >> N >> M >> L;
		to = N - M;
		vector<agency> A;
		for(int i = 0; i < L; ++i) {
			agency a; string s; 
			cin >> s;
			a.name = "";
			int j = 0; while (s[j] != ':') { a.name += s[j]; ++j; }
			++j; a.A = strtoul(s.c_str()+j, NULL, 10);
			while (s[j] != ',') ++j; ++j;
			a.B = strtoul(s.c_str()+j, NULL, 10);
			a.cost = 0;			
			A.push_back(a);
		}
	for(int i = 0; i < A.size(); ++i) {
			double p;
			if (to > 0) {
				int curr = N;
				while (curr > M) {
					double dB = A[i].B / (double)(curr - curr/2);
					if (dB <= A[i].A - eps && (curr/2) >= M) {
						A[i].cost += A[i].B; curr /= 2;
					} else {
						A[i].cost += A[i].A * (curr - M);
						curr = M; break;
					}
				}
			} else
				A[i].cost = 0;
		}
		sort(A.begin(), A.end(), [](const agency& a, const agency& b) { if (a.cost == b.cost) return a.name < b.name; return a.cost < b.cost; });
		cout << "Case " << testCase+1 << endl;
		// output
		for(int i = 0; i < A.size(); ++i) {
				cout << A[i].name << " " << A[i].cost << endl;
		}
	}
	return 0;
}


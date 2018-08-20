#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <utility>
#include <vector>
#include <cmath>
using namespace std;

int main()
{ long N, M;
	cin >> N;
	for(long I = 0; I < N; ++I) {
		cin >> M;
		vector<pair<long,long> > S;
		if (I!=0) printf("\n");
		while (1)  {
			pair<long,long> P;
			cin >> P.first >> P.second;
			if (P.first==0 && P.second==0) break;
			S.push_back(P);
		}
		sort( S.begin(), S.end(), [](const pair<long,long>& a, const pair<long,long>& b) {
				return a.first < b.first; // according to L endpoint
		});
		vector<pair<long,long> > solutions;
		pair<long,long> last_solution;
		long i = 0, L = 0, R = 0, maxd = 0, cnt = 1; 
		while (S[i].second < 0) ++i;
		unsigned c=0;
		while (i < S.size()) { //Problem 2: can't terminate when R<=M; must scan all segments
			if (S[i].first <= L && S[i].second - L > maxd) {
				maxd = S[i].second - L;
				R = S[i].second;
				last_solution = S[i];
			} else if (S[i].first > L) {
//				if (R < S[i].first - 1) { /* **** This problem has a problem: it's actually (L_i, R_i) not [L_i, R_i] *** */
				if (R < S[i].first && R<M) { // infeasible condition
					printf("0\n");				
					goto __;
				} else if (R==M) {
					solutions.push_back(last_solution);
					goto _;
				}
				solutions.push_back(last_solution);
				L = max(R,S[i].first); 
				if (R>=M) { goto 	_; }
				++cnt; 
				maxd = 0;
				continue;
			} 
			++i;
		}
		if (last_solution.second < M) {
			printf("0\n");
			goto __;
		}
		solutions.push_back(last_solution);
_:
		printf("%ld\n", cnt);
		for(const auto& sol : solutions) {
			printf("%ld %ld\n", sol.first, sol.second);
		}
__:;
	}
	return 0;
}

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

int main()
{ int N, k = 0, L = 0, R = 0;
	pair<int,int> cover, best;
	vector< pair<int,int> > PS, SS;
	cin >> N;
	cin >> cover.first >> cover.second;
	for(int i = 0; i < N; ++i) {
		pair<int,int> p;
		cin >> p.first >> p.second;
		PS.push_back(p);
	}
	sort(PS.begin(), PS.end(), [](const pair<int,int>& a, const pair<int,int>& b) {return a.first < b.first;});
	L = cover.first; R = L;
	printf("covering: [%d,%d]\n", cover.first, cover.second);
	while (k < PS.size()) {
		if (PS[k].second < L) { ++k; continue; }
		if (R >= cover.second) break;
		if (PS[k].first <= L && PS[k].second > R) {
			best = PS[k];
			R = PS[k].second;
		} else if (PS[k].first > L) {
			if (PS[k].first > R) goto imps;
			if (PS[k].second >= cover.second) {
				SS.push_back(best);
				best = PS[k];
				R = PS[k].second;
				break;
			}
			SS.push_back(best);
			L = R;
			continue;
		}
		++k;
	}	
	if (L!=R) SS.push_back(best);
	if (R < cover.second) goto imps;
	printf("Size=%lu\n", SS.size());
	for(const auto& p : SS) {
		printf("(%d,%d)\n", p.first, p.second);
	}
	return 0;

imps:
		 printf("Impossible\n");
	return 0;
}

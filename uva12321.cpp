#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <utility>
#include <vector>
#include <memory.h>
using namespace std;

int main()
{ int G,L;
	while (cin>>L>>G) {
		if (G==0&&L==0) break;
		vector< pair<int,int> > as, ss;
		for(int i = 0; i < G; ++i) {
			int x, r; pair<int,int> p;
			cin >> x >> r;
			p.first = x - r; p.second = x + r;
			as.push_back(p);
		}
		sort(as.begin(), as.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
			return a.first < b.first;		
		});
		int l=0, r=0, p=0, k=0;
		pair<int,int> best;
		while (p < as.size()) {
			if (as[p].second < l) { ++p; continue; }
			if (r >= L) { break; }
			if (as[p].first <= l && as[p].second > r) {
				r = as[p].second;
				best = as[p];
			} else if (as[p].first > l) {
				if (as[p].first > r) goto imp;
				if (as[p].second >= L) {
					ss.push_back(best);
					r = as[p].second;
					best = as[p];
					break;
				}
				ss.push_back(best);
				best = as[p];
				l = r;
				continue;
			}
			++p;
		}
		if (l != r) ss.push_back(best);
		if (r < L) goto imp;
		k = as.size() - ss.size();
		printf("%d\n", k);
		continue;
imp:
		printf("-1\n");
	}
	return 0;
}

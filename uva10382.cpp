#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <utility>
#include <memory.h>
#include <vector>
#include <cmath>
using namespace std;
#define td(x) ((double)(x))
#define sq(x) ((x)*(x))
#define sqtd(x) (sq(td(x)))
const static double eps = 0.000000001;
int main()
{ int n,l,w;
	while (cin>>n>>l>>w) {
		vector<pair<double,double> > in;
		for(int i = 0; i < n; ++i) {
			int pos, rad;
			pair<double,double> p;
			cin >> pos >> rad;
			if (rad > (double)w /2.0) {
				p.first = td(pos) - sqrt(sqtd(rad) - sq(td(w)/2));
				p.second = td(pos) + sqrt(sqtd(rad) - sq(td(w)/2));
				in.push_back(p);
			}
		}
		sort(in.begin(), in.end(), [](const pair<double,double> a, const pair<double,double> b) {
			return a.first < b.first - eps;	
		});
		int k = 0, p = 0;
		double L=0.0, R=0.0;
		while (p < in.size()) {
			if (in[p].second < L) { ++p; continue; }
			if (R >= l) break;
			if (in[p].first <= L && in[p].second > R) {
				R = in[p].second;
			} else if (in[p].first > L) {
				if (in[p].first > R) {
					goto imp;
				}
				if (in[p].second >= l) {
					R = in[p].second;
					++k; break;
				}
				++k; L = R; continue;
			}
			++p;
		}
		if (R < l) goto imp;
		if (!(L >= R - eps && L <= R + eps)) ++k;
		printf("%d\n", k);
		continue;
imp:
		printf("-1\n");
	}
	return 0;
}

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>
using namespace std;
const static double eps = 0.000000001;
inline static bool in(pair<double,double>& v, double d)
{
	return d >= v.first && d <= v.second;
}

int main()
{ int n,d,c=1;
	while (cin >> n >> d) {
		if (n < 1 || n > 1000) break;
		vector< pair<double,double> > is;
		bool mark = 0;
		for(int i = 0; i < n; ++i) {
			int x,y; pair<double,double> p;
			cin >> x >> y;
			if (y > d) mark = 1;
			else {
				double dd = sqrt((double)(d*d) - (double)(y*y));
				p.first = x - dd; p.second = x + dd;
				is.push_back(p);
			}
		}
		if (mark) goto imp;
		sort(is.begin(), is.end(), [](const pair<double,double>& a, const pair<double,double>& b) {
			return a.second < b.second - eps;		
		});
		int k = 0, p = 0;
		double culm = 0;
		while (p < is.size()) {
			if (in(is[p], culm)) {
				++p; continue;	
			} else {
				++k;
				
			}
			++p;
		}

		printf("Case %d: %d\n", c, k);
		continue;
imp:
		printf("Case %d: -1\n", c);
	}
	return 0;
}

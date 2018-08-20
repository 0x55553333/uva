#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <utility>

using namespace std;

int main()
{	int c;
	cin >> c;
	for(int i = 0; i < c; ++i) {
		int t, m, n, C[1500], total_time = 0, total_rounds = 0;
		cin >> n >> t >> m;
		for(int j = 0; j < m; ++j) cin >> C[j];
		if (m>n) {
			int take = m % n;
			if (take==0) {
				take = n - 1;
				total_time = C[take];
				while (take < m) {
					take += n;
					total_time = max(C[take], total_time+2*t) ;
					total_rounds++;
				}	
				if (C[take-n] >= total_time - 2*t)
					total_time = C[m-1]+t; 
				else
					total_time -= t; 
			} else {
				--take;
				total_time = C[take];
				while (take < m) {
					total_time = max(C[take], total_time+2*t);	
					total_rounds++;
					take += n;
				}
				if (C[take-n] >= total_time - 2*t)
					total_time = C[m-1] + t;
				else
					total_time -= t;
			}
		} else {
			total_rounds = 0;
			total_time = C[n-1] + t;
		}
		cout << total_time << " " << total_rounds << endl;
	}
	return 0;
}

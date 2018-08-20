#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <utility>
#include <memory.h>
using namespace std;

int main()
{ int T, N, P;
	cin >> T;
	for(int c = 0; c < T; ++c) {
		cin >> N;
		vector<string> ss;
		for(int i = 0; i < N; ++i) {
			string s;
			cin >> s;
			ss.push_back(s);
		}
		sort(ss.begin(), ss.end());
		P = ss[0].size();
		for(int i = 1; i < N; ++i) {
			int j;
			for(j = 0; j < ss[i-1].size() && j < ss[i].size(); ++j)
				if (ss[i][j] != ss[i-1][j]) break;
			P += ss[i].size() - j;
		}
		cout << P << endl;
		for(int i = 0; i < N; ++i) cout << ss[i] << endl;
	}
	return 0;
}

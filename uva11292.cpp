#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <utility>
#include <memory.h>
using namespace std;

int main()
{ int N, M;
	while (cin >> N >> M) {
		if (M==0&&N==0) break;
		vector<int> heads, knights;
		for(int i = 0; i < N; ++i) { int j; cin >> j; heads.push_back(j); }
		for(int i = 0; i < M; ++i) { int j; cin >> j; knights.push_back(j); }
		sort(heads.begin(), heads.end(), [](const int& a, const int& b) { return a < b; });
		sort(knights.begin(), knights.end(), [](const int& a, const int& b) { return a < b; });
		int i = 0, j = 0, tot = 0;
		while (i < knights.size() && j < heads.size()) {
			if (heads[j] > knights[i]) ++i;
			else {
				tot += knights[i];
				++i; ++j;
			}
		}
		if (j != heads.size()) {
			cout << "Loowater is doomed!" << endl;
		} else
			cout << tot << endl;
	}
	return 0;
}

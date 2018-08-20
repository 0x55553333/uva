#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <utility>
#include <memory.h>
using namespace std;

int main()
{ int N, k;
	while (cin >> N) {
		vector<int> s;
		if (N==0) break;
		for(int i = 0; i < N; ++i) {
			cin >> k;
			if (k > 0) s.push_back(k);
		}
		if (s.size() > 0) {
			for(int i = 0; i < s.size() - 1; ++i) printf("%d ", s[i]);
			printf("%d\n", s[s.size()-1]);
		} else printf("0\n");
	}
	return 0;
}

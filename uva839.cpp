#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <utility>
#include <memory.h>
using namespace std;
pair<bool, int> solve()
{ int wL, dL, wR, dR;
	cin >> wL >> dL >> wR >> dR;
	if (wL == 0 && wR == 0) {
		pair<bool, int> rL = solve(), rR = solve();
		return make_pair<bool,int>(
				rL.first && rR.first && (rL.second * dL == rR.second * dR), rL.second+rR.second);
	} else if (wL == 0) {
		pair<bool, int> rL = solve();
		return make_pair<bool,int>
			((rL.first) && (rL.second * dL == wR * dR), rL.second+wR);
	} else if (wR == 0) {
		pair<bool, int> rR = solve();
		return make_pair<bool, int>
			((rR.first) && (wL * dL == rR.second * dR), wL+rR.second);
	} else {
		return make_pair<bool, int>
			(wL * dL == wR * dR, wL+wR);
	}
}

int main()
{ int f;
	cin >> f;
	for(int i = 0; i < f; ++i) {
		pair<bool, int> R = solve();
		if (R.first) cout << "YES" << endl;
		else cout << "NO" << endl;
		if (i != f-1) cout << endl;
	}
	return 0;
}



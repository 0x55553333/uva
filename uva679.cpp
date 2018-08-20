#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <bitset>
#include <vector>
#include <utility>
#include <algorithm>
#include <memory.h>
using namespace std;
int main()
{ int l, D, I;
	cin >> l;
	while (l--) {
		cin >> D >> I;
		int k = 1;
		for(int i = 0; i < D-1; ++i) {
			if (I & 1) { k <<= 1; I = (I+1) >> 1; }
			else { k <<= 1; k += 1; I >>= 1; }
		}
		cout << k << endl;
	}
	cin >> l;
	return 0;
}

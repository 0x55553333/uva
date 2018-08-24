#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <utility>
#include <algorithm>
#include <memory.h>
#include <cmath>
using namespace std;

int main()
{ long long T;
	while (cin >> T) {
		long long X1, X2, Y1, Y2, Z1, Z2;
		X1 = Y1 = Z1 = -0xffffffffff;
		X2 = Y2 = Z2 = 0xfffffffffff;
		if (T == 0) break;
		while (T--) {
			long long x1, y1, z1, x2, y2, z2, p;
			cin >> x1 >> y1 >> z1 >> p;
			x2 = x1+p; y2 = y1+p; z2 = z1+p;
			X1 = max(X1, x1); Y1 = max(Y1, y1); Z1 = max(Z1, z1);
			X2 = min(X2, x2); Y2 = min(Y2, y2); Z2 = min(Z2, z2);
		}
		long long area = (X2-X1)*(Y2-Y1)*(Z2-Z1);
		printf("%lld\n", area < 0 ? 0 : area);
	}
	return 0;
}

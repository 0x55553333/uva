#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <utility>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;

int X[2000], Y[2000], n;
double m[2000][2000];

double dist(int i, int j)
{ double dx = (double) X[i] - X[j],
				 dy = (double) Y[i] - Y[j];
	return sqrt(dx*dx + dy*dy);
}

double opt(int i, int j);
double _opt(int i, int j)
{
	return min(dist(j, i+1) + opt(i+1, i), dist(i, i+1) + opt(i+1, j));
}
double opt(int i, int j)
{
	if (i == n-1) return dist(n-1, n) + dist(j, n);
	if (m[i][j] != 0) return m[i][j];
	else return m[i][j] = _opt(i, j);
}

int main()
{
	while (cin >> n) {
		if (n == 0) break;
		memset(X, 0, sizeof(X)); memset(Y, 0, sizeof(Y));
		memset(m, 0, sizeof(m));
		for(int i = 1; i <= n; ++i) {
			cin >> X[i]; cin >> Y[i];
		}
		printf("%.2f\n", opt(1,1));
	}
	return 0;
}


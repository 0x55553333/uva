#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <utility>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;
int g[11][101], M[101][11], v[101][11], m, n;

int opt(int i, int j);
int _opt(int i, int j)
{
	return min(opt(i+1, j), min(opt(i+1, j-1), opt(i+1, j+1))) + g[j][i];
}
int opt(int i, int j)
{
	if (j == m) j = 0;
	if (j == -1) j = m-1;
	if (i == n-1) return M[i][j] = g[j][i];
	if (!v[i][j]) {
		v[i][j] = 1;
		return M[i][j] = _opt(i, j);
	} else return M[i][j];
}

void print_path(int i, int j, vector<int>& path)
{ int next = 0xfffff;
	path.push_back(j+1);
	if (i+1 == n) return;
	for(int p = -1, k = j + p; p <= 1; ++p, k = j + p) {
		if (k == m) k = 0;
		if (k == -1) k = m-1;
		if (M[i+1][k] == M[i][j] - g[j][i]) {
			next = min(next, k);
		}
	}
	if (next != 0xfffff)
		print_path(i+1, next, path);
}

int main()
{
	while (cin >> m >> n) {
		vector<int> path;
		memset(g, 0, sizeof(g)); memset(v, 0, sizeof(v));
		memset(M, 0, sizeof(m));
		for(int i = 0; i < m; ++i) 
			for(int j = 0; j < n; ++j)
				cin >> g[i][j];
		int min_d = 0xfffff, min_i = m-1;
		for(int i = m-1, a; i >= 0; --i) {
			a = opt(0, i);
			if (a <= min_d) {
				min_d = a; min_i = i;
			}
		}
		print_path(0, min_i, path);
		for(int i = 0; i < path.size()-1; ++i) printf("%d ", path[i]);
		printf("%d\n%d\n", path[path.size()-1], min_d);
	}
	return 0;
}


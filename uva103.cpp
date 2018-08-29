#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <utility>
#include <memory.h>
using namespace std;
int G[31][31], m[31][31], d[31][11];

// i inside j
bool inside(int i, int j, int n)
{
	for(int k = 0; k < n; ++k)
		if (d[i][k] >= d[j][k]) return 0;
	return 1;
}

void build_graph(int n, int k)
{
	for(int i = 1; i <= k; ++i)
		for(int j = 1; j <= k; ++j)
			if (inside(i, j, n)) {
				G[i][j] = 1;
			}
}

int visit(int o, int i, int k);
int _visit(int o, int i, int k)
{
	int ans = 1;
	for(int j = 1; j <= k; ++j)
		if (G[i][j]) {
			ans = max(ans, visit(o, j, k) + 1);
		}
	return ans;
}

int visit(int o, int i, int k)
{
	if (m[o][i] != 0) return m[o][i];
	else return m[o][i]=_visit(o, i, k);
}

void print(int i, int o, int k, vector<int>& result)
{
	result.push_back(i);
	for(int j = 1; j <= k; ++j)
		if (G[i][j] && m[o][i] == m[o][j] + 1) {
			print(j, o, k, result);
			return;
		}
}

int main()
{
	int n, k;
	while (cin >> k >> n) {
		memset(G, 0, sizeof(G));
		memset(m, 0, sizeof(m));
		memset(d, 0, sizeof(d));
		if (k < 0 || k > 30) break;
		for(int i = 1; i <= k; ++i) {
			for(int j = 0; j < n; ++j) 
				cin >> d[i][j];
			sort(d[i], d[i]+n, less<int>());
		}
		build_graph(n, k);
		int max_d = 1, max_i = 1;
		for(int i = 1; i <= k; ++i) {
			m[i][i] = visit(i, i, k);
			if (m[i][i] > max_d) {
				max_d = m[i][i]; max_i = i;
			}
		}
		vector<int> result;
		printf("%d\n", max_d);
		print(max_i, max_i, k, result);
		for(int i = 0; i < result.size()-1; ++i) printf("%d ", result[i]);
		printf("%d\n", result[result.size()-1]);
	}
	return 0;
}


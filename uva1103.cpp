#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
#include <utility>
#include <vector>
#include <memory.h>
#include <algorithm>
using namespace std;
/*
A: 2
J: 4
D: 6
S: 5
W: 1
K: 3
	 */
const char* Hash = "0WAKJSD";
struct graph {
	map<int, set<int> > List;
	map<int, short> orig;
	void add_edge(int s, int t) {
		this->List[s].insert(t);
		this->List[t].insert(s);
	}
	void set_orig(int s, short s1) {
		this->orig[s] = s1;
	}
	int size;
	graph() { this->size = 0; }
};

inline static short c2h(char c)
{
	if (c >= '0' && c <= '9') return c - '0';
	else return c - 'a' + 10;
}

void build(int* M, graph& G, int m, int n, int i, int j, int t, int r)
{
	if (i >= m || j >= n || i < 0 || j < 0) return;
	if (M[i*n+j] != t) {
		if (M[i*n+j] > 1 && M[i*n+j] != r) {
			G.add_edge(r, M[i*n+j]);
			G.set_orig(r, t);
		}
		return;
	}
	M[i*n+j] = r;
	build(M, G, m, n, i, j+1, t, r);
	build(M, G, m, n, i, j-1, t, r);
	build(M, G, m, n, i+1, j, t, r);
	build(M, G, m, n, i-1, j, t, r);
}

void print_mat(int* mat, int m, int n)
{
	for(int i = 0; i < m; ++i) {
		for(int j = 0; j < n; ++j) {
			if (mat[i*n+j]<2)
				printf("%d", mat[i*n+j]);
			else
				printf("f");
		}
		printf("\n");
	}
}

int main()
{
	int m, n, cnt = 0;
	while (cin >> m >> n) {
		++cnt;
		if (m==0 && n==0) break;
		graph g;
		m += 2; n *= 4; n += 2;
		int *mat = new int[m*n];
		int reg = m*n*16+1;
		memset(mat, 0, m*n*sizeof(int));
		getc(stdin);
		for(int i = 1; i < m-1; ++i) {
			for(int j = 1; j < n-1; j += 4) {
				short x = c2h((char) getc(stdin));	
				for(int k = 3; k >= 0; --k, x >>= 1) 
					mat[i*n+j+k] = x & 1;
			}
			getc(stdin);
		}
		for(int i = 0; i < m; ++i)
			for(int j = 0; j < n; ++j)
				if (mat[i*n+j] < 2) {
					build(mat, g, m, n, i, j, mat[i*n+j], reg);
					++reg; ++g.size;
				}
		printf("Case %d: ", cnt);
		vector<char> output;
		for(const pair<int,set<int> >& pk : g.List) {
			if (g.orig[pk.first]) {
					output.push_back(Hash[pk.second.size()]);
			}	
		}
		sort(output.begin(), output.end());
		for(const char& c : output) printf("%c", c);
		printf("\n");
		delete[] mat;
	}
	return 0;
}


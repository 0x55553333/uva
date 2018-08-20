#include <iostream>
#include <cstdio>
#include <cstdlib>
#include<map>
#include <set>
using namespace std;

// building adjacency list for floodfill in n^2 * (log^2 n) time
// from input matrix
// main idea: hashing graph into different blocks
struct graph {
	map<int, set<int> > list;
	int size;
	void add_edge(int s, int t) {
		this->list[s].insert(t);
		this->list[t].insert(s);
	}
	int get_size() { return this->size; }
	void set_size(int N) { this->size = N; }
};

void build(int* M, graph& g, int m, int n, int i, int j, int t, int r)
{
	if (i >= m || j >= n || i < 0 || j < 0) return;
	if (M[i*m+j] != t) {
		if (M[i*m+j] >= m*n && M[i*m+j]!=r) 
			g.add_edge(r, M[i*m+j]);
		return;
	} 
	M[i*m+j] = r;
	build(M, g, m, n, i, j+1, t, r);
	build(M, g, m, n, i+1, j, t, r);
	build(M, g, m, n, i, j-1, t, r);
	build(M, g, m, n, i-1, j, t, r);
	build(M, g, m, n, i+1, j+1, t, r);
	build(M, g, m, n, i-1, j-1, t, r);
	build(M, g, m, n, i+1, j-1, t, r);
	build(M, g, m, n, i-1, j+1, t, r);
}

void print_graph(graph& g) {
	for(const auto& p : g.list) {
		int i = p.first;
		printf("Node %d: ", i);
		for(const int& k : g.list[i]) 
			printf("%d ", k);
		puts("");
	}
}

void print_matrix(int* M, int m, int n)
{
	for(int i = 0; i < m; ++i) {
		for(int j = 0; j < n; ++j)
			printf("%d ", M[i*m+j]);
		puts("");
	}
}

int main()
{ int m, n;
	cin >> m >> n;
	int* in = new int [m*n];
	for(int i = 0; i < m; ++i)
		for(int j = 0; j < n; ++j)
			cin >> in[m * i + j];
	int size = 0, reg = m*n+1;
	printf("done, initializing graph of size %d..\n", m*n*m*n);
	print_matrix(in, m, n);
	graph g;
	printf("building graph...\n");
	for(int i = 0; i < m; ++i)
		for(int j = 0; j < n; ++j)
			if (in[i*m+j]<m*n) {
				printf("i: build(*), i=%d, j=%d\n",i,j);
				build(in, g, m, n, i, j, in[i*m+j], reg);
				print_matrix(in, m, n);
				++reg; ++size;
			}
	g.set_size(size);
	printf("graph built; size=%d\n", size);
	print_graph(g);
	return 0;
}


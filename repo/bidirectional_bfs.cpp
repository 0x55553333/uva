#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <utility>
#include <memory.h>
#include <ctime>
#include <cassert>
using namespace std;
// Implementation of
// O(2b^(1/2)) bidirectional search
// along with a traditional bfs
// to verify it
struct graph {
	vector<int> *list;
	int size;
	graph(int N) {
		this->list = new vector<int>[N];
		this->size = N;
	}
	~graph() { delete[] this->list; }
	void add_edge(int s, int t) {
		if (!safe(s) || !safe(t)) return;
		this->list[s].push_back(t);
	}
	bool is_adjacent(int s, int t) {
		if (!safe(s) || !safe(t)) return false;
		return find(this->list[s].begin(), this->list[s].end(),t) != this->list[s].end();
	}
	bool safe(int s) { return s < this->size && s >= 0; }
};
// L of size N, R of size N
int bbfs(graph& g, int s, int t, int* L, int* R)
{ if (s == t) return 0;
	if (!g.safe(s) || !g.safe(t)) return -1;
		queue<int> front, back;
		int k, j;
		front.push(s); back.push(t);
		for(int i = 0; i < g.size; ++i)
			L[i] = R[i] = 0xfffffff;
		L[s] = 0; R[t] = 0;
		while (!front.empty() && !back.empty()) {
			k = front.front(); front.pop();
			j = back.front(); back.pop();
			if (k == j) break;
			for(const int& adj : g.list[k]) {
				if (L[adj] > L[k]+1) {
					L[adj] = L[k] + 1;
				  front.push(adj);
        }
			}
			for(const int& adj : g.list[j]) {
				if (R[adj] > R[j] + 1) {
					R[adj] = R[j] + 1;
				  back.push(adj);
        }
			}
		}
		if (k != j) return -1;
		return L[k] + R[k];
}

int bfs(graph& g, int s, int t, int *D)
{
	if (s == t) return 0;
	if (!g.safe(s) || !g.safe(t)) return -1;
	queue<int> nodes;
	int k;
	nodes.push(s); 
	for(int i = 0; i < g.size; ++i)
		D[i] = 0xfffffff;
	D[s] = 0;
	while (!nodes.empty()) {
		k = nodes.front(); nodes.pop();
		if (k == t) break;
		for(const int& adj : g.list[k]) {
			if (D[adj] > D[k]+1)
				D[adj] = D[k] + 1;
			nodes.push(adj);
		}
	}
	if (k != t) return -1;
	return D[t];
}

void print_graph(graph& g)
{
	for(int i = 0; i < g.size; ++i) {
		printf("Node %d: ", i);
		for(const int& adj : g.list[i])
			printf("%d ", adj);
		printf("\n");
	}
}

void generate_graph(graph& g, int size_edges)
{
	assert(g.size > 0 && size_edges > 0);
	for(int i = 0; i < size_edges; ++i) {
		int s = rand() % g.size, t = rand() % g.size;
		g.add_edge(s, t);
	}
}

int main()
{ srand(time(NULL));
	int size = 50, size_edges = 3*size;
	graph g(size);
	printf("size of graph = %d\n", g.size);
	generate_graph(g, size_edges);
	print_graph(g);
	int *D = new int[size], *L = new int[size], *R = new int[size];
	int s = rand() % size, t = rand() % size, bfs_r = bfs(g, s, t, D), bfs_t = bbfs(g, s, t, L, R);
	printf("bfs: %d, bbfs: %d, s=%d, t=%d\n", bfs_r, bfs_t, s, t);
	delete[] D; delete[] L; delete[] R;
	return 0;
}


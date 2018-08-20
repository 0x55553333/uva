#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <utility>
#include <memory.h>
#include <cstring>
using namespace std;
pair<int,int> solve(int* A1, int* A2, int *D1, int* D2, int L1, int R1, int L2, int R2)
{
	if (R2 < L2) return make_pair(0xffff,0xffff);
	if (L2==R2) return make_pair(A2[L2], A2[L2]);
	int root = A2[R2], p = L1;
	pair<int,int> p1, p2;
//	while (A1[p] != root && p <= R1) ++p;
	p = D1[root];
	p1 = solve(A1, A2, D1, D2, L1, p-1, L2, L2+(p-L1)-1);
	p2 = solve(A1, A2, D1, D2, p+1, R1, L2+(p-L1), R2-1);
	if (p1.second < p2.second) {
		return make_pair
			(p1.first, root+p1.second);
	} else if (p1.second == p2.second) {
		if (p1.first < p2.first) {
			return make_pair
				(p1.first, root+p1.first);
		} else return make_pair
			(p2.first, root+p2.second);
	} else { /* p2.second < p1.second */
		return make_pair
			(p2.first, root+p2.second);
	}
}

int solve2(int* A1, int*A2, int* D1, int* D2, int L1, int R1, int L2, int R2, int& leaf)
{
	if (R2 < L2) {
		leaf = 0xffff; return 0xffff;
	}
	if (L2 == R2) { leaf = A2[L2]; return A2[L2]; }
//	printf("solve2: %d,%d,%d,%d\n", L1, R1, L2, R2);
	int root = A2[R2], a1, a2, p = D1[root], leaf1, leaf2;
	a1 = solve2(A1, A2, D1, D2, L1, p-1, L2, L2+(p-L1)-1, leaf1);
	a2 = solve2(A1, A2, D1, D2, p+1, R1, L2+(p-L1), R2-1, leaf2);
	if (a1 < a2) {
		leaf = leaf1; return a1;
	} else if (a1 == a2) {
		if (leaf1 < leaf2) { leaf = leaf1; return a1; }
		else { leaf = leaf2; return a2; }
	} else {
		leaf = leaf2; return a2;
	}
}
int parse(char* order, int* o, int* od)
{ int p = 0, k;
	o[p++] = atoi(order);
	while (1) {
		while (*order != '\0' && *order != '\n' && isdigit(*order)) ++order;
		while (*order != '\0' && *order != '\n' && *order == ' ') ++order;
		if (*order == '\0' || *order == '\n') break;
		k = atoi(order); 
		od[k] = p; 
		o[p++] = k;
	}
	return p;
}
int main()
{
	int in_order_t[20000], post_order_t[20000],
			din_order_t[20000], dpost_order_t[20000];
	while (1) {
		char *in_order = new char[20000], *post_order = new char[20000];
		memset(in_order_t, 0, sizeof(int)*20000); memset(post_order_t, 0, sizeof(int)*20000);
		memset(din_order_t, 0, sizeof(int)*20000); memset(dpost_order_t, 0, sizeof(int)*20000);
		if (fgets(in_order, 20000, stdin) == NULL) break;
		if(fgets(post_order, 20000, stdin) == NULL) break;
		int nit = parse(in_order, in_order_t, din_order_t), npt = parse(post_order, post_order_t, dpost_order_t);	
		delete[] in_order; delete[] post_order;
		if (nit == 0 || npt == 0) break;
//		int leaf, rep = solve2(in_order_t, post_order_t, din_order_t, dpost_order_t, 0, nit-1, 0, npt-1, leaf);
		pair<int,int> p = solve(in_order_t, post_order_t, din_order_t, dpost_order_t, 0, nit-1, 0, npt-1);
		int leaf = p.first;
		printf("%d\n", leaf);
	}
	return 0;
}


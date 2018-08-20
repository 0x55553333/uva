#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <utility>
#include <memory.h>
#include <time.h>
#include <cassert>
using namespace std;
// Binary-Indexed Tree (BIT, or Fenwick trees)
// Two operations:
// Add(x, d): Add d values to index x
// Query(L, R): Compute cumulative sum from index L to index R (L<=R)
#define lowbit(x) ((x)&(-x))
int sum(int *t, int L, int R)
{
	int r = 0;
	while (R > L) {
		r += t[R]; R -= lowbit(R);
	}
	return r;
}

void add(int *t, int x, int d, int n)
{
	while (x <= n) {
		t[x] += d; x += lowbit(x);
	}
}

void s_add(int *t, int x, int d)
{
	t[x] += d;
}
int s_sum(int *t, int L, int R)
{
	int r = 0;
	for(int i = L; i < R; ++i)
		r += t[i];
	return r;
}
int main()
{
	srand(time(NULL));
	int k = 50, t[50], tv[50];
	memset(t, 0, k*sizeof(int));
	memset(tv, 0, k*sizeof(int));
	printf("adding rand()\n");
	for(int i = 1; i < k; ++i) {
		int r = rand() % 50+1;
		add(t, i, r, k);
		s_add(t, i, r);
	}
	printf("verifying\n");
	for(int i = 1; i < 100; ++i) {
		int L = rand() % 50 + 2, R = rand() % (50 - L-1) + 1;
		printf("verifying: L=%d, R=%d\n", L, R);
		printf("sum = %d, s_sum = %d\n", sum(t, L, R), s_sum(t, L, R));
	}
	return 0;
}

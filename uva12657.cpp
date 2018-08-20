#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <utility>
#include <memory.h>
using namespace std;
int first, last;

inline static void 
unlink(int* left, int* right, int x)
{
	if (right[x] == -1) {
		right[left[x]] = -1;
		last = left[x];
	} else if (left[x] == -1) {
		left[right[x]] = -1;
		first = right[x];
	} else {
		right[left[x]] = right[x];
		left[right[x]] = left[x];
	}
}
inline static void
link_right(int* left, int* right, int x, int y);
inline static void 
link_left(int* left, int* right, int x, int y)
{
	if (left[y] == -1) {
		left[y] = x; right[x] = y; left[x] = -1;
		first = x;
	} else {
		left[x] = left[y]; right[left[y]] = x;
		right[x] = y; left[y] = x;
	}
}

inline static void
swap(int* left, int* right, int x, int y)
{
	if (right[x] == y || right[y] == x) {
		if (right[y] == x) {
			int t = x; x = y; y = t;
		}
		if (right[y] == -1) last = x;
		if (left[x] == -1) first = y;
		right[x] = right[y];
		left[y] = left[x];
		if (right[y] != -1) 
			left[right[y]] = x;
		if (left[x] != -1)
			right[left[x]] = y;
		left[x] = y;
		right[y] = x;
	} else {
		int x_left = left[x], x_right = right[x];
		if (first == x) first = y;
		else if (first == y) first = x;
		if (last == x) last = y;
		else if (last == y) last = x;
		left[x] = left[y];
		right[x] = right[y];
		left[y] = x_left;
		right[y] = x_right;
		if (right[x] != -1) left[right[x]] = x;
		if (left[x] != -1) right[left[x]] = x;
		if (right[y] != -1) left[right[y]] = y;
		if (left[y] != -1) right[left[y]] = y;
	}
}

inline static void
link_right(int* left, int* right, int x, int y)
{
	int _first = first, _last = last, d = 0;
	if (right[y] == -1) d = 1;
	link_left(right, left, x, y); 
	first = _first; last = _last;
	if (d) {
		last = x;
	}
}

void reverse(int* left, int* right)
{
	int p1 = first, p2;
	while (right[p1] != -1) {
		p2 = right[p1];
		right[p1] = left[p1];
		left[p1] = p2;
		p1 = p2;
	}
	right[p1] = left[p1];
	left[p1] = -1;
	p2 = last;
	last = first;
	first = p2;
}

inline static void print_state(int* left, int* right)
{
	int p = first;
	printf("Printing state\n");
	int breakout = 300;
	while (p != -1) {
		printf("Curr: %d; Left: %d, Right: %d\n", p, left[p], right[p]);
		p = right[p];
		if (--breakout < 0) {
			printf("Caput!\n");  exit(1); }
	}
}

int main()
{ int n, m, k = 1;
	while( cin >> n >> m ) {
		int* left = new int[n+1];
		int* right= new int[n+1];
		for(int i = 1; i <= n; ++i) {
			left[i] = i-1;
			right[i] = i+1;
		}
		left[1] = -1; right[n] = -1;
		first = 1; last = n;
		unsigned inv = 0;
		//printf("Original State: ");
		//print_state(left, right);
		for(int i = 0; i < m; ++i) {
			int c, x, y;
			cin >> c;
			if (c!= 4) cin >> x >> y;
			else inv = !inv;
			if (inv && c != 3) c = 3 - c;
			//printf("Executing action[%d/%d]: %d\n", i, m, c);
			switch (c) {
				case 1: 
					if (left[y] == x) break;
					//printf("Moving %d to left of %d\n", x, y);
					unlink(left, right, x);
					link_left(left, right, x, y);
					break;
				case 2:
					if (right[y] == x) break;
					//printf("Moving %d to right of %d\n", x, y);
					unlink(left, right, x);
					link_right(left, right, x, y);
					break;
				case 3:
					//printf("Swapping %d with %d\n", x, y);
					swap(left, right, x, y);
					break;
			}
		}
		int p = first, b = 1;
		long long s = 0;
		while (p != -1) {
			if (b&1) s += p;
			p = right[p]; ++b;
		}
		if (inv && n%2==0) {
			s = (long long)n*(n+1)/2 - s;
		}
		cout << "Case " << k << ": " << s << endl;
		++k; delete[] left; delete[] right;
	}
}

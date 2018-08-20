#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <utility>
#include <memory.h>
using namespace std;

/*
	 Fixed size doubly-linked array:
	 Fixed-length container that supports dynamic
	 reordering.
	
	 Usage scenario: When dynamic reordering operations
	 (i.e. move to left, move to right) needs to be performed on
	 a fixed array of indexed data.

	 Copyright (c) Ruijie Fang 2018.
*/

/* pointers to the beginning of the list (in order)
	 and the last element of the list (in order). */
int first, last;

/* unlink(3):
	 Unlinks element indexed 'x' from list
	 */
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

/* ... */
inline static void
link_right(int* left, int* right, int x, int y);

/*
	link_left(4):
	Links element 'x' to the left of 'y'.
	*/
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

/*
	 swap(4):
	 Swaps elements 'x' and 'y'.
	 */
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

/*
	 link_right(4):
	 Links element 'x' to the right of element 'y'.
	 */
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

/*
	 reverse(2):
	 Reverses the current order of the entire list.
	 */
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

/*
	 print_state(2):
	 Prints the current list
	 */
inline static void print_state(int* left, int* right)
{
	int p = first;
	printf("Printing state\n");
	//int breakout = 300;
	while (p != -1) {
		printf("Curr: %d; Left: %d, Right: %d\n", p, left[p], right[p]);
		p = right[p];
		//if (--breakout < 0) {printf("Caput!\n");  exit(1); }
	}
}

int main()
{
	cout << 
		"	 Fixed size doubly-linked array:\n" <<
		"	 Fixed-length container that supports dynamic\n" <<
		"	 reordering.\n" <<
		"	\n" <<
		"	 Usage scenario: When dynamic reordering operations\n" <<
		"	 (i.e. move to left, move to right) needs to be performed on\n" <<
		"	 a fixed array of indexed data.\n" <<
		"\n" <<
		"	 Copyright (c) Ruijie Fang 2018.\n";
	return 0;
}

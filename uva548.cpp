#include<stdio.h>
#include<iostream>
#include<sstream>
#include <memory.h>
using namespace std;
int in[10000],post[10000], din[10000], dpost[10000];
int solve(int L1, int R1, int L2, int R2, int& l)
{ if (R2 < L2) {l = 0xffff; return 0xffff;}
	if (L2 == R2) {
		l = post[L2]; return post[L2];
	}
	int root = post[R2], p = din[root], l1, l2,
			r1 = solve(L1, p-1, L2, L2+(p-L1)-1, l1), 
			r2 = solve(p+1, R1, L2+(p-L1), R2-1, l2);
	if (r1 < r2 || (r1==r2 && l1 < l2)) {
		l = l1; return root+r1;
	} else {
		l = l2; return root+r2;
	}
}
int main() {
  string line;
  stringstream sin;
  int c1, c2;
  while(getline(cin, line)) {
    sin.clear(); sin << line;
		memset(in, 0, sizeof(in)); memset(post, 0, sizeof(post));
		memset(din, 0, sizeof(din)); memset(dpost, 0, sizeof(dpost));
    c1 = 0;
		while(sin >> in[c1]) {
			din[in[c1]] = c1; ++c1;
		}
    getline(cin, line);
    sin.clear(); sin << line;
		c2 = 0;
		while(sin >> post[c2]) {
			dpost[post[c2]] = c2; ++c2;
		}
		if (c1 == 0 || c1 > 10000 || c2 ==0 | c2 > 10000) break;
		int ans;
		solve(0, c1-1, 0, c2-1, ans);
		printf("%d\n", ans);
	}
	return 0;
}


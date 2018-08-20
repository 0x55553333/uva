#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <utility>
#include <memory.h>

using namespace std;
int build1(string& x, int& px, int level)
{ if (px == x.size()) return 0;
	switch(x[px]) {
		case 'p': {
			++px;
			int a1 = build1(x, px, level/2);
			int a2 = build1(x, px, level/2);
			int a3 = build1(x, px, level/2);
			int a4 = build1(x, px, level/2);
			return a1+a2+a3+a4; }
		case 'e':
			++px;
			return 0;
			break;
		case 'f':
			++px;
			return level*level;
			break;
	}
	return 0;
}

int build(string& x, string& y, int& px, int& py, int level)
{ if (px == x.size() && py == y.size()) return 0;
	if (px == x.size()) return build1(y, py, level);
	else if (py == y.size()) return build1(x, px, level);
	if (x[px] == 'p' && y[py] != 'p') {
		if (y[py] == 'f') {
			++py;
			build1(x, px, level);
			return level * level;
		} else {
			++py;
			return build1(x, px, level);
		}
	} else if (x[px] != 'p' && y[py] == 'p') {
		if (x[px] == 'f') {
			++px;
			build1(y, py, level);
			return level*level; 
		} else {
			++px;
			return build1(y, py, level);
		}
	} else if (x[px] == 'p' && y[py] == 'p'){ 
		++px; ++py;
		int a1 = build(x, y, px, py, level/2),
				a2 = build(x, y, px, py, level/2),
				a3 = build(x, y, px, py, level/2),
				a4 = build(x, y, px, py, level/2);
		return a1+a2+a3+a4;
	} else { /* both not parents */
		int p = 0;
		if (x[px] == 'f') p = 1;
		if (y[py] == 'f') p = 1;
		++px; ++py;
		return p * level * level;
	}
}

int main()
{ int c;
	cin >> c;
	while (c--) {
		string x, y;
		cin >> x >> y;
		int level = 32, px = 0, py = 0;
		printf("There are %d black pixels.\n",
				build(x, y, px, py, level));
	}
	return 0;
}


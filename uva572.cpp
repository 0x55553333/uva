#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <utility>
#include <memory.h>
using namespace std;
char t[100][100];
int size=0;
void floodfill(int m, int n, int i, int j, char tg, char ind) {
	if (i >= m || j >= n || i < 0 || j < 0) return;
	if (t[i][j] != tg) return;
	t[i][j] = ind;
	floodfill(m, n, i+1, j, tg, ind);
	floodfill(m, n, i-1, j, tg, ind);
	floodfill(m, n, i, j+1, tg, ind);
	floodfill(m, n, i, j-1, tg, ind);
	floodfill(m, n, i-1, j-1, tg, ind);
	floodfill(m, n, i+1, j+1, tg, ind);
	floodfill(m, n, i-1, j+1, tg, ind);
	floodfill(m, n, i+1, j-1, tg, ind);
}

void print(int m, int n)
{
	for(int i = 0; i < m; ++i)
		printf("%s\n", t[i]);
}

int main()
{ int m, n;
	while (cin >> m >> n) {
		size = 0;
		if (m == 0) break;
		memset(t, 0, 100*100);
		for(int i = 0; i < m; ++i) {
			scanf("%s", t[i]);
		}
		for(int i = 0; i < m; ++i)
			for(int j = 0; j < n; ++j)
				if(t[i][j] == '@') {
					floodfill(m, n, i, j, '@', 'A');
					++size;
				}
		printf("%d\n", size);
	}
	return 0;
}


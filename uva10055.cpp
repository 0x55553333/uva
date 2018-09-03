#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
	unsigned long long h, o, t;
	while (cin >> h >> o) {
		if (h > o) { t = o; o = h; h = t; }
		printf("%llu\n", o - h);
	}
	return 0;
}

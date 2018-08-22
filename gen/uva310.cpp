#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <utility>
#include <algorithm>
#include <ctime>
#include <memory.h>
using namespace std;
const char* m = "ab ";
int main(int argc, char** argv)
{ srand(time(NULL));
	int k = atoi(argv[1]);
	while (k--) {
		string a = "", b = "", o = "", z = "";
		size_t a_len, b_len, o_len, z_len;
		a_len = rand() % 5 + 1;
		b_len = rand() % 5 + 1;
		o_len = rand() % 8;
		z_len = rand() % 10;
		while (a_len--) a += m[rand() & 1];
		while (b_len--) b += m[rand() & 1];
		while (o_len--) o += m[rand() & 1];
		while (z_len--) z += m[rand() & 1];
		printf("%s\n%s\n%s\n%s\n", a.c_str(),
			b.c_str(), o.c_str(), z.c_str());	
	}
	return 0;
}

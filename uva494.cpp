#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <sstream>
#include <memory.h>
#include <ctype.h>
using namespace std;
int is_word(const char* s) 
{
	if (isalpha(*s)) return 1;
	return 0;
}

int main()
{ string x;
	while (getline(cin, x)) {
		if (x.size() < 1) break;
		const char *p = x.c_str();
		size_t cnt = 0;
		while (1) {
			while (!isalpha(*p) && *p != '\0') ++p;
			if (*p == '\0') break;
			if (is_word(p)) ++cnt;
			while (isalpha(*p)) ++p;
			if (*p == '\0') break;
		}
		printf("%lu\n", cnt);
	}
	return 0;
}

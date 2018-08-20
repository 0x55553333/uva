#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <memory.h>
#include <string>
#include <cstring>
using namespace std;

int main()
{ string s, t;
	while (cin >> s >> t) {
		if(s.size()==0&&t.size()==0) break;
		unsigned i=0,j=0;
		while(i<s.size()&&j<t.size()) {
			if (t[j]==s[i]) ++i;
			++j;
		}
		if (i==s.size()) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}

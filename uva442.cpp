#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <utility>
#include <memory.h>
#include <stack>
using namespace std;
int row[200], col[200];
int REG = 26;
inline static bool ismatrix(char c)
{ return c >= 'A' && c <= 'Z'; }

inline static bool ist(char c)
{ return c == '\n' || c == '\t' || c == ' ' || c == '\0'; }

int main()
{ int n; 
	cin >> n;
	for(int i = 0; i < n; ++i) {
		char k; cin >> k; k -= 'A';
		cin >> row[k]; cin >> col[k];
	}
	string s;
	getline(cin, s);
	while (getline(cin, s)) {
		if (s=="" || s=="\n") break;
		const char *p = s.c_str();
		stack<char> stk;
		memset(&(row[26]), 0, (200-26)*sizeof(int));
		memset(&(col[26]), 0, (200-26)*sizeof(int));
		bool can = 1;
		long result = 0;
		while (!ist(*p)) {
			if (ismatrix(p[0])) {
				stk.push(p[0]);
			} else if (p[0] == ')') {
				char b = stk.top() - 'A'; stk.pop();
				char a = stk.top() - 'A'; stk.pop();
				if (col[a] != row[b]) { can = 0; break; }
				result += row[a] * col[a] * col[b];
				++REG;
				row[REG] = row[a]; col[REG] = col[b];
				stk.push(REG+'A');
			}
			++p;
		}
		if (!stk.empty() && stk.size() > 1) {
			char b = stk.top() - 'A'; stk.pop();
			char a = stk.top() - 'A'; stk.pop();
			if (col[a] != row[b]) { can = 0; break; }
			result += row[a] * col[a] * col[b];
			row[REG] = row[a]; col[REG] = col[b];
		}
		if (!can) printf("error\n");
		else { 
			printf("%ld\n", result);
		}
	}
	return 0;
}


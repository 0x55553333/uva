#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <list>
using namespace std;

int main()
{ string txt;
	while (cin >> txt) {
		list<char> btxt;
		list<char>::iterator ptr = btxt.begin();
		for(char c : txt) {
			if (c == '[') {
				ptr = btxt.begin();
			} else if (c == ']') {
				ptr = btxt.end();
			} else {
				btxt.insert(ptr, c);
			}
		}
		for(char& c : btxt) cout << c;
		cout << "\n";
	}
	return 0;
}

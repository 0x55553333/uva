#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;

int main()
{ int n;
	cin >> n;
	string* names = new string[n];
	string song[16] = { 
		"Happy", "birthday", "to", "you", "Happy", "birthday", "to", "you", "Happy", "birthday", "to", "Rujia", "Happy", "birthday", "to", "you" };
	for(int i = 0; i < n; ++i) cin >> names[i];
	int p = 0;
	for(int i = 0; i < n; ++i, ++p, p %= 16) {
		cout << names[i] << ": " << song[p] << endl;
	}
	int i = 0;
	while (p < 16) {
		cout << names[i] << ": " << song[p] << endl;
		++p; ++i; i %= n;
	}
	return 0;
}

#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int cps[56] = {2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, 97,
	113, 131, 197, 199, 311, 337, 373, 719, 733, 919, 971, 991,
	1193, 1931, 3119, 3779, 7793, 7937, 9311, 9377, 11939, 19391,
	19937, 37199, 39119, 71993, 91193, 93719, 93911, 99371, 193939,
	199933, 319993, 331999, 391939, 393919, 919393, 933199, 939193, 
	939391, 993319, 999331, 999999}; /* last element filled in */

int count(int x, int y)
{
	int L = 0, R = 55, M, lo, hi;
	while (L < R) { // lower bound
		M = L + (R-L) / 2;
		if (cps[M] >= x) R = M; 
		else { L = M + 1; }
	}
	lo = L; L = 0; R = 55;
	while (L < R) { // upper bound
		M = L + (R-L) / 2;
		if (cps[M] <= y) L = M + 1;
		else R = M;
	}
	hi = L;
	return hi-lo;
}

int main()
{
	int L, R;
	while (cin >> L) {
		if (L == -1) break;
		cin >> R;
		int rt = count(L, R);
		if (rt == 1) cout << "1 Circular Prime.\n";
		else if (rt <= 0) cout << "No Circular Primes.\n";
		else cout << rt << " Circular Primes." << endl;
	}
	return 0;
}


#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <memory.h>
#include <ctime>
using namespace std;
// O(2^(n/2)) subset sum for large numbers
// due to Horowitz and Sahni
uint64_t S[40], t;
vector<uint64_t> L, R;

// O(n)
void init()
{
	for(int i = 0; i < 40; ++i) {
		S[i] = rand() % 2000; 
		t += S[i];
	}
	t /= 2;
}

// O(2^(n/2) *2)
void generate()
{
	for(int i = 0, pl=0, pr=0; i <= (1<<20); ++i, pl=pr=0) {
		for(int j = 0; j < 20; ++j) 
			if (i>>j&1) {
				pl += S[j]; pr+=S[j+20];
			}
		L.push_back(pl); R.push_back(pr);
	}
}

int subset_sum()
{
	for(uint64_t i = 0; i < L.size(); ++i) { // 2^(n/2)
		if (binary_search(R.begin(), R.end(), t-L[i])) return 1; // log(2^n/2)=n/2
	}
	return 0;
}

int main()
{ srand(time(NULL));
	init(); generate(); // O(n) 
	sort(L.begin(), L.end()); // 2^(n/2) * log(2^(n/2)) = n*2^(n/2)/2
	sort(R.begin(), R.end()); // same as above
	printf("result: %d\n", subset_sum()); // overall: n*2^(n/2)
	// roughly 41,943,040 4*10^8 ops
	return 0;
}



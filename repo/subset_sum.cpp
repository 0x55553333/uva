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
void init()
{ for(int i = 0; i < 40; ++i) S[i] = rand() % 2000; t = rand() % 6000; }

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
	for(uint64_t i = 0; i < L.size(); ++i) {
		if (binary_search(R.begin(), R.end(), t-L[i])) return 1;
	}
	return 0;
}

int main()
{ srand(time(NULL));
	init(); generate();
	sort(L.begin(), L.end());
	sort(R.begin(), R.end());
	printf("result: %d\n", subset_sum());
	return 0;
}


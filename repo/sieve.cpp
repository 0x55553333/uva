#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int sieve(int n, int* primes)
{
	int p = 0;
	primes[p++] = 2;
	primes[p++] = 3;
	primes[p++] = 5;
	for(int i = 6; i < n; ++i) {
		for(int j = 0; j < p; ++j)
			if (i % primes[j] == 0) goto not_prime;
		primes[p++] = i;
		not_prime: continue;
	}
	return p;
}

void print(int p, int* primes)
{ int k = 0;
	switch (p%5) {
		do {
	case 0: printf("%d, ", primes[k++]);
	case 1: printf("%d, ", primes[k++]);
	case 2: printf("%d, ", primes[k++]);
	case 3: printf("%d, ", primes[k++]);
	case 4: printf("%d,\n", primes[k++]);
		} while (k < p);
	};
}

int main()
{
	int n, *ps;
	cin >> n;
	ps = new int[n];
	int p = sieve(n, ps);
	printf("int PRIMES[%d]={", p);
	print(p, ps);
	printf("};\n");
	delete[] ps;
	return 0;
}

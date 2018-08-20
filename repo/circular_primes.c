#include "primes.h"
#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include <string.h>
void reverse(char s[])
{ int i, j;
	char c;
	for (i = 0, j = strlen(s)-1; i<j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

void itoa(int n, char s[], int useless)
{
 int i, sign;
 if ((sign = n) < 0)
	n = -n;
 i = 0;
 do { 
 	s[i++] = n % 10 + '0'; 
 } while ((n /= 10) > 0); 
 if (sign < 0)
 	s[i++] = '-';
 s[i] = '\0';
 reverse(s);
}

char b[32];
int is_circular(int m, int* dual)
{
	itoa(m, b, 10);
	size_t k = strlen(b), i, j;
	printf("Checking %d - ", m);
	for(i = 0; i < k; ++i) {
		char s = b[0];
		for(j = 1; j < k; ++j)
			b[j-1]=b[j];
		b[k-1] = s;
		int t = atoi(b);
		printf(" %d ", t);
		if (t > 1050000) {
			printf("AHHHH - t=%d, m=%d\n", t, m);
		}
		if (dual[t] == -1) {
			memset(b, 0, 32);
			printf("(is not prime)\n");
			return 0;
		}
	}
	printf("(is prime) \n");
	memset(b,0,32);
	return 1;
}

void print_circular(int* circular, int k)
{ int i;
	for(i = 0; i < k; ++i) {
		printf("%d, ", circular[i]);
	}
	printf("\n");
}

int main()
{
	int i, n = sizeof(PRIMES)/sizeof(int), k=0;
	int *dp = malloc(sizeof(int) * 1050000), *circular = malloc(sizeof(PRIMES));
	for(int i = 0; i < 1050000; ++i)
		dp[i] = -1;
	for(i = 0; i < n; ++i) 
		dp[PRIMES[i]] = i;
	for(i = 0; i < n; ++i) {
		if (PRIMES[i] >= 1000000) break;
		if (is_circular(PRIMES[i], dp)) {
			circular[k++] = PRIMES[i];
			printf("k=%d\n", k);
		}
	}	
	printf("checking complete, printing circular...\n");
	print_circular(circular, k);
	free(circular); free(dp);
	return 0;
}


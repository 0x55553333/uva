// UVa 120
// Correct-by-construction 1

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <algorithm>
#include <utility>
#include <memory.h>
#include <cstring>
using namespace std;

void print_state(unsigned *P, unsigned *PP, unsigned *PS, unsigned s, unsigned m)
{ for(unsigned i =0; i < s; ++i) printf("P[%u]=%u\t",i,P[i]);
	printf("\n");
	for(unsigned i =0; i < s; ++i) printf("S[%u]=%u\t",i,PS[i]);
	printf("\n");
	for(unsigned i =0; i < m; ++i) printf("PP[%u]=%u\t",i,PP[i]);
	printf("\n");
}

void dual_reverse(unsigned *Pstart, unsigned *Pend, unsigned *PP)
{ while ((Pstart != Pend)&&(Pstart != --Pend)) {
		unsigned d = PP[*Pstart]; PP[*Pstart] = PP[*Pend]; PP[*Pend] = d;
		unsigned t = *Pstart; *Pstart = *Pend; *Pend = t;
		++Pstart;
	}
}

void solve(unsigned* P, unsigned s)
{ unsigned m=0,*PP,*PS;
	for(unsigned i = 0; i < s; ++i) m = max(m,P[i]); ++m;
	PP = new unsigned[m];
	PS = new unsigned[s];
	memcpy(PS,P,s*sizeof(unsigned));
	memset(PP,0,m*sizeof(unsigned));
	for(unsigned i = 0; i < s; ++i) PP[P[i]] = i;
	sort(PS,PS+s,[](const int& a, const int& b) { return a>=b; });
	for(unsigned i = 0; i < s; ++i) {
		if (PS[i]!=P[i]) {
			/*
				If we want an optimal solution
				Uncomment the if statements.
				The if statements avoid vacuous steps but
				according to the problem, both are mutually
				acceptable (uDebug version is with ifs).
				 */
			//if (PP[PS[i]]+1!=s) {
				printf("%u ", PP[PS[i]]+1);
				dual_reverse(P + PP[PS[i]], P + s, PP); 
			//}
			//if (i+1!=s) {
				printf("%u ",i+1);
				dual_reverse(P + i, P + s, PP);
			//}
		}
	}
}

int main()
{
	unsigned P[30],k;
	char buf[300];
	memset(buf,0,300);
	while (gets(buf)!=NULL) {
		unsigned s = 0;
		char *p = strtok(buf," ");
		if(p==NULL) { exit(0); }
		while (p != NULL) {
			P[s++] = (unsigned)atoi(p);
			p= strtok(NULL," ");
		}
		for(unsigned i =0; i < s-1; ++i)
			printf("%d ", P[i]);
		printf("%d\n",P[s-1]);
		if (s==0) return 0;
		reverse(P,P+s);
		solve(P,s);
		printf("0\n");
	}
	return 0;
}

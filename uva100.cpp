#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define odd(i) (i&1)

inline static unsigned N(unsigned i)
{ unsigned cnt=1;
	while (i!=1) {
		if (odd(i)) i = 3*i+1;
		else i /= 2;
		++cnt;
	}
//	printf("cnt(%u)=%u\n",cnt,i);
	return cnt;
}

int main()
{ char b[60], *buf=b;
	unsigned i,j,r;
	while(cin>>i>>j) {
//		i=j=0;
//		sscanf(buf, "%u %u", &i,&j);
		//		printf("_i=%u,_j=%u\n",i,j);
		if(i<=0||j<=0) break;
		unsigned L = min(i,j), R = max(i,j);
		r=0;
		for(unsigned k = L; k <= R; ++k)
			r = max(r, N(k));
		cout << i << " " << j << " " << r << "\n";
	}
	return 0;
}

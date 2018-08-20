#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cassert>
#include <memory.h>
#define MAXSIZE 5001
using namespace std;

struct entry {
	unsigned first;
	unsigned second;
	unsigned area;
	unsigned id;
};

void entrysort(vector<entry>& V)
{
	sort(V.begin(), V.end(), [](const entry& a, const entry& b) { 
		return a.second < b.second;
	});
}

bool search(unsigned N, vector<entry>& V, unsigned* SV, unsigned *S)
{ for(unsigned i = 0; i < V.size(); ++i) {
		unsigned& vL = V[i].first;
		unsigned& vR = V[i].second;
		unsigned& id = V[i].id;
		unsigned j;
		for(j = vL; j <= vR; ++j) {
			if (SV[j] == 0) {
				SV[j] = id;
				break;
			}
		}
		if (j > N || j > vR || SV[j] != id) 
			return false;
		S[id] = j;
	}
	return true;
}

int main()
{ unsigned N;
	while (cin>>N) {
		if (N==0) break;
		vector<entry> X, Y;
		unsigned SX[5001], SY[5001], SL[5001], SR[5001];
		memset(SX, 0, 5001*sizeof(unsigned));
		memset(SY, 0, 5001*sizeof(unsigned));
		memset(SL, 0, 5001*sizeof(unsigned));
		memset(SR, 0, 5001*sizeof(unsigned));
		for(unsigned i = 0; i < N; ++i) {
			entry xp, yp;
			cin >> xp.first >> yp.first >> xp.second >> yp.second; // xl,yl,xr,yr
			xp.id = yp.id = i+1;
			xp.area = xp.second - xp.first;
			yp.area = yp.second - yp.first;
			X.push_back(xp); Y.push_back(yp);
		}
		// sort
		entrysort(X); entrysort(Y);
		// search
		if (!search(N, X, SX, SL)) {
			printf("IMPOSSIBLE \n");
			goto impj;
		}
		if (!search(N, Y, SY, SR)) {
			printf("IMPOSSIBLE \n");
			goto impj;
		}
		// output solution
		for(unsigned i = 1; i <= N; ++i) { // IDs are 1-indexed
			cout << SL[i] << " " << SR[i] << endl;
		}
impj:; // impossible; skip
	}
	return 0;
}

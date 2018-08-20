#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;
typedef long long ll;
int main()
{	int N;
	while (cin>>N) {
		if (N<2||N>100000) break;
		ll transfer = 0, accum = 0, village = 0;
		for(int i = 0; i < N; ++i) {
			cin >> village;
			transfer += abs(accum);
			accum += village;
		}
		cout << transfer << endl;
	}
	return 0;
}

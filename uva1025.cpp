#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <utility>
#include <memory.h>
using namespace std;
int D[51], t1[51], tN[51], N, T, M1, M2, m[51][1000], in[51][1000][2];
int k = 0;
int opt(int i, int t);
int _opt(int i, int t)
{
	int ans = opt(i, t+1) + 1;
	if (in[i][t][0])
		ans = min(ans, opt(i-1, t+D[i-1]));
	if (in[i][t][1]) {
		ans = min(ans, opt(i+1, t+D[i]));
	}
	return ans;
}
int opt(int i, int t)
{ //printf("opt=%d,%d\n",i,t); 
	if (t == T) {
		if (i == N) return 0;
		else return 0xfffff;
	} else if (t >= T) return 0xfffff;
	if (i < 1 || i > N) {
		//		printf("AHHHHHH\n"); exit(1);
		return 0xffffff;
	}
	if (m[i][t] != -1) return m[i][t];
	else return m[i][t]=_opt(i, t);
}

int main()
{ int c = 1;
	while (cin >> N >> T) {
		if (N < 2 || N > 50) break;
		memset(D, 0, sizeof(D)); memset(in, 0, sizeof(in));
		memset(t1, 0, sizeof(t1)); memset(tN, 0, sizeof(tN));
		for(int i = 1; i < N; ++i) cin >> D[i];
		cin >> M1;
		for(int i = 0; i < M1; ++i) cin >> t1[i];
		cin >> M2;
		for(int i = 0; i < M2; ++i) cin >> tN[i];
		for(int i = 0, t = t1[0]; i < M1; ++i, t = t1[i]) {
			for(int j = 1; j < N; t += D[j], ++j) {
				in[j][t][1] = 1; // left to right trains
			}
		}
		for(int i = 0, t = tN[0]; i < M2; ++i, t = tN[i])
			for(int j = N; j > 1; --j, t += D[j]) {
				in[j][t][0] = 1; // right to left trains
			}
		for(int i = 0; i < 51; ++i)
			for(int j = 0; j < 1000; ++j)
				m[i][j] = -1;
		int ans = opt(1, 0);
		cout << "Case Number " << c;
		if (ans > T) cout << ": impossible\n";
		else cout << ": " << ans << "\n";
		++c;
	}
	return 0;
}


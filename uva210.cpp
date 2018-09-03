#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <memory.h>
#include <deque>
using namespace std;

int reg[26], locked;

int main()
{ int T;
	cin >> T;
	while (T--) {
		int n, q_assign, q_output, q_lock, q_unlock, q_end, q, k = 1;
		cin >> n >> q_assign >> q_output >> q_lock >> q_unlock >> q_end >> q;
		vector<string> ps[n+1];
		vector<int> p_states[n+1], Q[n+1];	
		deque<int> p, s;
		do {
			string in = "";
			while (in != "end") {
				cin >> in; ps[k].push_back(in);
			}
			p.push_back(k);
			p_states.push_back(0); Q.push_back(q);
		} while (++k < n);
		while (!p.empty()) {
			int curr = p.top(), line = p; p.pop_front();
			switch (ps[curr][]
		}
	}
	return 0;
}

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <utility>
#include <memory.h>
#include <string>
#include <cstring>
#include <deque>
#include <sstream>
using namespace std;

bool atomic_lock = 0;
enum ptype {
	Assign, Print, Lock, Unlock, End, None
};
struct payload {
	string a;
	int b;
};
struct program {
	vector< pair<ptype, payload> > data;
	int ID;
	int status;
	int pc;
};
int cost[5];
int table[26];
deque<program> sr, sw;

int main()
{ int C, N, Q;
	cin >> C;
	for(int c = 0; c < C; ++c) {
		cin >> N;
		cin >> cost[0] >> cost[1]
			>> cost[2] >> cost[3] 
			>> cost[4] >> Q;
		for(int i = 0; i < N; ++i) {
			string l; program P; 
			P.pc = 0; P.ID = i + 1; P.status = 0;
			while (getline(cin, l)) {
				string t;
				istringstream is(l);
				pair<ptype, payload> tp;
				tp.first = None; tp.second.a = ""; tp.second.b = -1;
				while (getline(is, t, ' ')) {
					if (t == "print") {
						tp.first = Print;
						continue;
					} else if (t == "lock") {
						tp.first = Lock; P.data.push_back(tp);
						break;
					} else if (t == "unlock") {
						tp.first = Unlock; P.data.push_back(tp); 
						break;
					} else if (t == "end") {
						tp.first = End; P.data.push_back(tp);
						break;
					} else if (t == "=") {
						continue;
					} else if (isalpha(t[0])) {
						if (tp.first == Print) {
							tp.second.a = t; P.data.push_back(tp);
							break;
						}
						tp.first = Assign;
						tp.second.a = t;
						continue;
					} else {
						tp.second.b = strtoul(t.c_str(), NULL, 10);
						P.data.push_back(tp);
						break;
					}
				}
				if (tp.first == End) break;
			}
end: sr.push_back(P);
		}
		while (!sr.empty()) {
			program curr = sr.front(); sr.pop_front();
			int total = Q; bool finished = 0; bool lck = 0, unlck = 0;
			while (total >= 0 && curr.pc < curr.data.size()) {
				pair<ptype, payload>& line = curr.data[curr.pc++];
				switch (line.first) {
					case Assign: 
						if (total - cost[0] < 0) {
							--curr.pc; goto p_end; }
						table[line.second.a[0] - 'a'] = line.second.b; total -= cost[0]; 
						break;
					case Print: 
						if (total - cost[1] < 0) {
							--curr.pc; goto p_end; }
						cout << curr.ID << ": " << table[line.second.a[0] - 'a'] << endl; total -= cost[1]; 
						break;
					case Lock:  
						if (total - cost[2] < 0) {
							--curr.pc; goto p_end; }
						if (atomic_lock) {
							--curr.pc; lck = 1; goto p_end;
						}
						total -= cost[2]; atomic_lock = 1; break;
					case Unlock: 
						if (total - cost[3] < 0) { 
							--curr.pc; goto p_end; }
						total -= cost[3]; unlck = 1; atomic_lock = 0; break;
					case End: 
						if (total - cost[4] < 0) {
							--curr.pc; goto p_end; }
						finished = 1; goto p_end; break;
					default: cout << "What?!" << endl; exit(1);
				}
			} 
p_end:;
			if (curr.pc == curr.data.size()) finished = 1;
			if (unlck && !sw.empty()) {
				sr.push_front(sw.front()); sw.pop_front();
			}
			if (!finished) {
				if (lck) sw.push_back(curr);
				else sr.push_back(curr);
			} 
		}
	}
	return 0;
}


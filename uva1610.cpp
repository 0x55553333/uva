#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string out;
unsigned outSize=0xffff;
bool fin = 0;
void generate(string& x, string& L, string& R)
{ if (fin) return;
	if (x.size() <= L.size() && x >= L && x < R && x.size() < outSize) {
		//cout << "generate: Finished, " << x << endl;
		//cout << ":" << x << endl;
		cout << x << endl;
		outSize = x.size();
		fin=1;
		return;
	}
	if (x.size() > L.size() || x >= R) return;
	//cout << x << endl;
	if (x < R) {
		if (x[x.size()-1]<'Z') {
			++x[x.size()-1];
			generate(x,L,R);
			--x[x.size()-1];
		} 
		x += 'A';
		generate(x,L,R);
		x.pop_back();
	} 
}

int main()
{ unsigned d;
	while (scanf("%u", &d)) {
		vector<string> names;
		if (d==0)return 0;
		
		for(unsigned i = 0; i < d; ++i) {
			string x;
			cin >> x;
			names.push_back(x);
		}
		sort(names.begin(), names.end(), [](const string& a, const string& b) {
					unsigned i=0,j=0;
					while (a[i]==b[j]) {
						if(i==a.size()) return 1;
						if(j==b.size()) return 0;
						++i,++j;
					}
					return (int)(a[i]<b[j]);
				});
		string L = names[(names.size()-1)/2];
		string R = names[(names.size()-1)/2+1];
//		cout << "L:"<< L << endl;
//		cout << "R:" << R << endl;
		string x="A";
		generate(x,L,R);
		fin=0;
		outSize=0xffff;
		out="";
	}

	return 0;
}

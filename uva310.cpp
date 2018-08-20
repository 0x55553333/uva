#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <map>
#include <unordered_set>
#include <memory.h>
using namespace std;

int main()
{ string u, v, o, z;
  while (!cin.eof()) {
    getline(cin, u);
    if (cin.eof()) break;
    getline(cin, v); getline(cin, o); getline(cin, z);
    if (u == "" || v == "") break;
    queue<string> q;
    unordered_set<string> visited;
    bool found = 0;
    long sz = z.size();
    for(long i = 0; i < o.size(); ++i) {
      string k = o.substr(i, sz);
      q.push(k); visited.insert(k);
    }
    while (!q.empty()) {
      string curr = q.front(); q.pop();
      string a, b, c;
      if (curr == z) {
        found = 1; break;
      }
      for(const char& ch : curr)
        switch (ch) {
          case 'a': c += u; break;
          case 'b': c += v; break;
        }
      for(long i = 0; i < c.size(); ++i) {
        string k = c.substr(i, sz);
        if (visited.find(k) == visited.end())
          q.push(k); visited.insert(k);
      } 
    }
    if (found) printf("YES\n");
    else printf("NO\n");
  }
  return 0;
}

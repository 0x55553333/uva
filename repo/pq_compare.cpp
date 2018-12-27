#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <utility>
#include <memory.h>
#include <queue>
using namespace std;
bool Comp1(const int& a, const int& b) {return a>b;}
bool Comp2(const int& a, const int& b) {return a<b;} 
int main()
{
  priority_queue<int> Q;
  priority_queue<int, vector<int>, decltype(&Comp1)> Q1(Comp1);
  priority_queue<int, vector<int>, decltype(&Comp2)> Q2(Comp2);
  for(int i = 1; i <= 3; ++i) {
    Q.push(int(i)); 
    Q1.push(int(i)); 
    Q2.push(int(i));
  }
  cout << "Q:" ;
  while(Q.size()!=0) { cout << Q.top(); Q.pop(); }
  cout << endl << "Q1:";
  while(Q1.size()!=0) { cout << Q1.top(); Q1.pop(); }
  cout << endl << "Q2:";
  while(Q2.size()!=0) { cout << Q2.top(); Q2.pop(); }
  cout << "done" << endl;
  return 0;
}


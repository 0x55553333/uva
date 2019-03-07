// k-way in-place in-shuffle (a Riffle shuffle)
// in O(kN)-time
// uses kN+1 swaps
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <memory.h>
using namespace std;
typedef pair<int, int> Item;
string indent = "";
vector< vector<int> > pos;
vector<Item> A;
int N, k;

void print_shuffle()
{
  cout << indent;
  for(int i = 1; i <A.size(); ++i ){
    printf("%d_%d ", A[i].first, A[i].second);
  }
  printf("\n");
}

void in_shuffle(Item e, int i)
{ //printf("shuffle(%d,%d):", e.first, e.second);
  if (i == A.size()) {
    print_shuffle(); return;
  }
  int tidx = pos[e.first][e.second]; 
  Item te = A[i], e1;
  A[i] = A[tidx];
  A[tidx] = te;
  pos[e.first][e.second] = i;
  pos[te.first][te.second] = tidx;
  print_shuffle();
  e1.first = e.first > 1 ? e.first - 1 : k;
  e1.second = e.first > 1 ? e.second : e.second + 1;
  indent += " ";
  in_shuffle(e1, i + 1);
  indent.pop_back();
}

int main()
{
  cin >> N >> k;
  pos.assign(k + 1, vector<int>());
  for(int i = 1; i <= k; ++i) pos[i].push_back(0);
  A.push_back(make_pair(0, 0));
  for(int i = 1; i <= k; ++i) {
    for(int j = 1; j <= N; ++j) {
      A.push_back(make_pair(i, j));
      pos[i].push_back(A.size()-1);
    }
  }
  print_shuffle();
  indent += " ";
  in_shuffle(make_pair(k,1), 1);
  return 0;
}


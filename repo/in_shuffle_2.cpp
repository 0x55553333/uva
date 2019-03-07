// 2-way in-shuffle
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <memory.h>
using namespace std;
typedef pair<char, int> Item;
string indent = "";
vector<int> apos, bpos;
vector<Item> A;
int N;

void print_shuffle()
{
  cout << indent;
  for(int i = 1; i <A.size(); ++i ){
    printf(" %c%d ", A[i].first, A[i].second);
  }
  printf("\n");
}

void two_way_in_shuffle(Item e, int i)
{ //printf("shuffle(%c,%d):", e.first, e.second);
  if (i == 2 * N || A[i] == e) {
    print_shuffle(); return;
  }
  int t, tidx; Item te, e1;
  
  if (e.first == 'a') {
    te = A[i];
    tidx = apos[e.second];
    apos[e.second] = i;
    if (te.first=='a') apos[te.second] = tidx;
    else bpos[te.second] = tidx;
    A[i] = A[tidx];
    A[tidx] = te;
  } else {
    te = A[i];
    tidx = bpos[e.second];
    bpos[e.second] = i;
    if (te.first=='a') apos[te.second] = tidx;
    else bpos[te.second] = tidx;
    A[i] = A[tidx];
    A[tidx] = te;
  }
  print_shuffle();
  e1.first = e.first == 'a' ? 'b' : 'a';
  e1.second = e.first == 'b' ? e.second : e.second + 1;
  indent += " ";
  two_way_in_shuffle(e1, i + 1);
  indent.pop_back();
}

int main()
{
  cin >> N;
  apos.push_back(0); bpos.push_back(0);
  A.push_back(make_pair('z', 0));
  for(int i = 1; i <= N; ++i) {
    A.push_back(make_pair('a', i));
    apos.push_back(A.size()-1);
  }
  for(int i = 1; i <= N; ++i) {
    A.push_back(make_pair('b', i));
    bpos.push_back(A.size()-1);
  }
  print_shuffle();
  indent += " ";
  two_way_in_shuffle(make_pair('b',1), 1);
  return 0;
}


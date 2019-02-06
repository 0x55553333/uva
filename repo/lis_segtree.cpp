#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <utility>
#include <vector>
#include <memory.h>
using namespace std;

struct tree {
  vector<int> RMQ;
  int N;

  void build(int p, int l, int r, int idx, int val)
  {
    if (idx < l || idx > r) return;
    if (l == r) {
      RMQ[p] = val;
      return;
    }
    build(2*p+1, l, l+(r-l)/2, idx, val);
    build(2*p+2, l+(r-l)/2+1, r, idx, val);
    RMQ[p] = max(RMQ[2*p+1], RMQ[2*p+2]);
  }
  
  int range_maximum(int p, int l, int r, int L, int R)
  {
    if (L > r || R < l) return 0;
    if (r <= R && l >= L) return RMQ[p];
    return max(
        range_maximum(2*p+1, l, l+(r-l)/2, L, R),
        range_maximum(2*p+2, l+(r-l)/2+1, r, L, R));
  }

  void build(int idx, int val)
  { build(0, 0, this->N - 1, idx, val); }

  int range_maximum(int L, int R)
  { return range_maximum(0, 0, this->N - 1, L, R); }

  tree(int n) {
    RMQ.assign(n*4, 0); 
    this->N = n;
  }
};

int LIS(vector<int>& A) 
{
  vector<pair<int,int> > sorted;
  tree tau(A.size()+1);
  for(int i = 0; i < A.size(); ++i) sorted.push_back(make_pair(A[i], i));
  printf("sorting\n");
  sort(sorted.begin(), sorted.end());
  for(int i = 0; i < A.size(); ++i) {
    printf("LIS before %d = ", i);
    int liss = tau.range_maximum(0, sorted[i].second);
    printf("%d\n", liss);
    tau.build(sorted[i].second, liss + 1);
  }
  return tau.range_maximum(0, A.size()-1);
}

int main()
{

  int N; vector<int> arr;
  while (1) {
    cin >> N; for(int i=0; i <N; ++i){int k; cin>> k;
    arr.push_back(k);}
    cout << LIS(arr) << endl;
  }
  return 0;
}


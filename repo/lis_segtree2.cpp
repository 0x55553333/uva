// for longest strictly increasing subsequence
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <utility>
#include <vector>
#include <memory.h>
using namespace std;
int compare(pair<int, int> p1, pair<int, int> p2)
{
     /* For same values, element with the higher
        index appear earlier in the sorted array.
        This is for strictly increasing subsequence.
        For increasing subsequence, the lower index
         appears earlier in the sorted array. */
    if (p1.first == p2.first)
        return p1.second > p2.second;

    // Sorting the array according to their values.
    return p1.first < p2.first;
}

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
  sort(sorted.begin(), sorted.end(), compare);
  for(int i = 0; i < A.size(); ++i) {
    int liss = tau.range_maximum(0, sorted[i].second);
    tau.build(sorted[i].second, liss + 1);
  }
  return tau.range_maximum(0, A.size()-1);
}


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        return LIS(nums);
    }
};


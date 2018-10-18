#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <utility>
#include <memory.h>
using namespace std;

template <typename T>
struct segtree_min {
  vector<long> tree;
  vector<T> content;
  /* segment tree for range minimum query */
  long lch(long i) { return (i<<1)+1; }
  long rch(long i) { return (i<<1)+2; }

  void build(long p, long l, long r) 
  {
    if (l == r) {
      //printf("(%d, %d, %d):=%d\n", l, r, p, l);
      tree[p] = l;
      return;
    }
    build(lch(p), l, l+(r-l)/2);
    build(rch(p), l+(r-l)/2+1, r);
    if (content[tree[lch(p)]] <= content[tree[rch(p)]])
      tree[p] = tree[lch(p)];
    else
      tree[p] = tree[rch(p)];
    //printf("(%d, %d, %d):=%d; lch=%d, rch=%d\n", l, r, p, tree[p], content[tree[lch(p)]], content[tree[rch(p)]]);
  }

  void update(long p, long l, long r, long idx, long val)
  {
    if (l == r) {
      content[idx] = val;
      return;
    }
    if (l <= idx && idx <= l + (r-l)/2)
      update(lch(p), l, l+(r-l)/2, idx, val);
    else if (l+(r-l)/2<idx && idx <= r)
      update(rch(p), l+(r-l)/2, idx, val);
    else return;
    if (content[tree[lch(p)] <= content[tree[rch(p)]]])
      tree[p] = tree[lch(p)];
    else
      tree[p] = tree[rch(p)];
  }

  void update(long idx, long val)
  {
    if (idx >= content.size() || idx < 0) return;
    return this->update(0, 0, content.size()-1, idx, val);
  }

  long query(long p, long l, long r, long i, long j)
  {
    if (i>r || j<l) return -1;
    if (l>=i && r<=j) return this->tree[p];
    long p1 = query(lch(p), l, l+(r-l)/2, i, j),
        p2 = query(rch(p), l+(r-l)/2+1, r, i, j);
    if (p1 == -1) return p2;
    if (p2 == -1) return p1;
    return content[p1]<=content[p2]?p1:p2;
  }

  long query(long i, long j)
  { return this->query(0, 0, this->content.size()-1, i, j); }

  T min(long i, long j)
  { return this->content[this->query(i, j)]; }
  
  long argmin(long i, long j)
  { return query(i, j); }

  segtree_min(vector<T>& in) 
  {
    this->content = in;
    this->tree.assign(4*in.size(), 0); 
    build(0, 0, in.size()-1);
  }

};

int main()
{
  long arr[] = { 18, 17, 13, 19, 15, 11, 20 };//11
  vector<long> A(arr, arr + 7);
  segtree_min<long> st(A);
  printf("RMQ(1, 3) = %ld\n", st.argmin(1, 3));
  printf("RMQ(4, 6) = %ld\n", st.argmin(4, 6));
  return 0;
}


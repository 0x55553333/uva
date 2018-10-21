#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <memory.h>
using namespace std;
template <typename T>
struct binary_indexed_tree {
  vector<T> tree;
  /* notice: BIT uses 1-based indexing */
  T identity;
  
  size_t p(size_t x)
  { return x & -x; }

  T sum(size_t idx)
  {
    T s = this->identity;
    while (idx >= 1) {
      s += tree[idx];
      idx -= p(idx);
    }
    return s;
  }

  void inc(size_t idx, T val)
  {
    while (idx < tree.size()) {
      tree[idx] += val;
      idx += p(idx);
    }
  }

  void dec(size_t idx, T val)
  {
    return this->inc(idx, -val);
  }

  binary_indexed_tree(size_t n, T identity)
  {
    this->tree.assign(n+1, 0);
    this->identity = identity;
  }
};

int main()
{
  int arr[] = { 0, 1, 3, 4, 8, 6, 1, 4, 2 };
  binary_indexed_tree<int> bit(9, 0);
  for(int i = 1; i <= 8; ++i)
    bit.inc(i, arr[i]);
  for(int i = 1; i <= 8; ++i)
    printf("[%d]: %d\n", i, bit.tree[i]);
  for(int i = 1; i <= 8; ++i)
    printf("b(%d, %d):=%d\n", i, i-1, bit.sum(i)-bit.sum(i-1));
  return 0;
}


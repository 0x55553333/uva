#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <utility>
#include <memory.h>
using namespace std;
template <typename T>
class sum_seg_tree {
public:
    
    vector<T> tree;
    vector<T> content;
    T null_element;

    sum_seg_tree(vector<T> nums, T null_element_val) 
    {
        this->content = nums;
        this->tree.assign(4 * content.size(), null_element_val);
        this->null_element = null_element_val;
        if (this->content.size() != 0)
            build(0, 0, content.size() - 1);
    }
    
    void update(long i, T val) 
    {
        return update(0, 0, content.size()-1, i, val);
    }
    
    T sum(long i, long j) 
    {
        return sum(0, 0, content.size()-1, i, j);
    }
    
private:
    
    long lch(long i) { return (i<<1) + 1; }
    long rch(long i) { return (i<<1) + 2; }
    
    void update(long p, long l, long r, long idx, T val)
    {
        if (l == r) {
            this->tree[p] = val;
            return;
        }
        if (l <= idx && idx <= l + (r-l)/2)
            update(lch(p), l, l + (r-l)/2, idx, val);
        else if (l + (r-l)/2 < idx && idx <= r)
            update(rch(p), l + (r-l)/2+1, r, idx, val);
        else
            return;
        tree[p] = tree[lch(p)] + tree[rch(p)];
    }
    
    T sum(long p, long l, long r, long i, long j)
    {
        if (i > r || j < l) return this->null_element;
        if (l >= i && r <= j) return this->tree[p];
        T l_sum = sum(lch(p), l, l + (r-l)/2, i, j), 
            r_sum = sum(rch(p), l + (r-l)/2+1, r, i, j);
        return l_sum + r_sum;
    }
    
    void build(long p, long l, long r)
    {
        if (l == r) {
            tree[p] = content[l];
            return;
        }
        build(lch(p), l, l + (r-l)/2);
        build(rch(p), l + (r-l)/2+1, r);
        tree[p] = tree[lch(p)] + tree[rch(p)];
    }
};

int main()
{
  long arr[] = { 1, 6, -7, 2, 4, 14 };
  vector<long> A(arr, arr + sizeof(arr)/sizeof(long));
  sum_seg_tree<long> stree(A, 0L);
  printf("RSQ(2, 5)=%ld\n", stree.sum(2, 5));
  printf("RSQ(1, 3=%ld\n", stree.sum(1, 3));
  return 0;
}


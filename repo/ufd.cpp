#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;
// union-find-disjoint set

struct disjoint_set
{ vector<long> parent; vector<int> rank;
  long find(long i) // Find a parent of a set
  { if (parent[i] == i) return i;
    else return parent[i] = find(parent[i]);}
  bool eq(long i, long j){return find(i) == find(j);} // Test two parents
  void merge(long i, long j) // Merge two sets
  { long x = find(i), y = find(j);
    if (rank[x] > rank[y]) parent[y] = x;
    else { parent[x] = y;
      if (rank[x] == rank[y]) ++rank[y]; }}
  disjoint_set(long n) // n: size of set
  { this->rank.assign(n, 0); this->parent.assign(n, 0);
    for(long i = 0; i < n; ++i) this->parent[i] = i; }};

int main()
{
	printf("ufd set\n");
	return 0;
}

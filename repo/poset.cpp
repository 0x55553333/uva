#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;
// union-find-disjoint set
// for generic content
// similar to a poset
template <typename T>
struct disjoint_set
{
  vector<T> data;
  vector<long> parent;
  vector<int> rank;
  T identity;
  long find(long i)
  {
    if (parent[i] == i) return i;
    else return parent[i] = find(parent[i]);
  }

  T find_parent(long i)
  {
    long idx = find(i);
    return data[idx];
  }

  T at(long i)
  {
    return data[i];
  }

  bool eq(long i, long j)
  {
    return data[find(i)] == data[find(j)];
  }

  void merge(long i, long j)
  {
    long x = find(i), y = find(j);
    if (rank[x] > rank[y]) parent[y] = x;
    else {
      parent[x] = y;
      if (rank[x] == rank[y]) ++rank[y];
    }
  }

  void assign(long i, T& elem)
  {
    long idx = find(i);
    this->data[idx] = elem;
  }

  disjoint_set(long n, T& identity)
  {
    this->identity = identity;
    this->rank.assign(n, 0);
    this->parent.assign(n, 0);
    this->data.assign(n, identity);
    for(long i = 0; i < n; ++i)
      this->parent[i] = i;
  }
};

int main()
{
	printf("ufd set\n");
	return 0;
}

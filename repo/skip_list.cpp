#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <random>
#include <cmath>
using namespace std;
// an array-based skip list implementation

template <typename T>
struct skip_list
{
  long h, size, begin, end;
  random_device rng;
  mt19937 rng_mt;
  uniform_real_distribution<double> range;
  double p;

  struct entry_t {
    long top, down, left, right;
    entry_t() {
      top = down = left = right = 0;
    }
  };
  vector<T> data;
  vector<entry> nodes;

  long get_level(double prob)
  {
    long l = 0;
    while ( range(rng_mt) < p && l < h) ++l;
    return l;
  }
  
  void insert(T& obj)
  {
     
  }

  skip_list(long h, double p) 
    : rng{}, rng_mt{rng}, range{0.0, 1.0}
  {
    this->p = p;
        
    //for(long i = 1, double pp = p; i < h; ++i, pp *= p)
    //  this->node_count[i] = lround(pp * n) + 1;
  }

};

int main()
{
  return 0;
}

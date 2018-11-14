#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <utility>
#include <memory.h>
#include <bitset>
#include <deque>
#include <map>
using namespace std;
int  M, N, K, T, freq[200], a[3];
static unsigned long long Low, High, lomagic, himagic;
int all()
{ return Low == lomagic && High == himagic; }

void insert(int i)
{
  if (i > K || i < 1) return;
  --i;
  ++freq[i];
  if (i < 64) Low |= (1ULL<<i);
  else {
    i -= 64;
    High |= (1ULL<<i);
  }
}

void extract(int i)
{ 
  if (i > K || i < 1) return;
  --i;
  freq[i] = max(freq[i] - 1, 0);
  if (freq[i] == 0) {
    if (i < 64) Low &= ~(1ULL << i);
    else {
      i -= 64; High &= ~(1ULL << i);
    }
  }
}

void init(int highbit)
{ Low = High = lomagic = himagic = 0;
  memset(freq, 0, sizeof(freq));
  a[2] = 3; a[1] = 2; a[0] = 1;
  if (highbit >= 64) {
    lomagic = ~(0ULL);
    highbit -= 64;
    for(int i = 0; i < highbit; ++i) 
      himagic |= (1ULL<<i);
  } else {
    for(int i = 0; i < highbit; ++i)
      lomagic |= (1ULL<<i);
    himagic = 0ULL;
  }
}

int next(int i, int M)
{
  int k;
  switch (i) {
    case 3: return 3;
    case 2: return 2;
    case 1: return 1;
    default:
      k = (a[2] + a[1] + a[0]) % M + 1;
      a[0] = a[1]; a[1] = a[2]; a[2] = k;
      return k;
  }
}

int main()
{
  cin >> T;
  for(int z = 1; z <= T; ++z) {
    deque<int> window;
    unsigned i = 1, best = ~(0U), t;
    cin >> N >> M >> K;
    memset(freq, 0, sizeof(freq));
    init(K);
    {
      t = next(i, M);
      window.push_front(t);
      insert(t);
    }
    while (window.size() != 0) {
      if (all()) {
        best = min(best, (unsigned) window.size());
        t = window.back();
        extract(t);
        window.pop_back();
      } else if (i <= N) {
        t = next(i, M);
        window.push_front(t);
        insert(t);
        ++i;
      } else {
        break;
      }
    }
    if (best >= ~(0U))
      printf("Case %d: sequence nai\n", z);
    else 
      printf("Case %d: %d\n", z, best);
  }
  return 0;
}


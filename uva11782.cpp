#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <utility>
#include <memory.h>
using namespace std;

int H, K;
vector<int> tree;
int m[1+(1<<20)][30][2];
int dfs(int idx, int d, int k)
{
  if (k == 0) return -0xfffff;
  if (d == H + 1) return -0xfffff;
  if (m[idx][k][1]) return m[idx][k][0];
  int ans = tree[idx];
  for(int i = 0; i <= k; ++i) {
    ans = max(ans, dfs(2*idx+1, d+1, i) +
        dfs(2*idx+2, d+1, k-i));
  }
  if (!m[idx][k][1]) {
    m[idx][k][1] = 1;
    m[idx][k][0] = ans;
  }
  return ans;
}

void read(int idx, int d)
{
  if (d == H + 1) return;
  cin >> tree[idx];
  read(idx*2+1, d + 1); 
  read(idx*2+2, d + 1);
}

int main()
{
  while (cin >> H) {
    memset(m, 0, sizeof(m));
    if (H == -1) break; 
    cin >> K;
    tree.clear(); 
    tree.assign((1<<(H+1)) + 1, 0);
    read(0, 0);
    cout << dfs(0, 0, K) << endl;
  }

  return 0;
}


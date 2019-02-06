// GNU C++ STL policy-based order statistics tree
// using keyword is c++11
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using order_statistics_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename K, typename V>
using order_statistics_map = tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

#include <iostream>
int main()
{
  order_statistics_set<int> s1;
  order_statistics_map<int,int> m;
  for(int i = 0; i < 100; ++i) {
    s1.insert(i);
    m[i] = i*10+1;
  }
  cout << *s1.find_by_order(1) << endl;
  cout << *s1.find_by_order(3) << endl;
  //cout << *m.find_by_order(4) << endl;
  return 0;
}

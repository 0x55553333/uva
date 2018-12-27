#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <utility>
#include <memory.h>
#include <ctime>
using namespace std;

template<typename T>
struct treap {
  struct _Node {
    _Node()
    { this->lch = this->rch = NULL;
      this->rank = rand(); this->size = 1; }
    void maintain()
    {
      printf("maintain: maintaining tree of val:");
      cout << this->val << " ";
      this-> size = 1;
      if (this->rch != NULL)
        this-> size += this->rch->size;
      if (this->lch != NULL)
        this-> size += this->lch->size; 
      cout << this->size << endl;}
    void purge()
    { if (this->rch != NULL) this->rch->purge();
      if (this->lch != NULL) this->lch->purge();
      delete this->rch; delete this->lch; }
    unsigned long size;
    _Node * lch; 
    _Node * rch;
    T val;
    int rank;
  };
  _Node* root;
  treap()
  { srand(time(NULL));
    this->root = NULL; }
  ~treap()
  { if (this->root!=NULL)
    this->root->purge();
    if (this->root!=NULL)
    delete this->root; }
  void rotate_left(_Node*& o)
  { if (o->rch == NULL) return;
    _Node* k = o->rch;
    o->rch = k->lch;
    k->lch = o;
    o = k;
    o->maintain();
    k->maintain(); }
  void rotate_right(_Node*& o)
  { if (o->lch == NULL) return;
    _Node* k = o->lch;
    o->lch = k->rch;
    k->rch = o;
    o = k;
    o->maintain();
    k->maintain(); }
  void insert(_Node*& o, T& x)
  { if (o==NULL) {
      o = new _Node();
      o->val = x;
      o->rank = rand();
    } else {
      if (x < o-> val) {
        insert(o->lch, x);
        if (o->lch->rank > o->rank)
          rotate_right(o);
      } else if (x > o-> val) {
        insert(o->rch, x);
        if (o->rch->rank > o->rank)
          rotate_left(o);
      } else return; // already exists
    }}
  void insert(T x)
  { this->insert(root, x); }
  void remove(_Node*&o, T& x)
  { if (o==NULL)return;
    if (x == o->val) {
      if (o->lch == NULL) o = o->rch;
      else if (o->rch == NULL) o = o->lch;
      else {
        if (o->lch->rank > o->rch->rank) {
          rotate_right(o);
          remove(o->rch, x);
        } else {
          rotate_left(o);
          remove(o->lch, x);
        }
      }
      o->maintain();
    } else if (x < o->val) {
      remove(o->lch, x);
      o->maintain();
    } else {
      remove(o->rch, x);
      o->maintain();}}
  void remove(T x)
  { this->remove(root, x); }
  _Node* find(_Node* o, T& x)
  { if(o==NULL)return NULL;
    if (o->val == x) return o;
    else if (x < o->val) {
      if (o->lch == NULL) return NULL;
      else return find(o->lch, x);
    } else {
      if (o->rch == NULL) return NULL;
      else return find(o->rch, x);}}
  _Node* find(T x) 
  { return this->find(root, x); }
  _Node* kth(_Node* o, unsigned long k) // Find o s.t. o->s+1=k
  { if(o==NULL)return NULL;
    unsigned long order = o->rch == NULL ? 0 : o->rch->size + 1;
    if (o->size < k) return NULL;
    else if (k <= order) {
      if (o->rch != NULL) return kth(o->rch, k);
      else return NULL;
    } else {
      if (o->lch != NULL) return kth(o->lch, k-order-1);
      else return NULL;
    }
  }
  _Node* kth(unsigned long k)
  { return this->kth(root, k); }
  unsigned long rank(_Node* o, T& x)
  { if (o==NULL)return 0;
    if (o->val == x) {
      unsigned long r = o->lch == NULL ? 0 : o->lch->size;
      return (unsigned long) r;
    } else if (o->val > x) {
      if (o->lch == NULL) {
        return 0;
      } else if (o->lch->val < x) { // like case above
        return o->lch->size;
      } else // >=, leave for recursion to handle
        return rank(o->lch, x);
    } else // <, return size of entire tree
      return o->size;
  }
  unsigned long rank(T x)
  { return this->rank(root, x); }
  unsigned long size()
  { return this->root->size; }
};

int main()
{
  treap<long> T;
  T.insert(long(1L));
  T.insert(long(2L));
  T.insert(long(3L));
  T.insert(5L); T.insert(9L);
  cout << "size of tree:"<< T.size() << endl;
  cout << T.find(2L)->val << endl;
  cout << T.find(9L)->val << endl;
  cout << T.kth(3)->val << endl;
  return 0;
}



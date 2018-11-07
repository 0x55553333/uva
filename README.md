# UVa Online Judge Solutions
Copyright &copy; Rui-Jie Fang, 2018. Progress tracking: https://uhunt.onlinejudge.org/id/885236
<br>

## Folder structure

A bunch of useful data structures are in the `https://github.com/0x55553333/uva/tree/master/repo` folder:
  - `Prime.c` - Sieve of Erastothenes
  - `bidirectional_bfs.cpp` - Bidirectional BFS implementation, not yet correct
  - `bit_array.cpp` - Scalable bitset implementation (supports growing/shrinking, like a vector of bits)
  - `circular_primes.c	` - Circular primes sieve
  - `doubly_linked_array.cpp` - Array-based linked list implementation with O(1) query time for neighbor relationships
  - `equipartition.cpp` - Set partitioning problem using Horowitz-Sahni O(n 2^(n/2))-time algorithm for subset sum
  - `ufd_generic.cpp` -- Generic union-find-disjoint sets; they support storing any type within a UFD-like structure for fast parent query
  - `floodfill_graph.cpp` - Convert adjacencies between 0s and 1s in mesh graph into a graph
  - `interval_covering.cpp` - Greedy interval covering algorithm without nested loop 
  - `lis.cpp` - Longest Increasing Subsequence in O(n log n) time using patience sorting
  - `min_seg_tree.cpp` - Plug-n-play Template Library implementation of generic segment tree for Range Minimum Query, supports single updates (todo: lazy range updates)
  - `primes.h` - HUGE header file containing a BUNCH of primes
  - `subset_sum.cpp` - The Horowitz-Sahni algorithm for subset-sum
  - `sum_seg_tree.cpp` - Plug-n-play Template Library implementation of generic segment tree for Range Sum Query, supports single updates (todo: lazy propagation)
  - `ufd.cpp` - Union-find-disjoint sets, todo optimize.
  - `bit.cpp` - Binary-indexed tree supporting generics.
  - `quadrangle.cpp` - Quadrangle Inequality speedup for Optimal BST problem based on UVa10304 (fully-recursive memoized implementation; better readability than the diagonal-by-diagonal iterative version).
Comments are in the `comments/` folder. All submissions are compiled with UVa's c++11 option.


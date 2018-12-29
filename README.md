# Collection of Online Judge Solutions, Plug-n-play Algorithms, and data structures
Copyright &copy; Rui-Jie Fang, 2018. <br>
UVa Progress tracking: https://uhunt.onlinejudge.org/id/885236
<br>

## Algorithms included:
A bunch of useful data structures are in the `https://github.com/0x55553333/uva/tree/master/repo` folder:
  - `Prime.c` - Sieve of Erastothenes
  - `bidirectional_bfs.cpp` - Bidirectional BFS implementation, not yet correct
  - `bit_array.cpp` - Scalable bitset implementation (supports growing/shrinking, like a vector of bits)
  - `circular_primes.c	` - Circular primes sieve
  - `doubly_linked_array.cpp` - Array-based linked list implementation with O(1) query time for neighbor relationships
  - `equipartition.cpp` - Set partitioning problem using Horowitz-Sahni O(n 2^(n/2))-time algorithm for subset sum
  - `ufd_generic.cpp` -- Generic union-find-disjoint sets; they support storing any type within a UFD-like structure for fast parent query
  - `floodfill_graph.cpp` - Convert adjacencies between 0s and 1s in mesh graph into a graph
  - `interval_covering.cpp` - Greedy interval covering algorithm 
  - `lis.cpp` - Longest Increasing Subsequence in O(n log n) time using patience sorting
  - `LIS1.cpp` - Longest Increasing Subsequence in O(n log n) time and O(n) space using the Young Tableau technique (Fredman 1975)
  - `LIS2.cpp` - Longest Increasing Subsequence in O(n^2) time and O(n) space using the Young Tableau technique (Fredman 1975, w/o binary search)
  - `min_seg_tree.cpp` - Plug-n-play Template Library implementation of generic segment tree for Range Minimum Query, supports single updates (todo: lazy range updates)
  - `primes.h` - HUGE header file containing a BUNCH of primes
  - `subset_sum.cpp` - The Horowitz-Sahni algorithm for subset-sum
  - `sum_seg_tree.cpp` - Plug-n-play Template Library implementation of generic segment tree for Range Sum Query, supports single updates (todo: lazy propagation)
  - `ufd.cpp` - Optimized union-find-disjoint set with path compression.
  - `bit.cpp` - Binary-indexed tree supporting generics.
  - `quadrangle.cpp` - Quadrangle Inequality speedup for Optimal BST problem based on UVa10304 (fully-recursive memoized implementation; better readability than the diagonal-by-diagonal iterative version).
  - `treap.cpp` - Treap in increasing order with order statistic functions. Rank/kth Not yet correct but treap is ready.
  - `wavelet1.cpp` - reference wavelet tree implementation with order statistic functions
  - `dfs_grid.cpp` - Memoized DFS for finding MSSP on an input grid/maze
  - `bfs_grid.cpp` - BFS with path printing functionality for finding MSSP on an input grid/maze
  - `maxflow.cpp` - Find max-flow using Edmonds-Karp
  - `MCMF.cpp` - find min-cost-max-flow using Edmonds-Karp + Bellman-Ford
Comments are in the `comments/` folder. All submissions are compiled with UVa's c++11 option.


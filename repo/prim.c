
/* data structure for graphs */

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <memory.h>
#include <limits.h>
struct vertex {
	unsigned nedges;
	unsigned* edges;
	unsigned* edge_w;
	unsigned name;
};

struct graph {
	unsigned nvertices;
	vertex* vertices;
	bool* in_tree;
	unsigned *dist;
	unsigned *parent;
};

struct graph_edgelist {
	std::pair<unsigned,unsigned> edges;
	unsigned n_edges;
	std::vector<unsigned> edge_w;
};

bool *in_tree;

void prim(graph& g, unsigned start) {
	memset(g.in_tree, 0, sizeof(bool)*g.nvertices);
	memset(g.parent, 0, sizeof(unsigned)*g.nvertices);
	for(unsigned i=1;i<g.nvertices;++i) {
		g.dist[i] = INT_MAX;
	}

	g.dist[start]=0;
	unsigned v= start;
	/* while there's still a vertex to add to our tree */
	while(g.in_tree[v] == false) {
		/* add this vertex */
		g.in_tree[v] = true;
		/* now, discover another vertex that has minimum edge cost to connect to */
		for(unsigned i=0;i<g.vertices[v].nedges;++i) {
			/* a candidate from incident vertices to current one */
			unsigned candidate = g.vertices[v].edges[i];
			/* get its weight */
			unsigned weight = g.vertices[v].edge_w[i];
			
			if ( (g.dist[candidate] > weight /* update weight */) && (g.in_tree[candidate] == false) ) {
				g.dist[candidate] = weight; /* we update the weight here to best weight */
				g.parent[candidate] = v; /* we set parent of this candidate to v */
			}
		}	

		v = 1; /* loop */
		unsigned mdist=MAX_INT;
		/* now we try to discover one with the minimum weight that is not in the tree */
		for(unsigned i=2;i<=g.nvertices;++i) {
			/* if a node is not in mst and it has relatively minimum weight, add it as new discovery */
			if ((g.in_tree[i] == false)&&(mdist > g.dist[i])) {
				mdist = g.dist[i];
				v=i;
			}
		}
		/* the invariant: now, v is either 1, which has been discovered, or 
		 * another vertex, that is undiscovered and has a current minimum weight */
		/* continue the loop until every vertex is in our tree */
	}
}

int main(void) {

}

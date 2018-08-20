#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <utility>
#include <memory.h>
using namespace std;
#include <ctime>
#include <unistd.h>
struct node {
	int val;
	unsigned height;
	int used;
	int pad;
	node *lvs;
	void operator=(node& p){
		this->val = p.val;
		this->height = p.height;
		this->used = p.used;
		this->lvs = p.lvs;
	}
	node() { this->used = 0; this->lvs = NULL;
		this->height = this->val = 0;
	}

	explicit node(int val) {
		printf("constructing a new node\n");
		this->used = 0;  this->lvs = new node[15];
		printf("getting height for val=%d\n", val);
		this->height = get_height();
		printf("height = %d\n", this->height);
		this->used = 1;
	}

	~node() { delete[] this->lvs; }

	private:
	unsigned get_height()
	{ unsigned n = 0;
		while (rand()&1) ++n;
		return n;
	}
};

inline static void _link(node& root, node& curr, int level)
{ if (root.lvs[level].used) {
		node p = root.lvs[level];	
		root.lvs[level] = curr;
		curr.lvs[level] = p;
	} else {
		root.lvs[level] = curr;
	}
}

void insert(node& root, node& curr, unsigned level)
{	
	if (curr.height > root.height) {
		root.height = curr.height;
		root.lvs[root.height] = curr;
	}

	if (root.lvs[level].val < curr.val) return insert(root.lvs[level], curr, level);
	else {
		if (level == 0) {
			_link(root, curr, 0);
		} else {
			if (level <= curr.height) {
				_link(root, curr, level);
			}
			return insert(root.lvs[level - 1], curr, level - 1);
		}
	}	
}

node* _search(node& root, int val, unsigned level)
{ if (root.lvs[level].val < val) return _search(root.lvs[level], val, level);
	else {
		if (level == 0) {
			if (root.lvs[0].val != val) return NULL;
			else return &(root.lvs[0]);
		} else {
			return _search(root.lvs[level - 1], val, level - 1);
		}
	}
}

node* search(node& root, int val)
{
	return _search(root, val, root.height);
}

int main()
{ srand(time(NULL));
	node skip_list(0);
	sleep(1);
	node elem1(9), elem2(19), elem3(7);
	printf("inserting elem1\n");
	insert(skip_list, elem1, skip_list.height);
	printf("inserting elem2\n");
	insert(skip_list, elem2, skip_list.height);
	printf("inserting elem3\n");
	insert(skip_list, elem3, skip_list.height);
	return 0;
}

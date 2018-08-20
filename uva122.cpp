#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <vector>
#include <memory.h>
using namespace std;
struct Node {
	int val;
	Node* left;
	Node* right;
	Node() { this->val = -1; this->left = this->right = NULL; }
};
int main()
{ char s[0xffff];
	Node* root = NULL;
	int fail = 0;
	while (1) {
		if (scanf("%s", s) != 1) break;
		if (root == NULL) { root = new Node; fail = 0; }
		if (!strcmp(s, "()")) {
			queue<Node*> bfs; vector<int> order;
			if (fail) goto cleanup;
			bfs.push(root);
			while (!bfs.empty()) {
				Node* n = bfs.front(); bfs.pop();
				if (n->val == -1) { 
					fail = 1; goto cleanup; }
				order.push_back(n->val);
				if (n->left != NULL) bfs.push(n->left);
				if (n->right != NULL) bfs.push(n->right);
				delete n;
			}
cleanup:
			if (fail) {
				printf("not complete\n");
			} else {
				for(int i = 0; i < order.size() - 1; ++i) printf("%d ", order[i]);
				printf("%d\n", order[order.size()-1]);
			}
			root = NULL;
			fail = 0;
			continue;
		}
		if (fail) continue;
		int val;
		char * path = s;
		while (*path != ',') ++path;
		++path;
		Node* ptr = root;
		sscanf(&s[1], "%d", &val);
		while (*path != ')') {
			switch (*path) {
				case 'L':
					if (ptr->left == NULL) ptr->left = new Node;
					ptr = ptr->left;
					break;
				case 'R': 
					if (ptr->right == NULL) ptr->right = new Node;
					ptr = ptr->right;
					break;
			}
			++path;
		}
		if (ptr->val != -1) { fail = 1;continue; }
		ptr->val = val;
	}
	return 0;
}

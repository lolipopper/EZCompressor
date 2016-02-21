#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H
#include <bits/stdc++.h>
#define NYT (1<<8)
#include "Tree.h"
using namespace std;

class HuffmanTree {
public:
	HuffmanTree();

	Tree* getLeaf(int value);

	void updateTree(Tree* node);
	void updateBlockFirst();
	void splitNYT(Tree* node,int value);
	void writeCode(Tree* node);
	void writeTree();

private:
	Tree* root;
	Tree* blockFirst[];
	Tree* leaves[1000];
};

#endif
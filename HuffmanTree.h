#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H
#include <bits/stdc++.h>
#include "Tree.h"
#include "Reader.h"
#include "Writer.h"
#define NYT (1<<8)
#define EndOfFile (1<<8)+1
#define EndOfTransmission (1<<8)+3
using namespace std;

class HuffmanTree {
public:
	HuffmanTree();

	Tree* getRoot();
	Tree* getLeaf(int value);

	void updateTree(Tree* node);
	void updateBlockFirst();
	void splitNYT(Tree* node,int value);
	void writeCode(Tree* node,Writer& w);
	void writeTree();

private:
	Tree* root;
	map<int,Tree*> blockFirst;
	Tree* leaves[1000];
};

#endif
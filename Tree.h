#ifndef TREE_H
#define TREE_H
#include <bits/stdc++.h>
using namespace std;

class Tree {
public:
	Tree(int value,int weight, Tree* left, Tree* right, Tree* parent);
	Tree(const Tree& T);

	int getValue();
	int getWeight();
	Tree* getLeft();
	Tree* getRight();
	Tree* getParent();
	void setValue(int);
	void setWeight(int);
	void setLeft(Tree*);
	void setRight(Tree*);
	void setParent(Tree*);

	bool isLeftChild();
	bool isRightChild();

	void writeTree();

protected:
	int value;
	int weight;

	Tree* left;
	Tree* right;
	Tree* parent;
};

#endif
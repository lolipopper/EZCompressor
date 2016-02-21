#include "Tree.h"

Tree::Tree(int value,int weight=0, Tree* left=NULL, Tree* right=NULL, Tree* parent=NULL)
{
	this->value=value;
	this->weight=weight;
	this->left=left;
	this->right=right;
	this->parent=parent;
}

int Tree::getValue()
{
	return value;
}

int Tree::getWeight()
{
	return weight;
}

Tree* Tree::getLeft()
{
	return left;
}

Tree* Tree::getRight()
{
	return right;
}

Tree* Tree::getParent()
{
	return parent;
}

void Tree::setValue(int value)
{
	this->value=value;
}

void Tree::setWeight(int weight)
{
	this->weight=weight;
}

void Tree::setLeft(Tree* _left)
{
	this->left=_left;
}

void Tree::setRight(Tree* _right)
{
	this->right=_right;
}

void Tree::setParent(Tree* _parent)
{
	this->parent=_parent;
}

bool Tree::isLeftChild()
{
	return (this==parent->left);
}

bool Tree::isRightChild()
{
	return (this==parent->right);
}

void Tree::writeTree()
{
	if (getLeft()==NULL)
	{
		cout << value << ',' << weight;
	}
	else
	{
		cout << weight;
		cout << '(';
		getLeft()->writeTree();
		cout << ") (";
		getRight()->writeTree();
		cout << ')';
	}
}
#include "HuffmanTree.h"

HuffmanTree::HuffmanTree()
{
	root=new Tree(NYT,0,NULL,NULL,NULL);
	for (int i=0;i<512;i++)
	{
		leaves[i]=root;
	}
}

void HuffmanTree::updateTree(Tree* node)
{
	if (node->getParent()!=NULL)
	{
		Tree* firstInBlock=blockFirst[node->getWeight()];
		if ((firstInBlock!=node->getParent())&&(firstInBlock!=node))
		{
			//swap node
			Tree* par1=node->getParent();
			Tree* par2=firstInBlock->getParent();
			
			if (node->isLeftChild())
			{
				if (firstInBlock->isLeftChild())
				{
					par1->setLeft(firstInBlock);
					firstInBlock->setParent(par1);
					par2->setLeft(node);
					node->setParent(par2);
				}
				else
				{
					par1->setLeft(firstInBlock);
					firstInBlock->setParent(par1);
					par2->setRight(node);
					node->setParent(par2);
				}
			}
			else
			{
				if (firstInBlock->isLeftChild())
				{
					par1->setRight(firstInBlock);
					firstInBlock->setParent(par1);
					par2->setLeft(node);
					node->setParent(par2);
				}
				else
				{
					par1->setRight(firstInBlock);
					firstInBlock->setParent(par1);
					par2->setRight(node);
					node->setParent(par2);
				}
			}
		}
		node->setWeight(node->getWeight()+1);
		updateTree(node->getParent());
	}
	else
	{
		node->setWeight(node->getWeight()+1);
	}
}

void HuffmanTree::updateBlockFirst()
{
	queue<Tree*> q; //Algoritma BFS
	int curWeight=root->getWeight()+1;
	q.push(root);
	while(!q.empty())
	{
		Tree* temp=q.front();
		q.pop();
		if (temp->getWeight()!=curWeight) // new weight class
		{
			curWeight=temp->getWeight();
			blockFirst[temp->getWeight()]=temp;
		}

		if (temp->getRight()!=NULL)
		{
			q.push(temp->getRight());
			q.push(temp->getLeft());
		}
	}
}

Tree* HuffmanTree::getLeaf(int value)
{
	return leaves[value];
}

void HuffmanTree::splitNYT(Tree* node,int value)
{
	myfile << value;
	leaves[value]=new Tree(value,0,NULL,NULL,node);
	Tree* newParent=new Tree(512,0,node,leaves[value],node->getParent());
	if (node!=root)
	{
		if (node->isLeftChild())
			(node->getParent())->setLeft(newParent);
		else
			(node->getParent())->setRight(newParent);
	}
	else
	{
		root=newParent;
	}
	node->setParent(newParent);
	leaves[value]->setParent(newParent);
	//newParent->writeTree();
	//cout << endl;
}

void HuffmanTree::writeCode(Tree* node)
{
	if (node!=root)
	{
		writeCode(node->getParent());
		if (node->isLeftChild()) //coutnya gimana?
		{
			cout << 0;
		}
		else
		{
			cout << 1;
		}
	}
}

void HuffmanTree::writeTree()
{
	root->writeTree();
}
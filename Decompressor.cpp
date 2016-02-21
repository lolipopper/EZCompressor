#include "Decompressor.h"

void addCharacter(int* c,Reader& r)
{
	if (*c==NYT)
	{
		r.readNextNine(c);
		T.splitNYT(T.getLeaf(NYT),*c);
	}
	T.updateBlockFirst();
	T.updateTree(T.getLeaf(*c));
}

void Decompressor::Decompress(string outputName,pair<string,string> fileName)
{
	HuffmanTree T;
	int numberOfFiles=fileName.size();
	while (c!=EndOfTransmission)
	{
		string outputFileName;
		Reader r(fileName[i].first);
		Writer w(outputName);
		int c;

		while (c!=EndOfFile) //encode filename
		{
			bool b;
			Tree* node=T.getRoot();
			while (node->getLeft()!=NULL)
			{
				r.readNextBit(&b);
				if (b)
				{
					node=node->getRight();
				}
				else
				{
					node=node->getLeft();
				}
			}
			c=node->getValue();
			addCharacter(&c);
			outputFileName.push_back(c);
		}

		while (c!=EndOfFile) //encode filename
		{
			bool b;
			Tree* node=T.getRoot();
			while (node->getLeft()!=NULL)
			{
				r.readNextBit(&b);
				if (b)
				{
					node=node->getRight();
				}
				else
				{
					node=node->getLeft();
				}
			}
			c=node->getValue();
			addCharacter(&c);
		}
	}
}
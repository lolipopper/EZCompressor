#include "Decompressor.h"

void addCharacter(HuffmanTree& T,int* c,Reader& r)
{
	if (*c==NYT)
	{
		r.readNextNine(c);
		T.splitNYT(T.getLeaf(NYT),*c);
	}
	T.updateBlockFirst();
	T.updateTree(T.getLeaf(*c));
}

void Decompressor::Decompress(string outputName,string fileName)
{
	HuffmanTree T;
	int numberOfFiles=fileName.size();
	int c;
	Reader r(fileName);
	while (c!=EndOfTransmission)
	{
		string outputFileName;

		do //encode filename
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
			addCharacter(T,&c,r);
			if ((c!=EndOfFile)&&(c!=EndOfTransmission))
				outputFileName.push_back(c);
		}
		while ((c!=EndOfFile)&&(c!=EndOfTransmission));

		if (c!=EndOfTransmission)
		{
			Writer w(outputName+outputFileName);
			do //encode filename
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
				addCharacter(T,&c,r);
				w.writeByte(c);
			}
			while ((c!=EndOfFile)&&(c!=EndOfTransmission));
			w.flush();
		}
	}
}
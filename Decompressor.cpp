#include "Decompressor.h"

void Decompressor::Decompress(string outputName,vector< pair<string,string> > fileName)
{
	HuffmanTree T;
	ofstream outfile(outputName,ios::binary);
	ifstream infile(fileName,ios::binary);
	if (myfile.is_open())
	{
		do
		{
			Tree* node=T.readCode();
			int c=node->getValue();
			if (node->getValue()==NYT)
			{
				c=read9Bit();
				T.splitNYT(T.getLeaf(NYT),c);
			}
			//if (EOF)
			write(c);
			T.updateBlockFirst();
			T.updateTree(T.getLeaf(c));
		}
		while (c!='0');
		T.writeTree();
		cout<<endl;
	}
	else
	{
		cout << "unable to open file";
	}
}
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
			node=T.readCode();
			if (T.getLeaf(c)==T.getLeaf(NYT))
			{
				T.splitNYT(T.getLeaf(NYT),c);
			}
			T.updateBlockFirst();
			T.updateTree(T.getLeaf(c));
			myfile.close();
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
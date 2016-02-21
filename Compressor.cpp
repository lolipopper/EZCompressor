#include "Compressor.h"

void Compressor::Compress(string outputName,vector< pair<string,string> > fileName)
{
	HuffmanTree T;
	ofstream outfile(outputName,ios::binary);
	ifstream infile(fileName,ios::binary);
	if (myfile.is_open())
	{
		char c;
		do
		{
			infile >> c;
			T.writeCode(T.getLeaf(c));
			if (T.getLeaf(c)==T.getLeaf(NYT))
			{
				//cout << "splitNYT";
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
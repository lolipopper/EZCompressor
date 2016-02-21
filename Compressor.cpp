#include "Compressor.h"

void addCharacter(HuffmanTree& T,int c,Writer& w)
{
	T.writeCode(T.getLeaf(c),w);
	if (T.getLeaf(c)==T.getLeaf(NYT))
	{
		//cout << c;
		w.writeNine(c);
		T.splitNYT(T.getLeaf(NYT),c);
	}
	T.updateBlockFirst();
	T.updateTree(T.getLeaf(c));
	cout << (T.getRoot())->getWeight() << endl;
}

void Compressor::Compress(string outputName,vector< pair<string,string> > fileName)
{
	HuffmanTree T;
	int numberOfFiles=fileName.size();
	Writer w(outputName);
	for (int i=0;i<numberOfFiles;i++)
	{
		Reader r(fileName[i].first);
		int c;

		int lengthName=fileName[i].second.length(); //encode filename
		for (int j=0;j<lengthName;j++)
		{
			c=fileName[i].second[j];
			addCharacter(T,c,w);
			// cout << endl;
			// T.writeTree();
			// cout << endl;
		}
		addCharacter(T,EndOfFile,w);
		// cout << endl;
		// T.writeTree();
		// cout << endl;

		while (r.readNextByte(&c)) //encode file
		{
			addCharacter(T,c,w);
			// cout << endl;
			// T.writeTree();
			// cout << endl;
		}
		addCharacter(T,EndOfFile,w);
		// cout << endl;
		// T.writeTree();
		// cout << endl;
	}
	addCharacter(T,EndOfTransmission,w);
	// cout << endl;
	// T.writeTree();
	// cout << endl;
}
#ifndef COMPRESSOR_H
#define COMPRESSOR_H
#include <bits/stdc++.h>
#include "HuffmanTree.h"
using namespace std;

class Compressor {
public:
	static void Compress(string outputName,vector< pair<string,string> > fileName);

private:
	Compressor();
};

#endif
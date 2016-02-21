#ifndef writer_h
#define writer_h
#include "string"
#include "iostream"
#include "fstream"
#include "cstdio"

using namespace std;

class Writer
{
public:
	Writer(string filename){
		output = fopen(filename.c_str(), "wb");
		remainingBitCount = 7;
		newChar = false;
		currentByte = 0;
	}
	void writeBit(bool b) {
		char c = b;
		c <<= remainingBitCount;
		currentByte += c;
		fwrite (&currentByte, 1, 1, output);
		remainingBitCount--;
		if (remainingBitCount < 0)
		{
			newChar = true;		
			remainingBitCount = 7;
			currentByte = 0;
		}
		else
			fseek(output, -1, SEEK_CUR);
	}
	void writeByte(char c) {
		bool finish = false;
		for (int i = 7; i >= 0; i--) {
			writeBit((c >> i) & 1);
		}
	}

	void writeNine(int c) {
		bool finish = false;
		for (int i = 8; i >= 0; i--) {
			writeBit((c >> i) & 1);
		}
	}

	bool getNewChar() {
		if (newChar)
		{
			newChar = false;
			return true;
		}
		return false;
	}

	~Writer() {
		fclose(output);
	}
	
private:
	FILE* output;
	char remainingBitCount;
	char currentByte;
	bool newChar;
};

#endif

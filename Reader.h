#ifndef READER_H
#define READER_H
#include "string"
#include "iostream"
#include "fstream"

using namespace std;

class Reader
{
public:
	Reader(string filename){
		input.open(filename.c_str(), ios::binary | ios::in);
		remainingBitCount = 0;
		newChar = false;
	}
	bool readNextBit(bool* b) {
		if (remainingBitCount)
		{
			remainingBitCount--;
			*b = ((currentByte >> remainingBitCount) & 1);
			return true;
		}
		if (input.get(currentByte))
		{
			newChar = true;
			remainingBitCount = 8;
			remainingBitCount--;
			*b = ((currentByte >> remainingBitCount) & 1);
			return true;
		}
		return false;
	}
	bool readNextByte(char* c) {
		*c = 0;
		bool finish = false;
		for (int i = 7; i >= 0; i--) {
			bool b = 0;
			if (readNextBit(&b))
			{
				*c += b << i;
			}
			else
				finish = true;
		}
		return !finish;
	}

	bool readNextNine(int* c) {
		*c = 0;
		bool finish = false;
		for (int i = 8; i >= 0; i--) {
			bool b = 0;
			if (readNextBit(&b))
			{
				*c += b << i;
			}
			else
				finish = true;
		}
		return !finish;
	}

	bool getNewChar() {
		if (newChar)
		{
			newChar = false;
			return true;
		}
		return false;
	}

	~Reader() {
		input.close();
	}
	
private:
	ifstream input;
	char remainingBitCount;
	char currentByte;
	bool newChar;
};

#endif

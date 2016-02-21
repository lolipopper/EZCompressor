#ifndef matriks_h
#define matriks_h
#include "string"
#include "iostream"
#include "fstream"
#include "cstdio"

using namespace std;

class Reader
{
public:
	Reader(string filename){
		input = fopen(filename.c_str(), "rb");
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
		if (fread(&currentByte, 1, 1, input))
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
		fclose(input);
	}
	
private:
	FILE * input;
	char remainingBitCount;
	char currentByte;
	bool newChar;
};

#endif

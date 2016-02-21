#ifndef matriks_h
#define matriks_h
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
	}
	bool readNextBit(bool* b) {
		if (remainingBitCount)
		{
			remainingBitCount--;
			*b = ((currentByte >> remainingBitCount) & 1);
			return true;
		}
		else
		{
			if (input.get(currentByte))
			{
				remainingBitCount = 8;
				remainingBitCount--;
				*b = ((currentByte >> remainingBitCount) & 1);
				return true;
			}
			else
				return false;
		}
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


	~Reader() {
		input.close();
	}
	
private:
	ifstream input;
	char remainingBitCount;
	char currentByte;
};

#endif

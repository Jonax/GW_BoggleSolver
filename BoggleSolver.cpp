#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

struct Results
{
	const char* const* Words;    // pointers to unique found words, each terminated by a non-alpha char
	unsigned           Count;    // number of words found
	unsigned           Score;    // total score
	void*              UserData; // ignored
};

// input dictionary is a file with one word per line
void LoadDictionary(const char* path)
{
	ifstream dictionaryFile;
	dictionaryFile.open(path);

	string line;
	
	vector<string> words;
	if (dictionaryFile.is_open())
	{
		while (getline(dictionaryFile, line))
		{
			if (line != "")
			{
				cout << line << '\n';
			}
		}
		dictionaryFile.close();
	}
}

// this func may be called multiple times
// board: will be exactly width * height chars, and 'q' represents the 'qu' Boggle cube
Results FindWords(const char* board, unsigned width, unsigned height)
{
	Results finalResult;

	finalResult.Words = new char[] { "" };
	finalResult.Count = 0;
	finalResult.Score = 0;
	finalResult.UserData = NULL;
}

// 'results' is identical to what was returned from FindWords
void FreeWords(Results results)
{
	if (results.Words)
	{
		delete results.Words;
	}

	if (results.UserData)
	{
		delete results.UserData;
	}
}

void FreeDictionary()
{
}
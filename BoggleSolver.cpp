#include "BoggleSolver.h"

using namespace std;

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

	BoggleBoard mainBoard = BoggleBoard(width, height);
	mainBoard.Initialise(board);

	/*
	finalResult.Words = new char[] { "" };
	finalResult.Count = 0;
	finalResult.Score = 0;
	finalResult.UserData = NULL;
	*/

	return finalResult;
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

#ifndef _BOGGLE_BOARD_H_
#define _BOGGLE_BOARD_H_

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "BogglePiece.h"

class BoggleBoard
{
	public:
		BoggleBoard(const int width, const int height);
		~BoggleBoard();

		const bool Initialise(const char* board);

	private:
		const char CountSetBits(char value);

		static const bool SortPieces(BogglePiece* a, BogglePiece* b);

		int _width;
		int _height;

		std::vector<BogglePiece*> _pieces;
};

#endif
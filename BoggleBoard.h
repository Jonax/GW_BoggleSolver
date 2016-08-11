#ifndef _BOGGLE_BOARD_H_
#define _BOGGLE_BOARD_H_

#include <string>
#include <iostream>

#include "BogglePiece.h"

class BoggleBoard
{
	public:
		BoggleBoard(const int width, const int height);
		~BoggleBoard();

		const bool Initialise(const char* board);

	private:
		const char CountSetBits(char value);

		int _width;
		int _height;
};

#endif
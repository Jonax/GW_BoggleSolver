#include "BoggleBoard.h"

using namespace std;

const int LINK_RIGHT = 0x1;
const int LINK_DOWN  = 0x2;
const int LINK_LEFT  = 0x4;
const int LINK_UP    = 0x8;


BoggleBoard::BoggleBoard(const int width, const int height)
{
	_width = width;
	_height = height;

	_pieces = vector<BogglePiece*>();
	_pieces.reserve(_width * _height);
}

BoggleBoard::~BoggleBoard()
{
}

const bool BoggleBoard::Initialise(const char* board)
{
	int boardSize = _width * _height;
	if (strlen(board) != boardSize)
	{
		cout << "This board is misaligned, please correct." << endl;
		return false;
	}

	// JW: We could've gone straight for iterating via pointer increment, but in this case we want to know the index as well
	// to place each char in the board.  Hence the index access instead.  
	for (int i = 0; i < boardSize; ++i)
	{
		char sideAxis = 0;
		
		// If not on the left edge, then it has a right link.  
		if (i % _width != 0)
			sideAxis ^= LINK_LEFT;

		// If not on the top row, then it has a up link.  
		if (i > _width)
			sideAxis ^= LINK_UP;

		// If not on the right edge, then it has a left link.  
		if ((i + 1) % _width != 0)
			sideAxis ^= LINK_RIGHT;

		// If not on the bottom row, then it has a down link.  
		// NOTE: Went for an i+w approach instead of i/w in case divisor performance is an issue.  
		if ((i + _width) < boardSize)
			sideAxis ^= LINK_DOWN;

		// This determines how many adjacent letters this letter has, in order to determine how big its internal vector needs to be.  
		// This relies on a few things:
		// - Given the square nature of the board, it will always have two or three edge letters.  
		// - Given the square nature of the board, a letter is never going to be next to four edge letters.  
		// - Given the square nature of the board, the links are going to be "next" to each other (e.g. left-up or right-down, never left-right).  
		// - When two edge letters are next to each other, there is a guaranteed letter in the middle.  
		// So, we determine how many edge letters it has, THEN add the corner letters (as edge letters - 1).  
		int totalNumLinks = CountSetBits(sideAxis);
		totalNumLinks += (totalNumLinks - 1);

		BogglePiece* piece = new BogglePiece(board[i], totalNumLinks, sideAxis);
		_pieces.push_back(piece);
	}

	for (std::vector<BogglePiece*>::iterator it = _pieces.begin(); it != _pieces.end(); ++it)
	{
		BogglePiece* piece = *it;
		char adjLinks = piece->GetAdjacencyFlags();

		if (adjLinks & LINK_LEFT)
		{
			piece->AddLink(*(it - 1));
		}

		if (adjLinks & LINK_UP)
		{
			piece->AddLink(*(it - _width));

			if (adjLinks & LINK_LEFT)
				piece->AddLink(*(it - _width - 1));

			if (adjLinks & LINK_RIGHT)
				piece->AddLink(*(it - _width + 1));
		}

		if (adjLinks & LINK_RIGHT)
		{
			piece->AddLink(*(it + 1));
		}

		if (adjLinks & LINK_DOWN)
		{
			piece->AddLink(*(it + _width));

			if (adjLinks & LINK_LEFT)
				piece->AddLink(*(it + _width - 1));

			if (adjLinks & LINK_RIGHT)
				piece->AddLink(*(it + _width + 1));
		}
	}

	return true;
}

const char BoggleBoard::CountSetBits(char value)
{
	// This uses Brian Kernighan's algorithm for quickly counting number of bits in a value.  
	// Taken from: http://graphics.stanford.edu/~seander/bithacks.html#CountBitsSetTable

	unsigned int v = value; // count the number of bits set in v
	unsigned int c; // c accumulates the total bits set in v

	for (c = 0; v; c++)
	{
		v &= v - 1; // clear the least significant bit set
	}

	return c;
}

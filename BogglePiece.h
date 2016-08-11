#ifndef _BOGGLEPIECE_H_
#define _BOGGLEPIECE_H_

#include <vector>

class BogglePiece
{
	public:
		BogglePiece(const char letter, const int numAdjacent);
		~BogglePiece();

	private:
		char _letter;

		std::vector<BogglePiece> adjacentPieces;
};

#endif
#ifndef _BOGGLEPIECE_H_
#define _BOGGLEPIECE_H_

#include <vector>

class BogglePiece
{
	public:
		BogglePiece(const char letter, const int numAdjacent, const char adjacencyFlags);
		~BogglePiece();

		const char GetAdjacencyFlags();

		void AddLink(BogglePiece* pieceToLinkTo);

	private:
		char _letter;

		std::vector<BogglePiece*> _adjacentPieces;
		char _adjacencyFlags;
};

#endif
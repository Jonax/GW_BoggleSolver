#include "BogglePiece.h"

BogglePiece::BogglePiece(const char letter, const int numAdjacent, const char adjacencyFlags)
{
	_letter = letter;

	_adjacentPieces = std::vector<BogglePiece*>();
	_adjacentPieces.reserve(numAdjacent);

	_adjacencyFlags = adjacencyFlags;
}

BogglePiece::~BogglePiece()
{
	_adjacentPieces.clear();
}

const char BogglePiece::GetLetter()
{
	return _letter;
}

const char BogglePiece::GetAdjacencyFlags()
{
	return _adjacencyFlags;
}

void BogglePiece::AddLink(BogglePiece* pieceToLinkTo)
{
	// Quick safety check - If the piece (somehow) already has this piece set as an adjacent, don't add again.  
	for (std::vector<BogglePiece*>::iterator it = _adjacentPieces.begin(); it != _adjacentPieces.end(); ++it)
	{
		if (*it == pieceToLinkTo)
		{
			return;
		}
	}

	_adjacentPieces.push_back(pieceToLinkTo);
}
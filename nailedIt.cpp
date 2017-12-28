#include <iostream>
#include <fstream>
#include <vector>

std::vector<int> getPieces();
std::vector<int> findPossibleBoardLengths(std::vector<int> pieceList);
int findFenceLength(std::vector<int> pieceList, int boardLength);
std::vector<int> quickSortVector(std::vector<int> unsortedVector);

int main() {

	std::vector<int> pieceList = getPieces();

}

std::vector<int> getPieces() {

	/*
		Input mainly.
	*/

	std::ifstream file;
	file.open("c.in");

	int pieceCount;
	file >> pieceCount;

	std::vector<int> pieceList;

	for(int i = 0; i < pieceCount; i++) {
		int currentLength;
		file >> currentLength;
		pieceList.push_back(currentLength);
	}

	return pieceList;

}

std::vector<int> quickSortVector(std::vector<int> unsortedVector) {

	std::vector<int> sortedVector;

	/*
		Implement quicksort magickery.
	*/

	return sortedVector;

}
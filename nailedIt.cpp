#include <iostream>
#include <fstream>
#include <vector>

std::vector<int> getPieces();
std::vector<int> getUniqueFenceLengthCount(std::vector<int> pieceList);
int findViableHeights(std::vector<int> uniqueFenceLengthCount);
int findMaxFenceLength(std::vector<int> uniqueFenceLengthCount);

int main() {

	std::vector<int> pieceList = getPieces();
	std::vector<int> uniqueList = getUniqueFenceLengthCount(pieceList);

	for(int i = 0; i < uniqueList.size(); i++) {
		std::cout << uniqueList[i] << "\n";
	}

	std::cout << findMaxFenceLength(uniqueList);
	std::cout << " ";
	std::cout << findViableHeights(uniqueList) << "\n";

}

std::vector<int> getPieces() {

	/*
		Input mainly.
	*/

	std::ifstream file;
	file.open("s3.05.in");

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

std::vector<int> getUniqueFenceLengthCount(std::vector<int> pieceList) {

	std::vector<int> elementCount;
	elementCount.resize(4000);

	for(int i = 0; i < pieceList.size(); i++) {
		for(int j = i + 1; j < pieceList.size(); j++) {
			elementCount[pieceList[i] + pieceList[j]]++;
		}
	}

	return elementCount;

}

int findViableHeights(std::vector<int> uniqueFenceLengthCount) {

	int count = 0;

	for(int i = 0; i < uniqueFenceLengthCount.size(); i++) {
		if(uniqueFenceLengthCount[i] != 0) {
			count++;
		}
	}

	return count;

}

int findMaxFenceLength(std::vector<int> uniqueFenceLengthCount) {

	int temp;

	for(int i = 0; i < uniqueFenceLengthCount.size(); i++) {
		if(uniqueFenceLengthCount[i] > uniqueFenceLengthCount[i + 1]) {
			temp = uniqueFenceLengthCount[i];
			uniqueFenceLengthCount[i] = uniqueFenceLengthCount[i + 1];
			uniqueFenceLengthCount[i + 1] = temp;
		}
	}

	return uniqueFenceLengthCount[uniqueFenceLengthCount.size() - 1];

}


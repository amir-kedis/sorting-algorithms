#pragma once
/// Sorter class
/// Implementation of sorting algorithms will be done here

#include <windows.h>
#include <iostream>
#include "data.h"

class Sorter
{
private:
	/// Data Members
	SortingOption sortType;
	int* sortingArr;
	unsigned int sortingArrSize;

	/// Constants
	const int MIN_NUM = 0;
	const int MAX_NUM = 100;

	/// Private Functions
private:
	/// SortingAlgo
	void SelectionSrot();
	void InsertionSort();
	void HeapSort();
	void ShellSort();
	void MergeSort();
	void Mergelists(int l ,int h ,int mid);

	/// Heap Sort Functions
	// heapify the subtree rooted at index i
	void Heapify(int n, int i);

	/// I/O
	void ShowTitle();
	void ShowMenu();
	void GetUserInputMode();
	void PrintArr();
	void PrintArrAtStart();
	void PrintArrAtEnd();
	void SelectionSortPassPrint(int passCount, int minI);
	void InsetionSortPassPrint(int key, int j);
	void HeapSortPrintMaxHeap();
	void HeapSortPassPrint(int passCount);
	void ShellSortPassPrint(int gap, int passCount);
	void MergeSortpassprint(int i, int p,int c);
	void Quicksort();
	/// UI Configurations Functions
	void SetColor(Color color);
	void ResetColor();
	void PrintWarning(std::string msg);
	void PrintError(std::string msg);

	/// Array Setup Function
	int Random(int min, int max);
	void CreateRandomArr(unsigned int size);
	void CreateSortedArr(unsigned int size, bool isAscending);
	void DeleteArr();
	void Swap(int& a, int& b);


public:
	/// Constructor and Destructor
	Sorter();
	~Sorter();

	/// Functions
	void Start();
};


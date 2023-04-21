#include "Sorter.h"
#include <stdlib.h>
#include <time.h>
#include <iomanip>

/// Sorting Algorithms
void Sorter::SelectionSrot()
{
	int i, j;

	// Advance the position through the entire array
	for (i = 0; i < sortingArrSize - 1; i++)
	{
		// Find the Min Element in the unsorted SortingArr[i...SortingArrSize-1]

		// Assume the min is the first element
		int jMin = i;
		// Test Against Elements After i to find the smallest
		for (j = i + 1; j < sortingArrSize; j++)
		{
			// if element is less than jMin then it is the new min
			if (sortingArr[j] < sortingArr[jMin])
			{
				jMin = j;
			}
		}

		SelectionSortPassPrint(i + 0, jMin);


		// swap cur i and the min
		if (jMin != i)
		{
			Swap(sortingArr[i], sortingArr[jMin]);
		}
	}
}

void Sorter::InsertionSort()
{
	// for each element of the array
	for (int j = 1; j < sortingArrSize; j++)
	{
		// get the key
		int key = sortingArr[j];
		int i = j - 1;

		InsetionSortPassPrint(i, j);

		// shift the key until it's in its correct postilion
		while (i >= 0 && sortingArr[i] > key)
		{
			sortingArr[i + 1] = sortingArr[i];
			i = i - 1;
		}

		sortingArr[i + 1] = key;

	}
}

void Sorter::HeapSort()
{
	// Build Max Heap -- rearrange array
	for (int i = sortingArrSize / 2 - 1; i >= 0; i--)
	{
		Heapify(sortingArrSize, i);
	}

	HeapSortPrintMaxHeap();

	// extract max from the begin and put at the end
	for (int i = sortingArrSize - 1; i >= 0; i--)
	{
		HeapSortPassPrint(i);

		// move largest element at its Index from the end
		Swap(sortingArr[0], sortingArr[i]);

		// puts the maximum of the remaining back at the beginning
		Heapify(i, 0);

	}
}

void Sorter::ShellSort()
{
	// Start with the largest gap and work down to gap of 1
	for (int gap = 10; gap > 0; gap /= 2)
	{

		// Do a gapped insertion sort for each gap
		for (int offset = gap; offset < sortingArrSize; offset++)
		{
			int temp = sortingArr[offset];
			int j;
			for (j = offset; j >= gap && sortingArr[j - gap] > temp; j -= gap)
			{
				sortingArr[j] = sortingArr[j - gap];
			}
			sortingArr[j] = temp;
		}
		ShellSortPassPrint(gap, gap);


	}
}

/// Heap Sort Functions



void Sorter::Heapify(int n, int i)
{
	int largest = i;
	int l = 2 * i + 1; // 0 based
	int r = 2 * i + 2; // 0 based

	// Get the maximum
	if (l < n && sortingArr[l] > sortingArr[largest])
		largest = l;

	if (r < n && sortingArr[r] > sortingArr[largest])
		largest = r;

	if (largest != i)
	{
		Swap(sortingArr[i], sortingArr[largest]);

		// Recursively heapify the subtree
		Heapify(n, largest);
	}
}

/// Private Functions
void Sorter::ShowTitle()
{
	SetColor(BRIGHT_CYAN);

	std::cout << ".------------------------------------------------------------------------------." << std::endl;
	std::cout << "|                               Sorting Algorithms                             |" << std::endl;
	std::cout << "'------------------------------------------------------------------------------'" << std::endl;

	ResetColor();
}

void Sorter::ShowMenu()
{
	SetColor(BRIGHT_GREEN);

	std::cout << "Choose a sorting algorithm:" << std::endl;

	std::cout << "1. Selection Sort" << std::endl;
	std::cout << "2. Insertion Sort" << std::endl;
	std::cout << "3. Heap Sort" << std::endl;
	std::cout << "4. Shell Sort" << std::endl;
	std::cout << "5. Exit" << std::endl;

	ResetColor();
}

void Sorter::GetUserInputMode()
{
	std::cout << "Enter number of algorithm ex (2) for Insertion Sort: ";
	char rawInput;
	std::cin >> rawInput;

	switch (static_cast<int>(rawInput - '0'))
	{
	case SELECTION_SORT:
		sortType = SELECTION_SORT;
		break;
	case INSERTION_SORT:
		sortType = INSERTION_SORT;
		break;
	case HEAP_SORT:
		sortType = HEAP_SORT;
		break;
	case SHELL_SORT:
		sortType = SHELL_SORT;
		break;
	case EXIT:
		sortType = EXIT;
		break;
	default:
		PrintError("Wrong Input");
		break;
	}
}

void Sorter::PrintArr()
{
	if (!sortingArr)
		return;

	for (unsigned int i = 0; i < sortingArrSize; i++)
	{
		std::cout << sortingArr[i] << " ";
	}

	std::cout << std::endl;
}

void Sorter::PrintArrAtStart()
{
	SetColor(GREY);
	std::cout << "At the Start the random Array:\n";
	SetColor(BRIGHT_WHITE);
	PrintArr();
	ResetColor();

}

void Sorter::PrintArrAtEnd()
{
	SetColor(GREY);
	std::cout << "At the End the Sorted Array (Considered a Pass) :\n";
	SetColor(DARK_YELLOW);
	PrintArr();
	ResetColor();

}

void Sorter::SelectionSortPassPrint(int passCount, int minI)
{
	SetColor(GREY);
	std::cout << "After " << std::setprecision(2) << std::setfill('0') << std::setw(2) << passCount << " Pass: ";

	for (unsigned int i = 0; i < sortingArrSize; i++)
	{
		if (i < passCount)
		{
			SetColor(DARK_YELLOW);
		}
		else if (i == passCount || i == minI)
		{
			SetColor(BRIGHT_BLUE);
		}
		else {
			SetColor(BRIGHT_WHITE);
		}

		std::cout << sortingArr[i] << " ";
	}

	std::cout << std::endl;
	ResetColor();
}

void Sorter::InsetionSortPassPrint(int key, int j)
{
	SetColor(GREY);
	std::cout << "After " << std::setprecision(2) << std::setfill('0') << std::setw(2) << j << " Pass: ";

	for (unsigned int i = 0; i < sortingArrSize; i++)
	{

		if (i < j)
		{
			SetColor(DARK_YELLOW);
		}
		else {
			SetColor(BRIGHT_WHITE);
		}

		if (i == key + 1)
		{
			SetColor(BRIGHT_BLUE);
		}


		std::cout << sortingArr[i] << " ";
	}

	std::cout << std::endl;
	ResetColor();

}

void Sorter::HeapSortPrintMaxHeap()
{
	SetColor(GREY);
	std::cout << "After MaxHeapfing the Array:\n";
	SetColor(BRIGHT_BLUE);
	PrintArr();
	ResetColor();

}

void Sorter::HeapSortPassPrint(int passCount)
{
	SetColor(GREY);
	std::cout << "After " << std::setprecision(2) << std::setfill('0') << std::setw(2) << sortingArrSize - passCount << " Pass: ";

	for (unsigned int i = 0; i < sortingArrSize; i++)
	{
		if (i == 0)
		{
			SetColor(BRIGHT_BLUE);
		}
		else if (i > passCount)
		{
			SetColor(DARK_YELLOW);
		}
		else
		{
			SetColor(BRIGHT_WHITE);
		}

		std::cout << sortingArr[i] << " ";
	}

	std::cout << std::endl;
	ResetColor();

}

void Sorter::ShellSortPassPrint(int gap, int passCount)
{
	SetColor(GREY);
	std::cout << "After K= " << std::setprecision(2) << std::setfill('0') << std::setw(2) << passCount << " Pass: ";

	for (unsigned int i = 0; i < sortingArrSize; i++)
	{
		if (i % gap == 0)
		{
			SetColor(BRIGHT_BLUE);
		}
		else
		{
			SetColor(BRIGHT_WHITE);
		}

		std::cout << sortingArr[i] << " ";
	}

	std::cout << std::endl;
	ResetColor();

}

/// UI Configurations Functions
void Sorter::SetColor(Color color)
{
	HANDLE consoleOutputHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(consoleOutputHandle, color);
}

void Sorter::ResetColor()
{
	HANDLE consoleOutputHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(consoleOutputHandle, DEFAULT_WHITE);
}

void Sorter::PrintWarning(std::string msg)
{
	SetColor(YELLOW);
	std::cout << msg << std::endl;
	ResetColor();
}

void Sorter::PrintError(std::string msg)
{
	SetColor(BRIGHT_RED);
	std::cout << msg << std::endl;
	ResetColor();
}
/// Array Setup Function
int Sorter::Random(int min, int max)
{
	return rand() % (max - min + 1) + min;
}

void Sorter::CreateRandomArr(unsigned int size)
{
	if (sortingArr)
		DeleteArr();

	sortingArr = new int[size];
	sortingArrSize = size;

	for (unsigned int i = 0; i < size; i++)
	{
		sortingArr[i] = Random(MIN_NUM, MAX_NUM);
	}
}

void Sorter::CreateSortedArr(unsigned int size, bool isAscending)
{
	if (sortingArr)
		DeleteArr();

	sortingArr = new int[size];
	sortingArrSize = size;

	if (isAscending)
	{

		for (unsigned int i = 0; i < size; i++)
			sortingArr[i] = i;
	}
	else
	{
		for (unsigned int i = 0; i < size; i++)
			sortingArr[i] = (size - i);

	}


}

void Sorter::DeleteArr()
{
	if (sortingArr)
	{
		delete sortingArr;
		sortingArr = NULL;
		sortingArrSize = 0;
	}
}

void Sorter::Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

/// Constructor and Destructor
Sorter::Sorter()
{
	sortType = OPTION_SIZE;
	sortingArr = NULL;
	sortingArrSize = 0;

	srand(static_cast<unsigned int>(time(0))); // seed the c++ rand

}

Sorter::~Sorter()
{
	DeleteArr();
}


/// Functions
void Sorter::Start()
{
	ShowTitle();
	ShowMenu();

	while (sortType == OPTION_SIZE)
		GetUserInputMode();

	if (sortType == EXIT)
		return;

	CreateRandomArr(15);

	PrintArrAtStart();

	switch (sortType)
	{
	case SELECTION_SORT:
		SetColor(BRIGHT_GREEN);
		std::cout << "Running Selection Sort...\n";
		SelectionSrot();
		break;
	case INSERTION_SORT:
		SetColor(BRIGHT_GREEN);
		std::cout << "Running Insertion Sort...\n";
		InsertionSort();
		break;
	case HEAP_SORT:
		SetColor(BRIGHT_GREEN);
		std::cout << "Running Heap Sort...\n";
		HeapSort();
		break;
	case SHELL_SORT:
		SetColor(BRIGHT_GREEN);
		std::cout << "Running Shell Sort...\n";
		ShellSort();
		break;
	case EXIT:
		break;
	case OPTION_SIZE:
		break;
	default:
		SelectionSrot();
		break;
	}

	PrintArrAtEnd();

	system("pause");
	sortType = OPTION_SIZE;
	system("cls");
	Start();
}

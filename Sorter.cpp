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

		// Assume the the min is the first element
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

void Sorter::InertionSort()
{
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
		SelectionSrot();
		break;
	case INSERTION_SORT:
		break;
	case HEAP_SORT:
		break;
	case SHELL_SORT:
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

}

#include "Sorter.h"

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
	int rawInput;
	std::cin >> rawInput;

	switch (rawInput)
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

/// Constructor and Destructor
Sorter::Sorter()
{
	sortType = OPTION_SIZE;
}

Sorter::~Sorter()
{
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


}

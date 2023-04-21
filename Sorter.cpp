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
}

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

/// Constructor and Destructor
Sorter::Sorter()
{
}

Sorter::~Sorter()
{
}


/// Functions
void Sorter::Start()
{
	ShowTitle();
}

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


	/// Private Functions
private:
	void ShowTitle();
	void ShowMenu();
	void GetUserInputMode();

	/// UI Configurations Functions
	void SetColor(Color color);
	void ResetColor();
	void PrintWarning(std::string msg);
	void PrintError(std::string msg);


public:
	/// Constructor and Destructor
	Sorter();
	~Sorter();

	/// Functions
	void Start();
};


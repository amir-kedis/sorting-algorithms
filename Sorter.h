#pragma once
/// Sorter class
/// Implementation of sorting algorithms will be done here

#include <windows.h>
#include <iostream>
#include "data.h"

class Sorter
{
private:

	/// Private Functions
private:
	void ShowTitle();
	void ShowMenu();
	void SetColor(Color color);
	void ResetColor();


public:
	/// Constructor and Destructor
	Sorter();
	~Sorter();

	/// Functions
	void Start();
};


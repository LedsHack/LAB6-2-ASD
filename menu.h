#pragma once
#include "data.h"
#include "File.h"
#include <iostream>
#include <math.h>

class menu
{
private:

	int selector;
	
public:
	data obj;
	File file;

	menu();
	void get_date();
	void add();
	void print();
	void save();
	void main();
	void del();
	void SearchSort();
	void Search();

};


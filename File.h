#pragma once
#include "data.h"
#include <iostream>
#include <fstream>

class File
{
public:
	data read(data get);
	bool save(data get);
};


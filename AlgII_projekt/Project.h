#pragma once
#include <cstdio>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
class Project
{
private:
	std::vector<int> sourceCodes;
	std::vector<int> dependencyMatrix;
	void ParseSourceCodes(std::vector<std::string>);
	int TwoDToOneD(int, int);
public:
	bool ReadFile(std::string);
	void PrintDependecies();
};


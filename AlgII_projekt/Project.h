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
	void FillDependencyMatrix(std::vector<std::string>);
	void Warshall();
	std::vector<int> GetRow(int);
	int TwoDToOneD(int, int);
public:
	bool ReadFile(std::string);
	void PrintDependecies();
};


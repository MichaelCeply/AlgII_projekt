#pragma once
#include <cstdio>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
class SourceCode
{
private:
	int number;
	std::vector<int> includedSC;
	std::vector<int> thisIncludedInCS;
public:
	SourceCode(int);
	void addIncludedSC(int);
	int GetNum();
};
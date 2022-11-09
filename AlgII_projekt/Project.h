#pragma once
#include "SourceCode.h"
class Project
{
private:
	std::vector<SourceCode> sourceCodes;
	void ParseSourceCodes(std::vector<std::string>);
	void AddSourceCode(int, int);
	int ScPosition(int);
	void SortSC();
public:
	bool ReadFile(std::string);
	void PrintDependecies();
	static bool Compare(const SourceCode& a, const SourceCode& b);
};


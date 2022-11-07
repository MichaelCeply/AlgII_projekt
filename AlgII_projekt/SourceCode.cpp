#include "SourceCode.h"

SourceCode::SourceCode(int num)
{
	this->number = num;
}

void SourceCode::addIncludedSC(int i)
{
	this->includedSC.push_back(i);
}

int SourceCode::GetNum()
{
	return this->number;
}

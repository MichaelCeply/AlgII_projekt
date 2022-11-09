#include "SourceCode.h"

SourceCode::SourceCode(int num)
{
	this->number = num;
}

void SourceCode::addIncludedSC(int i)
{
	this->includedSC.push_back(i);
}

void SourceCode::addIncludedInSC(int i)
{
	this->thisIncludedInCS.push_back(i);
}

int SourceCode::GetNumComp() const
{
	return this->number;
}

int SourceCode::GetNum()
{
	return this->number;
}

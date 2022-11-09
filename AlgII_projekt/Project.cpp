#include "Project.h"

void Project::ParseSourceCodes(std::vector<std::string> vecOfStrings)
{
    for (int i = 0; i < vecOfStrings.size(); i++)
    {
        std::string tmpSC,includesFrom;
        int spaceCounter = 0;
        for (int j = 0; j < vecOfStrings.at(i).size(); j++)
        {
            char c = vecOfStrings.at(i).at(j);
            if (c == ' ')
            {
                spaceCounter++;
            }
            else if (spaceCounter == 0)
            {
                tmpSC.push_back(c);
            }
            else if (spaceCounter == 2)
            {
                includesFrom.push_back(c);
            }
        }
        int intSC = std::stoi(tmpSC);
        int intInclude = std::stoi(includesFrom);
        this->AddSourceCode(intSC, intInclude);
    }
}

void Project::AddSourceCode(int intSC,int intIncl)
{
    int SCpos = this->ScPosition(intSC);
    if (SCpos != -1)
    {
        this->sourceCodes.at(SCpos).addIncludedSC(intIncl);
    }
    else
    {
        SourceCode sc(intSC);
        sc.addIncludedSC(intIncl);
        this->sourceCodes.push_back(sc);
    }

    int InclPos = this->ScPosition(intIncl);
    if (InclPos != -1)
    {
        //this->sourceCodes.at(InclPos).addIncludedSC()
    }
    else
    {
        SourceCode sc(intIncl);
        this->sourceCodes.push_back(sc);
    }
}

int Project::ScPosition(int a)
{
    this->SortSC();
    for (int i = 0; i < this->sourceCodes.size(); i++)
    {
        if (a == this->sourceCodes.at(i).GetNum())
            return i;
    }
    return -1;
}

void Project::SortSC()
{
    std::sort(this->sourceCodes.begin(), this->sourceCodes.end(), Compare);
}

bool Project::Compare(const SourceCode& a,const SourceCode& b)
{
    return a.GetNumComp() < b.GetNumComp();
}

bool Project::ReadFile(std::string fileName)
{
    std::string line;
    std::vector<std::string> vectorOfLines;
    std::ifstream myFile(fileName);
    
    if (!myFile.is_open())
    {
        std::cout << "Unable to open file" << std::endl;
        return false;
    }
    
    while (std::getline(myFile, line))
    {
        vectorOfLines.push_back(line);
    }

    this->ParseSourceCodes(vectorOfLines);

    myFile.close();
    return true;
}

void Project::PrintDependecies()
{
    this->SortSC();
    for (int i = 0; i < this->sourceCodes.size(); i++)
    {
        std::cout << this->sourceCodes.at(i).GetNum()<<": " << std::endl;
    }
}

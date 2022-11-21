#include "Project.h"

void Project::ParseSourceCodes(std::vector<std::string> vecOfStrings)
{
    for (int i = 0; i < vecOfStrings.size(); i++)
    {
        std::string fromStr,toStr;
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
                fromStr.push_back(c);
            }
            else if (spaceCounter == 2)
            {
                toStr.push_back(c);
            }
        }

        int fromInt = std::stoi(fromStr);
        int toInt = std::stoi(toStr);
        
        if (this->sourceCodes.size() == 0 )
        {
            this->sourceCodes.push_back(fromInt);
        }
        if(std::find(this->sourceCodes.begin(), this->sourceCodes.end(), fromInt) == this->sourceCodes.end())
        {
            this->sourceCodes.push_back(fromInt);
        }
        if (std::find(this->sourceCodes.begin(), this->sourceCodes.end(), toInt) == this->sourceCodes.end())
        {
            this->sourceCodes.push_back(toInt);
        }
        
    }

    std::sort(this->sourceCodes.begin(), this->sourceCodes.end());

    for (int i = 0; i < this->sourceCodes.size() * this->sourceCodes.size(); i++)
    {
        this->dependencyMatrix.push_back(0);
    }

}

int Project::TwoDToOneD(int x, int y)
{
    return x*this->sourceCodes.size() + y;
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
    for (int i = 0; i < this->sourceCodes.size(); i++)
    {
        std::cout << this->sourceCodes.at(i) << std::endl;
    }
}

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

void Project::FillDependencyMatrix(std::vector<std::string> vecOfStrings)
{
    for (int i = 0; i < vecOfStrings.size(); i++)
    {
        std::string fromStr, toStr;
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

        int fromIndex = std::find(this->sourceCodes.begin(), this->sourceCodes.end(), fromInt) - this->sourceCodes.begin();
        int toIndex = std::find(this->sourceCodes.begin(), this->sourceCodes.end(), toInt) - this->sourceCodes.begin();

        this->dependencyMatrix[this->TwoDToOneD(toIndex, fromIndex)] = 1;
    }
    this->Warshall();
}

void Project::Warshall()
{
    int lineLenght = this->sourceCodes.size();
    std::vector<std::vector<int>> vecOfVec;
    vecOfVec.push_back(this->dependencyMatrix);

    for (int k = 0; k < lineLenght; k++)
    {
        //vlozeni prazdneho vektoru na pozici vecOfVec[k], abych nasledne mohl upravovat jeho prvky   
        std::vector<int> tmp(lineLenght * lineLenght, 0);
        vecOfVec.push_back(tmp);

        for (int i = 0; i < lineLenght; i++)
        {
            for (int j = 0; j < lineLenght; j++)
            {
                vecOfVec[k + 1][this->TwoDToOneD(i, j)] = (int)((bool)vecOfVec[k][this->TwoDToOneD(i, j)] || ((bool)vecOfVec[k][this->TwoDToOneD(i, k)] && (bool)vecOfVec[k][this->TwoDToOneD(k, j)]));
            }
        }
    }
    this->dependencyMatrix = vecOfVec[lineLenght];
}

void Project::PrintDependencyMatrix()
{
    for (int i = 0; i < this->sourceCodes.size();i++)
    {
        for (int j = 0; j < this->sourceCodes.size();j++)
        {
            std::cout << this->dependencyMatrix[this->TwoDToOneD(i, j)] << ",";
        }
        std::cout << std::endl;
    }
}

std::vector<int> Project::GetRow(int pos)
{
    std::vector<int> row;
    for (int i = 0; i < this->sourceCodes.size(); i++)
    {
        if (this->dependencyMatrix[this->TwoDToOneD(pos, i)] == 1)
        {
            row.push_back(this->sourceCodes[i]);
        }
    }
    return row;
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
    this->FillDependencyMatrix(vectorOfLines);

    myFile.close();
    return true;
}

void Project::PrintDependecies()
{
    for (int i = 0; i < this->sourceCodes.size(); i++)
    {
        std::cout << this->sourceCodes.at(i) << ": ";
        auto vec = this->GetRow(i);
        if (vec.size() == 0)
        {
            std::cout << this->sourceCodes.at(i);
        }
        else
        {
            for (int i = 0; i < vec.size(); i++)
            {
                if(i + 1 == vec.size())
                    std::cout << vec.at(i);
                else
                    std::cout << vec.at(i)<<",";
            }
        }
        std::cout << std::endl;
    }
}

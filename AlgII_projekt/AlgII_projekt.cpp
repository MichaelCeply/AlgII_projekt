#include "Project.h"

int main()
{
    std::cout << "Hello World!\n";
    Project p;
    p.ReadFile("Text.txt");
    p.PrintDependecies();
}
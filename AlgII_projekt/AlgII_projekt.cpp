#include "Project.h"

int main()
{
    Project p;
    p.ReadFile("SmallProject.txt");
    p.PrintDependecies();
}
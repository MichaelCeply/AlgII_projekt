#include "Project.h"

int main()
{
    Project p;
    p.ReadFile("LargeProject.txt");
    p.PrintDependecies();
}
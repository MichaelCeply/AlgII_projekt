/**
*@file Project.h
*@author Michael Ceply
*@brief Trida Project
*/

#pragma once
#include <cstdio>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
class Project
{
private:
	std::vector<int> sourceCodes;
	std::vector<int> dependencyMatrix;
	/**
	*\brief Metoda na naplneni sourceCodes jednotlivymi source kody
	*@param std::vector<std::string> Vektor s jednotlivymi radky z txt souboru
	*/
	void ParseSourceCodes(std::vector<std::string>);
	/**
	*\brief Naplneni dependecyMatrix
	*@param std::vector<std::string> Vektor s jednotlivymi radky z txt souboru
	*/
	void FillDependencyMatrix(std::vector<std::string>);
	/**
	*\Pouziti Warshallova algoritmu na dependecyMatrix
	* 
	* Algoritmus najde, zda existuje cesta mezi dvema vrcholy orientovaneho grafu.
	* Zdroj: LEVITIN, Anany., 2012. Introduction to the Design and Analysis of Algorithms. 3rd ed. Boston: Pearson. ISBN 978-0-13-231681-1.
	* Strana 307
	*/
	void Warshall();
	/**
	*\brief Metoda pro ziskani vrcholu do kterych existuje cesta
	*@param int Poradi vrcholu v sourceCodes
	*@return Vektor vrcholu do kterych existuje cesta
	*/
	std::vector<int> GetRow(int);
	/**
	*\brief Metoda na prevod 2D souradnice v dependencyMatrix na 1D souradnici
	*@param int, int X a Y souradnice
	*/
	int TwoDToOneD(int, int);
public:
	/**
	*\brief Metoda na nacteni vstupniho souboru
	*@param std::string Jmeno vstupniho souboru
	*@return Boolean zdali se nacteni povedlo
	*/
	bool ReadFile(std::string);
	/**
	*\brief Metoda na tisk jednotlivych zdrojaku a na nich zdrojaku
	*/
	void PrintDependecies();
};


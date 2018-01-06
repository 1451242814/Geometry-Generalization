#pragma once
#include <fstream>
#include <iostream>
#include <vector>
#include "base.h"

int countLins(std::ifstream &ifs);
int parsPoly(std::ifstream &ifs, std::vector<Polylin> &polys);
int parsPoint(std::ifstream &ifs, std::list<CP> &cps);

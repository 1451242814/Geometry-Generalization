#pragma once
#include <list>
#include <vector>
struct Point
{
	double x, y;
};
struct Polylin
{
	int id;
	std::list<Point> points;
};
struct CP
{
	int id;
	double x, y;
};
#include "parser.h"


int countLins(std::ifstream &linstream)
{
	int cnt = 0;
	while (linstream.peek()!=EOF)
	{
		cnt++;
		linstream.ignore(200000, '\n');
	}
	linstream.clear();
	linstream.seekg(0, std::ios::beg);

	return cnt;
}

int parsPoly(std::ifstream &linstream, std::vector<Polylin> &polys)
{
	char c;
	Point p;
	int counts;//通过数>的个数解析字符串，坐标在第二个>的后面
	int linCnt=0;
	int id;

	polys.resize(countLins(linstream));
	while (linstream.peek()!=EOF)
	{

		linstream >> id;
		counts = 0;
		while (counts <= 1)
		{
			linstream >> c;
			counts += (c == '>');
		}

		while (linstream.peek() != '<' && !linstream.eof())
		{
			linstream >> p.x;
			linstream.ignore(20, ',');
			linstream >> p.y;
			linstream.ignore(20,' ');
			polys[linCnt].id = id;
			polys[linCnt].points.push_back(p);
		}

		linCnt++;
		linstream.ignore(1024, '\n');
	}
	return linCnt;
}

int parsPoint(std::ifstream &ptstream, std::list<CP> &cps)
{
	char c;
	CP p;
	int counts;//通过数>的个数解析字符串，坐标在第二个>的后面
	int ptCnt=0;

	while (ptstream.peek()!= EOF)
	{

		ptstream >> p.id;
		counts = 0;
		while (counts <= 1)
		{
			ptstream >> c;
			counts += (c == '>');
		}

		ptstream >> p.x;
		ptstream.ignore(20, ',');
		ptstream >> p.y;
		ptstream.ignore(20,' ');
		cps.push_back(p);

		ptCnt++;
		ptstream.ignore(1024, '\n');
	}
	return ptCnt;
}
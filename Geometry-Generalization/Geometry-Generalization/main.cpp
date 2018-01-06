#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include "base.h"
#include "parser.h"

using namespace std;




//Parser files code begin

//Parser File code end



int main(int argc,char *argv[])
{
	const char *argvv[] = {
		"",
		"",
		"data\\lines_out.txt",
		"data\\points_out.txt"
	};
	
	ifstream linStream, ptStream;

	linStream.open(argvv[2]);
	if (linStream.fail())
	{
		cerr << "Opening lines file failed!" << endl;
		return 1;
	}

	vector<Polylin> polys;
	parsPoly(linStream, polys);

	ptStream.open(argvv[3]);

	list<CP> cps;
	parsPoint(ptStream, cps);
	if (ptStream.fail())
	{
		cerr << "Opening points file failed!" << endl;
		return 1;
	}

	system("pause");

}
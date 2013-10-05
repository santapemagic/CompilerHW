#include "Parser.h"

using namespace std;


int main(int argc, char * argv[])
{

	if(argc != 2)
	{
		cout<<"The command has wrong argument(s)"<<endl;
		system("pause");
		return 0;
	}

	Parser parser(argv[1]);

	//parser->

	return 0;
}
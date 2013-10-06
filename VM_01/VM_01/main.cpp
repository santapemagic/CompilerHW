#include "Parser.h"

using namespace std;

int CodeWriter::TorF = 0;

int main(int argc, char * argv[])
{

	if(argc != 2)
	{
		cout<<"The command has wrong argument(s)"<<endl;
		system("pause");
		return 0;
	}

	Parser* parser = new Parser(argv[1]);
	
	parser->startParsing();

	return 0;
}
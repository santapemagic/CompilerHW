#include "Parser.h"



Parser::Parser(string input)		//�Է¹��� ������ .vm�������� Ȯ��
{		

	string temp(input);				//���� ���ϸ� �ӽ�����
	temp.erase( temp.begin(), temp.end()-2 );

	if( temp.compare( "vm" ) )		//Ȯ���� ���� vm�� �ƴ� ���
	{
		cout<<"Wrong type of file!"<<endl;
		exit(EXIT_FAILURE);
	}

	cout << "file open success!\n";
	system("pause");

	fileName = input;				//���ϸ� �Է�
	fin.open(fileName);				//ifstream ����

	if( !fin.is_open() )			//������ ���������� ������ �ʾ��� ���
	{
		cout << fileName << " does not exist or is corrupted!" << endl;
		exit( EXIT_FAILURE );
		} 

	//������� ���� ���� �Ϸ�


//	���� outputfile ���� �� ���Ϳ� ���پ� ����
// 	string outputFile(fileName);	//��� ���ϸ�
// 	outputFile.erase( outputFile.end()-2, outputFile.end() );
// 	outputFile += "vm";
// 
// 	fout.open( outputFile );		//ofstream ����
// 	while(!fin.eof())
// 	{
// 		string tempCode;
// 		fin>>tempCode;
// 		code.push_back(tempCode);
// 	}
// 	currentCodeNo = -1;
// 	fin.close();
}



// bool Parser::HasMoreCommands()
// {
// 	if ( /*currentCodeNo == code.size()*/ )
// 	{
// 		return false;
// 	}
// 	else
// 	{
// 		return true;
// 	}
// }



void Parser::advance()
{
	currentCodeNo++;

/*	string currentCode = code.at(currentCodeNo);*/
	
//	Command command;
	// ARITHMETIC, POP, PUSH

	char* whilespaces = " \t";

	
}

// CommandType Parser::commandType()
// {
// 	
// }
// 
// std::string Parser::arg1()
// {
// }
// 
// int Parser::arg2()
// {
// }



//���Ϳ� ���� ���� ��ɾ� ���ٴ����� ��� �о ���� -> ���پ� �о ó���ϰ� �Ѿ�� ������.
//�����ϱ����� �ٶ��, ����, �ּ�, ��Ű ��� �����Ұ� �ʿ�<<
//���� ���� ����� �� ������ �Ľ��Ҷ� advance?
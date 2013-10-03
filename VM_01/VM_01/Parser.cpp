#include "Parser.h"



Parser::Parser(string input)		//입력받은 파일이 .vm형식인지 확인
{		

	string temp(input);				//받은 파일명 임시저장
	temp.erase( temp.begin(), temp.end()-2 );

	if( temp.compare( "vm" ) )		//확장자 명이 vm이 아닐 경우
	{
		cout<<"Wrong type of file!"<<endl;
		exit(EXIT_FAILURE);
	}

	cout << "file open success!\n";
	system("pause");

	fileName = input;				//파일명 입력
	fin.open(fileName);				//ifstream 생성

	if( !fin.is_open() )			//파일이 정상적으로 열리지 않았을 경우
	{
		cout << fileName << " does not exist or is corrupted!" << endl;
		exit( EXIT_FAILURE );
	} 
 
//
// 	string outputFile(fileName);	//출력 파일명
// 	outputFile.erase( outputFile.end()-2, outputFile.end() );
// 	outputFile += "vm";
// 
// 	fout.open( outputFile );		//ofstream 생성
	while(!fin.eof())
	{
		string tempCode;
		fin>>tempCode;
		code.push_back(tempCode);
	}
	currentCodeNo = -1;
	fin.close();
}



bool Parser::HasMoreCommands()
{
	if ( currentCodeNo == code.size() )
	{
		return false;
	}
	else
	{
		return true;
	}
}



void Parser::advance()
{
	currentCodeNo++;

	string currentCode = code.at(currentCodeNo);
	
	Command command;
	// ARITHMETIC, POP, PUSH

	char* whilespaces = " \t";
}

CommandType Parser::commandType()
{
	
}

std::string Parser::arg1()
{
}

int Parser::arg2()
{
}


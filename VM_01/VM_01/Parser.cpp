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

	//여기까지 파일 오픈 완료


//	이하 outputfile 설정 및 벡터에 한줄씩 저장
// 	string outputFile(fileName);	//출력 파일명
// 	outputFile.erase( outputFile.end()-2, outputFile.end() );
// 	outputFile += "vm";
// 
// 	fout.open( outputFile );		//ofstream 생성
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



//벡터에 파일 내의 명령어 한줄단위로 모두 읽어서 저장 -> 한줄씩 읽어서 처리하고 넘어가는 식으로.
//저장하기전에 줄띄움, 공백, 주석, 탭키 모두 제거할것 필요<<
//벡터 내에 저장된 한 라인을 파싱할때 advance?
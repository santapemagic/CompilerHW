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


	fileName = input;				//파일명 입력
	fin.open(fileName);				//ifstream 생성

	cout << "Input file: " << fileName << endl;
	if( !fin.is_open() )			//파일이 정상적으로 열리지 않았을 경우
	{
		cout << fileName << " does not exist or is corrupted!" << endl;
		exit( EXIT_FAILURE );
	} 

	cout << "input file open success!\n";
	//여기까지 파일 오픈 완료


	//	이하 outputfile 설정
	string outputFile(fileName);	//출력 파일명
	outputFile.erase( outputFile.end()-2, outputFile.end() );
	outputFile += "asm";				//출력파일명 확장자를 .vm으로

	
	Writer = new CodeWriter( outputFile );

	originalCounter = 0;
	refinedCounter = 0;
}



bool Parser::HasMoreCommands()
{
	do
	{
		getline( fin, command);
		originalCounter++;

		if(fin.eof())
		{
			return 0;
		}

	}
	while(command == "\0"||(command[0]=='/'&&command[1]=='/'));		//공백이거나 주석만 있는 줄이면 넘어감.


	if(fin.eof())
	{
		return 0;
	}
	else
	{
		refinedCounter++;
		return 1;
	}
}



void Parser::advance()
{
	string::size_type blankPos = command.find_first_of(" ");		//공백 제거

	while (blankPos != string::npos) 
	{
		command.replace(blankPos,1,"");
		blankPos = command.find_first_of(" ", blankPos);
	}

	string::size_type tapPos = command.find_first_of("\t");			//탭키 제거

	while (tapPos != string::npos) 
	{
		command.replace(tapPos,1,"");
		tapPos = command.find_first_of("\t", tapPos);
	}

	string::size_type commentPos = command.find_first_of("//");		//주석 제거

	if(commentPos!=string::npos)
	{
		command.replace(commentPos,command.npos-commentPos,"");
	}


	c_type = commandType();

	Partition( c_type );

}

void Parser::startParsing()
{

	while( HasMoreCommands() )
	{
		advance();

		if( c_type != C_RETURN )
		{
			segment = arg1();		//segment에 argument의 segment를 저장
		}

		if( c_type == C_PUSH || c_type ==  C_POP || c_type == C_CALL || c_type == C_FUNCTION )
		{
			index = arg2();			//index 저장
		}

		if( c_type == C_ARITHMETIC )
		{
			Writer->WriteArithmetic( segment );
		}
		else if( c_type == C_PUSH || c_type == C_POP )
		{
			Writer->WritePushPop( c_type, segment, index );
		}
	}

	cout << "Translating is successful!" << endl;
}

CommandType Parser::commandType()
{
	std::size_t pushPS = command.find("push");
	if(pushPS != command.npos)
	{
		return C_PUSH;
	}


	std::size_t popPS = command.find("pop");
	if(popPS != command.npos)
	{
		return C_POP;
	}

	if(command == "add" || command == "sub" || command == "neg" || command == "eq" || command == "gt" || command == "lt" || command == "and" || command == "or" || command == "not")
	{
		return C_ARITHMETIC;
	}
	//	return error;

}

std::string Parser::arg1()
{
	string arg;

	if( c_type == C_ARITHMETIC )	//읽은줄이 arithmetic이면
	{
		arg = command;				//그대로 반환
	}
	
	else
	{
		std::size_t blankPS = command.find_first_of(" ");
		std::size_t first = blankPS;
		blankPS = command.find_first_of(" ",blankPS+1);
		std::size_t second = blankPS; 

		arg = command.substr(first+1,second-first-1);
	}

	return arg;

}

int Parser::arg2()
{
	string result;

	std::size_t blankPS = command.find_first_of(" ");
	blankPS = command.find_first_of(" ",blankPS+1);

	result = command.substr(blankPS+1,command.npos-blankPS);


	return atoi(result.c_str());
}

void Parser::Partition(CommandType currentType)
{

	if(currentType == C_PUSH)
	{
		std::size_t pushPS = command.find("push");

		command.insert(pushPS+4," ");
		std::size_t nextPS = command.find_first_of("0123456789");
		if(nextPS != command.npos)
		{
			command.insert(nextPS," ");
		}
		else
		{
			//			error;
		}

	}
	else if(currentType == C_POP)
	{
		std::size_t popPS = command.find("pop");

		command.insert(popPS+3," ");
		std::size_t nextPS = command.find_first_of("0123456789");
		if(nextPS != command.npos)
		{
			command.insert(nextPS," ");
		}
		else
		{
			//			error;
		}
	}



}


//벡터에 파일 내의 명령어 한줄단위로 모두 읽어서 저장 -> 한줄씩 읽어서 처리하고 넘어가는 식으로.
//읽어들일때 줄띄움, 공백, 주석, 탭키 모두 제거할것 필요<<
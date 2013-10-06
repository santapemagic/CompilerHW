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


	fileName = input;				//���ϸ� �Է�
	fin.open(fileName);				//ifstream ����

	cout << "Input file: " << fileName << endl;
	if( !fin.is_open() )			//������ ���������� ������ �ʾ��� ���
	{
		cout << fileName << " does not exist or is corrupted!" << endl;
		exit( EXIT_FAILURE );
	} 

	cout << "input file open success!\n";
	//������� ���� ���� �Ϸ�


	//	���� outputfile ����
	string outputFile(fileName);	//��� ���ϸ�
	outputFile.erase( outputFile.end()-2, outputFile.end() );
	outputFile += "asm";				//������ϸ� Ȯ���ڸ� .vm����

	
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
	while(command == "\0"||(command[0]=='/'&&command[1]=='/'));		//�����̰ų� �ּ��� �ִ� ���̸� �Ѿ.


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
	string::size_type blankPos = command.find_first_of(" ");		//���� ����

	while (blankPos != string::npos) 
	{
		command.replace(blankPos,1,"");
		blankPos = command.find_first_of(" ", blankPos);
	}

	string::size_type tapPos = command.find_first_of("\t");			//��Ű ����

	while (tapPos != string::npos) 
	{
		command.replace(tapPos,1,"");
		tapPos = command.find_first_of("\t", tapPos);
	}

	string::size_type commentPos = command.find_first_of("//");		//�ּ� ����

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
			segment = arg1();		//segment�� argument�� segment�� ����
		}

		if( c_type == C_PUSH || c_type ==  C_POP || c_type == C_CALL || c_type == C_FUNCTION )
		{
			index = arg2();			//index ����
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

	if( c_type == C_ARITHMETIC )	//�������� arithmetic�̸�
	{
		arg = command;				//�״�� ��ȯ
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


//���Ϳ� ���� ���� ��ɾ� ���ٴ����� ��� �о ���� -> ���پ� �о ó���ϰ� �Ѿ�� ������.
//�о���϶� �ٶ��, ����, �ּ�, ��Ű ��� �����Ұ� �ʿ�<<
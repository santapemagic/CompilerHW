#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <vector>
#include <stdlib.h>

using namespace std;

typedef vector<string> Code;

typedef enum CommandType
{
	C_ARITHMETIC,
	C_PUSH,
	C_POP,
	C_LABEL,
	C_GOTO,
	C_IF,
	C_FUNCTION,
	C_RETURN,
	C_CALL
};

typedef struct _Command
{
	CommandType commandType;
	string		arg1;
	int			arg2;
}Command;

typedef list<Command> CommandList;

class Parser
{
private:
	ifstream fin;		//입력 스트림
	ofstream fout;		//출력 스트림
	Code code;	//
	int	currentCodeNo;
	string fileName;	//입력 파일명
	CommandList outputList;
	

public:
	Parser(string input);		//생성자
	void getReady();		//ready to parse it!
	bool HasMoreCommands();	//읽어들일 command가 있는지 확인
	void advance();			//공백제거

	CommandType commandType();
	string	arg1();
	int		arg2();
//	com_type commandType();	//command 타입 반환



};

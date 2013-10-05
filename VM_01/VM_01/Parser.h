#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;


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

// typedef struct _Command
// {
// 	CommandType commandType;
// 	string		arg1;
// 	int			arg2;
// }Command;


class Parser
{
private:
	ifstream fin;		//입력 스트림
	ofstream fout;		//출력 스트림
	int	currentCodeNo;
	string fileName;	//입력 파일명


public:
	Parser(string input);		//생성자
//	void getReady();		//ready to parse it!	용도 파악
	bool HasMoreCommands();	//읽어들일 command가 있는지 확인
	void advance();			//공백제거

	CommandType commandType();
	string	arg1();
	int		arg2();




};

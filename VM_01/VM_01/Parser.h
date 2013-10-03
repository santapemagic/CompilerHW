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
	ifstream fin;		//�Է� ��Ʈ��
	ofstream fout;		//��� ��Ʈ��
	Code code;	//
	int	currentCodeNo;
	string fileName;	//�Է� ���ϸ�
	CommandList outputList;
	

public:
	Parser(string input);		//������
	void getReady();		//ready to parse it!
	bool HasMoreCommands();	//�о���� command�� �ִ��� Ȯ��
	void advance();			//��������

	CommandType commandType();
	string	arg1();
	int		arg2();
//	com_type commandType();	//command Ÿ�� ��ȯ



};

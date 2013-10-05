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
	ifstream fin;		//�Է� ��Ʈ��
	ofstream fout;		//��� ��Ʈ��
	int	currentCodeNo;
	string fileName;	//�Է� ���ϸ�


public:
	Parser(string input);		//������
//	void getReady();		//ready to parse it!	�뵵 �ľ�
	bool HasMoreCommands();	//�о���� command�� �ִ��� Ȯ��
	void advance();			//��������

	CommandType commandType();
	string	arg1();
	int		arg2();




};

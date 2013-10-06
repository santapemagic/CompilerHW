#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#include "CodeWriter.h"


using namespace std;


class Parser
{
private:
	CodeWriter* Writer;				//�ڵ带 ���� Ŭ����
	
	ifstream fin;					//�Է� ��Ʈ��
	int	currentCodeNo;
	string fileName;				//�Է� ���ϸ�
	string command;					//�޾Ƶ��� Ŀ�ǵ�
	
	CommandType c_type;				//�о���� ��ɾ� Ÿ�� �Ǻ�
	string segment;					//�о���� segment
	int index;						//push, pop ��ɾ��϶� �޾Ƶ��̴� index ��

	int originalCounter;			//���� ������ ī����
	int refinedCounter;				//����, �ּ����� ������ ī����

public:
	Parser(string input);			//������
	
	bool HasMoreCommands();			//�о���� command�� �ִ��� Ȯ��
	
	void startParsing();			//����
	void advance();					//��������
	void Partition(CommandType currentType);

	CommandType commandType();		//��ɾ� Ÿ�� ��ȯ

	string	arg1();					
	int		arg2();


};

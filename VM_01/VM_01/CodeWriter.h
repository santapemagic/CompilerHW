#include <iostream>
#include <fstream>
#include <string>


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

class CodeWriter
{
private:
	string command;
	ofstream outputFile;		//��� ��Ʈ��
	static int TorF;
public:
	CodeWriter( string fileName );
	void SetFileName( string fileName );		//������� ����
	void WriteArithmetic( string command );		//Arithmetic�ڵ� ��ȯ
	void WritePushPop( CommandType command, string segment, int index );	//push, pop �ڵ� ��ȯ
	
	void WriteInit();					
	void WriteLabel( string label );	//label ���� ��ɾ� ��
	void WriteGoto(	string label );		//goto ���� ��ɾ� ��
	void WriteIf( string label );		//if-goto ���� ��ɾ� ��
	void WriteCall( string funcName, int numArg );	//call ���� ��ɾ� ��
	void WriteReturn();					//return ���� ��ɾ� ��
	void WriteFunction( string funcName, int numLocals );	//function ���� ��ɾ� ��
		
};


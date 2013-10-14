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
	ofstream outputFile;		//출력 스트림
	static int TorF;
public:
	CodeWriter( string fileName );
	void SetFileName( string fileName );		//출력파일 오픈
	void WriteArithmetic( string command );		//Arithmetic코드 변환
	void WritePushPop( CommandType command, string segment, int index );	//push, pop 코드 변환
	
	void WriteInit();					
	void WriteLabel( string label );	//label 관련 명령어 씀
	void WriteGoto(	string label );		//goto 관련 명령어 씀
	void WriteIf( string label );		//if-goto 관련 명령어 씀
	void WriteCall( string funcName, int numArg );	//call 관련 명령어 씀
	void WriteReturn();					//return 관련 명령어 씀
	void WriteFunction( string funcName, int numLocals );	//function 관련 명령어 씀
		
};


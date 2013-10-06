#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#include "CodeWriter.h"


using namespace std;


class Parser
{
private:
	CodeWriter* Writer;				//코드를 쓰는 클래스
	
	ifstream fin;					//입력 스트림
	int	currentCodeNo;
	string fileName;				//입력 파일명
	string command;					//받아들인 커맨드
	
	CommandType c_type;				//읽어들인 명령어 타입 판별
	string segment;					//읽어들인 segment
	int index;						//push, pop 명령어일때 받아들이는 index 값

	int originalCounter;			//원본 문서의 카운터
	int refinedCounter;				//공백, 주석등을 제거한 카운터

public:
	Parser(string input);			//생성자
	
	bool HasMoreCommands();			//읽어들일 command가 있는지 확인
	
	void startParsing();			//시작
	void advance();					//공백제거
	void Partition(CommandType currentType);

	CommandType commandType();		//명령어 타입 반환

	string	arg1();					
	int		arg2();


};

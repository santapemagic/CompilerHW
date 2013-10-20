#include "CodeWriter.h"

static int temp=0;

CodeWriter::CodeWriter( string fileName )
{
	SetFileName( fileName );
}

void CodeWriter::SetFileName( string fileName )
{
	outputFile.open( fileName );		//출력파일 열기

	if(!outputFile.is_open())
	{
		cout<< fileName <<" output file error"<<endl;
		exit(EXIT_FAILURE);
	}
	cout << "Output: " <<fileName << endl;
	cout << "Output file open success!" << endl;
}



void CodeWriter::WriteArithmetic( string command )
{
	if(command =="add")
	{
//		outputFile<<"//ADD"<<endl;
		outputFile<<"@SP"<<endl;
		outputFile<<"A=M-1"<<endl;		//스택포인터 1감소인듯?
		outputFile<<"D=M"<<endl;
		outputFile<<"A=A-1"<<endl;
		outputFile<<"D=D+M"<<endl;
		outputFile<<"M=D"<<endl;
		outputFile<<"@SP"<<endl;
		outputFile<<"M=M-1"<<endl;		//스택포인터 1감소?
		outputFile<<endl;

	}
	else if(command == "sub")
	{
//		outputFile<<"//SUB"<<endl;
		outputFile<<"@SP"<<endl;
		outputFile<<"A=M-1"<<endl;
		outputFile<<"D=M"<<endl;
		outputFile<<"A=A-1"<<endl;
		outputFile<<"D=M-D"<<endl;
		outputFile<<"M=D"<<endl;
		outputFile<<"@SP"<<endl;
		outputFile<<"M=M-1"<<endl;
		outputFile<<endl;
	}
	else if(command == "neg")
	{
//		outputFile<<"//NEG"<<endl;
		outputFile<<"@SP"<<endl;
		outputFile<<"A=M-1"<<endl;
		outputFile<<"D=-M"<<endl;
		outputFile<<"M=D"<<endl;
		outputFile<<endl;
	}
	else if(command == "eq")
	{
//		outputFile<<"//EQ"<<endl;
		outputFile<<"@SP"<<endl;
		outputFile<<"A=M-1"<<endl;
		outputFile<<"D=M"<<endl;
		outputFile<<"A=A-1"<<endl;
		outputFile<<"D=M-D"<<endl;
		outputFile<<"@STARTTRUTH"<<TorF<<endl;
		outputFile<<"D;JNE"<<endl;
		outputFile<<"@SP"<<endl;
		outputFile<<"A=M-1"<<endl;
		outputFile<<"A=A-1"<<endl;
		outputFile<<"M=-1"<<endl;
		outputFile<<"@SP"<<endl;
		outputFile<<"M=M-1"<<endl;
		outputFile<<"@ENDTRUTH"<<TorF<<endl;
		outputFile<<"0;JMP"<<endl;
		outputFile<<"(STARTTRUTH"<<TorF<<")"<<endl;
		outputFile<<"@SP"<<endl;
		outputFile<<"A=M-1"<<endl;
		outputFile<<"A=A-1"<<endl;
		outputFile<<"M=0"<<endl;
		outputFile<<"@SP"<<endl;
		outputFile<<"M=M-1"<<endl;
		outputFile<<"(ENDTRUTH"<<TorF<<")"<<endl;
		outputFile<<endl;

		TorF++;

	}
	else if(command == "gt")
	{
//		outputFile<<"//EQ"<<endl;
		outputFile<<"@SP"<<endl;
		outputFile<<"A=M-1"<<endl;
		outputFile<<"D=M"<<endl;
		outputFile<<"A=A-1"<<endl;
		outputFile<<"D=M-D"<<endl;
		outputFile<<"@STARTTRUTH"<<TorF<<endl;
		outputFile<<"D;JLE"<<endl;
		outputFile<<"@SP"<<endl;
		outputFile<<"A=M-1"<<endl;
		outputFile<<"A=A-1"<<endl;
		outputFile<<"M=-1"<<endl;
		outputFile<<"@SP"<<endl;
		outputFile<<"M=M-1"<<endl;
		outputFile<<"@ENDTRUTH"<<TorF<<endl;
		outputFile<<"0;JMP"<<endl;
		outputFile<<"(STARTTRUTH"<<TorF<<")"<<endl;
		outputFile<<"@SP"<<endl;
		outputFile<<"A=M-1"<<endl;
		outputFile<<"A=A-1"<<endl;
		outputFile<<"M=0"<<endl;
		outputFile<<"@SP"<<endl;
		outputFile<<"M=M-1"<<endl;
		outputFile<<"(ENDTRUTH"<<TorF<<")"<<endl;
		outputFile<<endl;

		TorF++;

	}
	else if(command == "lt")
	{
//		outputFile<<"//EQ"<<endl;
		outputFile<<"@SP"<<endl;
		outputFile<<"A=M-1"<<endl;
		outputFile<<"D=M"<<endl;
		outputFile<<"A=A-1"<<endl;
		outputFile<<"D=M-D"<<endl;
		outputFile<<"@STARTTRUTH"<<TorF<<endl;
		outputFile<<"D;JGE"<<endl;
		outputFile<<"@SP"<<endl;
		outputFile<<"A=M-1"<<endl;
		outputFile<<"A=A-1"<<endl;
		outputFile<<"M=-1"<<endl;
		outputFile<<"@SP"<<endl;
		outputFile<<"M=M-1"<<endl;
		outputFile<<"@ENDTRUTH"<<TorF<<endl;
		outputFile<<"0;JMP"<<endl;
		outputFile<<"(STARTTRUTH"<<TorF<<")"<<endl;
		outputFile<<"@SP"<<endl;
		outputFile<<"A=M-1"<<endl;
		outputFile<<"A=A-1"<<endl;
		outputFile<<"M=0"<<endl;
		outputFile<<"@SP"<<endl;
		outputFile<<"M=M-1"<<endl;
		outputFile<<"(ENDTRUTH"<<TorF<<")"<<endl;
		outputFile<<endl;

		TorF++;

	}
	else if(command == "and")
	{
//		outputFile<<"//AND"<<endl;
		outputFile<<"@SP"<<endl;
		outputFile<<"A=M-1"<<endl;
		outputFile<<"D=M"<<endl;
		outputFile<<"A=A-1"<<endl;
		outputFile<<"D=D&M"<<endl;
		outputFile<<"M=D"<<endl;
		outputFile<<"@SP"<<endl;
		outputFile<<"M=M-1"<<endl;
		outputFile<<endl;
	}
	else if(command == "or")
	{
//		outputFile<<"//OR"<<endl;
		outputFile<<"@SP"<<endl;
		outputFile<<"A=M-1"<<endl;
		outputFile<<"D=M"<<endl;
		outputFile<<"A=A-1"<<endl;
		outputFile<<"D=D|M"<<endl;
		outputFile<<"M=D"<<endl;
		outputFile<<"@SP"<<endl;
		outputFile<<"M=M-1"<<endl;
		outputFile<<endl;
	}
	else if(command == "not")
	{
//		outputFile<<"//NOT"<<endl;
		outputFile<<"@SP"<<endl;
		outputFile<<"A=M-1"<<endl;
		outputFile<<"D=!M"<<endl;
		outputFile<<"M=D"<<endl;
		outputFile<<endl;
	}
	else
	{
		//error;		
	}



}



void CodeWriter::WritePushPop( CommandType command, string segment, int index )
{
	if( command == C_PUSH )
	{
		outputFile<<"//PUSH"<<endl;
		if(segment == "constant")
		{
			outputFile<<"@"<<index<<endl;
			outputFile<<"D=A"<<endl;
			outputFile<<"@SP"<<endl;
			outputFile<<"A=M"<<endl;
			outputFile<<"M=D"<<endl;
			outputFile<<"@SP"<<endl;
			outputFile<<"M=M+1"<<endl;
			outputFile<<endl;

		}
		else if(segment == "argument")
		{
			outputFile<<"@"<<index<<endl;
			outputFile<<"D=A"<<endl;
			outputFile<<"@ARG"<<endl;
			outputFile<<"A=M+D"<<endl;
			outputFile<<"D=M"<<endl;
			outputFile<<"@SP"<<endl;
			outputFile<<"A=M"<<endl;
			outputFile<<"M=D"<<endl;
			outputFile<<"@SP"<<endl;
			outputFile<<"M=M+1"<<endl;
			outputFile<<endl;
		}
		else if(segment == "local")
		{
			outputFile<<"@"<<index<<endl;
			outputFile<<"D=A"<<endl;
			outputFile<<"@LCL"<<endl;
			outputFile<<"A=M+D"<<endl;
			outputFile<<"D=M"<<endl;
			outputFile<<"@SP"<<endl;
			outputFile<<"A=M"<<endl;
			outputFile<<"M=D"<<endl;
			outputFile<<"@SP"<<endl;
			outputFile<<"M=M+1"<<endl;
			outputFile<<endl;
		}
		else
		{
			//error
		}

	}
	else if( command == C_POP)
	{
		outputFile<<"//POP"<<endl;
		if(segment == "argument")
		{
			outputFile<<"@"<<index<<endl;
			outputFile<<"D=A"<<endl;
			outputFile<<"@ARG"<<endl;
			outputFile<<"D=M+D"<<endl;
			outputFile<<"@SP"<<endl;
			outputFile<<"A=M"<<endl;
			outputFile<<"M=D"<<endl;
			outputFile<<"@SP"<<endl;
			outputFile<<"A=M-1"<<endl;
			outputFile<<"D=M"<<endl;
			outputFile<<"A=A+1"<<endl;
			outputFile<<"A=M"<<endl;
			outputFile<<"M=D"<<endl;
			outputFile<<endl;
		}
		else if(segment == "local")
		{
			outputFile<<"@"<<index<<endl;
			outputFile<<"D=A"<<endl;
			outputFile<<"@LCL"<<endl;
			outputFile<<"D=M+D"<<endl;
			outputFile<<"@SP"<<endl;
			outputFile<<"A=M"<<endl;
			outputFile<<"M=D"<<endl;
			outputFile<<"@SP"<<endl;
			outputFile<<"A=M-1"<<endl;
			outputFile<<"D=M"<<endl;
			outputFile<<"A=A+1"<<endl;
			outputFile<<"A=M"<<endl;
			outputFile<<"M=D"<<endl;
			outputFile<<endl;
		}
	}
	else
	{
		//error
	}
}

void CodeWriter::WriteInit()
{

	//THIS, THAT, POINTER, ARG, LCL등등을 초기화해줘야함
}

void CodeWriter::WriteLabel( string label )
{
	outputFile << "(" << label << ")" << endl;
}	
//완

void CodeWriter::WriteGoto( string label )
{
	outputFile << "@" << label << endl;
	outputFile << "0;JMP" << endl;
}	 
//완 

void CodeWriter::WriteIf( string label )
{
	outputFile << "@SP" << endl;
	outputFile << "A=M-1" << endl;
	outputFile << "D=M" << endl;
	outputFile << "@" << label << endl;
	outputFile << "D;JNE" << endl;
}	
//완

void CodeWriter::WriteCall( string funcName, int numArg )
{

	string ret1;
	ret1 = "RETURNADRRESS"+temp;

	//push returnAddress
	outputFile << "@SP" << endl;
	outputFile << "D=M" << endl;
	outputFile << "@RETURNADDRESS" << temp++ << endl;
	outputFile << "A=D" << endl;

	//push LCL
	outputFile << "@LCL" << endl;
	outputFile << "D=A" << endl;
	outputFile << "@SP" << endl;
	outputFile << "A=M" << endl;
	outputFile << "M=D" << endl;
	outputFile << "@SP" << endl;
	outputFile << "M=M+1" << endl;

	//push ARG
	outputFile << "@ARG" << endl;
	outputFile << "D=A" << endl;
	outputFile << "@SP" << endl;
	outputFile << "A=M" << endl;
	outputFile << "M=D" << endl;
	outputFile << "@SP" << endl;
	outputFile << "M=M+1" << endl;

	//push THIS
	outputFile << "@THIS" << endl;
	outputFile << "D=A" << endl;
	outputFile << "@SP" << endl;
	outputFile << "A=M" << endl;
	outputFile << "M=D" << endl;
	outputFile << "@SP" << endl;
	outputFile << "M=M+1" << endl;

	//push THAT
	outputFile << "@THAT" << endl;
	outputFile << "D=A" << endl;
	outputFile << "@SP" << endl;
	outputFile << "A=M" << endl;
	outputFile << "M=D" << endl;
	outputFile << "@SP" << endl;
	outputFile << "M=M+1" << endl;

	//ARG = SP-nArgs-5
	outputFile << "@5" << endl;
	outputFile << "D=A" << endl;
	outputFile << "@" << numArg << endl;
	outputFile << "A=A+D" << endl;		//이게 맞나?
	outputFile << "D=A" << endl;
	outputFile << "@SP" << endl;
	outputFile << "A=M-D" << endl;
	outputFile << "D=A" << endl;
	outputFile << "@ARG" << endl;
	outputFile << "A=D" << endl;
	
	//LCL = SP
	outputFile << "@SP"	<< endl;
	outputFile << "D=A" << endl;
	outputFile << "@LCL" << endl;
	outputFile << "A=D" << endl;

	//goto g			//함수 정의부로 ㄱㄱ
	outputFile << "@" << funcName << endl;
	outputFile << "0;JMP" << endl;

	//returnAddress:	//함수 실행이 끝나고 돌아올 위치
	outputFile << "(" << ret1 << ")" << endl;
	//이게 맞나??

}
//완

void CodeWriter::WriteReturn()
{
	// frame = LCL
	outputFile << "@LCL" << endl;
	outputFile << "D=M" << endl;
	outputFile << "@FRAME" << endl;
	outputFile << "M=D" << endl;
	
	//retAddr = *(frame-5)
	outputFile << "@5" << endl;
	outputFile << "D=A" << endl;
	outputFile << "@FRAME" << endl;
	outputFile << "A=M-D" << endl;
	outputFile << "D=M" << endl;
	outputFile << "@RET" << endl;
	outputFile << "M=D" << endl;

	//WritePushPop();			//스택 최상위값을 현재 ARG[0]위치에 리턴값으로 저장
	WritePushPop( C_POP,  "argument", 0);

	//SP=ARG+1
	outputFile << "@ARG" << endl;
	outputFile << "D=M+1" << endl;
	outputFile << "@SP" << endl;
	outputFile << "M=D" << endl;

	//THAT = *(frame-1)
	outputFile << "@1" << endl;
	outputFile << "D=A" << endl;
	outputFile << "@FRAME" << endl;
	outputFile << "A=M-D" << endl;
	outputFile << "D=M" << endl;
	outputFile << "@THAT" << endl;
	outputFile << "M=D" << endl;

	//THIS = *(frame-2)
	outputFile << "@3" << endl;
	outputFile << "D=A" << endl;
	outputFile << "@FRAME" << endl;
	outputFile << "A=M-D" << endl;
	outputFile << "D=M" << endl;
	outputFile << "@THIS" << endl;
	outputFile << "M=D" << endl;

	//ARG = *(frame-3)
	outputFile << "@3" << endl;
	outputFile << "D=A" << endl;
	outputFile << "@FRAME" << endl;
	outputFile << "A=M-D" << endl;
	outputFile << "D=M" << endl;
	outputFile << "@ARG" << endl;
	outputFile << "M=D" << endl;

	//LCL = *(frame-4)
	outputFile << "@4" << endl;
	outputFile << "D=A" << endl;
	outputFile << "@FRAME" << endl;
	outputFile << "A=M-D" << endl;
	outputFile << "D=M" << endl;
	outputFile << "@LCL" << endl;
	outputFile << "M=D" << endl;

	//goto retAddr
	outputFile << "@RET" << endl;
	outputFile << "0;JMP" << endl;
	
}
//완

void CodeWriter::WriteFunction( string funcName, int numLocals )
{
	//g:
	outputFile << "(" << funcName << ")" << endl;

	//repeat nVars times
	//push 0
	for( int i=0; i<numLocals; i++ )
	{
		outputFile<< "@0" <<endl;
		outputFile<< "D=A" <<endl;
		outputFile<< "@SP" <<endl;
		outputFile<< "A=M" <<endl;
		outputFile<< "M=D" <<endl;
		outputFile<< "@SP" <<endl;
		outputFile<< "M=M+1" <<endl;
	}
}
//완


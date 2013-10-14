#include "CodeWriter.h"


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
		outputFile<<"A=M-1"<<endl;
		outputFile<<"D=M"<<endl;
		outputFile<<"A=A-1"<<endl;
		outputFile<<"D=D+M"<<endl;
		outputFile<<"M=D"<<endl;
		outputFile<<"@SP"<<endl;
		outputFile<<"M=M-1"<<endl;
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

}

void CodeWriter::WriteLabel( string label )
{

}

void CodeWriter::WriteGoto( string label )
{

}

void CodeWriter::WriteIf( string label )
{

}

void CodeWriter::WriteCall( string funcName, int numArg )
{

}

void CodeWriter::WriteReturn()
{

}

void CodeWriter::WriteFunction( string funcName, int numLocals )
{

}



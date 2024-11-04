#pragma once
#include"Stack.h"

enum TOKENTYPE { PLUS, MINUS, MULTI, DIVIDE, NUMBER, BLANK, END };

class Calc {
private:
	char* m_postfix;	//후위 표기 수식
	ArrayStack<float> m_stack;		//수식의 숫자를 관리하는 스택
	ArrayStack<TOKENTYPE> m_tokenstack;		//수식의 연산자를 저장하는 스택
	float m_result;
	int m_curReadPos;

public:
	Calc(int Max = 100) : m_result(0),m_curReadPos(0){
		m_postfix = new char[Max];
	}
	~Calc(){
		if (m_postfix) delete[] m_postfix;
	}
	void SetPostfix(const char* str);		//후위수식을 m_postfix에 복사
	TOKENTYPE GetToken(char* token);				//문자열을 토큰으로 파싱
	void Calculate();							//stack을 이용하여 수식을 계산

	void infixTopostfix();

	float GetResult() { return m_result; }
	void Draw();
};
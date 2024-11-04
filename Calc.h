#pragma once
#include"Stack.h"

enum TOKENTYPE { PLUS, MINUS, MULTI, DIVIDE, NUMBER, BLANK, END };

class Calc {
private:
	char* m_postfix;	//���� ǥ�� ����
	ArrayStack<float> m_stack;		//������ ���ڸ� �����ϴ� ����
	ArrayStack<TOKENTYPE> m_tokenstack;		//������ �����ڸ� �����ϴ� ����
	float m_result;
	int m_curReadPos;

public:
	Calc(int Max = 100) : m_result(0),m_curReadPos(0){
		m_postfix = new char[Max];
	}
	~Calc(){
		if (m_postfix) delete[] m_postfix;
	}
	void SetPostfix(const char* str);		//���������� m_postfix�� ����
	TOKENTYPE GetToken(char* token);				//���ڿ��� ��ū���� �Ľ�
	void Calculate();							//stack�� �̿��Ͽ� ������ ���

	void infixTopostfix();

	float GetResult() { return m_result; }
	void Draw();
};
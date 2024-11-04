#include"Calc.h"
#include<iostream>

using namespace std;

void Calc::SetPostfix(const char* str)
{
	memcpy(m_postfix, str, strlen(str) + 1);
}

//*token : �о���� �����͸� �����ϱ� ���� ����
TOKENTYPE Calc::GetToken(char* token)
{
	int tokenIndex = 0;
	switch (m_postfix[m_curReadPos]) {
	case '+':
		token[tokenIndex++] = m_postfix[m_curReadPos++];
		token[tokenIndex] = '\0';
		return PLUS;

	case '-':
		token[tokenIndex++] = m_postfix[m_curReadPos++];
		token[tokenIndex] = '\0';
		return MINUS;

	case '*':
		token[tokenIndex++] = m_postfix[m_curReadPos++];
		token[tokenIndex] = '\0';
		return MULTI;

	case '/':
		token[tokenIndex++] = m_postfix[m_curReadPos++];
		token[tokenIndex] = '\0';
		return DIVIDE;

	case ' ':
		m_curReadPos++;
		return BLANK;

	case '\0':
	case '=':
		return END;

	default:	//����
		while(m_postfix[m_curReadPos]>='0'&& m_postfix[m_curReadPos] <= '9')
			token[tokenIndex++] = m_postfix[m_curReadPos++];
		token[tokenIndex] = '\0';
		return NUMBER;
	}

	return END;
}

void Calc::Calculate()
{
	float popVal1;
	float popVal2;
	float number = 0.0f;	//���ڿ� ���ڸ� �Ǽ��� ��ȯ�Ͽ� ����
	char token[20];

	m_curReadPos = 0;
	TOKENTYPE curToken;

	while ((curToken = GetToken(token)) != END) {
		switch (curToken)
		{
		case PLUS:
			popVal2 = m_stack.Top();
			m_stack.Pop();
			popVal1 = m_stack.Top();
			m_stack.Pop();
			
			m_stack.Push(popVal1 + popVal2);
			break;

		case MINUS:
			popVal2 = m_stack.Top();
			m_stack.Pop();
			popVal1 = m_stack.Top();
			m_stack.Pop();

			m_stack.Push(popVal1 - popVal2);
			break;

		case MULTI:
			popVal2 = m_stack.Top();
			m_stack.Pop();
			popVal1 = m_stack.Top();
			m_stack.Pop();

			m_stack.Push(popVal1 * popVal2);
			break;

		case DIVIDE:
			popVal2 = m_stack.Top();
			m_stack.Pop();
			popVal1 = m_stack.Top();
			m_stack.Pop();

			m_stack.Push(popVal1 / popVal2);
			break;

		case NUMBER:	//���ڷ� ��ȯ�Ͽ� Push()
			for (int i = 0; token[i] != '\0'; i++)	number = 10.0 * number + token[i] - '0';
			m_stack.Push(number);
			break;
		case BLANK:
			break;
		case END:
			break;
		}
	}
	m_result = m_stack.Top();
	m_stack.Pop();
}

void Calc::infixTopostfix()
{
}

void Calc::Draw()
{
	cout << " PostFix : " << m_postfix << " = " << m_result << endl;
}

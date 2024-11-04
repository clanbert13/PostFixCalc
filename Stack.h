#pragma once
template<class T>

class ArrayStack {
private:
	T* m_data;
	int m_top;
	int m_max;

public:
	ArrayStack(int Max = 50) : m_max(Max), m_top(0) { m_data = new T[Max]; }
	~ArrayStack() { delete[] m_data; }

	void Push(const T item) {
		if (!Full()) {
			m_data[m_top] = item;
			m_top++;
		}
	}

	T Pop() {
		if (!Empty()) {
			T temp;
			temp = m_data[m_top - 1];
			m_data[m_top - 1] = '\0';
			m_top--;
			return temp;
		}
	}
	int Top() { return m_top; }
	bool Empty() { return m_top == 0; }
	bool Full() { return m_top == m_max; }

	int GetSize() { return m_max; }
};
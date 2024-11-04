#include"Calc.h"

int main() {
	Calc calc(100);

	char postfixFormula[] = "2 5 + 3 * 1 -";
	//char postfixFormula[] = "3 5 10+/";
	calc.SetPostfix(postfixFormula);

	calc.Calculate();
	calc.Draw();

	return 0;
}
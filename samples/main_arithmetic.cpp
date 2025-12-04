#include <arithmetic.h>
#include <string>
using namespace std;
int main()
{
	int flag = 1;
	do {
		cout << "\nwrite expression\nPossible operators: -a, a+b, a-b, a*b, a/b, sqrt(a), ln(a), log2(a), log10(a), sin(a), cos(a), tan(a), asin(a), acos(a), atan(a)\nPossible constants: pi, e\nFunctions require brackets to work correctly\nDo not use spaces"<<endl;
		string in;
		cin >> in;
		try {
			postfix expression(in);
			do {
				double res = expression.calculate();
				cout << res << "\nEnter number\n0 - exit\n1 - calculate new expression\n2 - calculate this expression with new variable values" << endl;
				cin >> flag;
				while (flag != 0 && flag != 1 && flag != 2) {
					cout << "wrong input";
					cin >> flag;
				}
			} while (flag == 2);
		}
		catch (const int i) {
			cout << "invalid expression in symbol number " << i << endl;
		}
	} while (flag != 0);
}

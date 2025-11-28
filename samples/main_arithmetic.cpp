#include <arithmetic.h>
#include <string>
using namespace std;
int main()
{
	int flag = 1;
	do {
		cout << "write expression\nPossible operators: -a, a+b, a-b, a*b, a/b, sqrt(a), pow(a,b), ln(a), log2(a), log10(a), sin(a), cos(a), tan(a), asin(a), acos(a), atan(a)\nPossible constants: pi, e\nFunctions require brackets to work correctly\nDo not use spaces"<<endl;
		string in;
		cin >> in;
		postfix expression(in);
		double res = expression.calculate();
		cout << res << "\nEnter number\n0 - exit\n1 - calculate new expression" << endl;
		cin >> flag;
		while (flag != 0 && flag != 1) {
			cout << "wrong input";
			cin >> flag;
		}
	} while (flag != 0);
}

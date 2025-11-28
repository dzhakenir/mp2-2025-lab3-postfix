#define _USE_MATH_DEFINES
#include <arithmetic.h>
#include <math.h>
bool match(const string& s, int ind, string s2) {
	int len = s2.size();
	if (ind + len > s.size())return false;
	for (int i = 0; i < len; i++)if (s[ind + i] != s2[i])return false;
	return true;
}
postfix::postfix(const string& s) {
	stack<token> t;
	token next;
	token prev=token(EMPTY);
	int brackets = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '-') {
			if (tokens.is_empty() || t.get().type == LEFT_BRACKET)next = token(UNARY_MINUS, 4);
			else next = token(MINUS, 2);
		}
		else if (s[i] == '+')next = token(PLUS, 2);
		else if (s[i] == '*')next = token(MUL, 3);
		else if (s[i] == '/')next = token(DIV, 3);
		else if (s[i] == 'e'){
			prev = token(NUMBER,1);
			tokens.push(token(NUMBER, 1,M_E));
			continue;
		}
		else if (match(s, i, "pi")) {
			tokens.push(token(NUMBER, 1, M_PI));
			prev = token(NUMBER,1);
			i++;
			continue;
		}
		else if (match(s, i, "ln")) {
			next = token(LN, 5);
			i++;
		}
		else if (match(s, i, "sin")) {
			next = token(SIN, 5);
			i += 2;
		}
		else if (match(s, i, "cos")) {
			next = token(COS, 5);
			i += 2;
		}
		else if (match(s, i, "tan")) {
			next = token(TAN, 5);
			i += 2;
		}
		else if (match(s, i, "pow")) {
			next = token(POW, 5);
			i += 2;
		}
		else if (match(s, i, "asin")) {
			next = token(ASIN, 5);
			i += 3;
		}
		else if (match(s, i, "acos")) {
			next = token(ACOS, 5);
			i += 3;
		}
		else if (match(s, i, "atan")) {
			next = token(ATAN, 5);
			i += 3;
		}
		else if (match(s, i, "log2")) {
			next = token(LOG2, 5);
			i += 3;
		}
		else if (match(s, i, "sqrt")) {
			next = token(SQRT, 5);
			i += 3;
		}
		else if (match(s, i, "log10")) {
			next = token(LOG10, 5);
			i += 4;
		}
		else if (s[i] >= '0' && s[i] <= '9') {
			if (prev.type == NUMBER || prev.prior == 1 || prev.prior >= 5)throw runtime_error("invalid expression");
			double res = s[i] - '0';
			i++;
			while (s[i] >= '0' && s[i] <= '9') {
				res = res * 10 + s[i] - '0';
				i++;
			}
			if (s[i] == '.') {
				int j = 0;
				i++;
				while (s[i] >= '0' && s[i] <= '9') {
					res = res * 10 + s[i] - '0';
					j++;
					i++;
				}
				res /= pow(10, j);
			}
			i--;
			tokens.push(token(NUMBER,1, res));
			prev = token(NUMBER,1);
			continue;
		}
		else if (s[i] == ' ')continue;
		else if (s[i] == '(') {
			t.push(LEFT_BRACKET);
			prev = token(LEFT_BRACKET);
			brackets++;
			continue;
		}
		else if (s[i] == ')') {
			if (prev.type != NUMBER && prev.prior != 1 && prev.prior <= 5 && prev.type!=RIGHT_BRACKET || brackets==0)throw runtime_error("invalid expression");
			brackets--;
			while (t.get().type != LEFT_BRACKET)tokens.push(t.pop());
			t.pop();
			prev = token(RIGHT_BRACKET,1);
			continue;
		}
		else if (s[i] == ',') {
			prev = token(COMMA);
			continue;
		}
		else throw runtime_error("invalid expression");
		if (next.prior == 2 && next.prior == 3 && (prev.prior >= 2 && prev.prior <= 5 || prev.prior == 0) || next.prior==4 && prev.prior!=0 || next.prior == 5 && (prev.prior == 1 || prev.prior == 5))throw runtime_error("invalid_expression");
		while (!t.is_empty() && t.get().prior >= next.prior)tokens.push(t.pop());
		t.push(next);
		prev = next;
	}
	while (!t.is_empty())tokens.push(t.pop());
}

double postfix::calculate() {
	stack<token> inv;
	stack<double> res;
	while (!tokens.is_empty())
		inv.push(tokens.pop());
	while (inv.size() > 0) {
		token t = inv.pop();
		tokens.push(t);
		if (t.type == NUMBER)res.push(t.value);
		else if (t.type == PLUS) {
			double a = res.pop();
			double b = res.pop();
			res.push(a + b);
		}
		else if (t.type == MINUS) {
			double a = res.pop();
			double b = res.pop();
			res.push(b - a);
		}
		else if (t.type == MUL) {
			double a = res.pop();
			double b = res.pop();
			res.push(a * b);
		}
		else if (t.type == DIV) {
			double a = res.pop();
			double b = res.pop();
			res.push(b / a);
		}
		else if (t.type == POW) {
			double a = res.pop();
			double b = res.pop();
			res.push(pow(b, a));
		}
		else if (t.type == SIN) {
			double a = res.pop();
			res.push(sin(a));
		}
		else if (t.type == COS) {
			double a = res.pop();
			res.push(cos(a));
		}
		else if (t.type == TAN) {
			double a = res.pop();
			res.push(tan(a));
		}
		else if (t.type == SQRT) {
			double a = res.pop();
			res.push(sqrt(a));
		}
		else if (t.type == ASIN) {
			double a = res.pop();
			res.push(asin(a));
		}
		else if (t.type == ACOS) {
			double a = res.pop();
			res.push(acos(a));
		}
		else if (t.type == ATAN) {
			double a = res.pop();
			res.push(atan(a));
		}
		else if (t.type == UNARY_MINUS) {
			double a = res.pop();
			res.push(-a);
		}
		else if (t.type == LN) {
			double a = res.pop();
			res.push(log(a));
		}
		else if (t.type == LOG2) {
			double a = res.pop();
			res.push(log2(a));
		}
		else if (t.type == LOG10) {
			double a = res.pop();
			res.push(log10(a));
		}
	}
	return res.pop();
}

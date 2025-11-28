
#ifndef __POSTFIX_H__
#define __POSTFIX_H__
#include <stack.h>
#include <string>

using namespace std;

enum TokenType {
    EMPTY,
    COMMA, LEFT_BRACKET, RIGHT_BRACKET,
    VARIABLE, NUMBER, PI, E,
    PLUS, MINUS, MUL, DIV, UNARY_MINUS, POW, 
    SQRT, LN, LOG2, LOG10,
    SIN, COS, TAN, ACOS, ASIN, ATAN
};

struct var {
    string name;
    bool given;
    double val;
    var(string a) :name(a), given(false) {};
};//У чисел нет приоритета, у функций - значения

struct token {
    TokenType type;
    double value;
    int prior;
    token(TokenType t = EMPTY, int pr = 0, double val = 0) noexcept :type(t), value(val), prior(pr) {}
};

class postfix {
private:
    stack<token> tokens;
public:
    postfix(const string& s);
    double calculate();
};
#endif
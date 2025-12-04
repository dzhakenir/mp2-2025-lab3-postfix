
#ifndef __POSTFIX_H__
#define __POSTFIX_H__
#include <stack.h>
#include <string>

using namespace std;

enum TokenType {
    EMPTY,
    COMMA, LEFT_BRACKET, RIGHT_BRACKET,
    NUMBER, PI, E, X, Y, Z,
    PLUS, MINUS, MUL, DIV, UNARY_MINUS, POW, 
    SQRT, LN, LOG2, LOG10,
    SIN, COS, TAN, ACOS, ASIN, ATAN
};

struct var {
    bool given;
    double val;
    var() :given(false) {};
    var(double t) :given(true), val(t) {}
};

struct token {
    TokenType type;
    double value;
    int kind; //0 - пустота и левая скобка, 1 - переменные, числа, константы и правая скобка, 2 - + и -, 3 - * и /, 4 - унарный минус, 5 - функции
    token(TokenType t = EMPTY, int pr = 0, double val = 0) noexcept :type(t), value(val), kind(pr) {}
};//У операторов value всегда равно 0, kind - приоритет операции

class postfix {
private:
    stack<token> tokens;
public:
    postfix(const string& s);
    double calculate(var x = var(), var y = var(), var z = var());
};
#endif

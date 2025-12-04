// тесты для вычисления арифметических выражений
#define _USE_MATH_DEFINES

#include <gtest.h>
#include <arithmetic.h>
double pi = M_PI;
double e = M_E;
TEST(postfix, test_1) {
	EXPECT_EQ(postfix("1+2").calculate(),3);
}
TEST(postfix, test_2) {
	EXPECT_EQ(postfix("3*5").calculate(), 15);
}
TEST(postfix, test_3) {
	EXPECT_EQ(postfix("6/4").calculate(), 6.0/4);
}
TEST(postfix, test_4) {
	EXPECT_EQ(postfix("sin(cos(2))").calculate(), sin(cos(2)));
}
TEST(postfix, test_5) {
	EXPECT_EQ(postfix("x*y+z").calculate(2,3,4), 10);
}
TEST(postfix, test_6) {
	EXPECT_EQ(postfix("sqrt(cos(1)*sin(2)-tan(pi*e))*10/33").calculate(), sqrt(cos(1) * sin(2) - tan(pi * e)) * 10 / 33);
}
TEST(postfix, test_7) {
	EXPECT_EQ(postfix("3*4/5*6/7").calculate(), 3.0 * 4 / 5 * 6 / 7);
}
TEST(postfix, test_8) {
	EXPECT_EQ(postfix("5/(6+7)*3*(3+(5+6)*4)/4+4").calculate(), 5.0 / (6 + 7) * 3 * (3 + (5 + 6) * 4) / 4 + 4);
}
TEST(postfix, test_9) {
	EXPECT_EQ(postfix("sin(12*cos(4)/5+sqrt(123*pi/e)*32)/ln(43*29-98/log2(63)+498*log10(399998))").calculate(), sin(12 * cos(4) / 5 + sqrt(123 * pi / e) * 32) / log(43 * 29 - 98 / log2(63) + 498 * log10(399998)));
}
TEST(postfix, test_10) {
	EXPECT_EQ(postfix("-3+(-4)*(-5)-6*(-3)/(-4)+(-6)").calculate(), -3.0 + (-4.0) * (-5) - 6.0 * (-3) / (-4) + (-6));
}
TEST(postfix, test_11) {
	string s = "1";
	for (int i = 0; i < 100000; i++)s += "+1";
	EXPECT_EQ(postfix(s).calculate(), 1e5+1);
}
TEST(postfix, test_12) {
	EXPECT_EQ(postfix("4-3").calculate(), 1);
}
TEST(postfix, test_13) {
	double x = 12, y = 23, z = 34;
	EXPECT_EQ(postfix("sin(y*cos(y)/5+sqrt(x*pi/e)*32)/ln(x*y-98/log2(63)+x*log10(z))").calculate(x,y,z), sin(y * cos(y) / 5 + sqrt(x * pi / e) * 32) / log(x * y - 98 / log2(63) + x * log10(z)));
}
TEST(postfix, test_14) {
	EXPECT_EQ(postfix("asin(0.5)").calculate(), asin(0.5));
}
TEST(postfix, test_15) {
	EXPECT_EQ(postfix("acos(0.5)").calculate(), acos(0.5));
}
TEST(postfix, test_16) {
	EXPECT_EQ(postfix("atan(0.5)").calculate(), atan(0.5));
}
TEST(postfix, test_17) {
	double x = 12, y = 23;
	EXPECT_EQ(postfix("sin(y*cos(y)/5+sqrt(x*pi/e)*32)/ln(x*y-98/log2(63)+x*log10(34))").calculate(x, y), sin(y * cos(y) / 5 + sqrt(x * pi / e) * 32) / log(x * y - 98 / log2(63) + x * log10(34)));
}

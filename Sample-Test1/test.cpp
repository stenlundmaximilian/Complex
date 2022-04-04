#include "pch.h"
#include "Complex.h"
#include <fstream>
TEST(ComplexTest, DefaultRealAndImaginary) {//checks that default values are set to zero
	Complex c = Complex();
	double real = c.real();
	double imag = c.imag();
	EXPECT_EQ(real, 0.0);
	EXPECT_EQ(imag, 0.0);
}

TEST(ComplexTest, RealOnly) { //checks that a real number is initialized correctly
	Complex c1(3);
	Complex c2(10.17);
	double real1 = c1.real();
	double imag1 = c1.imag();
	double real2 = c2.real();
	double imag2 = c2.imag();
	EXPECT_EQ(real1, 3.0);
	EXPECT_EQ(imag1, 0.0);
	EXPECT_EQ(real2, 10.17);
	EXPECT_EQ(imag2, 0.0);
}

TEST(ComplexTest, SetRealAndImaginary) { //checks that a complex number is set correctly
	Complex c1(3, 4);
	Complex c2(10.17, 11.37);
	double real1 = c1.real();
	double imag1 = c1.imag();
	double real2 = c2.real();
	double imag2 = c2.imag();
	EXPECT_EQ(real1, 3.0);
	EXPECT_EQ(imag1, 4.0);
	EXPECT_EQ(real2, 10.17);
	EXPECT_EQ(imag2, 11.37);
}

TEST(ComplexTest, CopyConstructor) { //tests copy constructor
	Complex c1(3, 4);
	Complex c2(10.17, 11.37);
	Complex c3 = c1;
	Complex c4 = c2;
	double real1 = c3.real();
	double imag1 = c3.imag();
	double real2 = c4.real();
	double imag2 = c4.imag();
	EXPECT_EQ(real1, 3.0);
	EXPECT_EQ(imag1, 4.0);
	EXPECT_EQ(real2, 10.17);
	EXPECT_EQ(imag2, 11.37);
}

TEST(OperatorAssign, CopyAssignmentOperator) { // test copy assignment operator
	Complex c1(3, 4);
	Complex c2(10.17, 11.37);
	Complex c3;
	Complex c4;
	c3 = c1;
	c4 = c2;
	double real1 = c3.real();
	double imag1 = c3.imag();
	double real2 = c4.real();
	double imag2 = c4.imag();
	EXPECT_EQ(real1, 3.0);
	EXPECT_EQ(imag1, 4.0);
	EXPECT_EQ(real2, 10.17);
	EXPECT_EQ(imag2, 11.37);
}

TEST(RealTest, GetRealMethod) { //tests that .real() returns the real part
	Complex c1(3, 4);
	Complex c2(10.17, 11.37);
	double real1 = c1.real();
	double real2 = c2.real();
	EXPECT_EQ(real1, 3.0);
	EXPECT_EQ(real2, 10.17);
}

TEST(ImagTest, GetImagMethod) { //tests that .imag() returns the imaginary part
	Complex c1(3, 4);
	Complex c2(10.17, 11.37);
	double imag1 = c1.imag();
	double imag2 = c2.imag();
	EXPECT_EQ(imag1, 4.0);
	EXPECT_EQ(imag2, 11.37);
}

TEST(OperatorMultiplyEqualsTest, MultiplyEquals) { // tests that x1 *= x2; works correctly 
	Complex c1(1, 2);
	Complex c2(3.1, 4.2);
	c1 *= c2;
	double real1 = c1.real();
	double imag1 = c1.imag();
	real1 = round(real1 * 1000.0) / 1000.0;
	imag1 = round(imag1 * 1000.0) / 1000.0;
	EXPECT_EQ(real1, -5.3);
	EXPECT_EQ(imag1, 10.4);
}

TEST(OperatorDivisionEqualsTest, DivisionEquals) { // tests that x1 /= x2; works correctly
	Complex c1(12, 24);
	Complex c2(3.1, 4);
	c1 /= c2;
	double real1 = c1.real();
	double imag1 = c1.imag();
	real1 = round(real1 * 1000.0) / 1000.0;
	imag1 = round(imag1 * 1000.0) / 1000.0;
	EXPECT_EQ(real1, 5.201);
	EXPECT_EQ(imag1, 1.031);
}

TEST(OperatorAdditionEqualsTest, AdditionEquals) { // tests that x1 += x2; works correctly
	Complex c1(12, 24);
	Complex c2(3.1, 4);
	c1 += c2;
	double real1 = c1.real();
	double imag1 = c1.imag();
	real1 = round(real1 * 1000.0) / 1000.0;
	imag1 = round(imag1 * 1000.0) / 1000.0;
	EXPECT_EQ(real1, 15.1);
	EXPECT_EQ(imag1, 28);
}

TEST(OperatorSubtractionEqualsTest, SubtractionEquals) { //tests that x1 -= x2; works correctly
	Complex c1(12, 24);
	Complex c2(3.1, 4);
	c1 -= c2;
	double real1 = c1.real();
	double imag1 = c1.imag();
	real1 = round(real1 * 1000.0) / 1000.0;
	imag1 = round(imag1 * 1000.0) / 1000.0;
	EXPECT_EQ(real1, 8.9);
	EXPECT_EQ(imag1, 20);
}

TEST(OperatorMultiplyTest, Multiply) { // tests that x1 = x2 * x3 works correctly
	Complex c1(1, 2);
	Complex c2(3.1, 4.2);
	c1 = c1 * c2;
	double real1 = c1.real();
	double imag1 = c1.imag();
	real1 = round(real1 * 1000.0) / 1000.0;
	imag1 = round(imag1 * 1000.0) / 1000.0;
	EXPECT_EQ(real1, -5.3);
	EXPECT_EQ(imag1, 10.4);
}

TEST(OperatorDivisionTest, Division) { //tests that x1 = x2 / x3 works correctly
	Complex c1(12, 24);
	Complex c2(3.1, 4);
	c1 = c1 / c2;
	double real1 = c1.real();
	double imag1 = c1.imag();
	real1 = round(real1 * 1000.0) / 1000.0;
	imag1 = round(imag1 * 1000.0) / 1000.0;
	EXPECT_EQ(real1, 5.201);
	EXPECT_EQ(imag1, 1.031);
}

TEST(OperatorAdditionTest, Addition) { // tests that x1 = x2 + x3; works correctly
	Complex c1(12, 24);
	Complex c2(3.1, 4);
	c1 = c1 + c2;
	double real1 = c1.real();
	double imag1 = c1.imag();
	real1 = round(real1 * 1000.0) / 1000.0;
	imag1 = round(imag1 * 1000.0) / 1000.0;
	EXPECT_EQ(real1, 15.1);
	EXPECT_EQ(imag1, 28);
}

TEST(OperatorSubtractionTest, Subtraction) { // tests that x1 -= x2 works correctly
	Complex c1(12, 24);
	Complex c2(3.1, 4);
	c1 = c1 - c2;
	double real1 = c1.real();
	double imag1 = c1.imag();
	real1 = round(real1 * 1000.0) / 1000.0;
	imag1 = round(imag1 * 1000.0) / 1000.0;
	EXPECT_EQ(real1, 8.9);
	EXPECT_EQ(imag1, 20);
}

TEST(OperatorEqualsTest, Equals) { // tests that x1 == x2; works correctly
	Complex c1(12, 24);
	Complex c2(3.1, 4);
	EXPECT_EQ(c1 == c1, true);
	EXPECT_EQ(c1 == c2, false);
}

TEST(OperatorNotEqualsTest, NotEquals) { // tests that x1 != x2; works correctly
	Complex c1(12, 24);
	Complex c2(3.1, 4);
	EXPECT_EQ(c1 != c1, false);
	EXPECT_EQ(c1 != c2, true);
}

TEST(RealTest, GetRealFunction) { // tests that real() returns real part of complex number
	Complex c1(3, 4);
	Complex c2(10.17, 11.37);
	double real1 = real(c1);
	double real2 = real(c2);
	EXPECT_EQ(real1, 3.0);
	EXPECT_EQ(real2, 10.17);
}

TEST(ImagTest, GetImagFunction) { // tests that imag() returns imaginary part of complex number
	Complex c1(3, 4);
	Complex c2(10.17, 11.37);
	double imag1 = imag(c1);
	double imag2 = imag(c2);
	EXPECT_EQ(imag1, 4.0);
	EXPECT_EQ(imag2, 11.37);
}

TEST(AbsTest, GetAbsoluteValue) { // tests that abs() returns absolute value of complex number
	Complex c1(12, 24);
	Complex c2(3.1, 4);
	double abs1 = abs(c1);
	double abs2 = abs(c2);
	abs1 = round(abs1 * 1000.0) / 1000.0;
	abs2 = round(abs2 * 1000.0) / 1000.0;
	EXPECT_EQ(abs1, 26.833);
	EXPECT_EQ(abs2, 5.061);
}

TEST(OperatorLessThanTest, LessThan) { //tests that x1 < x2; works correctly
	Complex c1(12, 24);
	Complex c2(3.1, 4);
	Complex c3(0, 0);
	Complex c4(1, 1);
	EXPECT_EQ(c2 < c1, true);
	EXPECT_EQ(c1 < c2, false);
	EXPECT_EQ(c3 < c4, true);
	EXPECT_EQ(c4 < c3, false);
}

TEST(OperatorInStream, Instream) {
	std::fstream myFile;
	myFile.open("instream1.txt", std::ios::out);
	if (myFile.is_open()) {
		myFile << "(3.14,2.713)";
		myFile.close();
	}

	Complex c1;
	myFile.open("instream1.txt", std::ios::in);
	if (myFile.is_open()) {
		myFile >> c1;
		myFile.close();
	}

	myFile.open("instream2.txt", std::ios::out);
	if (myFile.is_open()) {
		myFile << "(3.1415)";
		myFile.close();
	}

	Complex c2;
	myFile.open("instream2.txt", std::ios::in);
	if (myFile.is_open()) {
		myFile >> c2;
		myFile.close();
	}

	EXPECT_EQ(c1.real(), 3.14);
	EXPECT_EQ(c1.imag(), 2.713);
	EXPECT_EQ(c2.real(), 3.1415);
	EXPECT_EQ(c2.imag(), 0.0);
}

TEST(OperatorOutstream, Outstream) {
	std::fstream myFile;
	Complex c1(3.14, 2.71);
	myFile.open("outstream.txt", std::ios::out);
	if (myFile.is_open()) {
		myFile << c1;
		myFile.close();
	}

	Complex c2;
	myFile.open("outstream.txt", std::ios::in);
	if (myFile.is_open()) {
		myFile >> c2;
		myFile.close();
	}
	EXPECT_EQ(c2.real(), 3.14);
	EXPECT_EQ(c2.imag(), 2.71);
}

TEST(Operator_iTest, _i) {
	Complex c1 = 3 + 2_i;
	Complex c2 = 4.0 + 5.0_i;
	EXPECT_EQ(c1.real(), 3.0);
	EXPECT_EQ(c1.imag(), 2.0);
	EXPECT_EQ(c2.real(), 4.0);
	EXPECT_EQ(c2.imag(), 5.0);
}
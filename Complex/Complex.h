#pragma once
#include <iostream>
#include <string>
#include <stdlib.h>

class Complex {
public:
	// constructors and assignment operators
	Complex();
	Complex(double real);
	constexpr Complex(double real, double imaginary);
	Complex(const Complex& rhs);

	Complex(Complex& other);
	Complex(Complex&& other) noexcept;
	Complex& operator=(const Complex& other);
	Complex& operator=(Complex&& other) noexcept;
	//accessors
	double real() const;
	double imag() const;

	//operators
	void operator*=(const Complex& other);
	void operator/=(const Complex& other);
	void operator+=(const Complex& other);
	void operator-=(const Complex& other);

private:
	double c_real;
	double c_imag;
};

//non member 

Complex operator*(const Complex& c1, const Complex& c2);
Complex operator/(const Complex& c1, const Complex& c2);
Complex operator+(const Complex& c1, const Complex& c2);
Complex operator-(const Complex& c1, const Complex& c2);
bool operator==(const Complex& c1, const Complex& c2);
bool operator!=(const Complex& c1, const Complex& c2);

double real(const Complex& c);
double imag(const Complex& c);
double abs(const Complex& c);

bool operator<(const Complex& c1, const Complex& c2);
std::istream& operator>>(std::istream& is, Complex& c);
std::ostream& operator<<(std::ostream& os, const Complex& m);

constexpr Complex operator "" _i(long double arg) {
	return Complex(0.0, (double)arg);
}

constexpr Complex operator "" _i(size_t arg) {
	return Complex(0.0, (double)arg);
}
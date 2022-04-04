#include "Complex.h"
Complex::Complex() //default value of complex number is 0 + 0i
	: c_real(0.0)
	, c_imag(0.0)
{}

Complex::Complex(double real) //creates a real number x + 0i
	: c_real(real)
	, c_imag(0.0)
{}

constexpr Complex::Complex(double real, double imaginary) //creates a complex number x + yi
	: c_real(real)
	, c_imag(imaginary)
{}

Complex::Complex(const Complex& rhs)
	: c_real(rhs.c_real)
	, c_imag(rhs.c_imag)
{}

Complex::Complex(Complex& other) //copy constructor
	: c_real(other.c_real)
	, c_imag(other.c_imag)
{}

Complex::Complex(Complex&& other) noexcept //move constructor
	: c_real(other.c_real)
	, c_imag(other.c_imag)
{
	other.c_real = 0.0;
	other.c_imag = 0.0;
}

Complex& Complex::operator=(const Complex& other) { //copy assignment operator
	if (this != &other) {
		c_real = other.c_real;
		c_imag = other.c_imag;
	}
	return *this;
}
Complex& Complex::operator=(Complex&& other) noexcept { //move assignment operator
	if (this != &other) {
		c_real = other.c_real;
		c_imag = other.c_imag;
		other.c_real = 0.0;
		other.c_imag = 0.0;
	}
	return *this;
}

double Complex::real() const { //returns real value of complex number
	return c_real;
}

double Complex::imag() const {//returns imaginary value of complex number
	return c_imag;
}

void Complex::operator*=(const Complex& other) { //operator multiply equals 
	double real_temp = c_real * other.c_real - c_imag * other.c_imag;
	c_imag = c_real * other.c_imag + c_imag * other.c_real;
	c_real = real_temp;
}
void Complex::operator/=(const Complex& other) { //operator divide equals
	double real_temp = (c_real * other.c_real + c_imag * other.c_imag) / (other.c_real * other.c_real + other.c_imag * other.c_imag); //real part of new number
	c_imag = (c_imag * other.c_real - c_real * other.c_imag) / (other.c_real * other.c_real + other.c_imag * other.c_imag); //imaginary part of new number
	c_real = real_temp;
}
void Complex::operator+=(const Complex& other) { //operator addition equals
	c_real += other.c_real;
	c_imag += other.c_imag;
}
void Complex::operator-=(const Complex& other) { //operator subtract equals
	c_real -= other.c_real;
	c_imag -= other.c_imag;
}

Complex operator*(const Complex& c1, const Complex& c2) { //operator multiply
	Complex c3(c1.real() * c2.real() - c1.imag() * c2.imag(), c1.real() * c2.imag() + c1.imag() * c2.real());
	return c3;
}

Complex operator/(const Complex& c1, const Complex& c2) { //operator divide
	Complex c3((c1.real() * c2.real() + c1.imag() * c2.imag()) / (c2.real() * c2.real() + c2.imag() * c2.imag()), (c1.imag() * c2.real() - c1.real() * c2.imag()) / (c2.real() * c2.real() + c2.imag() * c2.imag()));
	return c3;
}

Complex operator+(const Complex& c1, const Complex& c2) { //operator addition
	Complex c3(c1.real() + c2.real(), c1.imag() + c2.imag());
	return c3;
}

Complex operator-(const Complex& c1, const Complex& c2) {//operator subtract
	Complex c3(c1.real() - c2.real(), c1.imag() - c2.imag());
	return c3;
}

bool operator==(const Complex& c1, const Complex& c2) {//operator equals
	if ((c1.real() == c2.real()) and c1.imag() == c2.imag()) {
		return true;
	}
	else {
		return false;
	}
}

bool operator!=(const Complex& c1, const Complex& c2) {//operator not equals
	if ((c1.real() == c2.real()) and c1.imag() == c2.imag()) {
		return false;
	}
	else {
		return true;
	}
}

double real(const Complex& c) { //returns real part of complex number
	return c.real();
}

double imag(const Complex& c) { //returns imaginary part of complex number
	return c.imag();
}

double abs(const Complex& c) { //returns absolute value of complex number
	return (sqrt(c.real() * c.real() + c.imag() * c.imag()));
}

bool operator<(const Complex& c1, const Complex& c2) { //true if the lhs absolute value is less than rhs absolute value, false otherwise
	if ((c1.real() * c1.real() + c1.imag() * c1.imag()) < (c2.real() * c2.real() + c2.imag() * c2.imag())) {
		return true;
	}
	else {
		return false;
	}
}

std::istream& operator>>(std::istream& is, Complex& c) { //reads complex number from file in format (x,y) or (x)
	std::string complex;
	is >> complex; //reads the complex number into a string
	int x = complex.find(","); //finds the comma postition
	if (x != -1) { //exexutes block below if there was a comma
		std::string number1 = "";
		for (int i = 1; i < x; i++) { //adds all the values before the comma to a string
			number1.push_back(complex[i]);
		}
		int y = complex.size();
		std::string number2 = "";
		for (int i = x + 1; i < y - 1; i++) {//adds all the values after the comma to a string
			number2.push_back(complex[i]);
		}
		double num1 = atof(number1.c_str()); //converts the number before the comma into a double
		double num2 = atof(number2.c_str()); //converts the number after the comma into a double
		Complex temp(num1, num2);
		c = temp; //creates a complex number with the arguments read from the file
	}
	else { //if there was no comma executes block below
		int z = complex.size();
		std::string number = "";
		for (int i = 1; i < z - 1; i++) {
			number.push_back(complex[i]); //adds all values to a string
		}
		double num = atof(number.c_str()); // converts string into a double
		Complex temp(num, 0.0);
		c = temp; //creates a real valued complexnumber with the argument read from the file
	}
	return is;
}

std::ostream& operator<<(std::ostream& os, const Complex& m) { //writes a complex number 
	os << "(" << m.real() << "," << m.imag() << ")" << std::endl;
	return os;
}
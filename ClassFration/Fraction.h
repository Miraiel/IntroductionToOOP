#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

class Fraction;

Fraction operator+(const Fraction& left, const Fraction& right);
Fraction operator/(const Fraction& left, const Fraction& rigth);// прототип фу-ии = объявление фун-ии
Fraction operator*(Fraction left, Fraction right);

class Fraction
{
	int integer, numenator, denominator;

public:
	int get_integer()const;
	int get_numenator()const;
	int get_denominator()const;
	void set_integer(int integer);
	void set_numenator(int nemenator);
	void set_denominator(int denominator);

	//----------------Constructors---------------

	Fraction();
	explicit Fraction(int integer);
	Fraction(double decimal);
	Fraction(int numenator, int denominator);
	Fraction(int integer, int numenator, int denominator);
	~Fraction();

	//--------------Operators--------------------

	Fraction& operator=(const Fraction& other);
	Fraction& operator*=(const Fraction& other);
	Fraction& operator/=(const Fraction& other);
	Fraction& operator() (int integer, int numerator, int denominator);

	//---------Type-cast operators---------------

	explicit operator int();
	operator double();

	//---------------Methods---------------------

	Fraction& reduce();
	Fraction& to_improper();
	Fraction& to_proper();
	Fraction inverted()const;
	void print()const;

};
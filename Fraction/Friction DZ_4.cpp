#include<iostream>

using std::cin;
using std::cout;
using std::endl;

class Fraction
{
	double nume, deno;

public:
	double get_nume()const
	{
		return nume;
	}
	double get_deno()const
	{
		return deno;
	}
	void set_nume(double nume)
	{
		this->nume = nume;
	}
	void set_deno(double deno)
	{
		if (deno == 0)deno == 1;
		this->deno = deno;
	}

	//------------------Constructors-----------------

	Fraction(double nume = 0, double deno = 1)
	{
		this->nume = nume;
		this->deno = deno;
	}

	//-------------------Operators-------------------

	Fraction& operator=(const Fraction& other)
	{
		this->nume = other.nume;
		this->deno = other.deno;
		return *this;
	}

	//--------------------Methods--------------------

	void show()const
	{
		cout << "Fraction: " << nume << "/" << deno << endl;
	}
	void show_res()const
	{
		cout << "Result: " << nume << "/" << deno << endl;
	}
};

Fraction operator+(const Fraction& left, const Fraction& right)
{
	Fraction res;
	if (left.get_deno() != right.get_deno())
	{
		res.set_nume(left.get_nume() * right.get_deno() + right.get_nume() * left.get_deno());
		res.set_deno(left.get_deno() * right.get_deno());
	}
	else
	{
		res.set_nume(left.get_nume() + right.get_nume());
		res.set_deno(left.get_deno());
	}
	return res;
}

Fraction operator-(const Fraction& left, const Fraction right)
{
	Fraction res;
	if (left.get_deno() != right.get_deno())
	{
		res.set_nume(left.get_nume() * right.get_deno() - right.get_nume() * left.get_deno());
		res.set_deno(left.get_deno() * right.get_deno());
	}
	else
	{
		res.set_nume(left.get_nume() - right.get_nume());
		res.set_deno(left.get_deno());
	}
	return res;
}

Fraction operator/(const Fraction& left, const Fraction right)
{
	Fraction res;
	res.set_nume(left.get_nume() * right.get_deno());
	res.set_deno(left.get_deno() * right.get_nume());
	return res;
}

Fraction operator*(const Fraction& left, const Fraction right)
{
	Fraction res;
	res.set_nume(left.get_nume() * right.get_nume());
	res.set_deno(left.get_deno() * right.get_deno());
	return res;
}


void main()
{
	Fraction A(7, 9);
	A.show();
	Fraction B(3, 4);
	B.show();
	Fraction Sum = A + B;
	Sum.show_res();
	Fraction Diff = A - B;
	Diff.show_res();
	Fraction Divi = A / B;
	Divi.show_res();
	Fraction Mul = A * B;
	Mul.show_res();
}
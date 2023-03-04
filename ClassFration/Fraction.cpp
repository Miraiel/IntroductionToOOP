#include"Fraction.h"

int Fraction::get_integer()const
{
	return integer;
}
int Fraction::get_numenator()const
{
	return numenator;
}
int Fraction::get_denominator()const
{
	return denominator;
}
void Fraction::set_integer(int integer)
{
	this->integer = integer;
}
void Fraction::set_numenator(int nemenator)
{
	this->numenator = numenator;
}
void Fraction::set_denominator(int denominator)
{
	if (denominator == 0)denominator = 1;
	this->denominator = denominator;
}
//----------------Constructors---------------

Fraction::Fraction()
{
	this->integer = 0;
	this->numenator = 0;
	this->denominator = 1;
	cout << "DefaultConctructor:\t" << this << endl;
}
Fraction::Fraction(int integer)
{
	this->integer = integer;
	this->numenator = 0;
	this->denominator = 1;
	cout << "lArgConctructor:\t" << this << endl;
}

Fraction::Fraction(double decimal)
{
	decimal += 1e-10;						// прибавляем маленькое значение
	integer = decimal;						// сохраняем целую часть десятичной дроби
	decimal -= integer;						// убираем целую часть
	denominator = 1e+9;						// записываем максимально возможный знаменатель
	numenator = decimal * denominator;		//всю дробную часть десятичной дроби загружаем в числитель
	reduce();
	cout << "lArgConstructor:\t" << this << endl;
}

Fraction::Fraction(int numenator, int denominator)
{
	this->integer = 0;
	this->numenator = numenator;
	set_denominator(denominator);
	cout << "Conctructor:\t\t" << this << endl;
}

Fraction::Fraction(int integer, int numenator, int denominator)
{
	this->integer = integer;
	this->numenator = numenator;
	set_denominator(denominator);
	cout << "Constructor:\t\t" << this << endl;
}

Fraction::~Fraction()
{
	cout << "Destructor:\t\t" << this << endl;
}
//--------------Operators--------------------

Fraction& Fraction::operator=(const Fraction& other)		//конструктор копиролвания(константная ссылка на объект)
{
	this->integer = other.integer;
	this->numenator = other.numenator;
	this->denominator = other.denominator;
	cout << "CopyAssigmentr\t\t" << this << endl;
	return *this;
}

Fraction& Fraction::operator*=(const Fraction& other)
{
	return *this = *this * other; // Вызов функции (operator *)
}

Fraction& Fraction::operator/=(const Fraction& other)
{
	return *this = *this / other;
}

Fraction& Fraction::operator() (int integer, int numerator, int denominator)
{
	set_integer(integer);
	set_numenator(numerator);
	set_denominator(denominator);
	return *this;
}

//---------Type-cast operators---------------

Fraction::operator int()
{
	return integer;
}

Fraction::operator double()
{
	return integer + (double)numenator / denominator;
}


//---------------Methods---------------------

Fraction& Fraction::reduce()
{
	int more, less, rest;
	if (numenator > denominator) more = numenator, less = denominator;
	else more = denominator, less = numenator;
	do
	{
		rest = more % less;
		more = less;
		less = rest;
	} while (rest);
	int GCD = more;		// наибольший общий делитель
	numenator /= GCD;
	denominator /= GCD;
	return *this;
}

Fraction& Fraction::to_improper()
{
	numenator += integer * denominator;
	integer = 0;
	return *this;
}

Fraction& Fraction::to_proper()
{
	integer += numenator / denominator;
	numenator %= denominator;
	return *this;
}

Fraction Fraction::inverted()const
{
	Fraction inverted = *this;
	inverted.to_improper();
	std::swap(inverted.numenator, inverted.denominator);
	return inverted;
}

void Fraction::print()const
{
	if (integer)cout << integer;
	if (numenator)
	{
		if (integer) cout << "(";
		cout << numenator << "/" << denominator;
		if (integer)cout << ")";
	}
	else if (integer == 0)cout << 0;
	cout << endl;
}

Fraction operator+(const Fraction& left, const Fraction& right)
{
	return Fraction(
		left.get_integer() + right.get_integer(),
		left.get_numenator() * right.get_denominator() + left.get_denominator() * right.get_numenator(),
		left.get_denominator() * right.get_denominator()
	).to_proper().reduce();
}

Fraction operator*(Fraction left, Fraction right) // Реализация фу-ии или определение фун-ии
{
	left.to_improper();
	right.to_improper();
	/*
	result.set_numenator(left.get_numenator() * right.get_numenator());
	result.set_denominator(left.get_denominator() * right.get_denominator());
	*/
	/*Fraction result;
	(
		left.get_numenator() * right.get_numenator(),
		left.get_denominator() * right.get_denominator()
	);
	return result;*/
	//Временные безымянные объекты существуют только в пределах одного выражения (до ; )
	return Fraction //создаем временный безымянный объект и сразу же возвращаем его на место вызова
	(
		left.get_numenator() * right.get_numenator(),
		left.get_denominator() * right.get_denominator()
	).to_proper().reduce();
}

Fraction operator/(const Fraction& left, const Fraction& rigth)
{
	return left * rigth.inverted();
}
////////////////////////////////////////////////////////////////////
bool operator==(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_proper();
	return
		left.get_numenator() * right.get_denominator() ==
		right.get_numenator() * left.get_denominator();
}

bool operator!=(const Fraction& left, const Fraction& right)
{
	return !(left == right);
	!true == false;
}

bool operator>(Fraction left, Fraction rigth)
{
	left.to_improper();
	rigth.to_proper();
	return
		left.get_numenator() * rigth.get_denominator() >
		rigth.get_numenator() * left.get_denominator();
}

bool operator<(Fraction left, Fraction rigth)
{
	left.to_improper();
	rigth.to_proper();
	return
		left.get_numenator() * rigth.get_denominator() <
		rigth.get_numenator() * left.get_denominator();
}

bool operator<=(const Fraction& left, const Fraction& right)
{
	return left < right || left == right;
}
bool operator>=(const Fraction& left, const Fraction& right)
{
	return !(left < right);//  быстрее чем строка 226
}

////////////////////////////////////////////////////////////////////
std::ostream& operator<<(std::ostream& os, const  Fraction& obj)
{
	if (obj.get_integer())os << obj.get_integer();
	if (obj.get_numenator())
	{
		if (obj.get_integer()) os << "(";
		cout << obj.get_numenator() << "/" << obj.get_denominator();
		if (obj.get_integer()) os << ")";
	}
	else if (obj.get_integer() == 0)os << 0;
	return os;
}

std::istream& operator>>(std::istream& is, Fraction& obj)
{

#ifdef PRIMETIV_EXTRACTION
	int integer, numerator, denominator;
	is >> integer >> numerator >> denominator;
	/*obj.set_integer(integer);
	obj.set_numenator(numerator);
	obj.set_denominator(denominator);*/
	obj(integer, numerator, denominator);
#endif

	const int SIZE = 256;
	char buffer[SIZE] = {};
	char delimiters[] = "/ ()";
	int number[3] = {};
	//is >> buffer;
	is.getline(buffer, SIZE);

	int n = 0; //счетчик чисел извлеченных из строки
	for (char* pch = strtok(buffer, delimiters); pch; pch = strtok(NULL, delimiters))
		number[n++] = atoi(pch);
	//for (int i = 0; i < n; i++)cout << number[i] << "\t"; cout << endl;

	obj = Fraction();// обнулили объект, сбрасыываем его до объекта по умолчанию
	switch (n)
	{
	case 1: obj.set_integer(number[0]); break;
	case 2: obj.set_numenator(number[0]); obj.set_denominator(number[1]); break;
	case 3: obj(number[0], number[1], number[2]);
	}
	return is;

}
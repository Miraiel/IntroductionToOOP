#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

class Fraction;

Fraction operator/(const Fraction& left, const Fraction& rigth);// прототип фу-ии = объявление фун-ии
Fraction operator*(Fraction left, Fraction right);

class Fraction
{
	int integer, numenator, denominator;

public:
	int get_integer()const
	{
		return integer;
	}
	int get_numenator()const
	{
		return numenator;
	}
	int get_denominator()const
	{
		return denominator;
	}
	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numenator(int nemenator)
	{
		this->numenator = numenator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0)denominator = 1;
		this->denominator = denominator;
	}
	//----------------Constructors---------------

	Fraction()
	{
		this->integer = 0;
		this->numenator = 0;
		this->denominator = 1;
		cout << "DefaultConctructor:\t" << this << endl;
	}
	explicit Fraction(int integer)
	{
		this->integer = integer;
		this->numenator = 0;
		this->denominator = 1;
		cout << "lArgConctructor:\t" << this << endl;
	}

	Fraction(double decimal)
	{
		decimal += 1e-10;						// прибавляем маленькое значение
		integer = decimal;						// сохраняем целую часть десятичной дроби
		decimal -= integer;						// убираем целую часть
		denominator = 1e+9;						// записываем максимально возможный знаменатель
		numenator = decimal * denominator;		//всю дробную часть десятичной дроби загружаем в числитель
		reduce();
		cout << "lArgConstructor:\t" << this << endl;
	}

	Fraction(int numenator, int denominator)
	{
		this->integer = 0;
		this->numenator = numenator;
		set_denominator(denominator);
		cout << "Conctructor:\t\t" << this << endl;
	}

	Fraction(int integer, int numenator, int denominator)
	{
		this->integer = integer;
		this->numenator = numenator;
		set_denominator(denominator);
		cout << "Constructor:\t\t" << this << endl;
	}

	~Fraction()
	{
		cout << "Destructor:\t\t" << this << endl;
	}
	//--------------Operators--------------------

	Fraction& operator=(const Fraction& other)		//конструктор копиролвания(константная ссылка на объект)
	{
		this->integer = other.integer;
		this->numenator = other.numenator;
		this->denominator = other.denominator;
		cout << "CopyAssigmentr\t\t" << this << endl;
		return *this;
	}

	Fraction& operator*=(const Fraction& other)
	{
		return *this = *this * other; // Вызов функции (operator *)
	}

	Fraction& operator/=(const Fraction& other)
	{
		return *this = *this / other;
	}

	Fraction& operator() (int integer, int numerator, int denominator)
	{
		set_integer(integer);
		set_numenator(numerator);
		set_denominator(denominator);
		return *this;
	}

	//---------Type-cast operators---------------

	explicit operator int()
	{
		return integer;
	}

	operator double()
	{
		return integer + (double)numenator / denominator;
	}


	//---------------Methods---------------------

	Fraction& reduce()
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

	Fraction& to_improper()
	{
		numenator += integer * denominator;
		integer = 0;
		return *this;
	}

	Fraction& to_proper()
	{
		integer += numenator / denominator;
		numenator %= denominator;
		return *this;
	}

	Fraction inverted()const
	{
		Fraction inverted = *this;
		inverted.to_improper();
		std::swap(inverted.numenator, inverted.denominator);
		return inverted;
	}

	void print()const
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
};

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

//#define PRIMETIV_EXTRACTION
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

////////////////////////////////////////////////////////////////////

//#define CONSTRACTORS_CHECK
//#define ARIHMETICAL_OPERATORS_CHEK
//#define IOSTREAM_OPERATORS_CHECK
//#define	CONVERSION_FROM_OTHER_TO_CLASS
//#define CONVERSION_FROM_CLASS_TO_OTHER
//#define HOME_WORK_1
//#define HOME_WORK_2
void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTRACTORS_CHECK

	Fraction A; // конструктор по умолчанию
	A.print();

	Fraction B = 5;
	B.print();

	Fraction C(1, 2);
	C.print();

	Fraction D(2, 3, 4);
	D.print();

	Fraction E = D;
	E.print();

	Fraction F;
	F = E;
	F.print();
#endif

#ifdef ARIHMETICAL_OPERATORS_CHEK
	Fraction A(2, 3, 4);
	A.print();

	Fraction B(3, 4, 5);
	B.print();
	/*
		Fraction C = A * B;
		C.print();
	*/
	//	Fraction D = A / B;
	//	D.print();

	(A + B).print();

	A *= B;
	A.print();

	A /= B;
	A.print();
#endif

	//cout << (Fraction(1, 2) <= Fraction(5, 10)) << endl;

#ifdef IOSTREAM_OPERATORS_CHECK
	Fraction A;
	cout << "Введите простую дробь: ";
	cin >> A;
	cout << A << endl;

	/*Необходимо предусмотреть следующий вариант ввода:

	5
	1/2
	2 3/4

	*/
#endif
#ifdef CONVERSION_FROM_OTHER_TO_CLASS
	/*
		int a = 2;		// не преобразований
		double b = 3;	// преобразование от меньшего к большему
		int c = b;		// преобразование от большего к меньшемуб, без потери данных
		int d = 5.2;	// преобразование от большего к меньшему, с потерей данных

		//cout << d << endl;					// при выводе теряем 2
		cout << (double)7 / 2 << endl;		// 2 неявно преобразуется в double
	*/

	Fraction A = (Fraction)5;		// преобразование от меньшего к большему (From int to Fraction)
	// вызывается конструктор с одним параметром
	cout << A << endl;

	Fraction B;					//вызывается конструктор по умолчанию
	B = Fraction(7);				//вызываетяс оператор присваивания, 7 преобразуется в Fraction
	cout << B << endl;
#endif
#ifdef CONVERSION_FROM_CLASS_TO_OTHER
	Fraction  A(2, 3, 4);
	cout << A << endl;
	int a = (int)A;
	cout << a << endl;
#endif
#ifdef HOME_WORK_1

	Fraction A(2, 3, 4);
	cout << A << endl;
	double a = A;
	cout << a << endl;

#endif // HOME_WORK_1
#ifdef HOME_WORK_2

	Fraction B = 2.75;
	cout << B << endl;

#endif // HOME_WORK_2

}
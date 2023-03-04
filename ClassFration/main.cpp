#include"Fraction.h"

//#define PRIMETIV_EXTRACTION
//#define CONSTRACTORS_CHECK
//#define ARIHMETICAL_OPERATORS_CHEK
//#define IOSTREAM_OPERATORS_CHECK
//#define	CONVERSION_FROM_OTHER_TO_CLASS
//#define CONVERSION_FROM_CLASS_TO_OTHER
#define HOME_WORK_1
#define HOME_WORK_2
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
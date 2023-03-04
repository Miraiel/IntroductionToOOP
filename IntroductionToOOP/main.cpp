#include"Point.h"

//#define STRUCT_POINT // STRUCT_POINT сами называем имя макроса
//#define CONSTRUCTORS_CHEK
//#define DICTANCE_CHECK
//#define ASSIGMENT_CHEK

void main()
{
	setlocale(LC_ALL, "Russian");

#ifdef STRUCT_POINT //закрывает часть кода, конец блока закрывается #endif
	int a;
	Point A;//Объявление переменной А типа Point или 
	//Cоздание объекта А структуры Point или 
	//Cоздание экземпляра А структуры Point
	A.x = 2;
	A.y = 3;

	cout << A.x << "\t" << A.y << endl;

	Point* pA = &A;
	cout << pA->x << "\t" << pA->y << endl;
#endif
#ifdef CONSTRUCTORS_CHEK
	Point A(2, 3);		//здесь вызывается конструктор по умолчанию(Default constructor)
	//A.set_x(2);
	//A.set_y(3);
	//cout << A.get_x() << "\t" << A.get_y() << endl;
	A.print();

	Point B(4, 5);
	B.print();

	Point C(22, 33);
	C.print();

	Point D = C;
	D.print();

	Point E;
	E = D;			//copy assigment
	E.print();

	/*for (int i = 0; i < 10; i++)
	{
		cout << i << "\t";
	}
	cout << endl;*/
#endif
#ifdef DICTANCE_CHECK
	Point A(2, 3);
	A.print();

	Point B(4, 5);
	B.print();

	cout << delimiter << endl;
	cout << "Растояние от точки А до точки В: " << A.distance(B) << endl;
	cout << delimiter << endl;
	cout << "Растояние от точки В до тоски А: " << B.distance(A) << endl;
	cout << delimiter << endl;
	cout << "Растояние между точками А и В: " << distance(A, B) << endl;
	cout << delimiter << endl;
	cout << "Растояние между точками В и А: " << distance(B, A) << endl;
	cout << delimiter << endl;

	Point C = B; //создается конструктор копирования
#endif
#ifdef ASSIGMENT_CHEK
	int a, b, c;
	a = b = c = 2;
	cout << a << "\t" << b << "\t" << c << endl;

	Point A, B, C;
	A = B = C = Point(2, 3);
	A.print();
	B.print();
	C.print();
#endif

	int a = 2;
	int b = 3;
	int c = a + b;		   // int = int + int

	Point A(2, 3);
	A.print();
	Point B(4, 5);
	B.print();
	Point C = A + B;	  // Poin = Point + Point
	C.print();
	C++;
	C.print();
}
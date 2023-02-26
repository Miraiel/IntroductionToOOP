#include<iostream>
//using namespace std;
using std::cin;//решают проблему с ошибкой cin
using std::cout;//решают проблему с ошибкой cout
using std::endl;//решают проблему с ошибкой endl

#define delimiter "\n-----------------------\n"

class Point
{
	double x;
	double y;
	
public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}

	//------------------Constructors-----------------
	/*Point()
	{
		x = y = double();//значение по умолчанию
		cout << "DefaultConstructor:\t" << this << endl;
	}

	Point(double x)
	{
		this->x = x;
		this->y = 0;
		cout << "lArgConstructor:\t" << this << endl;
	}*/

	Point(double x = 0, double y = 0)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t\t" << this << endl;
	}
	
	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor:\t" << this << endl;
	}

	~Point()
	{
		cout << "Destructor:\t\t" << this << endl;
	}

	//---------------------Operators-------------------

	Point& operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssignment:\t\t" << this << endl;
		return *this;
	}

	Point& operator++()			// перегрузка префиксного инкримента
	{
		x++;
		y++;
		return *this;
	}

	Point& operator++(int)		// перегру постфиксного инкримента
	{
		Point old = *this;		// сохраняем старое значение объекта
		//Изменяем объект
		x++;
		y++;
		return old;

	}

	//---------------------Methods--------------------

	double distance(const Point& other)const// метод по ДЗ1
	{
		//this - эта точка
		//other - та точка
		double x_dictance = this->x - other.x;
		double y_dictance = this->y - other.y;
		double dictance = sqrt(x_dictance * x_dictance + y_dictance * y_dictance);
		return dictance;
	}


	void print()const
	{
		cout << "X= " << x << "\tY= " << y << endl;
	}
};

Point operator+(const Point& left, const Point& right)
{
	Point res;
	res.set_x(left.get_x() + right.get_x());
	res.set_y(left.get_y() + right.get_y());
	return res;
}

double distance(const Point& A, const Point& B)// функция по ДЗ1
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
	return distance;
}


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
	Point A(2,3);		//здесь вызывается конструктор по умолчанию(Default constructor)
	//A.set_x(2);
	//A.set_y(3);
	//cout << A.get_x() << "\t" << A.get_y() << endl;
	A.print();

	Point B(4,5);
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
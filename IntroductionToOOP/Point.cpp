#include"Point.h"

double Point::get_x()const
{
	return x;
}
double Point::get_y()const
{
	return y;
}
void Point::set_x(double x)
{
	this->x = x;
}
void Point::set_y(double y)
{
	this->y = y;
}

Point::Point(double x = 0, double y = 0) :x(x), y(y)
{
	//this->x = x;
	//this->y = y;
	cout << "Constructor:\t\t" << this << endl;
}

Point::Point(const Point& other) :x(other.x), y(other.y)
{
	//this->x = other.x;
	//this->y = other.y;
	cout << "CopyConstructor:\t" << this << endl;
}

Point::~Point()
{
	cout << "Destructor:\t\t" << this << endl;
}

//---------------------Operators-------------------

Point& Point::operator=(const Point& other)
{
	this->x = other.x;
	this->y = other.y;
	cout << "CopyAssignment:\t\t" << this << endl;
	return *this;
}

Point& Point::operator++()			// перегрузка префиксного инкримента
{
	x++;
	y++;
	return *this;
}

Point& Point::operator++(int)		// перегру постфиксного инкримента
{
	Point old = *this;		// сохраняем старое значение объекта
	//Изменяем объект
	x++;
	y++;
	return old;

}

//---------------------Methods--------------------

double Point::distance(const Point& other)const// метод по ДЗ1
{
	//this - эта точка
	//other - та точка
	double x_dictance = this->x - other.x;
	double y_dictance = this->y - other.y;
	double dictance = sqrt(x_dictance * x_dictance + y_dictance * y_dictance);
	return dictance;
}


void Point::print()const
{
	cout << "X= " << x << "\tY= " << y << endl;
}

Point operator+(const Point& left, const Point& right)
{
	Point res;
	res.set_x(left.get_x() + right.get_x());
	res.set_y(left.get_y() + right.get_y());
	return res;
}

double distance(const Point& A, const Point& B)
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
	return distance;
}
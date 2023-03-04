#pragma once
#include<iostream>
using namespace std;

class Point;
Point operator+(const Point& left, const Point& right);

class Point
{
	double x;
	double y;

public:
	double get_x()const;
	double get_y()const;
	void set_x(double x);
	void set_y(double y);

	Point(double x, double y);
	Point(const Point& other);
	~Point();

	//---------------------Operators-------------------

	Point& operator=(const Point& other);
	Point& operator++();
	Point& operator++(int);

	//---------------------Methods--------------------

	double distance(const Point& other)const;
	void print()const;
};
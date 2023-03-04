//#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

class String;
String operator+(const String& left, const String& right);

class String
{
	int size;
	char* str;
public:
	int get_size()const
	{
		return size;
	}
	const char* get_str()const		//если передаем указатель, обязательно должно быть const ---- const
	{
		return str;
	}
	char* get_str()
	{
		return str;
	}

	//--------------Contructors----------------
	explicit String(int size = 80)
	{
		this->size = size;
		this->str = new char[size] {};
		cout << "DefConstructor:\t" << this << endl;
	}

	String(const char* str)
	{
		this->size = strlen(str);
		this->str = new char[size] {};
		for (int i = 0; str[i]; i++)
			this->str[i] = str[i];
		cout << "Constructor:\t" << this << endl;
	}

	/*
	String(const char* s)		//мой вариант
	{
		size = strlen(s);
		str = new char[size + 1];
		strcpy(str, s);
	}
	*/

	String(const String& other)
	{
		if (this == &other)
		{
			return this;
		}
		delete[] this->str;		//удаляем старую строку, чтобы избежать утечку памяти

		this->size = other.size;
		//Deep copy(Побитовое копирование) :
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)
		{
			this->str[i] = other.str[i];
		}
		cout << "CopyConstructor:" << this << endl;
	}

	~String()
	{
		delete[] this->str;
		this->str = nullptr;
		cout << "Destructor:\t" << this << endl;
	}

	//----------------Operators-----------------

	String& operator=(const String& other)
	{
		this->size = other.size;
		//Deep copy(Побитовое копирование) :
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)
		{
			this->str[i] = other.str[i];
		}
		cout << "CopyAssigment:\t" << this << endl;
		return *this;

		/*size = other.size;
		for (int i = 0; i < size; i++)
		{
			str[i] = other.str[i];
			return *this;
		}
		*/
	}

	String& operator+=(const String& other)
	{
		return *this = *this + other;
	}

	char operator[](int i)const
	{
		return str[i];
	}

	char& operator[](int i)
	{
		return str[i];
	}

	//-----------------Methods------------------
	void print()const
	{
		cout << "Size:\t" << size << endl;
		cout << "Str:\t" << str << endl;
	}
};

String operator+(const String& left, const String& right)
{
	String cat(left.get_size() + right.get_size() - 1);	//удаление \0
	for (int i = 0; i < left.get_size(); i++)
	{
		cat[i] = left[i];
	}
	for (int i = 0; i < right.get_size(); i++)
	{
		cat[i + left.get_size() - 1] = right[i];
	}
	return cat;
}

std::ostream& operator<<(std::ostream& os, String& obj)
{
	return os << obj.get_str();
}

#define HOME_WORK

void main()
{
	setlocale(LC_ALL, "");
	/*String str;
	str.print();*/

#ifdef HOME_WORK
	String str1 = "Hello";
	str1 = str1;
	cout << str1 << endl;

	String str2 = "World";
	cout << str2 << endl;

	//String str3 = str1 + str2;		//Copy constructor
	String str3;
	str3 = str1 + str2;
	cout << str3 << endl;

	str1 += str2;
	cout << str1 << endl;
#endif // HOME_WORK

}
//String (ClassString)
#define _CRT_SECURE_NO_WARNINGS
#include<Windows.h>
#include<iostream>
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
#define delimiter "\n--------------------------------------------------------"

class String
{
	int size;
	char* str;
public:
	const char* get_str()const
	{
		return str;
	}
	char* get_str()
	{
		return str;
	}
	const int get_size()const
	{
		return size;
	}
	//				Constructors:
	explicit String(int size = 80)
	{
		this->size = size;
		this->str = new char [size] {};
		cout << "DefConstructor:\t" << this << endl;
	}
	String(const char str[])
	{
		this->size = strlen(str) + 1;
		this->str = new char[size] {};
		for (int i = 0; str[i]; i++)this->str[i] = str[i];
		cout << "Constructor:\t" << this << endl;
	}
	String(const String& other)
	{
		this->size = other.size;
		this->str = new char [size] {};
		for (int i = 0;i<size; i++)this->str[i] = other.str[i];
		cout << "CopyConstructor: " << this << endl;
	}
	String(String&& other)
	{
		//String&& - r-value reference
		this->size = other.size;
		this->str = other.str;
		other.size = 0;
		other.str = nullptr;

		cout << "MoveConstructor:"<< this << endl;
	}
	~String()
	{
		delete[] str;
		cout << "Destructor:\t" << this << endl;
	}

	//				Metods:
	void print()const
	{
		cout << "Size:\t" << size << endl;
		cout << "Str:\t" << str << endl;
	}
	//				Operators:
	String& operator=(const String& other)
	{
		if (this == &other)return *this;
		delete[]this->str;
		this->size = other.size;
		this->str = new char [size] {};
		for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		cout << "CopyAssigment:\t" << this << endl;
		return *this;
	}
	const char operator[](int i) const
	{
		return str[i];
	}
	char& operator[](int i)
	{
		return str[i];
	}
	String& operator= (String&& other)
	{
		if (this == &other)return *this;
		delete[]this->str;
		this->size = other.size;
		this->str = new char [size] {};
		for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		other.size = 0;
		other.str = nullptr; 
		cout << "MoveAssigment:\t" << this << endl;
		return *this;
	}
};

std::ostream& operator<<(std::ostream& os, const String& str);
String operator+(const String& left, const String& right);

void main()
{
	setlocale(LC_ALL, "");
	String str(12);
	str.print();

	String str1 = "Hello";
	str1 = str1;
	//str1.print();
	//cout << str1 << endl;

	String str2;
	str2 = "World!";
	//cout << str2 << endl;
	cout << delimiter << endl;
	String str3 = str1 + str2;
	cout << delimiter << endl;
	
	cout << str3 << endl;
}



std::ostream& operator<<(std::ostream& os, const String& obj)
{
	return os << obj.get_str();
}

String operator+(const String& left, const String& right)
{
	String result (left.get_size() + right.get_size()-1);
	int size = result.get_size();
	int right_size = right.get_size();
	int left_size = left.get_size()-1;
	for (int i = 0; i < left.get_size(); i++)
	{
		result.get_str()[i] = left.get_str()[i];
	}
	int j = 0;
	for (int i = left_size; i < size; i++)
	{
		result.get_str()[i] = right.get_str()[j];
		j++;
	}	
	return result;

}
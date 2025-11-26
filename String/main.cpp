//String (ClassString)
#define _CRT_SECURE_NO_WARNINGS
#include<Windows.h>
#include<iostream>
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
#define delimiter "\n--------------------------------------------------------"
#define CALLING_CONSTRUCTORS

//#define OPRERATORS_CHECK
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
	explicit String(int size = 80):size(size), str(new char[size]{})
	{
		//this->size = size;
		//this->str = new char [size] {};
		cout << "DefConstructor:\t" << this << endl;
	}
	String(const char str[]):size(strlen(str)+1),str(new char[size]{})
	{
		//this->size = strlen(str) + 1;
		//this->str = new char[size] {};
		for (int i = 0; str[i]; i++)this->str[i] = str[i];
		cout << "Constructor:\t" << this << endl;
	}
	String(const String& other):size(other.size), str(new char[size]{})
	{
		//this->size = other.size;
		//this->str = new char [size] {};
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
		this->str = other.str;
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
#ifdef OPRERATORS_CHECK
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
	String str3;
	str3 = str1 + str2;
	cout << delimiter << endl;
	
	cout << str3 << endl;
#endif
#ifdef CALLING_CONSTRUCTORS

	String str1;//Default Constructor
	str1.print();

	String str2(5);//Single-argument constructor int (explicit)
	str2.print();

	String str3 = "Hello";
	str3.print();

	String str4();//NOT Default constructor

	String str5{};
	str5.print();

	String str6{ 7 };
	str6.print();

	String str7("World");//Конструктор с одним параметром, типа 'const char*'
	str7.print();
	String str8{ "World" };//Конструктор с одним параметром, типа 'const char*' 
	str8.print();
	String str9 = str3;//Copy Constructor
	String str10(str9);//Copy Constructor
	String str11{ str9 };//Copy Constructor
	
	String str12 = str3 + str7;//MoveConstructor
	str12.print();

	String str13(str3 + str7);//MoveConstructor
	str13.print();

	String str14{ str3 + str7 };//MoveConstructor
	str14.print();
#endif
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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
#define delimeter "\n-----------------------------------------------\n"

//#define  CONSTRUCTORS_CHECK
//#define ARITHMETIC_CHECK
//#define COMPOUND_ASSIGNMENTS_CHECK
//#define INCREMENTO_DECREMENTO
//#define STREAMS_CHECK1
//#define TYPE_CONVERTIONS_BASIC
//#define CONVERSION_FROM_OTHER_TO_CLASS
#define HW

class Fraction
{
	int integer;
	int numerator;
	int denominator;
public:
	//				Get/Set
	int get_num()const
	{
		return numerator;
	}
	int get_denom()const
	{
		return denominator;
	}
	int get_integer()const
	{
		return integer;
	}
	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0) denominator = 1;
		this->denominator = denominator;
	}
	//				Constructor
	Fraction()
	{
		integer = 0;
		numerator = 0;
		denominator = 1;
		cout << "DefaultConstructor:\t" << this << endl;
	}
	explicit Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "SingleArgumentConstructor:" << this << endl;
	}
	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		set_numerator(numerator);
		set_denominator(denominator);
		cout << "Constructor:\t\t" << this << endl;
	}
	Fraction(int integer, int numerator, int denominator)
	{
		set_integer(integer);
		set_numerator(numerator);
		set_denominator(denominator);
		cout << "Constructor:\t\t" << this << endl;
	}
	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyConstructor: " << this << endl;
	}
	//				Destrctor
	~Fraction()
	{
		cout << "Destrctor:\t" << this << endl;
	}
	//				Operators
	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssigment:\t\t" << this << endl;
		return *this;
	}
	Fraction operator+=(Fraction other)
	{
		other.to_improper();
		this->numerator = this->numerator * other.denominator + other.numerator * this->denominator;
		this->denominator *= other.denominator;
		cout << "CopyAssigment:\t\t" << this << endl;
		return *this;
	}
	Fraction operator-=(Fraction other)
	{
		other.to_improper();
		this->numerator = this->numerator * other.denominator - other.numerator * this->denominator;
		this->denominator *= other.denominator;
		cout << "CopyAssigment:\t\t" << this << endl;
		return *this;
	}
	Fraction operator*=(Fraction other)
	{
		other.to_improper();
		this->numerator *= other.numerator;
		this->denominator *= other.denominator;
		cout << "CopyAssigment:\t\t" << this << endl;
		return *this;
	}
	Fraction operator/=(Fraction other)
	{
		other.to_improper();
		this->numerator *= other.denominator;
		this->denominator *= other.numerator;
		cout << "CopyAssigment:\t\t" << this << endl;
		return *this;
	}
	Fraction& operator++()
	{
		this->integer += 1;
		return *this;
	}
	Fraction operator++(int) //Всегда принимает только int и возвращает значение.
	{
		Fraction old = *this;
		this->integer++;
		return old;
	}
	Fraction& operator--()
	{
		this->integer -= 1;
		return *this;
	}
	Fraction operator--(int) //Всегда принимает только int и возвращает значение.
	{
		Fraction old = *this;
		this->integer--;
		return old;
	}

	//				Metods
	Fraction& to_improper()
	{
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}
	Fraction& to_proper()
	{
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
	}
	Fraction inverted()const
	{
		Fraction inverted = *this;
		inverted.to_improper();
		std::swap(inverted.numerator, inverted.denominator);
		return inverted;
	}
	Fraction& reduce()
	{
		int more, less, rest = 0;
		if (numerator > denominator) more = numerator, less = denominator;
		else less = numerator, more = denominator;
		do
		{
			rest = more % less;
			more = less;
			less = rest;
		} while (rest);
		int GCD = more; //GCD - Greatest Common Divisor (НОД)
		numerator /= GCD;
		denominator /= GCD;
		return *this;
	}

	void print()const
	{
		if (integer)cout << integer;
		if (numerator)
		{
			if (integer) cout << "(";
			cout << numerator << "/" << denominator;
			if (integer) cout << ")";
		}
		else if (integer == 0)cout << 0;
		cout << endl;
	}
};

Fraction operator+(const Fraction left, const Fraction right);
Fraction operator-(const Fraction left, const Fraction right);
Fraction operator/(const Fraction left, const Fraction right);
Fraction operator*(Fraction left, Fraction right);
bool operator==(Fraction left, Fraction right);
bool operator!=(Fraction left, Fraction right);
bool operator>=(Fraction left, Fraction right);
bool operator<=(Fraction left, Fraction right);
bool operator<(Fraction left, Fraction right);
bool operator>(Fraction left, Fraction right);
std::ostream& operator<<(std::ostream& os, const Fraction& obj);
std::istream& operator>>(std::istream& is, Fraction& obj);



void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTRUCTORS_CHECK
	Fraction A;
	A.print();

	Fraction B = 5;
	B.print();

	Fraction C(1, 2);
	C.print();

	Fraction D(2, 3, 4);
	D.print();

	Fraction E = D;
	E.print();
#endif
#ifdef ARITHMETIC_CHECK

	Fraction A(2, 3, 4);
	A.print();

	Fraction B(3, 4, 5);
	B.print();

	Fraction C = A / B;
	C.to_proper();
	C.print();
#endif
#ifdef OMPOUND_ASSIGNMENTS_CHECK
	Fraction A(2, 3, 4);
	Fraction B(3, 4, 5);
	A *= B;
	A.print();

	A /= B;
	A.reduce();
	A.print();
#endif
#ifdef INCREMENTO_DECREMENTO
	for (Fraction i(1, 2); i.get_integer() < 10; i++)
	{
		i.print();
	}

	Fraction A(1, 2);
	Fraction B = A++;
	B.print();
#endif
#ifdef STREAMS_CHECK1
	Fraction A(2, 3, 4);
	cout << "Введите простую дробь: "; cin >> A;
	cout << endl << A << endl;
#endif
#ifdef TYPE_CONVERTIONS_BASIC
	int a = 2;
	double b = a;
	int c = b;
	int d = 3.14;
#endif
#ifdef CONVERSION_FROM_OTHER_TO_CLASS
	Fraction A = (Fraction)5;
	cout << A << endl;

	Fraction B;
	B = Fraction(8);
	cout << B << endl;
#endif
#ifdef HW
	Fraction A = 2.45;
	cout << A << endl;
#endif
}
Fraction operator*(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	left.to_improper();
	right.to_improper();
	return Fraction
	(
		left.get_num() * right.get_num(),
		left.get_denom() * right.get_denom()
	);

}
Fraction operator+(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	left.to_improper();
	right.to_improper();
	return Fraction
	(
		left.get_num() * right.get_denom() + right.get_num() * left.get_denom(),
		left.get_denom() * right.get_denom()
	);

}
Fraction operator-(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	left.to_improper();
	right.to_improper();
	return Fraction
	(
		left.get_num() * right.get_denom() - right.get_num() * left.get_denom(),
		left.get_denom() * right.get_denom()
	);

}
Fraction operator/(Fraction left, Fraction right)
{

	return Fraction
	(
		left * right.inverted()
	);

}
bool operator==(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return left.get_num() * right.get_denom() == right.get_num() * left.get_denom();
}
bool operator!=(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return left.get_num() * right.get_denom() != right.get_num() * left.get_denom();
}
bool operator>=(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return left.get_num() * right.get_denom() >= right.get_num() * left.get_denom();
}
bool operator<=(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return left.get_num() * right.get_denom() <= right.get_num() * left.get_denom();
}
bool operator<(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return left.get_num() * right.get_denom() < right.get_num() * left.get_denom();
}
bool operator>(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return left.get_num() * right.get_denom() > right.get_num() * left.get_denom();
}
std::ostream& operator<<(std::ostream& os, const Fraction& obj)
{
	if (obj.get_integer()) os << obj.get_integer();
	if (obj.get_num())
	{
		if (obj.get_integer())os << "(";
		os << obj.get_num() << "/" << obj.get_denom();
		if (obj.get_integer())os << ")";
	}
	else if (obj.get_integer() == 0) os << 0;
	return os;
}
std::istream& operator>>(std::istream& is, Fraction& obj)
{
	const int SIZE = 32;
	char buffer[SIZE] = {};
	is >> buffer;
	//is.getline(buffer, SIZE);
	cout << buffer << endl;
	int numbers[3] = {};
	const char delimiters[] = "+( )/";
	int n = 0;
	for (char* pch = strtok(buffer, delimiters); pch; pch = strtok(NULL, delimiters))
	{
		numbers[n++] = std::atoi(pch);
		//cout << pch << "\t";
	}
	for (int i = 0; i < n; i++)
	{
		cout << numbers[i] << endl;
	}
	cout << endl;
	switch (n)
	{
	case 1: obj = Fraction(numbers[0]); break;
	case 2: obj = Fraction(numbers[0], numbers[1]); break;
	case 3: obj = Fraction(numbers[0], numbers[1], numbers[2]); break;
	}
	/*int integer;
	int numerator;
	int denominator;
	is >> integer >> numerator >> denominator;
	obj = Fraction(integer, numerator, denominator);
	*/

	return is;
	
}

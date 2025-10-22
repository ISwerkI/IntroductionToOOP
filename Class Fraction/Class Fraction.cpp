#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
#define delimeter "\n-----------------------------------------------\n"

//#define  CONSTRUCTORS_CHECK

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
	Fraction(int integer)
	{
		this->integer = integer;
		this -> numerator = 0;
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
	
	//				Metods
	void to_improper()
	{
		numerator += integer * denominator;
		integer = 0;
	}
	void to_proper()
	{
		integer += numerator / denominator;
		numerator %= denominator;
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

	Fraction A(2, 3, 4);
	A.print();

	Fraction B(3, 4, 5);
	B.print();

	Fraction C(0,2,4);
	C += A;

	A.to_proper();
	A.print();
	A.to_improper();
	A.print();
	C.to_proper();
	C.print();
}

Fraction operator*( Fraction left, Fraction right)
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
Fraction operator+( Fraction left, Fraction right)
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
Fraction operator-( Fraction left, Fraction right)
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
Fraction operator/( Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	left.to_improper();
	right.to_improper();
	return Fraction
	(
		left.get_num() * right.get_denom(),
		left.get_denom() * right.get_num()
	);

}
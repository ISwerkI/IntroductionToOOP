#include <iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

class Fraction
{
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
	void set_num(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denom(int denominator)
	{
		this->denominator = denominator;
	}
	//				Constructor
	Fraction()
	{
		numerator = {};
		denominator = 1;
		cout << "DefaultConstructor:\t" << this << endl;
	}
	Fraction(int numerator, int denominator)
	{
		if (denominator == 0) denominator = 1;
		this->numerator = numerator;
		this->denominator = denominator;
		cout << "NumDenomArgConstructor:\t" << this << endl;
	}
	Fraction(const Fraction& other)
	{
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyConstructor:\t" << this << endl;
	}
	//				Destrctor
	~Fraction()
	{
		cout << "Destrctor:\t" << this << endl;
	}
	//				Operators
	Fraction& operator=(const Fraction& other)
	{
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssigment:\t\t" << this << endl;
		return *this;
	}
	//				Metods
	void print()const
	{
		cout << numerator << "/" << denominator << endl;
	}
	void reduction()
	{
		int result;
		while (true)
		{
			int i;
			if (numerator & 2 == 0)
			{
				numerator /= 2;
				i = 2;
			}
			else if (numerator & 3 == 0)
			{
				numerator /= 3;
				i = 3;
			}
			else if (numerator & 5 == 0)
			{
				numerator /= 5;
				i = 5;
			}
			else
			{
				result *= numerator;
				break;
			}

			if (denominator & 2 == 0)
			{
				denominator /= 2;
				i = 2;
			}
			else if (denominator & 3 == 0)
			{
				denominator /= 3;
				i = 3;
			}
			else if (denominator & 5 == 0)
			{
				denominator /= 5;
				i = 5;
			}
			else
			{
				result *= denominator;
				break;
			}
		}
	}
};

Fraction operator+(const Fraction& left, const Fraction& right);
Fraction operator-(const Fraction& left, const Fraction& right);
Fraction operator/(const Fraction& left, const Fraction& right);
Fraction operator*(const Fraction& left, const Fraction& right);

void main()
{
	setlocale(LC_ALL, "");
	Fraction A(2,3);
	Fraction B(4, 3);
	A.print();
	B.print();
	Fraction C;
	C = B - A;
	C.print();
}

Fraction operator+( Fraction& left, Fraction& right)
{
	Fraction result;
	result.set_num(left.get_num() * right.get_denom() + right.get_num() * left.get_denom());
	result.set_denom(left.get_denom() * right.get_denom());
	return result;
}
Fraction operator-(const Fraction& left, const Fraction& right)
{
	Fraction result;
	result.set_num(left.get_num() * right.get_denom() - right.get_num() * left.get_denom());
	result.set_denom(left.get_denom() * right.get_denom());
	return result;
}
Fraction operator/(const Fraction& left, const Fraction& right)
{
	Fraction result;
	result.set_num(left.get_num() * right.get_denom());
	result.set_denom(left.get_denom() * right.get_num());
	return result;
}
Fraction operator*(const Fraction& left, const Fraction& right)
{
	Fraction result;
	result.set_num(left.get_num() * right.get_num());
	result.set_denom(left.get_denom() * right.get_denom());
	return result;
}
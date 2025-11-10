//String (ClassString)
#include<Windows.h>
#include<iostream>
using std::cin;
using std::cout;
using std::endl;

int StringLenght(const char str[]);
char* ToUpper(char str[]);
char* ToLower(char str[]);
char* DelSpace(char str[]);
bool is_palindrome(char str[]);
bool is_int_number(char str[]);
bool is_bin_number(char str[]);

//#define LINES_BASICS_1

void main()
{
	setlocale(LC_ALL, "");
#ifdef LINES_BASICS_1
	//char str[] = { 'H','e','l','l','o', '\0'};
	//char str[] = { 'H','e','l','l','o', 0};
	char str[] = "He1llo";
	cout << str << endl;
	cout << sizeof(str) << endl;
#endif
	const int SIZE = 20;
	char str[SIZE] = {};
	cout << "Введите строку: ";
	SetConsoleCP(1251);
	cin.getline(str,SIZE);
	cout << str <<endl;
	cout << StringLenght(str) << endl;
	is_bin_number(str);

}

int StringLenght(const char str[])
{
	int counter;
	for (counter = 0; str[counter] != "\0"[0]; counter++)
	{

	}
	return counter;
}

char* ToUpper(char str[])
{
	int const SIZE = StringLenght(str);
	for (int i = 0; i < SIZE ;i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z') str[i] = str[i] - ' ';
		if (str[i] >= 'а' && str[i] <= 'я') str[i] = str[i] - ' ';
		if (str[i] == 'ё')str[i] -= 16;
		if (str[i] == ' ') continue;
	}
	return str;
}

char* ToLower(char str[])
{
	int const SIZE = StringLenght(str);
	for (int i = 0; i < SIZE; i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z') str[i] = str[i] + ' ';
		if (str[i] >= 'А' && str[i] <= 'Я') str[i] = str[i] + ' ';
		if (str[i] == 'Ё')str[i] += 16;
	}
	return str;
}
char* DelSpace(char str[])
{
	int SIZE = StringLenght(str);
	for (int i = 0; i < SIZE; i++)
	{
		if (str[i] == ' ' and str[i - 1] == ' ')
		{
			for (int j = i; j < SIZE; j++)
			{
				str[j] = str[j + 1];
			}
			SIZE--;
			i--;
		}
		if (str[0] == ' ')
		{
			for (int j = 0; j < SIZE; j++)
			{
				str[j] = str[j + 1];
			}
			SIZE--;
		}
	}
	return str;
}
bool is_palindrome(char str[])
{
	bool palindrome_check = 1;
	str = ToLower(str);
	int SIZE = StringLenght(str);
	if (SIZE % 2 == 1) SIZE -= 1;
	for (int i = 0; i < SIZE/2; i++, SIZE--)
	{
		if (str[i] != str[SIZE]) palindrome_check = 0; break;
	}
	if (palindrome_check == 0) cout << "Данная строка не является палиндромом" << endl;
	else cout << "Данная строка является палиндромом!" << endl;
	return palindrome_check;
}

bool is_int_number(char str[])
{
	bool number_check = 1;
	int SIZE = StringLenght(str);
	for (int i = 0; i < SIZE; i++)
	{
		if (str[i] >= '0' && str[i] <= '9') continue;
		else number_check = 0; break;
	}
	if (number_check == 0) cout << "Данная строка не является целым десятичным числом" << endl;
	else cout << "Данная строка является целым десятичным числом!" << endl;
	return number_check;
}
bool is_bin_number(char str[])
{
	bool bin_check = 1;
	int SIZE = StringLenght(str);
	for (int i = 0; i < SIZE; i++)
	{
		if (str[i] != '0' and str[i] != '1') bin_check = 0; break;
	}
	if (bin_check == 0) cout << "Данная строка не является двоичным числом" << endl;
	else cout << "Данная строка является двоичным числом числом!" << endl;
	return bin_check;
}

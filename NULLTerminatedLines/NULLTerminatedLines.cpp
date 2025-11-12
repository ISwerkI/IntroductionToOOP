//String (ClassString)
#define _CRT_SECURE_NO_WARNINGS
#include<Windows.h>
#include<iostream>
using std::cin;
using std::cout;
using std::endl;

int StringLenght(const char str[]);
char* ToUpper(char str[]);
char* ToLower(char str[]);
char* DelSpace(char str[]);
bool is_palindrome(const char str[]);
bool is_int_number(const char str[]);
bool is_bin_number(const char str[]);
int bin_to_dec(const char str[]);
bool is_hex_number(const char str[]);
int hex_to_dec(const char str[]);
bool is_MAC_adress(const char str[]);

//#define LINES_BASICS_1
//#define LINES_BASICS_2
#define NUMERICS
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
#ifdef LINES_BASICS_2
	const int SIZE = 256;
	char str[SIZE] = {};
	cout << "Введите строку: ";
	SetConsoleCP(1251);
	cin.getline(str, SIZE);
	cout << str << endl;
	cout << StringLenght(str) << endl;
	is_palindrome(str);
#endif
#ifdef NUMERICS
	const int SIZE = 33;
	char str[SIZE] = {};
	cout << "Введите строку: ";
	SetConsoleCP(1251);
	cin.getline(str, SIZE);
	cout << is_MAC_adress(str) << endl;
#endif
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
	for (int i = 0; i < SIZE; i++)
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
		if (str[SIZE] == ' ')
		{
			for (int j = 0; j < SIZE - 1; j++)
			{
				str;
			}
			SIZE--;
		}
	}
	return str;
}
char* RemoveSymbol(char str[], char symbol = ' ')
{
	for (int i = 0; str[i]; i++)
	{
		while (str[i] == symbol)
		{
			for (int j = i; str[j]; j++) str[j] = str[j + 1];
		}
	}
	return str;
}
bool is_palindrome(const char str[])
{
	bool palindrome_check = 1;
	int SIZE = StringLenght(str);
	char* buffer = new char[SIZE + 1] {};
	strcpy(buffer, str);
	ToLower(buffer);
	RemoveSymbol(buffer);
	SIZE = StringLenght(buffer);
	for (int i = 0; i < SIZE / 2; i++)
	{
		if (buffer[i] != buffer[SIZE - 1 - i]) palindrome_check = 0; break;
	}
	if (palindrome_check == 0) cout << "Данная строка не является палиндромом" << endl;
	else cout << "Данная строка является палиндромом!" << endl;
	delete[] buffer;
	return palindrome_check;

}

bool is_int_number(const char str[])
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
bool is_bin_number(const char str[])
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
int bin_to_dec(const char str[])
{
	if (!is_bin_number(str))return INT_MIN;
	int decimal = 0;
	int weight = 1;
	int lenght = StringLenght(str);
	for (int i = lenght - 1; i >= 0; i--)
	{
		if (str[i] == ' ') continue;
		decimal += (str[i] - '0') * weight;
		weight *= 2;
	}
	return decimal;
}
bool is_hex_number(const char str[])
{
	bool number_check = 1;
	int SIZE = StringLenght(str);
	for (int i = 0; i < SIZE; i++)
	{
		if (str[i] >= '0' && str[i] <= '9' || str[i] >= 'A' && str[i] <= 'F') continue;
		else number_check = 0; break;
	}
	if (number_check == 0) cout << "Данная строка не является шеснадцатиричным числом" << endl;
	else cout << "Данная строка является шеснадцатиричным числом!" << endl;
	return number_check;
}

int hex_to_dec(const char str[])
{
	int decimal = 0;
	int weight = 1;
	int lenght = StringLenght(str);
	bool prefix = false;
	if (str[0] == '0' && str[1] == 'x')prefix = true;
	for (int i = lenght - 1; i >= (prefix ? 2 : 0); i--)
	{
		int digit;
		if (str[i] >= '0' && str[i] <= '9') digit = str[i] - 48;
		if (str[i] >= 'A' && str[i] <= 'F') digit = str[i] - 55;
		decimal += digit * weight;
		weight *= 16;
	}
	return decimal;
}

bool is_MAC_adress(const char str[])
{
	if (strlen(str) != 17) return false;
	for (int i = 0; str[i]; i++)
	{
		if ((i + 1) % 3 == 0 && (str[i] == '-' || str[i] == ':')) continue;
		else if ((i + 1) % 3 == 0) return false;
		if (
				!(str[i] >= '0' && str[i] <= '9') &&
				!(str[i] >= 'A' && str[i] <= 'F') &&
				!(str[i] >= 'a' && str[i] <= 'f')
				)return false;
	}
	return true;
}
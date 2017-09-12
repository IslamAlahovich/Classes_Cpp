// P1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <cstring>
#include <string.h>
#include <iostream>

using namespace std;

class String {
private:
	char* data;

public:
	String() // конструктор по умолчанию (создает пустую строку)
	{
		data = new char[1];
		strcpy(data, "");
	}
	
	String(char* my_str) // конструктор с параметром
	{
		data = new char[strlen(my_str) + 1];
		strcpy(data, my_str);
	}

	String(String& my_str) // конструктор копирования
	{
		int len = strlen(my_str.data);
		if (len)
		{
			data = new char[len + 1];
			strcpy(data, my_str.data);
		}
		else
		{
			data = new char[1];
			strcpy(data, "");
		}
	}

	~String() // деструктор
	{
		delete[] data;
	}

	void show() const // вывод значения
	{
		cout << data << endl;
	}

	String  operator+ (String) const; // конкатенация двух строк(+)
	void operator+= (String); // конкатенация двух строк(+=)
	String& operator= (const String&); // оператор присваивания
	char  operator[] (int) const; // оператора [] (константный для чтения)
	char& operator[] (int); // оператора [] (возвращающий char &)
	operator char* () const // оператор приведения к const char *
	{
		return data;
	}

};

//-----------------------ПЕРЕГРУЗКИ-------------------------------------------------------------------------------------------

String String::operator+ (String my_str) const
{
	char* concat = new char[strlen(data) + strlen(my_str.data) + 1];
	strcpy(concat, data);
	strcat(concat, my_str.data);
	return String(concat);
}

void String::operator+= (String my_str)
{
	strcat(data, my_str.data);
}

String& String::operator= (const String& my_str)
{
	if (this != &my_str)
	{
		this->data = new char[strlen(my_str.data) + 1];
		strcpy(this->data, my_str.data);
	}
	return *this;
}

char String::operator[] (int my_index) const
{
	if (my_index < 0 || my_index >= strlen(data))
	{
		cout << "\nINDEX ERROR" << endl;
	}
	else
	{
		return data[my_index];
	}
}

char& String::operator[] (int my_index)
{
	if (my_index < 0 || my_index >= strlen(data))
	{
		cout << "\nINDEX ERROR" << endl;
	}
	else
	{
		return *(data + my_index);
	}
}

//-----------------------ПРОВЕРКА--------------------------------------------------------------------------------------------

int main() 
{
	String str1; // пустая строка
	String str2 = "FALLOUT"; // используется конструктор с одним параметром
	String str3("vault-tec"); // также используется конструктор с одним параметром 
	String str4 = str2; // конструктор копирования
	String str5(str3);  // конструктор копирования

	cout << "SHOW:" << endl;
	str1.show();
	str2.show();
	str3.show();
	str4.show();
	str5.show();

	cout << "\nproverka operatora privideniya k tipu \"char\": " << endl;
	cout << "str2 = ";
	str2.show();
	char* some_str = str2;
	cout << "char* some_str = str2\nsome_str: " << some_str << endl;

	cout << "\nproverka rabotu operatora prisvaivania:" << endl;
	cout << "str2 = ";
	str2.show();
	cout << "str5 = ";
	str5.show();
	cout << "teper prisvaivaem str2 = str5..." << endl;
	str2 = str5;
	cout << "str2 = ";
	str2.show();
	cout << "str5 = ";
	str5.show();

	cout << "\nproverka rabotu operetora\"+\":";
	str1 = "\nlucky,boy ";
	cout << "str1 = ";
	str1.show();
	cout << "str3 = ";
	str3.show();
	cout << "str4 = str1 + str3\nstr4 = ";
	str4 = str1 + str3;
	str4.show();

	cout << "\nproverka rabotu operatora\"+=\": ";
	str2 = "Zdarova!";
	str1 += str2;
	cout << "str2 = ";
	str2.show();
	cout << "str1 = ";
	str1.show();

	cout << "\nproverka rabotu operatora\"[]\": ";
	str1.show();
	cout << "zadaite index" << endl;
	int index;
	cin >> index;
	cout << str1[index];


	cout << "\n\nteper menat budem\n";
	cout << "zadaite index: ";
	cin >> index;
	cout << "zadaite novoe znachenie: ";
	char value;
	cin >> value;
	str1[index] = value;
	str1.show();
	cout << "pomenyali" << endl;

    return 0;
}


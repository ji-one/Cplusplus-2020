#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
class MyString
{
	char *str;
	int size;

public:
	MyString() {} //default constructor

	MyString(const string &_str)
		: size(_str.length()), str(new char[_str.length() + 1])
	{
		for (int i = 0; i < _str.length(); i++)
		{
			str[i] = _str[i];
		}
		str[_str.length()] = '\0';
	}

	void set(const string &_str)
	{
		delete[] str;
		size = _str.length();
		str = new char[size + 1];
		for (int i = 0; i < size; i++)
		{
			str[i] = _str[i];
		}
		str[size] = '\0';
	}

	bool isEqual(const MyString &mystring) const
	{
		if (mystring.size != size)
			return false;
		for (int i = 0; i < size; i++)
		{
			if (mystring.str[i] != str[i])
			{
				return false;
			}
		}
		return true;
	}

	MyString(const MyString &another)
		: size(another.size), str(new char[another.size + 1])
	{
		for (int i = 0; i < another.size; i++)
		{
			str[i] = another.str[i];
		}
		str[another.size] = '\0';
	}

	void print() const
	{
		cout << str << '\n';
	}

	~MyString()
	{
		delete[] str;
	}
};

int main()
{
	MyString strs[] = {
		MyString("C"),
		MyString(),
		MyString("Java")};
	strs[1].set("C++");

	const MyString target("Java");
	for (int i = 0; i < 3; i++)
	{
		const MyString str(strs[i]);
		if (str.isEqual(target))
		{
			cout << "[" << i << "]: ";
			str.print();
			break;
		}
	}
	for (int i = 0; i < 3; i++)
	{
		const MyString &str = strs[i];
		str.print();
	}
}

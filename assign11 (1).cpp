#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

class Complex {
private:
	float real, imaginary;

public:
	Complex(float _real, float _imaginary)
		:real(_real),imaginary(_imaginary)
	{}

	void print() const
	{
		cout << real << ", " << imaginary;
	}

	bool isEqual(const Complex& c) 
	{
		if (real == c.real && imaginary == c.imaginary)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};class MyString {
private:
	char* str;
public:
	MyString(char* _str)
	:str(_str)
	{}

	void print() const 
	{
		cout << str;
	}

	bool isEqual(const char* s)
	{
		if (strcmp(str,s)==0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

};template <class T, int sz>
class List
{
	vector<T> v;

public:
	List(){}

	void add(const T& data)
	{
		if (v.size() < sz)
		{
			v.push_back(data);
			data.print();
			cout << " is added\n";
		}
	}

	void add(const char* data)
	{
		if (v.size() < sz)
		{
			MyString s(const_cast<char*>(data));
			v.push_back(s);
			s.print();
			cout << " is added\n";
		}
	}

	void find(const T& data)
	{
		typename vector<T>::iterator it;
		for (it = v.begin(); it != v.end(); it++)
		{
			if (it->isEqual(data))
			{
				data.print();
				cout << " is found\n";
				return;
			}
		}
		data.print();
		cout << " is not found\n";
	}

	void find(const char* data)
	{
		typename vector<T>::iterator it;
		for (it = v.begin(); it != v.end(); it++)
		{
			if (it->isEqual(data))
			{
				it->print();
				cout << " is found\n";
				return;
			}
		}
		cout << data <<" is not found\n";
	}

	void remove(const T& data)
	{
		typename vector<T>::iterator it;
		for (it = v.begin(); it != v.end(); it++)
		{
			if (it->isEqual(data))
			{
				v.erase(it);
				data.print();
				cout << " is removed\n";
				break;
			}
		}
	}

	void remove(const char* data)
	{
		typename vector<T>::iterator it;
		for (it = v.begin(); it != v.end(); it++)
		{
			if (it->isEqual(data))
			{
				v.erase(it);
				cout << data << " is removed\n";
				break;
			}
		}
	} 
};

int main() {
	List<Complex, 100> cList;
	List<MyString, 200> sList;
	cList.add(Complex(0, 0));
	cList.add(Complex(1, 1));
	sList.add("abc");
	sList.add("def");
	cList.find(Complex(1, 0));
	sList.find("def");
	cList.remove(Complex(0, 0));
	sList.remove("abc");
	List<MyString, 200> s2List(sList);
	List<MyString, 200> s3List;
	s3List.add("123");
	s3List = s2List;
	s3List.remove("def");
}
#include <iostream>
#include <string>
using namespace std;

class StackException {
	const string msg;
public:
	StackException(const string& msg) : msg(msg) {};
	void print() const { cout << msg << endl; }
};

class CharStack {
	int size;
	int top;
	char* s;
public:
	CharStack(int sz)
	{
		top = 0;
		s = new char[size = sz];
	}

	// destructor, copy constructor, and assignment operator
	CharStack(const CharStack& cs)
	{
		size = cs.size;
		top = cs.top;
		s = new char[cs.size];
		for (int i = 0; i < cs.top; i++)
		{
			s[i] = cs.s[i];
		}
	}

	void operator = (const CharStack& cs)
	{
		size = cs.size;
		top = cs.top;
		delete[] s;
		s = new char[cs.size];
		for (int i = 0; i < cs.top; i++)
		{
			s[i] = cs.s[i];
		}
	}

	void push(char c)
	{
		if (top == size)
		{
			throw StackException("Stack is full");
		}
		s[top++] = c;
	}

	char pop()
	{
		if (top == 0)
		{
			throw StackException("Stack is empty");
		}
		char r = s[--top];
		s[top] = '\0';
		return r;
	}

	void print() const
	{
		for (int i = 0; i < top; i++)
			cout << s[i];
		cout << endl;
	}

	~CharStack()
	{
		delete[] s;
	}

};

int main(void)
{
	cout << "[Stack Full Exception Check]\n";
	try
	{
		CharStack cs(2);
		cs.push('a');
		cs.push('b');
		cs.push('c'); //error
	}
	catch (const StackException & e)
	{
		e.print();
	}

	cout << "\n[Stack Empty Exception Check]\n";
	try
	{
		CharStack cs(2);
		cs.push('a');
		cout << cs.pop() << '\n';
		cout << cs.pop() << '\n'; //error
	}
	catch (const StackException & e)
	{
		e.print();
	}
	
	cout << "\n[Copy Constructor & Stack Full Exception Check]\n";
	try
	{
		CharStack cs1(2);
		cs1.push('a');
		cs1.push('b');

		CharStack cs2(cs1);
		cs2.push('c'); //error
	}
	catch (const StackException & e)
	{
		e.print();
	}
	
	cout << "\n[Assignment Operator & Stack Empty Exception Check]\n";
	try
	{
		CharStack cs1(2);
		cs1.push('a');
		cs1.push('b');
		CharStack cs2 = cs1;
		cout << cs2.pop() << '\n';
		cout << cs2.pop() << '\n';
		cout << cs2.pop() << '\n';//error
	}
	catch (const StackException & e)
	{
		e.print();
	}
}

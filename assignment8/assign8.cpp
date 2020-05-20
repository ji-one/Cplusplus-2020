#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

enum EmployeeLevel
{
	���,
	�븮,
	����,
	����,
	����
};
class Employee
{
	string name;
	const EmployeeLevel level;

public:
	Employee(const string& _name, const EmployeeLevel _level)
		: name(_name), level(_level)
	{
	}

	string getName() const
	{
		return name;
	}

	EmployeeLevel getLevel() const
	{
		return level;
	}

	friend ostream& operator<<(ostream& os, const Employee& employee);
};

ostream& operator<<(ostream& os, const Employee& employee)
{
	os << employee.level << ' ' << employee.name << '\n';

	return os;
}

class Manager : public Employee
{
	vector<Employee*> group;

public:
	Manager(const string& _name, const EmployeeLevel _level)
		: Employee(_name, _level)
	{
	}

	void addEmployee(Employee* employee)
	{
		group.push_back(employee);
	}

	friend ostream& operator<<(ostream& os, const Manager& manager);
};

ostream& operator<<(ostream& os, const Manager& manager)
{
	os << manager.getLevel() << ' ' << manager.getName() << '\n';

	os << "List of employees managed by me" << '\n';

	for (unsigned int i = 0; i < manager.group.size(); i++)
	{
		os << *(manager.group[i]);
	}

	return os;
}
int main()
{
	Employee e1("ȫ", ���), e2("��", �븮), e3("��", ���);
	cout << e1 << e2 << e3;
	Manager m1("Tom", ����);
	m1.addEmployee(&e1);
	m1.addEmployee(&e2);
	m1.addEmployee(&e3);
	cout << endl
		<< "Information for Manager" << endl;
	cout << m1;
}

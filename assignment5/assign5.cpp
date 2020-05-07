#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

enum MajorType
{
	CE,
	EE,
	ME,
	UD
};

class Major
{
private:
	MajorType majorType;

public:
	void setMajor(const MajorType _majorType)
	{
		majorType = _majorType;
	}
	const MajorType getMajor()
	{
		return majorType;
	}
};

class Student
{
private:
	string name;
	float gpa;
	Major major;

public:
	void setGPA(const float _gpa)
	{
		gpa = _gpa;
	}
	void setMajor(const MajorType _major)
	{
		major.setMajor(_major);
	}
	void setName(const string &_name)
	{
		name = _name;
	}

	const string &getName()
	{
		return name;
	}

	const float getGPA()
	{
		return gpa;
	}

	const MajorType getMajor()
	{
		return major.getMajor();
	}
};

class School
{
private:
	string schoolName;
	vector<Student> students;

public:
	School(const string &_schoolName)
		: schoolName(_schoolName), students(0)
	{
	}

	Student *addStudent(const string &studentName, MajorType major)
	{
		Student student;
		student.setName(studentName);
		student.setMajor(major);
		students.push_back(student);
		return &students.back();
	}

	Student *addStudent(const string &studentName, const float gpa)
	{
		Student student;
		student.setName(studentName);
		student.setGPA(gpa);
		students.push_back(student);
		return &students.back();
	}

	void print()
	{
		cout << "School Name: " << schoolName << ", Count: " << students.size() << '\n';
		for (int i = 0; i < students.size(); i++)
		{
			cout << "    Name: " << students[i].getName() << " GAP: " << students[i].getGPA() << " Major: ";
			const MajorType major = students[i].getMajor();
			if (major == CE)
			{
				cout << "Computer Eng." << '\n';
			}
			else if (major == EE)
			{
				cout << "Electrical Eng." << '\n';
			}
			else if (major == ME)
			{
				cout << "Mechanical Eng." << '\n';
			}
		}
		cout << '\n';
	}

	void sort()
	{
		int size = students.size();
		if (size > 0)
		{
			for (int i = size - 1; i > 0; i--)
			{
				for (int j = 0; j < i; j++)
				{
					if (students[j].getGPA() < students[j + 1].getGPA())
					{
						swap(students[j], students[j + 1]);
					}
				}
			}
		}
	}
};

int main()
{
	School pnu("PNU");
	Student *kim = pnu.addStudent("Kim", EE);
	kim->setGPA(3.5F);
	Student *hong = pnu.addStudent("Hong", CE);
	hong->setGPA(4.3F);
	Student *lee = pnu.addStudent("Lee", 4.0F);
	lee->setMajor(CE);
	Student *joo = pnu.addStudent("Joo", 1.5F);
	joo->setMajor(ME);
	pnu.print();
	pnu.sort(); // descending
	pnu.print();
}

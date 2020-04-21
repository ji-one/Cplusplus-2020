#include <bits/stdc++.h>
using namespace std;
class Student
{
private:
	string name;
	float gpa;

public:
	void setName(const string &_name)
	{
		name = _name;
	}
	void setGPA(const float _gpa)
	{
		gpa = _gpa;
	}
	const string &getName()
	{
		return name;
	}
	const float getGPA()
	{
		return gpa;
	}
};

class School
{
private:
	string schoolName;
	vector<Student> students;

public:
	//constructor
	School(const string &_schoolName)
		: schoolName(_schoolName), students(0)
	{
	}
	void addStudent(const string &name, const float gpa = 0.0F)
	{
		Student student;
		student.setName(name);
		student.setGPA(gpa);
		students.push_back(student);
	}
	void print()
	{
		cout << "School Name: " << schoolName << ", Count: " << students.size() << '\n';
		for (unsigned int i = 0; i < students.size(); i++)
		{
			cout << "    Name: " << students[i].getName() << " GPA: " << students[i].getGPA() << '\n';
		}
		cout<<'\n';
	}
	void sort()
	{
		unsigned int size = students.size();
		if (size > 0)
		{
			for (unsigned int i = 0; i < size; i++)
			{
				for (unsigned int j = 0; j < size - i; j++)
				{
					if (students[j].getGPA() < students[j + 1].getGPA())
					{
						swap(students[j], students[j + 1]);
					}
				}
			}
		}
	}
	Student &findStudentWithName(const string &name)
	{
		unsigned int size = students.size();
		if (size > 0)
		{
			for (unsigned int i = 0; i < size; i++)
			{
				if (students[i].getName() == name)
				{
					return students[i];
				}
			}
		}
		static Student empty;
		return empty;
	}
};

int main()
{
	School pnu("PNU");

	pnu.addStudent("Kim", 2.7F);
	pnu.addStudent("Hong", 3.5F);
	pnu.addStudent("Lee");
	pnu.addStudent("Joo", 1.5F);

	pnu.print();

	pnu.sort(); // descending
	pnu.print();

	School knu("KNU");
	knu.addStudent("Seo", 2.5F);
	knu.addStudent("Lee", 3.8F);
	knu.print();

	Student &lee = pnu.findStudentWithName("Lee");
	lee.setGPA(3.3F);
	lee.setName("Yoon");

	pnu.print();

	knu.addStudent("Hong", 4.3F);
	Student &hong = knu.findStudentWithName("Hong");
	hong.setGPA(3.3F);
	hong.setName("Joon");
	knu.print();
}

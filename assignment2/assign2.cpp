#include <bits/stdc++.h>
using namespace std;

const int SUBJECT_NO = 3;

struct StudentInfo
{
	string name;
	int scores[SUBJECT_NO];
	int sum;
	float average;
};

void printStudentInfo(const StudentInfo &student)
{
	cout.setf(ios::left);
	cout << setw(8) << student.name;
	for (int i = 0; i < SUBJECT_NO; i++)
	{
		cout << setw(8) << student.scores[i];
	}
	cout << setw(8) << student.sum << student.average << '\n';
}

void printVectorStudentInfo(const vector<StudentInfo> &studentVector, const vector<int> &total)
{
	int index = 1;
	cout.setf(ios::left);
	//use iterator
	typedef vector<StudentInfo>::const_iterator iterator;
	for (iterator it = studentVector.begin(); it != studentVector.end(); ++it)
	{
		cout << setw(8) << index;
		printStudentInfo(*it);
		index++;
	}

	cout << setw(16) << "Total";

	for (int i = 0; i <= SUBJECT_NO; i++)
	{
		cout << setw(8) << total[i];
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	vector<StudentInfo> students;
	vector<int> total(SUBJECT_NO + 1);

	int studentNum;
	cin >> studentNum;

	for (int i = 0; i < studentNum; i++)
	{
		StudentInfo studentinfo;
		cin >> studentinfo.name;
		studentinfo.sum = 0;
		for (int i = 0; i < SUBJECT_NO; i++)
		{
			cin >> studentinfo.scores[i];
			studentinfo.sum += studentinfo.scores[i];
			total[i] += studentinfo.scores[i];
		}
		total[SUBJECT_NO] += studentinfo.sum;
		studentinfo.average = static_cast<float>(studentinfo.sum) / SUBJECT_NO;

		students.push_back(studentinfo);
	}
	printVectorStudentInfo(students, total);
	
	return 0;
}

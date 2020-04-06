#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cout << "Enter the score count: ";
	int maxSize;
	cin >> maxSize;
	int currentSize = 0;
	int totalSum = 0;
	int *const scores = new int[maxSize];
	while (1)
	{
		string cmd;
		cout << "Enter command: (add, sum, average, quit) ";
		cin >> cmd;
		transform(cmd.begin(), cmd.end(), cmd.begin(), ::tolower);
		if (cmd == "add")
		{
			if (currentSize < maxSize)
			{
				cout << "Enter score: ";
				int score;
				cin >> score;
				if (score >= 0 && score <= 100)
				{
					scores[currentSize++] = score;
					totalSum += score;
					cout << score << " added\n";
				}
				else
				{
					cout << "Score should be between 0 and 100\n";
				}
			}
			else
			{
				cout << "Too many scores\n";
			}
		}
		else if (cmd == "sum")
		{
			cout << "Sum: " << totalSum << '\n';
		}
		else if (cmd == "average")
		{
			if (currentSize == 0)
			{
				cout << "1개 이상의 점수가 입력되어야 한다.\n";
			}
			else
			{
				double avg = static_cast<double>(totalSum) / currentSize;
				cout << "Average: " << avg << '\n';
			}
		}
		else //cmd == "quit"
		{
			cout << "Bye\n";
			break;
		}
	}
	delete[] scores;
	return 0;
}

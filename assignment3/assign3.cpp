#include <bits/stdc++.h>
using namespace std;
struct Rectangle
{
	int width;
	int height;
};

enum CommandKind
{
	ADD,
	SORT,
	PRINT,
	CLEAR,
	EXIT,
	INVALID
};
const CommandKind getCommandKind(string cmdstring)
{
	int cmd;
	if (cmdstring == "ADD")
		cmd = 0;
	else if (cmdstring == "SORT")
		cmd = 1;
	else if (cmdstring == "PRINT")
		cmd = 2;
	else if (cmdstring == "CLEAR")
		cmd = 3;
	else if (cmdstring == "EXIT")
		cmd = 4;
	else
		cmd = 5;
	const CommandKind command = static_cast<CommandKind>(cmd);
	return command;
}

const Rectangle &getRectangle()
{
	static Rectangle rectangle;
	cin >> rectangle.width >> rectangle.height;
	return rectangle;
}
void print(const Rectangle &rectangle)
{
	cout << '\t' << rectangle.width << ' ' << rectangle.height << ' ' << rectangle.width * rectangle.height << '\n';
}
void print(const vector<Rectangle> &rectangleVector)
{
	cout << "Rectangle Count: " << rectangleVector.size() << '\n';
	//use const_iterator
	typedef vector<Rectangle>::const_iterator iterator;
	for (iterator it = rectangleVector.begin(); it != rectangleVector.end(); it++)
	{
		print(*it);
	}
}
void sort(vector<Rectangle> &rectangleVector)
{
	if (rectangleVector.size() > 0)
	{
		for (int i = 0; i < rectangleVector.size() - 1; i++)
		{
			int smallestIndex = i;

			for (int j = i + 1; j < rectangleVector.size(); j++)
			{
				if (rectangleVector[j].width < rectangleVector[smallestIndex].width)
				{
					smallestIndex = j;
				}
				if (rectangleVector[j].width == rectangleVector[smallestIndex].width)
				{
					if (rectangleVector[j].height < rectangleVector[smallestIndex].height)
					{
						smallestIndex = j;
					}
				}
			}
			swap(rectangleVector[i], rectangleVector[smallestIndex]);
		}
	}
}

int main()
{
	vector<Rectangle> rectangles;
	while (true)
	{
		string commandString;
		cin >> commandString;
		const CommandKind command = getCommandKind(commandString);
		switch (command)
		{
		case ADD:
		{
			const Rectangle &newRectangle = getRectangle();
			rectangles.push_back(newRectangle);
			break;
		}
		case PRINT:
			print(rectangles);
			//use const_iterator in print()
			//define and call print(const Rectangle&)
			break;
		case SORT:
		{
			sort(rectangles); //define and call swap in sort()
			print(rectangles);
			break;
		}
		case CLEAR:
			rectangles.clear();
			break;
		case EXIT:
			break;
		default:
			assert(false);
			break;
		}
		if (command == EXIT)
			break;
	}
}

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

enum Color { RED, BLUE, YELLOW };

class Shape {
	Color lineColor;
public:
	Color getLineColor() const { return lineColor; }
	virtual Shape* clone() const = 0;
	virtual void print() const = 0;
	virtual float getLength() const = 0;
};

class Point {
	int x, y;
public:
	Point(int _x, int _y)
		:x(_x), y(_y)
	{}
	int getX() const
	{
		return x;
	}
	int getY() const
	{
		return y;
	}

	friend ostream& operator<<(ostream& os, const Point& point)
	{
		os << "(" << point.getX() << ", " << point.getY() << ")";
		return os;
	}
};

class  ClosedShape : public Shape {

public:
	virtual float getArea() const = 0;
};

class ShapeList {
	vector<Shape*> shapes;
public:

	ShapeList()
		:shapes() {}

	~ShapeList() {
		if (!shapes.empty())
		{
			for (auto it = shapes.begin(); it != shapes.end(); it++) {
				delete *it;
			}
		}
	}

	void addShape(Shape* const shape)
	{
		Shape* const s = shape->clone();
		shapes.push_back(s);
	}

	float getTotalArea() const {
		auto totalArea = 0.0F;
		for (const auto shape : shapes)
		{
			ClosedShape* const cs = dynamic_cast<ClosedShape*>(shape);
			totalArea += cs->getArea();
		}
		return totalArea;
	}

	void print() const {
		for (auto it = shapes.begin(); it != shapes.end(); it++)
		{
			(*it)->print();
		}
	}
};

class Polygon : public ClosedShape {

};

class Rectangle : public Polygon {
	Point p1, p2, p3, p4;
public:

	Rectangle(Point _p1, Point _p2, Point _p3, Point _p4)
		:p1(_p1), p2(_p2), p3(_p3), p4(_p4)
	{}

	float getArea() const {

		float h = (float)(abs(p1.getY() - p2.getY()));
		float w = (float)(abs(p3.getX() - p1.getX()));

		float area = h * w;
		return area;
	}

	float getLength() const
	{
		float length = 0.0F;
		length += (float)(sqrt(pow(p1.getX() - p2.getX(), 2) + pow(p1.getY() - p2.getY(), 2)));
		length += (float)(sqrt(pow(p2.getX() - p3.getX(), 2) + pow(p2.getY() - p3.getY(), 2)));
		length = length * 2.0F;
		return length;
	}

	void print() const {
		cout << "Rectangle: " << p1 << p2 << p3 << p4 << '\n';
	}

	Shape* clone() const {
		return new Rectangle(*this);
	}

};

class Triangle : public Polygon {
	Point p1, p2, p3;
public:
	Triangle(Point _p1, Point _p2, Point _p3)
		:p1(_p1), p2(_p2), p3(_p3)
	{}

	float getArea() const {
		int x1 = p1.getX();
		int x2 = p2.getX();
		int x3 = p3.getX();
		int y1 = p1.getY();
		int y2 = p2.getY();
		int y3 = p3.getY();

		float area = (float)(0.5 * abs((x1 * y2 + x2 * y3 + x3 * y1) - (x1 * y3 + x3 * y2 + x2 * y1)));
		return area;
	}
	float getLength() const {
		float length = 0.0F;
		length += (float)sqrt(pow(p1.getX() - p2.getX(), 2) + pow(p1.getY() - p2.getY(), 2));
		length += (float)sqrt(pow(p2.getX() - p3.getX(), 2) + pow(p2.getY() - p3.getY(), 2));
		length += (float)sqrt(pow(p3.getX() - p1.getX(), 2) + pow(p3.getY() - p1.getY(), 2));

		return length;
	}

	void print() const {
		cout << "Triangle: " << p1 << p2 << p3 << '\n';
	}

	Shape* clone() const {
		return new Triangle(*this);
	}

};

int main() {
	Point p1(0, 0), p2(0, 10), p3(20, 20), p4(20, 30);
	Shape* const r = new Rectangle(p1, p2, p3, p4);
	Shape* const t = new Triangle(p1, p2, p3);
	ShapeList list{};
	list.addShape(r);
	list.addShape(t);
	delete r;
	delete t;
	list.print();
	cout << list.getTotalArea() << endl;
}

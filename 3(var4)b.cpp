#include <iostream>

using namespace std;

class CPoint
{
protected:
	double x, y;
public:
	CPoint(double newX = 0, double newY = 0) : x(newX), y(newY)
	{
		cout << "CPoint (base class) constructor\n";
	};

	virtual ~CPoint() {};

	double getX() const { return this->x; }
	double getY() const { return this->y; }
	void setX(double newX) { this->x = newX; }
	void setY(double newY) { this->y = newY; }

	void set(double newX, double newY)
	{
		this->x = newX;
		this->y = newY;
	}

	virtual void print() const
	{
		cout << "(X: " << x << ", Y: " << y << ")\n";
	}
};

class CColoredPoint : public CPoint
{
protected:
	string color;
public:
	CColoredPoint(double newX = 0, double newY = 0, const string& newColor = "Black") :
		CPoint(newX, newY), color(newColor)
	{
		cout << "CColoredPoint constructor(X, Y, color)\n";
	}
	CColoredPoint(const string& newColor) :
		CPoint(0, 0), color(newColor)
	{
		cout << "CColoredPoint constructor(color)\n";
	}

	string getColor() const { return this->color; }
	void setColor(const string& newColor) { this->color = newColor; }

	void set(double newX, double newY, const string& newColor)
	{
		this->x = newX;
		this->y = newY;
		this->color = newColor;
	}

	void print() const override
	{
		cout << "(X: " << x << ", Y: " << y << ", Color: " << color << ")\n";
	}
};

class CLine : public CPoint
{
protected:
	CPoint point1, point2;
public:
	CLine(double newX1 = 0, double newY1 = 0, double newX2 = 1, double newY2 = 1) :
		point1(newX1, newY1), point2(newX2, newY2)
	{
		cout << "CLine constructor(X1, Y1, X2, Y2)\n";
	}
	CLine(CPoint& newPoint1, CPoint& newPoint2) :
		point1(newPoint1), point2(newPoint2)
	{
		cout << "CLine constructor(point1, point2)\n";
	}

	double getX1() const { return this->point1.getX(); }
	double getX2() const { return this->point2.getX(); }
	double getY1() const { return this->point1.getY(); }
	double getY2() const { return this->point2.getY(); }

	void setPoint1(double newX, double newY)
	{
		this->point1.setX(newX);
		this->point1.setY(newY);
	}
	void setPoint2(double newX, double newY)
	{
		this->point2.setX(newX);
		this->point2.setY(newY);
	}

	void set(double newX1, double newY1, double newX2, double newY2)
	{
		this->point1.setX(newX1);
		this->point1.setY(newY1);
		this->point2.setX(newX2);
		this->point2.setY(newY2);
	}

	void print() const override
	{
		cout << "Point1: (X: " << point1.getX() << ", Y: " << point1.getY() << ")\n"
			<< "Point2: (X: " << point2.getX() << ", Y: " << point2.getY() << ")\n";
	}
};

class CColoredLine : public CColoredPoint, public CLine
{
public:
	CColoredLine(double newX1 = 0, double newY1 = 0, double newX2 = 1, double newY2 = 1, const string& newColor = "Black") :
		CLine(newX1, newY1, newX2, newY2), CColoredPoint(newColor)
	{
		cout << "CColoredLine constructor(X1, Y1, X2, Y2, color)\n";
	}
	CColoredLine(CPoint& newPoint1, CPoint& newPoint2, const string& newColor) :
		CLine(newPoint1, newPoint2), CColoredPoint(newColor)
	{
		cout << "CColoredLine constructor(point1, point2, color)\n";
	}
	CColoredLine(CLine& newLine1, const string& newColor) :
		CLine(newLine1), CColoredPoint(newColor)
	{
		cout << "CColoredLine constructor(line1, color)\n";
	}

	void set(double newX1, double newY1, double newX2, double newY2, const string& newColor)
	{
		CLine::set(newX1, newY1, newX2, newY2);
		this->color = newColor;
	}

	void print() const override
	{
		cout << "Point1: (X: " << point1.getX() << ", Y: " << point1.getY() << ")\n"
			<< "Point2: (X: " << point2.getX() << ", Y: " << point2.getY() << ")\n"
			<< "Color: " << CColoredPoint::getColor() << endl;
	}
};

int main()
{
	CPoint point1(-15, 10);
	CPoint point2(6, -5);

	cout << "Point1: ";
	point1.print();
	cout << "Point2: ";
	point2.print();

	CLine line1(-5, 5, 5, 5);
	CLine line2(point1, point2);

	cout << "Line1: ";
	line1.print();
	cout << "Line2: ";
	line2.print();

	CColoredPoint coloredPoint1(-1.5, 5.7, "Red");
	CColoredPoint coloredPoint2(-5.3, -2, "Yellow");
	CColoredPoint coloredPoint3(10, -5.9, "Red");

	cout << "Colored point 1: ";
	coloredPoint1.print();
	cout << "Colored point2: ";
	coloredPoint2.print();
	cout << "Colored point3 :";
	coloredPoint3.print();

	CColoredLine coloredLine1(-4.3, 7, 10, 5.6, "Green");
	CColoredLine coloredLine2(point1, point2, "Yellow");
	CColoredLine coloredLine3(line1, "Red");

	cout << "Colored line1: ";
	coloredLine1.print();
	cout << "Colored line2: ";
	coloredLine2.print();
	cout << "Colored line3: ";
	coloredLine3.print();

	cout << "-----------------------------------------------------------------\n";
	cout << "Point1: (X: " << point1.getX() << ", Y: " << point1.getY() << ")\n";
	point1.setX(200);
	point1.setY(50);
	cout << "Point1: ";
	point1.print();
	point1.set(100, 300);
	cout << "Point1: ";
	point1.print();
	cout << "-----------------------------------------------------------------\n";
	cout << "Colored point1: (X: " << coloredPoint1.getX() << ", Y: " << coloredPoint1.getY() << ", Color: " << coloredPoint1.getColor() << ")\n";
	coloredPoint1.setX(5.2);
	coloredPoint1.setY(51);
	coloredPoint1.setColor("Purple");
	cout << "Colored point1: ";
	coloredPoint1.print();
	coloredPoint1.set(-5, -9.8, "White");
	cout << "Colored point1: ";
	coloredPoint1.print();
	cout << "-----------------------------------------------------------------\n";
	cout << "Line1: (X1: " << line1.getX1() << ", Y1: " << line1.getY1() << ", X2: " << line1.getX2() << ", Y2: " << line1.getY2() << ")\n";
	line1.setPoint1(41, -30);
	line1.setPoint2(-70, 83.1);
	cout << "Line1: ";
	line1.print();
	line1.set(100, 300, 200, 400);
	cout << "Line1: ";
	line1.print();
	cout << "-----------------------------------------------------------------\n";
	cout << "Colored line1: (X1: " << coloredLine1.getX1() << ", Y1: " << coloredLine1.getY1() << ", X2: " << coloredLine1.getX2() << ", Y2: " << coloredLine1.getY2() << ", color:" << coloredLine1.getColor() << ")\n";
	coloredLine1.setPoint1(30, -12);
	coloredLine1.setPoint2(-60, 75.123);
	cout << "Colored line1: ";
	coloredLine1.print();
	coloredLine1.set(-40, -50, 42.1, 68.23, "Grey");
	cout << "Colored line1: ";
	coloredLine1.print();
}
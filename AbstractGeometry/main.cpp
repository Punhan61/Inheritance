#include<iostream>
#include<windows.h>
using namespace std;

namespace Geometry
{
	enum Color
	{
		console_default = 0x07,
		console_blue = 0x99,
		console_green = 0xAA,
		console_red = 0xCC,
		console_yellow = 0xEE,
	};

	class Shape
	{
	protected:
		Color color;
	public:
		Shape(Color color) :color(color) {}
		virtual ~Shape() {}
		virtual double area()const = 0;
		virtual double perimeter()const = 0;
		virtual void draw()const = 0;
		virtual void info()const
		{
			cout << "������� ������: " << area() << endl;
			cout << "�������� ������: " << perimeter() << endl;
			draw();
		}
	};

	class Square :public Shape
	{

		double side;
	public:
		double get_side()const
		{
			return side;
		}
		void set_side(double side)
		{
			if (side < 5)side = 5;
			if (side > 20)side = 20;
			this->side = side;
		}
		// Constructor
		Square(double side, Color color) :Shape(color)
		{
			set_side(side);
		}
		~Square() {}
		double area()const override
		{
			return side * side;
		}
		double perimeter()const override
		{
			return side * 4;
		}
		void draw()const override
		{
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, color);

			for (int i = 0; i < side; i++)
			{
				for (int j = 0; j < side; j++)
				{
					cout << "* ";
				}
				cout << endl;
			}
			SetConsoleTextAttribute(hConsole, Color::console_default);
		}
		void info()const override
		{
			cout << typeid(*this).name() << endl;
			cout << "����� ������� ��������: " << side << endl;
			Shape::info();
		}
	};
	class Rectangle :public Shape
	{
		double width;
		double length;
	public:
		double get_widht()const
		{
			return width;
		}
		double get_length()const
		{
			return length;
		}
		void set_width(double width)
		{
			if (width < 8)width = 8;
			if (width > 30)width = 30;
			this->width = width;
		}
		void set_length(double length)
		{
			if (length < 3)length = 3;
			if (length > 20)length = 20;
			this->length = length;
		}
		Rectangle(double width, double length, Color color) :Shape(color)
		{
			set_width(width);
			set_length(length);
		}
		~Rectangle() {}
		double area()const override
		{
			return width * length;
		}
		double perimeter()const override
		{
			return(width + length) * 2;
		}
		void draw()const
		{
			/*HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, color);
			for (int i = 0; i < length; i++)
			{
				for (int j = 0; j < width; j++)
				{
					cout << "* ";
				}
				cout << endl;
			}
			SetConsoleTextAttribute(hConsole, Color::console_default);*/

			//1) �������� ���� �������
			HWND hwnd = GetConsoleWindow();
			//2) �������� �������� ���������� ��� ���� �������
			HDC hdc = GetDC(hwnd); // ��� ��,�� ��� ����� ��������

			//3) ������� �������� - ��� ��, ��� �� ����� ��������(�������� ������ �����)
			HPEN hPen = CreatePen(PS_SOLID, 5, color);
			//4) ������� �����.����� ������ ������� � ��������� ������
			HBRUSH hbrush = CreateSolidBrush(color);
			//5) �������� ��� � �� ��� �� ����� ��������
			SelectObject(hdc, hPen);
			SelectObject(hdc, hbrush);

			//6) ������ �������������
			::Rectangle(hdc, 100, 100, 500, 300);

			// ������� ��������
			DeleteObject(hPen);
			
			ReleaseDC(hwnd, hdc);
		}
		void info()const override
		{
			cout << typeid(*this).name() << endl;
			cout << "������: " << width << endl;
			cout << "�����: " << length << endl;
			Shape::info();
		}
	};
}

void main()
{
	setlocale(LC_ALL, "");
	//Shape shape;
	Geometry::Square square(8,Geometry::Color::console_red);
	square.info();

	Geometry::Rectangle rect(15, 7,Geometry::Color::console_yellow);
	rect.info();

}
#include <iostream>
	using std::cout;
	using std::endl;

#include <math.h>

#include "color.h"

#define FLOOR(x) (x >= 1) ?(unsigned char)255 : (unsigned char)floor(x * 255)

const Color Color::black = Color();
const Color Color::grey = Color(0.5, 0.5, 0.5);
const Color Color::white = Color(1, 1, 1);


Color Color::defaultColor = black;
Color Color::background = black;

Color::Color() : r(0), g(0), b(0)
{

}

Color::Color(double c1, double c2, double c3) : r(c1), g(c2), b(c3)
{

}

const Color & Color::operator += (const Color &c)
{
	r += c.r;
	g += c.g;
	b += c.b;

	return *this;
}

Color Color::operator * (double t)
{
	return Color(r * t, g * t, b * t);
}

void Color::SetBackground(const Color &bk)
{
	background = bk;
}

void Color::Print()
{
	cout << "<" << r << ", " << g << ", " << b << ">" << endl;
}

unsigned char Color::GetRed()
{
	return FLOOR(r);
}

unsigned char Color::GetGreen()
{
	return FLOOR(g);
}

unsigned char Color::GetBlue()
{
	return FLOOR(b);
}

Color operator + (const Color &c1, const Color &c2)
{
	return Color(c1.r + c2.r, c1.g + c2.g, c1.b + c2.b);
}

Color operator * (const Color &c1, const Color &c2)
{
	return Color(c1.r * c2.r, c1.g * c2.g, c1.b * c2.b);
}

void Color::GetRGBComponents(unsigned char *comp)
{
	comp[0] = FLOOR(r);
	comp[1] = FLOOR(g);
	comp[2] = FLOOR(b);
}

void Color::GetBGRComponents(unsigned char *comp)
{
	comp[0] = FLOOR(b);
	comp[1] = FLOOR(g);
	comp[2] = FLOOR(r);
}

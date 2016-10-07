#pragma once

class Color
{
public:

	double r,g,b;

	Color();
	Color(double c1, double c2, double c3);

	const Color & operator += (const Color &c);
	Color operator * (double x);

	unsigned char GetRed();
	unsigned char GetGreen();
	unsigned char GetBlue();

	void GetRGBComponents(unsigned char *comp);
	void GetBGRComponents(unsigned char *comp);

	void Print();

	static const Color black;
	static const Color grey;
	static const Color white;

	static Color background;
	static Color defaultColor;

	static void SetBackground(const Color &bk);
};

Color operator + (const Color &c1, const Color &c2);
Color operator * (const Color &c1, const Color &c2);


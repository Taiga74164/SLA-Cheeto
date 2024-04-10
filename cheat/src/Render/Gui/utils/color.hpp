#pragma once
#define DEFCOLOR_SRC(name, r, g, b) \
	static Color name##(uint8_t a = 255){ return Color(r, g, b, a); }
#include <imgui.h>
#include <imgui_internal.h>

class Color {
public:

	Color() {
		SetColor(0, 0, 0, 255);
	}

	Color(uint8_t r, uint8_t g, uint8_t b) {
		SetColor(r, g, b, 255);
	}

	Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
		SetColor(r, g, b, a);
	}

	ImU32 GetU32()
	{
		return ((_color[3] & 0xff) << 24) + ((_color[2] & 0xff) << 16) + ((_color[1] & 0xff) << 8)
			+ (_color[0] & 0xff);
		//return (ImU32)(((_color[3] & 0xff) << 24) + ((_color[0] & 0xff) << 16) + ((_color[1] & 0xff) << 8) + (_color[2] & 0xff));
	}

	void SetColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255) {
		_color[0] = (uint8_t)r;
		_color[1] = (uint8_t)g;
		_color[2] = (uint8_t)b;
		_color[3] = (uint8_t)a;
	}

	void GetColor(uint8_t &r, uint8_t &g, uint8_t &b, uint8_t &a) const {
		r = _color[0];
		g = _color[1];
		b = _color[2];
		a = _color[3];
	}

	inline float rBase() const { return _color[0] / 255.0f; }
	inline float gBase() const { return _color[1] / 255.0f; }
	inline float bBase() const { return _color[2] / 255.0f; }

	inline float aBase() const { return _color[3] / 255.0f; }

	void SetAlpha(int alpha) { _color[3] = alpha; }

	uint8_t &operator[](int index) {
		return _color[index];
	}

	const uint8_t &operator[](int index) const {
		return _color[index];
	}

	bool operator == (const Color &rhs) const {
		return (*((int *)this) == *((int *)&rhs));
	}

	bool operator != (const Color &rhs) const {
		return !(operator==(rhs));
	}

	Color DiffAlpha(int a)
	{
		return Color(this->r(), this->g(), this->b(), a);
	}

	int r() { return _color[0]; }
	int g() { return _color[1]; }
	int b() { return _color[2]; }
	int a() { return _color[3]; }

	int GetR() { return _color[0]; }
	int GetG() { return _color[1]; }
	int GetB() { return _color[2]; }
	int GetA() { return _color[3]; }

	void SetR(uint8_t _i) { _color[0] = _i; }
	void SetG(uint8_t _i) { _color[1] = _i; }
	void SetB(uint8_t _i) { _color[2] = _i; }
	void SetA(uint8_t _i) { _color[3] = _i; }

	Color &operator=(const Color &rhs) {
		*(int*)(&_color[0]) = *(int*)&rhs._color[0];
		return *this;
	}

	Color operator+(const Color &rhs) const {
		int red = _color[0] + rhs._color[0];
		int green = _color[1] + rhs._color[1];
		int blue = _color[2] + rhs._color[2];
		int alpha = _color[3] + rhs._color[3];

		red = red > 255 ? 255 : red;
		green = green > 255 ? 255 : green;
		blue = blue > 255 ? 255 : blue;
		alpha = alpha > 255 ? 255 : alpha;

		return Color(red, green, blue, alpha);
	}

	Color operator-(const Color &rhs) const {
		int red = _color[0] - rhs._color[0];
		int green = _color[1] - rhs._color[1];
		int blue = _color[2] - rhs._color[2];
		int alpha = _color[3] - rhs._color[3];

		red = red < 0 ? 0 : red;
		green = green < 0 ? 0 : green;
		blue = blue < 0 ? 0 : blue;
		alpha = alpha < 0 ? 0 : alpha;
		return Color(red, green, blue, alpha);
	}

	operator const uint8_t*() {
		return (uint8_t*)(&_color[0]);
	}

	static Color Outline()
	{
		return Color(9, 9, 9);
	}

	static Color FromHSB(float hue, float saturation, float brightness)
	{
		float h = hue == 1.0f ? 0 : hue * 6.0f;
		float f = h - (int)h;
		float p = brightness * (1.0f - saturation);
		float q = brightness * (1.0f - saturation * f);
		float t = brightness * (1.0f - (saturation * (1.0f - f)));

		if (h < 1)
		{
			return Color(
				(unsigned char)(brightness * 255),
				(unsigned char)(t * 255),
				(unsigned char)(p * 255)
			);
		}
		else if (h < 2)
		{
			return Color(
				(unsigned char)(q * 255),
				(unsigned char)(brightness * 255),
				(unsigned char)(p * 255)
			);
		}
		else if (h < 3)
		{
			return Color(
				(unsigned char)(p * 255),
				(unsigned char)(brightness * 255),
				(unsigned char)(t * 255)
			);
		}
		else if (h < 4)
		{
			return Color(
				(unsigned char)(p * 255),
				(unsigned char)(q * 255),
				(unsigned char)(brightness * 255)
			);
		}
		else if (h < 5)
		{
			return Color(
				(unsigned char)(t * 255),
				(unsigned char)(p * 255),
				(unsigned char)(brightness * 255)
			);
		}
		else
		{
			return Color(
				(unsigned char)(brightness * 255),
				(unsigned char)(p * 255),
				(unsigned char)(q * 255)
			);
		}
	}

	DEFCOLOR_SRC(Black, 0, 0, 0);
	DEFCOLOR_SRC(White, 255, 255, 255);
	DEFCOLOR_SRC(Red, 255, 0, 0);
	DEFCOLOR_SRC(Green, 0, 255, 0);
	DEFCOLOR_SRC(Blue, 0, 0, 255);
	DEFCOLOR_SRC(Lime, 0, 255, 0);
	DEFCOLOR_SRC(Yellow, 255, 255, 0);
	DEFCOLOR_SRC(Cyan, 0, 255, 255);
	DEFCOLOR_SRC(Magenta, 255, 0, 255);
	DEFCOLOR_SRC(Silver, 192, 192, 192);
	DEFCOLOR_SRC(Gray, 128, 128, 128);
	DEFCOLOR_SRC(Maroon, 128, 0, 0);
	DEFCOLOR_SRC(Olive, 128, 128, 0);
	DEFCOLOR_SRC(Purple, 128, 0, 128);
	DEFCOLOR_SRC(Teal, 0, 128, 128);
	DEFCOLOR_SRC(Navy, 0, 0, 128);
	DEFCOLOR_SRC(DarkRed, 139, 0, 0);
	DEFCOLOR_SRC(Brown, 165, 42, 42);
	DEFCOLOR_SRC(Firebrick, 178, 34, 34);
	DEFCOLOR_SRC(Crimson, 220, 20, 60);
	DEFCOLOR_SRC(IndianRed, 205, 92, 92);
	DEFCOLOR_SRC(LightCoral, 240, 128, 128);
	DEFCOLOR_SRC(DarkSalmon, 233, 150, 122);
	DEFCOLOR_SRC(Salmon, 250, 128, 114);
	DEFCOLOR_SRC(LightSalmon, 255, 160, 122);
	DEFCOLOR_SRC(OrangeRed, 255, 69, 0);
	DEFCOLOR_SRC(DarkOrange, 255, 140, 0);
	DEFCOLOR_SRC(Orange, 255, 165, 0);
	DEFCOLOR_SRC(Gold, 255, 215, 0);
	DEFCOLOR_SRC(DarkGoldenRod, 184, 134, 11);
	DEFCOLOR_SRC(GoldenRod, 218, 165, 32);
	DEFCOLOR_SRC(YellowGreen, 154, 205, 50);
	DEFCOLOR_SRC(DarkOliveGreen, 85, 107, 47);
	DEFCOLOR_SRC(OliveDrab, 107, 142, 35);
	DEFCOLOR_SRC(LawnGreen, 124, 252, 0);
	DEFCOLOR_SRC(ChartReuse, 127, 255, 0);
	DEFCOLOR_SRC(GreenYellow, 173, 255, 47);
	DEFCOLOR_SRC(DarkGreen, 0, 100, 0);
	DEFCOLOR_SRC(ForestGreen, 34, 139, 34);
	DEFCOLOR_SRC(LimeGreen, 50, 205, 50);
	DEFCOLOR_SRC(DarkCyan, 0, 139, 139);
	DEFCOLOR_SRC(Aqua, 0, 255, 255);
	DEFCOLOR_SRC(LightCyan, 224, 255, 255);
	DEFCOLOR_SRC(DarkTurquoise, 0, 206, 209);
	DEFCOLOR_SRC(Turquoise, 64, 224, 208);
	DEFCOLOR_SRC(MediumTurquoise, 72, 209, 204);
	DEFCOLOR_SRC(PaleTurquoise, 175, 238, 238);
	DEFCOLOR_SRC(Aquamarine, 127, 255, 212);
	DEFCOLOR_SRC(PowderBlue, 176, 224, 230);
	DEFCOLOR_SRC(DodgerBlue, 30, 144, 255);
	DEFCOLOR_SRC(Lightblue, 173, 216, 230);
	DEFCOLOR_SRC(SkyBlue, 135, 206, 235);
	DEFCOLOR_SRC(LightSkyBlue, 135, 206, 250);
	DEFCOLOR_SRC(MidnightBlue, 25, 25, 112);
	DEFCOLOR_SRC(DarkBlue, 0, 0, 139);
	DEFCOLOR_SRC(MediumBlue, 0, 0, 205);
	DEFCOLOR_SRC(RoyalBlue, 65, 105, 225);
	DEFCOLOR_SRC(BlueViolet, 138, 43, 226);
	DEFCOLOR_SRC(Indigo, 75, 0, 130);
	DEFCOLOR_SRC(DarkSlateBlue, 72, 61, 139);
	DEFCOLOR_SRC(SlateBlue, 106, 90, 205);
	DEFCOLOR_SRC(MediumSlateBlue, 123, 104, 238);
	DEFCOLOR_SRC(MediumPurple, 147, 112, 219);
	DEFCOLOR_SRC(Darkmagenta, 139, 0, 139);
	DEFCOLOR_SRC(Darkviolet, 148, 0, 211);
	DEFCOLOR_SRC(DarkGray, 169, 169, 169);
	DEFCOLOR_SRC(LightGray, 211, 211, 211);
	DEFCOLOR_SRC(Gainsboro, 220, 220, 220);
private:
	uint8_t _color[4];
};
struct Color2
{
	int r;
	int g;
	int b;
	int a;

	Color2()
	{
		this->r = 0;
		this->g = 0;
		this->b = 0;
		this->a = 255;
	}

	Color2(int r, int g, int b)
	{
		this->r = r;
		this->g = g;
		this->b = b;
		this->a = 255;
	}

	Color2(int r, int g, int b, int a)
	{
		this->r = r;
		this->g = g;
		this->b = b;
		this->a = a;
	}

	Color2 operator / (float div)
	{
		Color2 color = *this;
		color.r = color.r / div;
		color.g = color.g / div;
		color.b = color.b / div;
		return color;
	}

	Color2& operator /= (float div)
	{
		Color2& color = *this;
		color.r /= div;
		color.g /= div;
		color.b /= div;
		return color;
	}

	Color2& operator *= (float coeff)
	{
		Color2& color = *this;
		color.r *= coeff;
		color.g *= coeff;
		color.b *= coeff;
		return color;
	}

	static Color2 FromHSB(float hue, float saturation, float brightness)
	{
		float h = hue == 1.0f ? 0 : hue * 6.0f;
		float f = h - (int)h;
		float p = brightness * (1.0f - saturation);
		float q = brightness * (1.0f - saturation * f);
		float t = brightness * (1.0f - (saturation * (1.0f - f)));

		if (h < 1)
		{
			return Color2(
				(unsigned char)(brightness * 255),
				(unsigned char)(t * 255),
				(unsigned char)(p * 255)
			);
		}
		else if (h < 2)
		{
			return Color2(
				(unsigned char)(q * 255),
				(unsigned char)(brightness * 255),
				(unsigned char)(p * 255)
			);
		}
		else if (h < 3)
		{
			return Color2(
				(unsigned char)(p * 255),
				(unsigned char)(brightness * 255),
				(unsigned char)(t * 255)
			);
		}
		else if (h < 4)
		{
			return Color2(
				(unsigned char)(p * 255),
				(unsigned char)(q * 255),
				(unsigned char)(brightness * 255)
			);
		}
		else if (h < 5)
		{
			return Color2(
				(unsigned char)(t * 255),
				(unsigned char)(p * 255),
				(unsigned char)(brightness * 255)
			);
		}
		else
		{
			return Color2(
				(unsigned char)(brightness * 255),
				(unsigned char)(p * 255),
				(unsigned char)(q * 255)
			);
		}
	}

	static Color2 FromImColor(ImColor color)
	{
		return Color2(
			(int)(color.Value.x * 255),
			(int)(color.Value.y * 255),
			(int)(color.Value.z * 255),
			(int)(color.Value.w * 255)
		);
	}


	static ImColor ToImColor(Color2 color)
	{
		return ImColor(
			color.r / 255.f,
			color.g / 255.f,
			color.b / 255.f,
			color.a / 255.f
		);
	}

};

class Rainbow
{
public:
	float r, g, b, a;
	Rainbow(float r, float g, float b)
	{
		this->r = r;
		this->g = g;
		this->b = b;
		this->a = 255;
	}
};

extern Color2 Red;
extern Color2 Green;
extern Color2 White;
extern Color2 Black;


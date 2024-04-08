#pragma once
class Figure
{
private:
	float area;
public:
	Figure();
	virtual ~Figure();
	float getArea();
	void setArea(float _area);
	virtual void calculateArea() = 0;
	virtual void show();
};


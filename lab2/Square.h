#pragma once
#include "Figure.h"

class Square: public Figure
{
private:
	float a;
public:
	Square(float _a);
	~Square();
	virtual void calculateArea() override;
	virtual void show() override;
};


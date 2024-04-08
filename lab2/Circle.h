#pragma once
#include "Figure.h"

class Circle:public Figure
{
private:
	float r;
public:
	Circle(float _r);
	~Circle();
	virtual void calculateArea() override;
};


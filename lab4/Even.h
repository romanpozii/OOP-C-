#pragma once
class Even
{
private:
	int divider;
public:
	Even(int divider);
	bool operator() (int x);
};


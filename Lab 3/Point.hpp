#pragma once

using namespace std;

template <typename T>
class Point{

private:

	T coordX, coordY;

public:

	Point();
	Point(T e1,T e2);
	~Point();
	void reset();
	T getX();
	T getY();
	void moveX(T x);
	void moveY(T y);
	void moveXY(T x, T y);
	void display(string name);
	
};
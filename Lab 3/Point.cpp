#include <iostream>
#include <string>
#include "Point.hpp"
using namespace std;

template<typename T>
Point<T>::Point(){}

template<typename T>
Point<T>::Point(T x, T y) {

	coordX = x; coordY = y;
}
template<typename T>
Point<T>::~Point() {}

template<typename T>
void Point<T>::reset() {

	cout << "Resetting Point: ";
	coordX = 0; coordY = 0;
}

template<typename T>
T Point<T>::getX() {

	return coordX;
}

template<typename T>
T Point<T>::getY() {
	
	return coordY;
}

template<typename T>
void Point<T>::moveX(T x) {

	cout << "Moving Point " << x << " Units On X-Axis\n";
	coordX += x;
}

template<typename T>
void Point<T>::moveY(T y) {

	cout << "Moving Point " << y << " Units On Y-Axis\n";
	coordY += y;
}

template<typename T>
void Point<T>::moveXY(T x, T y) {

	cout << "Moving Point " << x << " Units On X-Axis And " << y << " Units On Y-Axis\n";
	coordX = x;
	coordY = y;
}

template<typename T>
void Point<T>::display(string name) {

	cout << name << " Has Coordinates: (" << coordX << ", " << coordY << ")\n";

}
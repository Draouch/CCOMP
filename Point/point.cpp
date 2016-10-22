#include "point.h"

double Point::getX(){
	
	return x;
	
}

double Point::getY(){
	
	return y;
	
}

void Point::setX(double nx){
	
	x = nx;
	
}

void Point::setY(double ny){
	
	y = ny;
	
}

void Point::printPoint(){
	
	cout << "point(" << x  << ", "  << y << "): " << endl;
	
}

void Point::modifyPoint(double nx, double ny){
	
	x = nx;
	y = ny;
	
}

void PointArray::resize(int newSize){
	
	Point *pts = new Point[newSize];
	int minSize = (newSize > size ? size : newSize);
	for(int i = 0; i < minSize; i++)
		points[i] = points[i];
		delete[] points;
		size = newSize;
		points = pts;
		
}

void PointArray::printArr(){
	
	for(int i=0; i < size; i++) 
		cout << "point[" << i << "]: " << "( " << points[i].getX() << ", " << points[i].getY()<< " )" << endl;
		
}

int PointArray::getSize() const{
	
	cout<<size<<endl;
	
	return 0;
	
}

int PointArray::Size() const{
	
	return size;
	
}

void PointArray::clear(){
	
	resize(0);
	
}

void PointArray::push_back(const Point &p){
	
	resize(size + 1);
	points[size - 1] = p;
	
}

void PointArray::insert(const int pos, const Point &p){
	
	resize(size + 1);
	
	for(int i = size - 1; i > pos; i--)
		points[i] = points[i - 1];
		
		points[pos] = p;
}

void PointArray::remove(const int pos){
	
	if(pos >= 0 && pos < size){
		for(int i = pos; i < size - 2; i++) {
			points [i] = points [i + 1];
		}
		resize (size - 1);
	}
	
}

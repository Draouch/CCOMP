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
	
	cout << "point(" << x  << ", "  << y << ")";
	
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

int PointArray::getSize() const{
	
	cout<<size<<endl;
	
	return 0;
	
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

void PointArray::printArr(){
	
	for(int i=0; i < size; i++) 
		cout << "point[" << i << "]: " << "( " << points[i].getX() << ", " << points[i].getY()<< " )" << endl;
		
}

void Vector::getStart(){
	
	end.printPoint();
	
}

void Vector::getEnd(){
	
	end.printPoint();
	
}

void Vector::setStart(double sx, double sy){
	
	start.modifyPoint(sx, sy);
	
}

void Vector::setEnd(double ex, double ey){
	
	end.modifyPoint(ex, ey);
	
}

void Vector::printVector(){
	
	cout << "Vector: ";
	start.printPoint();
	cout << " -> ";
	end.printPoint();
	
}

void Vector::modifyVector(double sx, double sy, double ex, double ey){
	
	start.modifyPoint(sx, sy);
	end.modifyPoint(ex, ey);
	
}

void VectorArray::resize(int newSize){
	
	Vector *arrvec = new Vector[newSize];
	int minSize = (newSize > size ? size : newSize);
	for(int i = 0; i < minSize; i++)
		vec[i] = vec[i];
		delete[] vec;
		size = newSize;
		vec = arrvec;
		
}

int VectorArray::getSize() const{
	
	cout<<size<<endl;
	
	return 0;
	
}

void VectorArray::clear(){
	
	resize(0);
	
}

void VectorArray::push_back(const Vector &v){
	
	resize(size + 1);
	vec[size - 1] = v;
	
}

void VectorArray::insert(const int pos, const Vector &v){
	
	resize(size + 1);
	
	for(int i = size - 1; i > pos; i--)
		vec[i] = vec[i - 1];
		
		vec[pos] = v;
}

void VectorArray::remove(const int pos){
	
	if(pos >= 0 && pos < size){
		for(int i = pos; i < size - 2; i++) {
			vec[i] = vec[i + 1];
		}
		resize (size - 1);
	}
	
}

void VectorArray::printArr(){
	
	for(int i=0; i < size; i++){
		cout << "Vector[" << i << "]: ";
		vec[i].getStart();
		cout << " -> ";
		vec[i].getEnd();
		cout << endl;
	}
	
}


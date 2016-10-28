#include "point.cpp"

class Vector{
	
private:
	
	Point start, end;
	
public:
	
	Vector(){
		
		start.modifyPoint(0.0 , 0.0);
		end.modifyPoint(0.0 , 0.0);
		
	}
	
	Vector(double sx, double sy, double ex, double ey){
		
		start.modifyPoint(sx, sy);
		end.modifyPoint(ex, ey);
		
	}
	
	Vector(Vector &o){
		
		start = o.start;
		end = o.end;
		
	}
	
	void getStart();
	
	void getEnd();
	
	void setStart(double sx, double sy);
	
	void setEnd(double ex, double ey);
	
	void printVector();
	
	void modifyVector(double sx, double sy, double ex, double ey);
	
};

class VectorArray{
	
private:
	
	int size;
	Vector *vec;
	
public:
	
	VectorArray(){
		
		size = 0;
		vec = new Vector[0];
		
	}
	
	VectorArray(Vector vecToCopy[], int toCopySize){
		
		size = toCopySize ;
		vec = new Vector[ toCopySize ];
		for(int i = 0; i < toCopySize ; ++i)
			vec[i] = vecToCopy[i];
			
	}
	
	VectorArray(VectorArray &pv){
		
		size = pv.size;
		vec = new Vector[size];
		for(int i = 0; i < size; i++)
			vec[i] = pv.vec[i];
			
	}
	
	void resize(int newSize);
	
	int getSize() const;
	
	void clear();
	
	void push_back(const Vector &v);
	
	void insert(const int pos, const Vector &v);
	
	void remove(const int pos);
	
	void printArr();
	
};

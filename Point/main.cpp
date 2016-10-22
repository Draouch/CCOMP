#include "point.cpp"

int main(){
	
	Point x;
	Point y;
	
	PointArray a;
	
	x.setX(5);
	x.setY(8);
	x.printPoint();
	
	cout<<"\n"<<endl;
	
	x.modifyPoint(4,7);
	x.printPoint();
	
	cout<<"\n"<<endl;
	
	y.setX(4);
	y.setY(9);
	y.printPoint();
	
	cout<<"\n"<<endl;
	
	a.getSize();
	
	cout<<"\n"<<endl;
	
	
	a.resize(5);
	a.insert(0,x);
	a.printArr();
	
	cout<<"\n"<<endl;
	
	a.getSize();
	
	cout<<"\n"<<endl;
	
	a.clear();
	a.resize(3);
	
	cout<<"\n"<<endl;
	
	a.push_back(y);
	a.printArr();	
	
	cout<<"\n"<<endl;
	
	a.getSize();
	
	cout<<"\n"<<endl;
	
	
	a.printArr();
	a.remove(1);
	
	cout<<"\n"<<endl;
	
	a.printArr();
	return 0;
	
}

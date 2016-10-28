#include <iostream>
#include <vector>

using namespace std;

int
	main(void)
{
	
	//Space for vector of int, called iVector
	vector <int> iVektor;
	
	//we will add the elements at the end of vector
	do
	{
		
		//space for next element of the vector
		cout<<"Next Element->"; int iElement; cin>>iElement;
		
		//to remove the element from the back use pop_back
		iVektor.push_back(iElement);
		
		cout<<"Size of the vector is ="<<iVektor.size()<<endl
			<<"Capacity of the vector="<<iVektor.capacity()<<endl
			<<"Max_Size of the vector="<<iVektor.max_size()<<endl;
		
		cout<<"More elements yes(y)/no(n)->";
		char cRespond; cin>>cRespond;
		
		if((cRespond == 'y')||(cRespond=='Y')) continue;
		
		break;
		
	} while(true);
	
	//display elements from begin to end
	for(vector<int>::iterator i=iVektor.begin();
	i != iVektor.end();
	cout<<*i++<<endl); cout<<endl<<endl;
	
	//display elements from end to begin
	for(vector<int>::reverse_iterator r=iVektor.rbegin();
	r != iVektor.rend();
	cout<<*r++<<endl); cout<<endl<<endl;
	
	cout<<"You wish to see the element->";int iIndex; cin>>iIndex;
	
	//first method to dispaly n-th element of a vector
	cout<<"At("<<iIndex<<")="
		<<iVektor.at(iIndex)<<endl
		<<"or like this=";
	
	//one more approach to display one of vector elements
	vector<int>::iterator p=iVektor.begin()+iIndex;cout<<*p<<endl;
	
	int iRespond; cin>>iRespond;
	
	return 0;
	
}

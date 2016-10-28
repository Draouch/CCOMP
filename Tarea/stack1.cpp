#include <iostream>
#include <stack>

typedef int myType;

using namespace std;

int
	main()
{
	
	cout<<"WE WILL CONVERT NUMBER INTO BINARY EQUIVALENT"<<endl;
		//PREPARE SPACE FOR NUMBER WE INPUT
		myType temp;
	cout<<"Please, input the number->";
	cin>>temp;
	
	//LET'S DECLARE STACK
	stack <int> nBinaryNumber;
	
	//FIND BINARY CIPHERS
	while(temp)
	{
		int nCipher = temp%2;
		nBinaryNumber.push(nCipher);
		temp/=2;
	}
	cout<<nBinaryNumber.size() <<endl;
	//PRESENT THE STACK
	while(!nBinaryNumber.empty())
	{
		(nBinaryNumber.top()==1)?cout<<'1':cout<<'0';
		nBinaryNumber.pop();
		
	}
	cout<<'\n';
	
	cout<<nBinaryNumber.size() <<endl;
	
	return 0;
}

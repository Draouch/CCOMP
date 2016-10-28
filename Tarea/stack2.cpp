#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
	stack<string> Carl;
	
	while (true)
	{
		char Ingrese;
		cout<<"Would you like to add new string y/n->";
		cin>>Ingrese;
		if(Ingrese=='n') break;
		
		cout<<"Next string please->";
		string Temporal;
		cin>>Temporal;
		Carl.emplace(Temporal);
		cout<<endl;
	}
	
	while(!Carl.empty())
	{
		//YES, AND NEGATION WILL TAKE SOME TIME!
		string Temporal;
		//FIRST WE TAKE COPY AND THEN WE TAKE FROM TOP OF THE STRING
		Temporal=Carl.top(); 
		Carl.pop();
		cout<<Temporal<<endl;
	}
	
	return 0;
}

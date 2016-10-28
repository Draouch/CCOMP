#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main(){
	
	queue <string> names,names2; /* Declare a queue */
	
	while (names2.empty())
	{
		names2.push("Iñigo");
		cout<< "Iniciando\n";
	}
	
	
	names.push ("Mauro"); /* Add some values to the queue */
	names.push ("Yhostin"); /* Much like vectors */
	names.push ("Wendy"); /* This basically does the same thing */
	
	names2.push ("Rodrigo");
	names2.push ("Carl");
	
	names.emplace("Alvaro");
	
	cout << "There are currently " << names.size () << " people in the queue" << endl
		<< "There are currently " << names2.size () << " people in the queue 2" << endl
		<< "The person at the front of the queue is " << names.front () << endl
		<< "The person at the back of the queue is " << names.back () << endl << endl;
	
	cout << "The person at the front of the queue 2 is " << names2.front () << endl
		<< "The person at the back of the queue 2 is " << names2.back () << endl << endl;
	
	cout << names.front () << " has been served!" << endl;
	names.pop ();
	cout << "There are currently " << names.size () << " people in the queue\n" << endl
		<< "There are currently " << names.size () << " people in the queue 2\n" << endl;
	
	names2.swap(names);
	cout << "The list 1 and 2 switch places \n "<< endl;
	
	cout << "The person at the front of the queue is " << names.front () << endl
		<< "The person at the front of the queue 2 is " << names2.front () << endl;
	
	cout << names.back () << " is still at the back!" << endl;
	cout<< names2.back () << " is still at the back 2!" << endl;
	
	return 0;
}

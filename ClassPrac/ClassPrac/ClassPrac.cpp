

#include <iostream>
using namespace std;


class Human {
public:
	string name;
	int age;
	Human(string n, int a) {
		name = n;
		age = a;
	}

};


void NameAndAge(Human* p) {
	cout << "Name: " << p -> name << endl;
	cout << "Age: " << p->age << endl;
}


int main()
{
	Human * h = new Human("Vebjorn", 20);
	
	NameAndAge(h);
	
	delete h;


}


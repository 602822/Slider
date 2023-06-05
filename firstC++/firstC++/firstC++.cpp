

#include <iostream>
using namespace std;


void swap(int* px, int* py) {
	int temp = *px;
	*px = *py;
	*py = temp;
}


int main()
{

	int x = 50;
	int y = 60;

	swap(&x, &y);

	cout << "The value of x: " << x << endl;
	cout << "The value of y: " << y << endl;



}


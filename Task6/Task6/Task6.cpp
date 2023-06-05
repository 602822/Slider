
#include <iostream>
#include <vector>
#include <list>
using namespace std;


class Car {
public:
    string color;
    Car(string _color) {
        color = _color;
    }
};

int main()
{
    int options = 0;
    list<Car*> carGarage = {};

    cout << "1. Drive a red car into the garage" << endl;
    cout << "2. Drive a blue car into the garage" << endl;
    cout << "3. Drive a green car into the garage" << endl;
    cout << "4. Drive a red car out of the garage" << endl;
    cout << "5. Quit" << endl;
    
    cout << "Enter a number between 1-5: ";
    cin >> options;

    do {
        switch (options) {
        case 1:
            if (carGarage.size() != 9) {
                carGarage.push_back(new Car("red"));
            }
            else {
                cout << "The garage is full" << endl;
            }
            cout << "Enter a number between 1-5: ";
            cin >> options;
            break;
        case 2:
            if (carGarage.size() != 9) {
                carGarage.push_back(new Car("blue"));
            }
            else {
                cout << "The garage is full" << endl;
            }
            cout << "Enter a number between 1-5: ";
            cin >> options;
            break;
        case 3:
            if (carGarage.size() != 9) {
                carGarage.push_back(new Car("green"));
            }
            else {
                cout << "The garage is full" << endl;
            }
            cout << "Enter a number between 1-5: ";
            cin >> options;
            break;
        case 4:
            cout << carGarage.front()->color << endl;
            carGarage.pop_front();
            cout << "Enter a number between 1-5: ";
            cin >> options;
            break;
        case 5:
        break;
        } 

        

    } while (options != 5);

    return 0;

}




#include <iostream>
using namespace std;

template <typename T> void reset( T **ppx, T **ppy) {
    **ppx = 0;
    **ppy = 0;
}

template <typename T> T finnMax(T *px, T *py) {
    return (*px > *py) ? *px : *py;
}


int main()
{
    int x = 100;
    int y = 200;

    double a = 5.5;
    double b = 8.8;

    int* px = &x;
    int* py = &y;

    double* pa = &a;
    double* pb = &b;
    

    reset(&px, &py);
    reset(&pa, &pb);

    wcout << L"*px = " << *px << endl;
    wcout << L"*py = " << *py << endl;

    wcout << L"*pa = " << *pa << endl;
    wcout << L"*pb = " << *pb << endl;


    int nummer1 = 40;
    int nummer2 = 50;

    int* pn1 = &nummer1;
    int* pn2 = &nummer2;

    int * max = finnMax(&pn1, &pn2);

    cout << "The biggest number: " << *max;


    return 0;
};
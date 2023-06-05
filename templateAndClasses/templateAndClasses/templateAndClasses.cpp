#include <iostream>
using namespace std;
template <typename T> class ClassT {
public:
    ClassT(T _val) : val(_val) {
    };
    T GetVal() {
        return val;
    }
    T val;
};
int main() {
    ClassT objI(100); // ClassT<int> before C++ v14. After compiler deduces/guesses ok     
    ClassT objD(3.14);
    cout << objI.GetVal() << endl;
    cout << objD.GetVal() << endl;
    return 0;
}
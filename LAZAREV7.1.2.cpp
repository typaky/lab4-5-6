#include <iostream>
#include <locale>
using namespace std;


template<class T>
void swap(T a, T b) {
    cout << "a = " << a << ", b = " << b << endl;
    T temp = a;
    a = b;
    b = temp;
    cout << "a = " << a << ", b = " << b << endl;
}

int main()
{
    cout<<"4icla:"<<endl;
    swap <int> (12, 1234);
    cout<<"SimBol:"<<endl;
    swap <char> ('a','b');
    cout<<"Ctpoka:"<<endl;
    swap <string> ("qwer_123", "123_qwer");
}

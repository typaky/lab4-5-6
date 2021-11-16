#include <iostream>
#include <locale>
#include <stdlib.h>
using namespace std;
class Base{
private:
    double d;
protected:
    long l;
public:
    int i;

void get_d(){
    cout << d << endl;
};

Base(double dd, long ll, int ii){
    d = dd; l = ll; i = ii;}

Base(){
    d = 1; l = 2; i = 3;}
friend ostream &operator <<(ostream& os, const Base &ob);
};

class Derived : public Base{
private:
    float f;
public:

Derived(long ll, int ii, float ff){
    l = ll; i = ii; f = ff;}

Derived(){
    l = 1, i = 2, f = 3;}

friend ostream &operator <<(ostream& os, const Derived& ob);
};

class Derived_1 : public Derived{
public:
    Derived_1(long ll, int ii, float ff){
    l = ll; i = ii;}

Derived_1(){
    l = 1, i = 2;}
};

int main(){
    Base a(1, 2, 3);
    Derived b(1, 2, 3);
    cout << "Base size: " << sizeof(Base) << " Bytes" << '\n';
    cout << "Derived size: " << sizeof(Derived) << " Bytes" << '\n';
    cout << "Derived_1 size: " << sizeof(Derived_1) << " Bytes" << '\n';
return 0;
}

ostream &operator<<(ostream &os, const Base &ob){
    os << "Class Base:" << '\n';
    os << "ob.d = " << ob.d << " address: " << &ob.d << '\n';
    os << "ob.l = " << ob.l << " address: " << &ob.l << '\n';
    os << "ob.i = " << ob.i << " address: " << &ob.i << '\n';
return os;
}

ostream &operator<<(ostream& os, const Derived &ob){
    os << "Class Derived:" << '\n';
    os << "ob.l = " << ob.l << " address: " << &ob.l << '\n';
    os << "ob.i = " << ob.i << " address: " << &ob.i << '\n';
    os << "ob.f = " << ob.f << " address: " << &ob.f << '\n';
    os << "ob.d = " << ob.get_d << " address: " << &ob.d <<'\n';
return os;
}

ostream &operator<<(ostream& os, const Derived_1 &ob){
    os << "Class Derived:" << '\n';
    os << "ob.l = " << ob.f << " address: " << &ob.l << '\n';
    os << "ob.i = " << ob.i << " address: " << &ob.i << '\n';
    os << "ob.f = " << ob.f << " address: " << &ob.f << '\n';
return os;
}

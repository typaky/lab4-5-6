#include <iostream>
#include <cstring>
#include <locale>
#include <stdlib.h>
using namespace std;
class Base1{
private:
    int i;
public:
    Base1(){
        i = 0;
        cout << "Конструктор Base1 без параметров" << '\n';}
    Base1(int p){
        i = p;
        cout << "Конструктор Base1 с параметром" << '\n';}
    void put(int p){ i = p; }
    int get(void){ return i; }
};

class Base2{
private:
    char name[20];
public:
    Base2(){
        strcpy(name, "default");
        cout << "Конструктор Base2 без параметров" << '\n';}
    Base2(char* p){
        strcpy(name, p);
        cout << "Конструктор Base2 с параметром" << '\n';}
    void put(char* p){ strcpy(name,p); }
    char* get(void){ return name; }
};

class Derived: public Base1, public Base2{
private:
    char ch;
public:
    Derived(){
        ch = 'D';
        cout << "Конструктор Derived без параметров"<<'\n';}
    Derived(char p, char* p2, int p1): Base1(p1), Base2(p2){
        ch = p;
        cout << "Конструктор Derived с параметром"<<'\n';}
    void put(char p){ ch = p; }
    char get(void){ return ch; }
    friend ostream &operator << (ostream&, Derived &d){
        cout << "\nch = " << d.ch << '\n';
        cout << "i    = " << d.Base1::get() << '\n';
        cout << "name = " << d.Base2::get() << '\n';}
};

int main(){
	setlocale(LC_ALL, "RUS");
	Derived d;
	cout << d;
	Derived d2('d', "d2", 111);
	cout << d2;
	d2.get();
}
#include <iostream>
#include <cstring>
#include <locale>

using namespace std;

template <class T>
void max_t(T x, T y) {
    cout << "Bi3BaHa Shablonaya Fynkcia"<< endl;
    if(x>y) cout<<"Bolshee 3Ha4eHue: "<<x<<endl;
		else if(y>x) cout<<"Bolshee 3Ha4eHue: "<<y<<endl;
		else {cout<<"Bolshego 3Ha4eHuya Het!"<<endl;
		cout<<"PaBHo: "<<"(x = "<<x<<") = "<<"(y = "<<y<<")"<<endl;
		}
    cout << endl;
}
template <>
void max_t(char* p_ch1, char* p_ch2) {
    cout << "Bi3BaHa cpecializipoBaHaya Fynkcia" << endl;
    if(strcmp(p_ch1, p_ch2) == 0) cout << " CTpoku odunakoBie" << endl;
    else if(strcmp(p_ch1, p_ch2) == 1) cout << " CTpoka 1 dLiHee" << endl;
    else cout << " CTpoka 2 dLiHee" << endl;
    cout << endl;
}

int main()
{
    setlocale(LC_ALL, "Rus");
    max_t<char>('a', '1');
    max_t<int>(1, 1);
    max_t<string>("Hello", "World");
    char ch1[] = "Hello, world!";
    char ch2[] = "Hello world!";
    max_t<char *>(ch1, ch2);
}


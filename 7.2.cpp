#include <iomanip>
#include <iostream>
using namespace std;

//EX 2.1
class Complex {
private:
    // veshestvenaya i mnimaya
    double m_re, m_im;

public:

    Complex();
    Complex(double re, double im = 0);

    double GetRe()
	{
        return m_re;
    }
    double GetIm()
	{
        return m_im;
    }

    //Operators:
    // *
    Complex operator*(const Complex& a)
	{
        return Complex(m_re * a.m_re - m_im * a.m_im,
            m_re * a.m_im - m_im * a.m_re);
    }
    // * on number
    Complex operator*(const double& a)
	{
        return Complex(m_re * a, m_im * a);
    }
    // =
    Complex& operator=(const Complex& a)
    {
        if (this != &a)
        {
            m_re = a.m_re;
            m_im = a.m_im;
        }
        return *this;
    }
    double& operator=(const double& a)
    {
        return m_re;
    }
    // out
    friend ostream& operator<< (ostream& out, const Complex& x)
    {
        return (out << "(" << x.m_re << "," << x.m_im << ")");
    }
};

//EX 2.2
template <class T>
class matrix {

private:
    T** M; // matrix
    int m; // kol-vo strok
    int n; // kol-vo stolbcoB

public:

    matrix()
    {
        n = m = 0;
    }

    matrix(int _m, int _n)
    {
        m = _m;
        n = _n;

        M = (T**) new T * [m];


        for (int i = 0; i < m; i++)
            M[i] = (T*)new T[n];

        //matrix full 0
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                M[i][j] = 0;
    }

    void SetMij(int i, int j, T value)
    {
        if ((i < 0) || (i >= m))
            return;
        if ((j < 0) || (j >= n))
            return;
        M[i][j] = value;
    }

    void Print(const char* ObjName)
    {
        cout << "Object: " << ObjName << endl;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
                cout << M[i][j] << "\t";
            cout << endl;
        }
        cout << "---------------------" << endl << endl;
    }

    matrix operator=(const matrix& _M)
    {
        if (n > 0)
        {

            for (int i = 0; i < m; i++)
                delete[] M[i];
        }

        if (m > 0)
        {
            delete[] M;
        }

        // coppy data M <= _M
        m = _M.m;
        n = _M.n;

        // memory clean
        M = (T**) new T * [m];
        for (int i = 0; i < m; i++)
            M[i] = (T*) new T[n];

        // copy
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                M[i][j] = _M.M[i][j];
        return *this;
    }

    // destructor
    ~matrix()
    {
        if (n > 0)
        {
            // ocBobodit BideleHHyy namyat' dlya kajdoi CTpoki
            for (int i = 0; i < m; i++)
                delete[] M[i];
        }

        if (m > 0)
            delete[] M;
    }
};

template <typename T> class Stack
{
    T* stackPtr;
    int size;
    T top;

public:
    Stack(int = 10);

    ~Stack();

    bool push(const T);
    bool pop();
    void printStack();
};

template <typename T> Stack<T>::Stack(int s)
{
    size = s > 0 ? s : 10;
    stackPtr = new T[size];
    top = -1;
}

template <typename T> Stack<T>::~Stack()
{
    delete[] stackPtr;
}

template <typename T> bool Stack<T>::push(const T value)
{
    if (top == size - 1)
        return false;

    top++;
    stackPtr[top] = value;

    return true;
}

template <typename T> bool Stack<T>::pop()
{
    if (top == -1)
        return false;

    stackPtr[top] = 0;
    top--;

    return true;
}

template <typename T> void Stack<T>::printStack()
{
    for (int ix = size - 1; ix >= 0; ix--)
        cout << "|" << setw(4) << stackPtr[ix] << endl;
}

int main()
{

    //EX 2.3
    matrix<int> in(2, 3);
    in.SetMij(1, 1, 2.1);
    in.SetMij(1, 2, 3);
    in.SetMij(2, 1, 'h');

    }



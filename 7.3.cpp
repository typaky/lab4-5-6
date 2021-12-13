 #include <iostream>
#include <cstdlib>
#include <ctime>
#include <locale>
#define LENGTH 10000000
using namespace std;

template<typename T>
struct Node {
    T value;
    struct Node * next;
};
template<typename T, int L>
struct Stack {
    struct Node<T> * top;
    int len = 0;
    int size = L;
};
template<typename T, int L>
Stack<T, L> * createStack() {
    Stack<T, L> * pS = new Stack<T, L>;
    if (pS) {
        pS->top = NULL;
         cout << "CTek co3DaH" << endl;
    return pS;
    }
    exit(EXIT_FAILURE);
}
template <typename T, int L>
int isEmpty(Stack<T, L> * pS) {
    if (pS->top && pS->len)
        return 0;
    return 1;
}
template <typename T, int L>
void push(Stack<T, L> * pS, T value) {
    if (pS->size > pS->len) {
        Node<T>* pN = new Node<T>;
        pN->value = value;
        pN->next = pS->top;
        pS->top = pN;
        pS->len++;
    }
    else cout <<"npeBiSheHie pa3Mepa stack"<<endl;
}
template<typename T, int L>
T pop(Stack<T, L> * pS) {
    Node<T> * pN = pS->top;
    int value = pN->value;
    pS->top = pN->next;
    free(pN);
    pS->len--;
    return value;
}
template<typename T, int L>
void print(Stack<T, L> * pS) {
    Node<T> * pN = pS->top;
    if (isEmpty(pS))
        cout << "Stack nycT" << endl;
    else{
    while (pN) {
        cout << pN->value << " ";
        pN = pN->next;
    }}
    cout << endl;
}
template<typename T, int L>
void clearStack(Stack<T, L> * pS) {
    while (!isEmpty(pS))
        pop(pS);
    free(pS);
}
template <class T>
void Stack_f(){
    Stack<T, LENGTH> * stack = createStack<T, LENGTH>();
    for (int i = 0; i < LENGTH; i++) {
        //int null_rand = rand()%2;
        //cout << null_rand << " ";
        T r = (97+ rand() % (122-97));//* null_rand;
        push(stack, r);
    }
    //print(stack);
    for (int i = 0; i < LENGTH/2; i++) {
        pop(stack);
    }
    //print(stack);
    clearStack(stack);
    //print(stack);
}

int main()
{
    srand(time(NULL));
    Stack_f<char>();
    Stack_f<int>();
    Stack_f<bool>();
    Stack_f<unsigned char>();
    return 0;
}

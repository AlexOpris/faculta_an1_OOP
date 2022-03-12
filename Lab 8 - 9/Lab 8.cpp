#include <iostream>
#include <exception>

using namespace std;

//class Stack{
//
//private:
//	
//  int capacity;
//	int top;
//	int arr[100];
//
//public:
//    Stack();
//
//    void push(int n);
//    void pop();
//
//    int size();
//    bool isEmpty();
//    bool isFull();
//
//    ~Stack();
//};
//
//Stack::Stack()
//{
//    this->capacity = 100;
//    this->top = -1;
//    for (int i = 0; i < 100; i++)
//        this->arr[i] = 0;
//}
//
//void Stack::push(int nr)
//{
//    this->top++;
//    this->arr[this->top] = nr;
//}
//
//void Stack::pop()
//{
//    this->top--;
//}
//
//int Stack::size()
//{
//    return this->top + 1;
//}
//
//bool Stack::isEmpty()
//{
//    if (this->top == -1)
//        return true;
//    return false;
//}
//
//bool Stack::isFull()
//{
//    if (this->top - 1 == this->capacity)
//        return true;
//    return false;
//}
//
//Stack::~Stack()
//{
//}

template <class A_Type> class Stack {

private:

    int capacity;
	int top;
	int arr[100];

public:
    Stack();

    void push(int n);
    void pop();

    int size();
    bool isEmpty();
    bool isFull();
    int first();

    void displayAll();

    ~Stack();
};

template<class A_Type> Stack<A_Type>::Stack()
{
    top = -1;
}

template<class A_Type> void Stack<A_Type>::push(int nr)
{
    if (isFull() == false) {
        top++;
        arr[top] = nr;
    }
    else
        throw exception();
}

template<class A_Type>
void Stack<A_Type>::pop()
{
    if (isEmpty() == false)
        top--;
    else
        throw exception();
}

template<class A_Type>
int Stack<A_Type>::size()
{
    return top-1;
}

template<class A_Type>
bool Stack<A_Type>::isEmpty()
{
    if (top == -1)
        return true;
    return false;
}

template<class A_Type>
bool Stack<A_Type>::isFull()
{
    if (top - 1 == capacity)
        return true;
    return false;
}

template<class A_Type>
int Stack<A_Type>::first()
{
    if (isEmpty() == true)
        throw exception();
    else
        return arr[top];

}

template<class A_Type>
void Stack<A_Type>::displayAll()
{
    if(isEmpty() == false)
        for (int i = 0; i < top; i++)
            cout << arr[i] << " ";
}

template<class A_Type>
Stack<A_Type>::~Stack()
{
}



int main()
{
    Stack<int> s;

    try{
        s.push(1);
        s.pop();
        s.pop();
    }
    catch (...) {
        cout << "Error";
    }
}

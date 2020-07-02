#ifndef STACK_TEMPLATE
#define STACK_TEMPLATE

#include <iostream>
#include <assert.h>

template <typename T>
class Stack
{

private:
    T* stackPtr;
    const int size;
    int top;
    
public:
    explicit Stack(int size = 10);
    Stack(const Stack<T>& s);
    Stack& operator = (const Stack& s);
    

    ~Stack();

    

    void push(const T&);
    void printStack();
    int getSize() const;
    int getTop() const;
    bool isEmpty();
    T pop();
    T* getPtr() const;
    const T& peek (int) const;
};


///////////////////////////////
//Class Method Implementation//
///////////////////////////////

template <typename T>
Stack<T>::Stack(int maxSize) : size(maxSize)
{
    stackPtr = new T[size];
    top = 0;
}

template <typename T>
Stack<T>::Stack(const Stack<T>& s) : size(s.getSize())
{
    stackPtr = new T[size];
    top = s.getTop();
    for(int i = 0; i < top; ++i)
        stackPtr[i] = s.getPtr()[i];

}

template <typename T>
Stack<T>& Stack<T>::operator = (const Stack& s)
{
    delete stackPtr;

    top = s.getSize();

    stackPtr = new T[s.getSize()];

    for(int i = 0; i <= s.getSize(); ++i)
        stackPtr[i] = s.getPtr()[i];

    return *this;
}

template <typename T>
Stack<T>::~Stack()
{
    delete[] stackPtr;
}

template <typename T>
void Stack<T>::push(const T& value)
{
    assert(top < size);
    stackPtr[++top] = value;

}

template <typename T>
T Stack<T>::pop()
{
    assert(top > 0);
    stackPtr[--top];
}

template <typename T>
const T& Stack<T>::peek(int number) const
{
    assert(number < top);
    return stackPtr[top - number];
}

template <typename T>
int Stack<T>::getSize() const
{   
    return size;
}

template <typename T>
T* Stack<T>::getPtr() const
{
    return stackPtr;
}

template <typename T>
int Stack<T>::getTop() const
{
    return top;
} 

template <typename T>
bool Stack<T>::isEmpty()
{
    return (top > 0 ? true : false);
}

template <typename T>
void Stack<T>::printStack()
{
    for (int i = top; i > 0; --i)
        std::cout << "| " << stackPtr[i] << " |" << '\n';
}

#endif

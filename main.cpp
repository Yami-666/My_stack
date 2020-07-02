#include <iostream>
#include "stack_template.cpp"

int main()
{
    int maxSize = 3;


    Stack<int> stack(maxSize);
    Stack<int> stack2(5);

    int x;
    for(int i = 0; i < stack.getSize(); ++i)
    {
        std::cin >> x;
        stack.push(x); 
    }

    for(int i = 0; i < stack2.getSize(); ++i)
    {
        std::cin >> x;
        stack2.push(x); 
    }

    std::cout << "\n";

    stack = stack2;

    if(stack.isEmpty() && stack2.isEmpty())
    {
        stack.printStack();
        std::cout << "\n";
        stack2.printStack();
    }
    else
    {
        std::cout << "Stack is empty!\n";
    }


    

    return 0;
}

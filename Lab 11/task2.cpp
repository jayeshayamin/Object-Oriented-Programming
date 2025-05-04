#include <iostream>
#include <exception>
using namespace std;

class StackOverflowException : public exception
{
public:
    const char *what() const noexcept override
    {
        return "StackOverflowException - Stack is full!";
    }
};

class StackUnderflowException : public exception
{
public:
    const char *what() const noexcept override
    {
        return "StackUnderflowException - Stack is empty!";
    }
};

template <typename T>
class Stack
{
    static const int fullcapacity = 4;
    T data[fullcapacity];
    int top;

public:
    Stack() : top(-1) {}

    void push(T value)
    {
        if (top >= fullcapacity - 1)
        {
            throw StackOverflowException();
        }
        data[++top] = value;
    }

    T pop()
    {
        if (top < 0)
        {
            throw StackUnderflowException();
        }
        return data[top--];
    }
};

int main()
{
    Stack<int> s;

    try
    {
        cout << "Pushing 5 elements..." << endl;
        for (int i = 0; i < 5; i++)
        {
            s.push(i * 10);
        }
    }
    catch (const exception &e)
    {
        cout << e.what() << endl;
    }

    try
    {
        cout << "Popping 6 elements..." << endl;
        for (int i = 0; i < 6; i++)
        {
            cout << "Popped: " << s.pop() << endl;
        }
    }
    catch (const exception &e)
    {
        cout << e.what() << endl;
    }

    return 0;
}

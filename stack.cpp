#include <iostream>
using namespace std;

#define MAX 100

int stack[MAX];
int top = -1;

void push(int item)
{
    if (top >= MAX - 1)
    {
        cout << "stack overflow" << endl;
        return;
    }
    stack[++top] = item;
}

int pop()
{
    if (top < 0)
    {
        cout << "stack underflow!" << endl;
        return -1;
    }
    return stack[top--];
}

int peek()
{
    if (top < 0)
    {
        return -1;
    }
    return stack[top];
}

bool isEmpty()
{
    return top < 0;
}

void display()
{
    cout << "stack : ";
    for (int i = 0; i <= top; i++)
    {
        cout << stack[i] << " ";
    }
    cout << endl;
}

int main()
{
    push(10);
    push(20);
    push(30);
    display();
    cout << "Top Element : " << peek() << endl;
    cout << "Popped Element : " << pop() << endl;
    display();
    return 0;
}

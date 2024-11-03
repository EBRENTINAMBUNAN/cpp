#include <iostream>
using namespace std;
#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

bool isFull()
{
    return ((rear + 1) % MAX == front);
}

bool isEmpty()
{
    return (front == -1);
}

void enqueue(int value)
{
    if (isFull())
    {
        {
            cout << "antrean penuh" << value << endl;
        }
        return;
    }
    if (isEmpty())
    {
        front = 0;
    }
    rear = (rear + 1) % MAX;
    queue
        [rear] = value;
    cout << "berhasil menambahkan " << value << "ke antrian." << endl;
}

void dequeue()
{
    if (isEmpty())
    {
        cout << "antrian kosong" << endl;
    }
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front = (front + 1) % MAX;
    }
}

void display()
{
    if (isEmpty())
    {
        cout << "antrian kosong" << endl;
        return;
    }
    cout << "isi antrian";
    int i =
        front;
    while (true)
    {
        cout << queue[i] << " ";
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    cout << endl;
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();

    dequeue();
    display();

    enqueue(40);
    enqueue(50);
    enqueue(60);
    display();

    dequeue();
    enqueue(70);
    display();

    dequeue();
    dequeue();
    dequeue();
    display();

    dequeue();
    display();
    return 0;
}
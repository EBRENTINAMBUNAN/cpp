#include <iostream>
using namespace std;

#define MAX 5

struct Queue
{
    int front, rear;
    string data[MAX];
};

void initializeQueue(Queue &q)
{
    q.front = -1;
    q.rear = -1;
}

bool isFull(Queue q)
{
    return (q.rear == MAX - 1);
}

bool isEmpty(Queue q)
{
    return (q.front == -1 || q.front > q.rear);
}

void enqueue(Queue &q, string value)
{
    if (isFull(q))
    {
        cout << "Queue is full!" << endl;
    }
    else
    {
        if (q.front == -1)
        {
            q.front = 0;
        }
        q.rear++;
        q.data[q.rear] = value;
        cout << value << " berhasil ditambahkan ke queue." << endl;
    }
}

void dequeue(Queue &q)
{
    if (isEmpty(q))
    {
        cout << "Queue is empty!" << endl;
    }
    else
    {
        cout << q.data[q.front] << " berhasil di hapus dari queue." << endl;
        q.front++;
        if (q.front > q.rear)
        {
            q.front = q.rear = -1;
        }
    }
}

void peek(Queue q)
{
    if (isEmpty(q))
    {
        cout << "Queue is empty!" << endl;
    }
    else
    {
        cout << "Front element: " << q.data[q.front] << endl;
    }
}

void display(Queue q)
{
    if (isEmpty(q))
    {
        cout << "Queue is empty!" << endl;
    }
    else
    {
        cout << "Queue elements: ";
        for (int i = q.front; i <= q.rear; i++)
        {
            cout << q.data[i] << " ";
        }
        cout << endl;
    }
}

int main()
{
    Queue q;
    initializeQueue(q);

    int menu;
    string isi;

    do
    {
        cout << "\nMenu:" << endl;
        cout << "1. Enqueue\n2. Dequeue\n3. Peek/Front\n4. Display Queue\n5. Exit" << endl;
        cout << "Silahkan pilih menu (1-5): ";
        cin >> menu;

        switch (menu)
        {
        case 1:
            cout << "Masukkan elemen untuk ditambahkan: ";
            cin >> isi;
            enqueue(q, isi);
            break;
        case 2:
            dequeue(q);
            break;
        case 3:
            peek(q);
            break;
        case 4:
            display(q);
            break;
        case 5:
            cout << "Keluar dari program." << endl;
            break;
        default:
            cout << "Pilihan tidak valid, coba lagi." << endl;
            break;
        }
    } while (menu != 5);

    return 0;
}

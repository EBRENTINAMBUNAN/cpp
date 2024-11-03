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

void insertFront(int value)
{
    if (isFull())
    {
        cout << "Dequeue penuh, tidak bisa menambahkan elemen " << value << " di depan" << endl;
        return;
    }

    if (isEmpty())
    {
        front = rear = 0;
    }
    else
    {
        front = (front - 1 + MAX) % MAX;
    }

    queue[front] = value;
    cout << "Menambahkan " << value << " ke depan Dequeue" << endl;
}

void insertRear(int value)
{
    if (isFull())
    {
        cout << "Dequeue penuh, tidak bisa menambahkan elemen " << value << " di belakang" << endl;
        return;
    }

    if (isEmpty())
    {
        front = rear = 0;
    }
    else
    {
        rear = (rear + 1) % MAX;
    }

    queue[rear] = value;
    cout << "Menambahkan " << value << " ke belakang Dequeue" << endl;
}

void deleteFront()
{
    if (isEmpty())
    {
        cout << "Dequeue kosong, tidak ada elemen untuk dihapus di depan" << endl;
        return;
    }

    cout << "Menghapus " << queue[front] << " dari depan Dequeue" << endl;

    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % MAX;
    }
}

void deleteRear()
{
    if (isEmpty())
    {
        cout << "Dequeue kosong, tidak ada elemen untuk dihapus di belakang" << endl;
        return;
    }

    cout << "Menghapus " << queue[rear] << " dari belakang Dequeue" << endl;

    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        rear = (rear - 1 + MAX) % MAX;
    }
}

void display()
{
    if (isEmpty())
    {
        cout << "Dequeue kosong" << endl;
        return;
    }

    cout << "Isi Dequeue: ";
    int i = front;
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
    int choice, value;

    do
    {
        cout << "\nMenu Dequeue: " << endl;
        cout << "1. Tambah elemen di depan" << endl;
        cout << "2. Tambah elemen di belakang" << endl;
        cout << "3. Hapus elemen dari depan" << endl;
        cout << "4. Hapus elemen dari belakang" << endl;
        cout << "5. Tampilkan elemen Dequeue" << endl;
        cout << "6. Keluar" << endl;
        cout << "Masukkan pilihan: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Masukkan nilai yang akan ditambahkan di depan: ";
            cin >> value;
            insertFront(value);
            break;
        case 2:
            cout << "Masukkan nilai yang akan ditambahkan di belakang: ";
            cin >> value;
            insertRear(value);
            break;
        case 3:
            deleteFront();
            break;
        case 4:
            deleteRear();
            break;
        case 5:
            display();
            break;
        case 6:
            cout << "Keluar dari program." << endl;
            break;
        default:
            cout << "Pilihan tidak valid!" << endl;
        }

    } while (choice != 6);

    return 0;
}

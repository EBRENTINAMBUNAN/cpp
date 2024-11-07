/*
|==============================================|
|   Implementasi LINIER DOUBLE LINKED LIST     |
|==============================================|
|     created by EBREN TINAMBUNAN              |
| Program ini membantu pengguna mengelola      |
| struktur data Double Linked List sederhana   |
| dengan operasi dasar, seperti menambah atau  |
| menghapus node di awal atau akhir list, serta|
| menampilkan isi list dari depan ke belakang  |
| atau sebaliknya.                             |
|                                              |
|       https://github.com/EBRENTINAMBUNAN     |
|==============================================|
*/

#include <iostream>

using namespace std;

struct Node

{

    int data;

    Node *prev;

    Node *next;

    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};

class DoubleLinkedList

{

private:
    Node *head;

    Node *tail;

public:
    DoubleLinkedList() : head(nullptr), tail(nullptr) {}

    ~DoubleLinkedList()

    {

        Node *current = head;

        while (current != nullptr)

        {

            Node *next = current->next;

            delete current;

            current = next;
        }
    }

    void addToFront(int value)

    {

        Node *newNode = new Node(value);

        if (head == nullptr)

        {

            head = tail = newNode;
        }

        else

        {

            newNode->next = head;

            head->prev = newNode;

            head = newNode;
        }

        cout << "Node " << value << " ditambahkan di depan.\n";
    }

    void addToEnd(int value)

    {

        Node *newNode = new Node(value);

        if (tail == nullptr)

        {

            head = tail = newNode;
        }

        else

        {

            newNode->prev = tail;

            tail->next = newNode;

            tail = newNode;
        }

        cout << "Node " << value << " ditambahkan di belakang.\n";
    }

    void removeFromFront()

    {

        if (head == nullptr)

        {

            cout << "List kosong, tidak ada node yang bisa dihapus.\n";

            return;
        }

        Node *temp = head;

        if (head == tail)

        {

            head = tail = nullptr;
        }

        else

        {

            head = head->next;

            head->prev = nullptr;
        }

        cout << "Node " << temp->data << " dihapus dari depan.\n";

        delete temp;
    }

    void removeFromEnd()

    {

        if (tail == nullptr)

        {

            cout << "List kosong, tidak ada node yang bisa dihapus.\n";

            return;
        }

        Node *temp = tail;

        if (head == tail)

        {

            head = tail = nullptr;
        }

        else

        {

            tail = tail->prev;

            tail->next = nullptr;
        }

        cout << "Node " << temp->data << " dihapus dari belakang.\n";

        delete temp;
    }

    void displayForward()

    {

        Node *current = head;

        cout << "List (depan -> belakang): ";

        while (current != nullptr)

        {

            cout << current->data << " ";

            current = current->next;
        }

        cout << endl;
    }

    void displayBackward()

    {

        Node *current = tail;

        cout << "List (belakang -> depan): ";

        while (current != nullptr)

        {

            cout << current->data << " ";

            current = current->prev;
        }

        cout << endl;
    }
};

int main()

{

    DoubleLinkedList list;

    list.addToFront(10);

    list.addToFront(20);

    list.addToEnd(30);

    list.addToEnd(40);

    list.displayForward();

    list.displayBackward();

    list.removeFromFront();

    list.displayForward();

    list.removeFromEnd();

    list.displayForward();

    return 0;
}

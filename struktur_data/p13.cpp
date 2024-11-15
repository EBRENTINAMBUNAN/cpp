/*
|==============================================|
|   Implementasi LINIER DOUBLE LINKED LIST     |
|==============================================|
|     Created by EBREN TINAMBUNAN              |
|----------------------------------------------|
| Program ini membantu pengguna mengelola      |
| struktur data Double Linked List sederhana   |
| dengan fitur-fitur berikut:                  |
| 1. Menambahkan data di awal, akhir, atau     |
|    tengah list.                              |
| 2. Menghapus data di awal, akhir, atau       |
|    tengah list.                              |
| 3. Menampilkan isi list.                     |
|                                              |
| Program dirancang untuk mencatat data        |
| mahasiswa (NIM, Nama, dan Nilai) dan         |
| mempermudah operasi terhadap list tersebut.  |
|                                              |
|     https://github.com/EBRENTINAMBUNAN       |
|==============================================|
*/

#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string nim;
    string nama;
    float nilai;
    Node *next;
    Node *prev;

    Node(string nim, string nama, float nilai)
    {
        this->nim = nim;
        this->nama = nama;
        this->nilai = nilai;
        next = prev = nullptr;
    }
};

class DoubleLinkedList
{
private:
    Node *head;

    // Fungsi untuk mencari node tengah (digunakan oleh insertAtMiddle dan deleteAtMiddle)
    Node *getMiddleNode()
    {
        if (head == nullptr)
            return nullptr;

        Node *slow = head;
        Node *fast = head;

        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

public:
    DoubleLinkedList() : head(nullptr) {}

    // Fungsi insert di awal
    void insertAtHead(const string &nim, const string &nama, float nilai)
    {
        Node *newNode = new Node(nim, nama, nilai);

        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // Fungsi insert di akhir
    void insertAtTail(const string &nim, const string &nama, float nilai)
    {
        Node *newNode = new Node(nim, nama, nilai);

        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    // Fungsi insert di tengah
    void insertAtMiddle(const string &nim, const string &nama, float nilai)
    {
        if (head == nullptr || head->next == nullptr)
        {
            insertAtTail(nim, nama, nilai);
            return;
        }

        Node *middle = getMiddleNode();
        Node *newNode = new Node(nim, nama, nilai);

        newNode->next = middle->next;
        newNode->prev = middle;

        if (middle->next != nullptr)
        {
            middle->next->prev = newNode;
        }
        middle->next = newNode;
    }

    // Fungsi delete di awal
    void deleteAtHead()
    {
        if (head == nullptr)
        {
            cout << "List kosong!" << endl;
            return;
        }

        Node *temp = head;
        head = head->next;

        if (head != nullptr)
        {
            head->prev = nullptr;
        }

        delete temp;
    }

    // Fungsi delete di akhir
    void deleteAtTail()
    {
        if (head == nullptr)
        {
            cout << "List kosong!" << endl;
            return;
        }

        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }

        if (temp->prev != nullptr)
        {
            temp->prev->next = nullptr;
        }
        else
        {
            head = nullptr;
        }

        delete temp;
    }

    // Fungsi delete di tengah
    void deleteAtMiddle()
    {
        if (head == nullptr || head->next == nullptr)
        {
            deleteAtHead();
            return;
        }

        Node *middle = getMiddleNode();

        if (middle->prev != nullptr)
        {
            middle->prev->next = middle->next;
        }

        if (middle->next != nullptr)
        {
            middle->next->prev = middle->prev;
        }

        delete middle;
    }

    // Fungsi cetak data
    void displayData() const
    {
        if (head == nullptr)
        {
            cout << "List kosong!" << endl;
            return;
        }

        Node *temp = head;
        cout << "Data Mahasiswa:" << endl;
        cout << "NIM\tNAMA\tNILAI" << endl;

        while (temp != nullptr)
        {
            cout << temp->nim << "\t" << temp->nama << "\t" << temp->nilai << endl;
            temp = temp->next;
        }
    }
};

void displayMenu()
{
    cout << "\nLDLL-DATA MAHASISWA\n";
    cout << "===================\n";
    cout << "1. Insert kiri\n";
    cout << "2. Insert kanan\n";
    cout << "3. Insert tengah\n";
    cout << "4. Delete kiri\n";
    cout << "5. Delete kanan\n";
    cout << "6. Delete tengah\n";
    cout << "7. Cetak data\n";
    cout << "8. Keluar\n";
    cout << "Pilihan (1-8): ";
}

void handleInsert(DoubleLinkedList &dll, const string &position)
{
    string nim, nama;
    float nilai;

    cout << "Masukkan NIM: ";
    cin >> nim;
    cout << "Masukkan Nama: ";
    cin >> nama;
    cout << "Masukkan Nilai: ";
    cin >> nilai;

    if (position == "head")
    {
        dll.insertAtHead(nim, nama, nilai);
    }
    else if (position == "tail")
    {
        dll.insertAtTail(nim, nama, nilai);
    }
    else if (position == "middle")
    {
        dll.insertAtMiddle(nim, nama, nilai);
    }
}

int main()
{
    DoubleLinkedList dll;
    int choice;

    do
    {
        displayMenu();
        cin >> choice;

        switch (choice)
        {
        case 1:
            handleInsert(dll, "head");
            break;
        case 2:
            handleInsert(dll, "tail");
            break;
        case 3:
            handleInsert(dll, "middle");
            break;
        case 4:
            dll.deleteAtHead();
            break;
        case 5:
            dll.deleteAtTail();
            break;
        case 6:
            dll.deleteAtMiddle();
            break;
        case 7:
            dll.displayData();
            break;
        case 8:
            cout << "Keluar..." << endl;
            break;
        default:
            cout << "Pilihan tidak valid!" << endl;
        }
    } while (choice != 8);

    return 0;
}

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Mahasiswa
{
    string nim;
    string nama;
    float nilai;
    Mahasiswa *prev;
    Mahasiswa *next;
};

Mahasiswa *head = nullptr;
Mahasiswa *tail = nullptr;

Mahasiswa *createNode(const string &nim, const string &nama, float nilai)
{
    return new Mahasiswa{nim, nama, nilai, nullptr, nullptr};
}

bool isEmpty()
{
    return head == nullptr;
}

void insertAtBeginning(const string &nim, const string &nama, float nilai)
{
    Mahasiswa *newNode = createNode(nim, nama, nilai);
    if (isEmpty())
    {
        head = tail = newNode;
        head->next = head->prev = head;
    }
    else
    {
        newNode->next = head;
        newNode->prev = tail;
        tail->next = newNode;
        head->prev = newNode;
        head = newNode;
    }
}

void insertAtEnd(const string &nim, const string &nama, float nilai)
{
    if (isEmpty())
    {
        insertAtBeginning(nim, nama, nilai);
        return;
    }
    Mahasiswa *newNode = createNode(nim, nama, nilai);
    newNode->prev = tail;
    newNode->next = head;
    tail->next = newNode;
    head->prev = newNode;
    tail = newNode;
}

void insertInOrder(const string &nim, const string &nama, float nilai)
{
    if (isEmpty() || nim < head->nim)
    {
        insertAtBeginning(nim, nama, nilai);
        return;
    }
    Mahasiswa *current = head;
    do
    {
        if (nim < current->nim)
        {
            Mahasiswa *newNode = createNode(nim, nama, nilai);
            newNode->prev = current->prev;
            newNode->next = current;
            current->prev->next = newNode;
            current->prev = newNode;
            return;
        }
        current = current->next;
    } while (current != head);

    insertAtEnd(nim, nama, nilai);
}

void deleteFromBeginning()
{
    if (isEmpty())
    {
        cout << "List kosong, tidak ada data untuk dihapus.\n";
        return;
    }
    Mahasiswa *temp = head;
    if (head == tail)
    {
        head = tail = nullptr;
    }
    else
    {
        head = head->next;
        head->prev = tail;
        tail->next = head;
    }
    delete temp;
    cout << "Data berhasil dihapus dari awal.\n";
}

void deleteFromEnd()
{
    if (isEmpty())
    {
        cout << "List kosong, tidak ada data untuk dihapus.\n";
        return;
    }
    Mahasiswa *temp = tail;
    if (head == tail)
    {
        head = tail = nullptr;
    }
    else
    {
        tail = tail->prev;
        tail->next = head;
        head->prev = tail;
    }
    delete temp;
    cout << "Data berhasil dihapus dari akhir.\n";
}

void deleteByNIM(const string &nim)
{
    if (isEmpty())
    {
        cout << "List kosong, tidak ada data untuk dihapus.\n";
        return;
    }
    Mahasiswa *current = head;
    do
    {
        if (current->nim == nim)
        {
            if (current == head)
            {
                deleteFromBeginning();
            }
            else if (current == tail)
            {
                deleteFromEnd();
            }
            else
            {
                current->prev->next = current->next;
                current->next->prev = current->prev;
                delete current;
                cout << "Data berhasil dihapus.\n";
            }
            return;
        }
        current = current->next;
    } while (current != head);

    cout << "Data dengan NIM " << nim << " tidak ditemukan.\n";
}

void printData()
{
    if (isEmpty())
    {
        cout << "List kosong, tidak ada data untuk ditampilkan.\n";
        return;
    }
    cout << left << setw(10) << "NIM" << setw(20) << "Nama" << setw(10) << "Nilai" << "\n";
    cout << string(40, '-') << "\n";

    Mahasiswa *current = head;
    do
    {
        cout << left << setw(10) << current->nim << setw(20) << current->nama << setw(10) << current->nilai << "\n";
        current = current->next;
    } while (current != head);
}

void inputData(string &nim, string &nama, float &nilai)
{
    cout << "Masukkan NIM  : ";
    cin >> nim;
    cin.ignore();
    cout << "Masukkan Nama : ";
    getline(cin, nama);
    cout << "Masukkan Nilai: ";
    cin >> nilai;
}

void menu()
{
    int choice;
    do
    {
        cout << "\nMenu:\n";
        cout << "1. Insert Kiri\n";
        cout << "2. Insert Kanan\n";
        cout << "3. Insert Tengah (Urut)\n";
        cout << "4. Hapus Kiri\n";
        cout << "5. Hapus Kanan\n";
        cout << "6. Hapus Tengah (berdasarkan NIM)\n";
        cout << "7. Cetak Data\n";
        cout << "8. Keluar\n";
        cout << "Pilih: ";
        cin >> choice;

        string nim, nama;
        float nilai;

        switch (choice)
        {
        case 1:
            inputData(nim, nama, nilai);
            insertAtBeginning(nim, nama, nilai);
            break;
        case 2:
            inputData(nim, nama, nilai);
            insertAtEnd(nim, nama, nilai);
            break;
        case 3:
            inputData(nim, nama, nilai);
            insertInOrder(nim, nama, nilai);
            break;
        case 4:
            deleteFromBeginning();
            break;
        case 5:
            deleteFromEnd();
            break;
        case 6:
            cout << "Masukkan NIM yang ingin dihapus: ";
            cin >> nim;
            deleteByNIM(nim);
            break;
        case 7:
            printData();
            break;
        case 8:
            cout << "Keluar dari program.\n";
            break;
        default:
            cout << "Pilihan tidak valid.\n";
        }
    } while (choice != 8);
}

int main()
{
    menu();
    return 0;
}

#include <iostream>
#include <string>
using namespace std;

class Mahasiswa
{
public:
    string nama;
    string nim;
    float nilai;
    Mahasiswa *next;

    Mahasiswa(string nm, string n, float nl)
    {
        nama = nm;
        nim = n;
        nilai = nl;
        next = nullptr;
    }
};

class CircularLinkedList
{
private:
    Mahasiswa *head;

public:
    CircularLinkedList()
    {
        head = nullptr;
    }

    void insertData(const string &nama, const string &nim, float nilai)
    {
        Mahasiswa *newNode = new Mahasiswa(nama, nim, nilai);
        if (!head)
        {
            head = newNode;
            newNode->next = head;
        }
        else
        {
            Mahasiswa *temp = head;
            Mahasiswa *prev = nullptr;

            // Cari posisi untuk memasukkan node berdasarkan NIM
            do
            {
                if (temp->nim > nim)
                    break;
                prev = temp;
                temp = temp->next;
            } while (temp != head);

            if (!prev)
            { // Insert sebagai head
                newNode->next = head;
                while (temp->next != head)
                    temp = temp->next;
                temp->next = newNode;
                head = newNode;
            }
            else
            { // Insert di tengah atau akhir
                newNode->next = prev->next;
                prev->next = newNode;
            }
        }
        cout << "Data berhasil ditambahkan." << endl;
    }

    void hapusData(const string &nim)
    {
        if (!head)
        {
            cout << "Data kosong!" << endl;
            return;
        }

        Mahasiswa *temp = head;
        Mahasiswa *prev = nullptr;

        // Jika data yang dihapus adalah head
        if (temp->nim == nim)
        {
            if (temp->next == head)
            { // Hanya ada satu elemen
                delete temp;
                head = nullptr;
            }
            else
            { // Banyak elemen, cari elemen terakhir
                while (temp->next != head)
                    temp = temp->next;
                temp->next = head->next;
                delete head;
                head = temp->next;
            }
            cout << "Data dengan NIM " << nim << " berhasil dihapus." << endl;
            return;
        }

        // Cari data yang sesuai
        temp = head;
        do
        {
            prev = temp;
            temp = temp->next;
            if (temp->nim == nim)
            {
                prev->next = temp->next;
                delete temp;
                cout << "Data dengan NIM " << nim << " berhasil dihapus." << endl;
                return;
            }
        } while (temp != head);

        cout << "Data dengan NIM " << nim << " tidak ditemukan." << endl;
    }

    void cetakData() const
    {
        if (!head)
        {
            cout << "Data kosong!" << endl;
            return;
        }

        Mahasiswa *temp = head;
        cout << "Data Mahasiswa:" << endl;
        cout << "===================" << endl;
        do
        {
            cout << "NIM: " << temp->nim << ", Nama: " << temp->nama
                 << ", Nilai: " << temp->nilai << endl;
            temp = temp->next;
        } while (temp != head);
    }
};

int main()
{
    CircularLinkedList cll;
    int pilihan;
    string nama, nim;
    float nilai;

    while (true)
    {
        cout << "\nCIRCULAR LINKED LIST" << endl;
        cout << "==========================" << endl;
        cout << "1. INSERT DATA" << endl;
        cout << "2. HAPUS DATA" << endl;
        cout << "3. CETAK DATA" << endl;
        cout << "4. EXIT" << endl;
        cout << "Pilihan (1/2/3/4): ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            cout << "Masukkan nama mahasiswa: ";
            cin.ignore(); // Mengabaikan newline
            getline(cin, nama);
            cout << "Masukkan NIM mahasiswa: ";
            getline(cin, nim);
            cout << "Masukkan nilai mahasiswa: ";
            cin >> nilai;
            cll.insertData(nama, nim, nilai);
            break;

        case 2:
            cout << "Masukkan NIM yang ingin dihapus: ";
            cin.ignore(); // Mengabaikan newline
            getline(cin, nim);
            cll.hapusData(nim);
            break;

        case 3:
            cll.cetakData();
            break;

        case 4:
            cout << "Keluar dari program..." << endl;
            return 0;

        default:
            cout << "Pilihan tidak valid, coba lagi." << endl;
        }
    }
    return 0;
}

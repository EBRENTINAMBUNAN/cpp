#include <iostream>
#include <string>

using namespace std;

struct Node
{
    string nim;
    string nama;
    Node *next;
};

class SinglyLinkedList
{
private:
    Node *head;

public:
    SinglyLinkedList()
    {
        head = nullptr;
    }

    void tambahMahasiswa(string nim, string nama)
    {
        if (cariMahasiswa(nim) != nullptr)
        {
            cout << "Mahasiswa dengan NIM " << nim << " sudah ada!" << endl;
            return;
        }

        Node *newNode = new Node();
        newNode->nim = nim;
        newNode->nama = nama;
        newNode->next = nullptr;

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
        }

        cout << "Mahasiswa dengan NIM " << nim << " dan nama " << nama << " berhasil ditambahkan." << endl;
    }

    void hapusMahasiswa(string nim)
    {
        if (head == nullptr)
        {
            cout << "Daftar mahasiswa kosong!" << endl;
            return;
        }

        if (head->nim == nim)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            cout << "Mahasiswa dengan NIM " << nim << " berhasil dihapus." << endl;
            return;
        }

        Node *current = head;
        Node *prev = nullptr;

        while (current != nullptr && current->nim != nim)
        {
            prev = current;
            current = current->next;
        }

        if (current == nullptr)
        {
            cout << "Mahasiswa dengan NIM " << nim << " tidak ditemukan." << endl;
            return;
        }

        prev->next = current->next;
        delete current;
        cout << "Mahasiswa dengan NIM " << nim << " berhasil dihapus." << endl;
    }

    Node *cariMahasiswa(string nim)
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            if (temp->nim == nim)
                return temp;
            temp = temp->next;
        }
        return nullptr;
    }

    void cetakDaftarMahasiswa()
    {
        if (head == nullptr)
        {
            cout << "Daftar mahasiswa kosong!" << endl;
            return;
        }

        Node *temp = head;
        cout << "\nDaftar Mahasiswa: " << endl;
        while (temp != nullptr)
        {
            cout << "NIM: " << temp->nim << ", Nama: " << temp->nama << endl;
            temp = temp->next;
        }
    }

    void hapusSemuaMahasiswa()
    {
        Node *current = head;
        while (current != nullptr)
        {
            Node *temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        cout << "Semua data mahasiswa telah dihapus." << endl;
    }

    ~SinglyLinkedList()
    {
        hapusSemuaMahasiswa();
    }
};

int main()
{
    SinglyLinkedList daftarMahasiswa;
    int pilihan;
    string nim, nama;

    do
    {
        cout << "\nMenu: " << endl;
        cout << "1. Tambah Mahasiswa" << endl;
        cout << "2. Hapus Mahasiswa Berdasarkan NIM" << endl;
        cout << "3. Cari Mahasiswa Berdasarkan NIM" << endl;
        cout << "4. Cetak Daftar Mahasiswa" << endl;
        cout << "5. Hapus Semua Mahasiswa" << endl;
        cout << "6. Keluar" << endl;
        cout << "Masukkan pilihan: ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            cout << "Masukkan NIM: ";
            cin >> nim;
            cout << "Masukkan Nama: ";
            cin.ignore();
            getline(cin, nama);
            daftarMahasiswa.tambahMahasiswa(nim, nama);
            break;
        case 2:
            cout << "Masukkan NIM mahasiswa yang ingin dihapus: ";
            cin >> nim;
            daftarMahasiswa.hapusMahasiswa(nim);
            break;
        case 3:
            cout << "Masukkan NIM mahasiswa yang ingin dicari: ";
            cin >> nim;
            if (daftarMahasiswa.cariMahasiswa(nim) != nullptr)
            {
                cout << "Mahasiswa dengan NIM " << nim << " ditemukan." << endl;
            }
            else
            {
                cout << "Mahasiswa dengan NIM " << nim << " tidak ditemukan." << endl;
            }
            break;
        case 4:
            daftarMahasiswa.cetakDaftarMahasiswa();
            break;
        case 5:
            daftarMahasiswa.hapusSemuaMahasiswa();
            break;
        case 6:
            cout << "Keluar dari program." << endl;
            break;
        default:
            cout << "Pilihan tidak valid!" << endl;
        }

    } while (pilihan != 6);

    return 0;
}

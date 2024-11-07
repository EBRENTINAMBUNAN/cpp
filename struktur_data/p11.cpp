/*
|==============================================|
|   Implementasi LINIER DOUBLE LINKED LIST     |
|==============================================|
|     created by EBREN TINAMBUNAN              |
| Program ini membantu pengguna mengelola      |
|daftar kontak sederhana dengan operasi dasar. |
|                                              |
|       https://github.com/EBRENTINAMBUNAN     |
|==============================================|
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Struktur data untuk menyimpan informasi kontak
struct Contact
{
    string name;
    string phone;
    string email;

    // Konstruktor untuk membuat kontak baru
    Contact(string n, string p, string e) : name(n), phone(p), email(e) {}
};

// Kelas AddressBook untuk menangani operasi pada kontak
class AddressBook
{
private:
    vector<Contact> contacts; // Vector untuk menyimpan daftar kontak

public:
    // Menambahkan kontak baru ke dalam buku alamat
    void addContact(const string &name, const string &phone, const string &email)
    {
        contacts.push_back(Contact(name, phone, email));
        cout << "Kontak berhasil ditambahkan!\n";
    }

    // Menampilkan semua kontak dalam buku alamat
    void displayContacts() const
    {
        if (contacts.empty())
        {
            cout << "Buku alamat kosong.\n";
            return;
        }

        cout << "\nDaftar Kontak:\n";
        for (size_t i = 0; i < contacts.size(); ++i)
        {
            cout << i + 1 << ". Nama: " << contacts[i].name
                 << ", Telepon: " << contacts[i].phone
                 << ", Email: " << contacts[i].email << endl;
        }
    }

    // Mencari kontak berdasarkan nama
    void searchContact(const string &name) const
    {
        bool found = false;
        for (const auto &contact : contacts)
        {
            if (contact.name == name)
            {
                cout << "Ditemukan! Nama: " << contact.name
                     << ", Telepon: " << contact.phone
                     << ", Email: " << contact.email << endl;
                found = true;
                break;
            }
        }
        if (!found)
        {
            cout << "Kontak dengan nama " << name << " tidak ditemukan.\n";
        }
    }

    // Menghapus kontak berdasarkan nama
    void deleteContact(const string &name)
    {
        for (auto it = contacts.begin(); it != contacts.end(); ++it)
        {
            if (it->name == name)
            {
                contacts.erase(it);
                cout << "Kontak " << name << " berhasil dihapus!\n";
                return;
            }
        }
        cout << "Kontak dengan nama " << name << " tidak ditemukan.\n";
    }
};

int main()
{
    AddressBook myAddressBook;
    int choice;
    string name, phone, email;

    do
    {
        // Menu interaktif
        cout << "\n=== Menu Buku Alamat ===\n";
        cout << "1. Tambah Kontak\n";
        cout << "2. Tampilkan Semua Kontak\n";
        cout << "3. Cari Kontak\n";
        cout << "4. Hapus Kontak\n";
        cout << "5. Keluar\n";
        cout << "Pilih opsi: ";
        cin >> choice;
        cin.ignore(); // Membersihkan newline dari input

        switch (choice)
        {
        case 1:
            // Menambahkan kontak baru
            cout << "Masukkan Nama: ";
            getline(cin, name);
            cout << "Masukkan Telepon: ";
            getline(cin, phone);
            cout << "Masukkan Email: ";
            getline(cin, email);
            myAddressBook.addContact(name, phone, email);
            break;

        case 2:
            // Menampilkan semua kontak
            myAddressBook.displayContacts();
            break;

        case 3:
            // Mencari kontak berdasarkan nama
            cout << "Masukkan Nama untuk Pencarian: ";
            getline(cin, name);
            myAddressBook.searchContact(name);
            break;

        case 4:
            // Menghapus kontak berdasarkan nama
            cout << "Masukkan Nama yang Akan Dihapus: ";
            getline(cin, name);
            myAddressBook.deleteContact(name);
            break;

        case 5:
            // Keluar dari program
            cout << "Keluar dari program.\n";
            break;

        default:
            cout << "Pilihan tidak valid. Coba lagi.\n";
        }
    } while (choice != 5);

    return 0;
}

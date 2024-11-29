#include <iostream>
using namespace std;

// Struktur Node untuk Linked List
struct Node {
    int data;
    Node* next;

    // Constructor untuk Node
    explicit Node(int value) : data(value), next(nullptr) {}
};

// Kelas Linear Single Linked List
class LinearSingleLinkedList {
private:
    Node* head; // Pointer ke head linked list

public:
    // Constructor untuk menginisialisasi linked list kosong
    LinearSingleLinkedList() : head(nullptr) {}

    // Fungsi untuk memasukkan data di awal linked list
    void insertAtFront(int value) {
        Node* newNode = new Node(value); // Membuat Node baru
        newNode->next = head;           // Node baru menunjuk ke head
        head = newNode;                 // Update head ke Node baru
    }

    // Fungsi untuk mencetak isi linked list
    void printList() const {
        if (!head) {
            cout << "Linked list kosong.\n";
            return;
        }

        Node* current = head;
        while (current) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "NULL\n";
    }

    // Fungsi untuk mencari elemen menggunakan linear search
    bool search(int key) const {
        Node* current = head;
        while (current) {
            if (current->data == key) {
                return true; // Data ditemukan
            }
            current = current->next;
        }
        return false; // Data tidak ditemukan
    }
};

// Fungsi untuk menampilkan menu utama
void displayMenu() {
    cout << "\n=== Linear Single Linked List ===\n";
    cout << "1. Tambahkan Data\n";
    cout << "2. Cetak Linked List\n";
    cout << "3. Cari Data\n";
    cout << "4. Keluar\n";
    cout << "Pilihan Anda: ";
}

// Fungsi utama program
int main() {
    LinearSingleLinkedList list; // Objek linked list
    int choice, value;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1: // Tambahkan data
                cout << "Masukkan nilai yang akan ditambahkan: ";
                cin >> value;
                list.insertAtFront(value);
                cout << "Data berhasil ditambahkan.\n";
                break;

            case 2: // Cetak linked list
                cout << "Isi Linked List: ";
                list.printList();
                break;

            case 3: // Cari data
                cout << "Masukkan nilai yang ingin dicari: ";
                cin >> value;
                if (list.search(value)) {
                    cout << "Data " << value << " ditemukan di linked list.\n";
                } else {
                    cout << "Data " << value << " tidak ditemukan di linked list.\n";
                }
                break;

            case 4: // Keluar
                cout << "Keluar dari program. Terima kasih!\n";
                break;

            default: // Pilihan tidak valid
                cout << "Pilihan tidak valid. Coba lagi.\n";
                break;
        }
    } while (choice != 4);

    return 0;
}

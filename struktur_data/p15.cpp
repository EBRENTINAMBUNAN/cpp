#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Struktur untuk data mahasiswa
struct Mahasiswa
{
    string nama;
    string nim;
    float nilai;
    Mahasiswa *sebelumnya;  // pointer ke node sebelumnya
    Mahasiswa *selanjutnya; // pointer ke node selanjutnya
};

// Kelas Circular Double Linked List
class CircularDoubleLinkedList
{
private:
    Mahasiswa *kepala; // pointer ke node kepala

    // Buat node baru untuk mahasiswa
    Mahasiswa *buatNode(const string &nama, const string &nim, float nilai)
    {
        Mahasiswa *nodeBaru = new Mahasiswa();
        nodeBaru->nama = nama;
        nodeBaru->nim = nim;
        nodeBaru->nilai = nilai;
        nodeBaru->sebelumnya = nullptr;
        nodeBaru->selanjutnya = nullptr;
        return nodeBaru;
    }

public:
    CircularDoubleLinkedList() : kepala(nullptr) {}

    // Tambah mahasiswa baru, urut berdasarkan NIM
    void tambahMahasiswa(const string &nama, const string &nim, float nilai)
    {
        Mahasiswa *nodeBaru = buatNode(nama, nim, nilai);

        if (!kepala)
        {
            // Kalau list kosong, node jadi kepala
            kepala = nodeBaru;
            kepala->selanjutnya = kepala;
            kepala->sebelumnya = kepala;
        }
        else
        {
            Mahasiswa *sekarang = kepala;
            Mahasiswa *sebelum = nullptr;

            // Cari posisi berdasarkan urutan NIM
            do
            {
                if (sekarang->nim > nim)
                    break;
                sebelum = sekarang;
                sekarang = sekarang->selanjutnya;
            } while (sekarang != kepala);

            if (!sebelum || sekarang == kepala)
            {
                // Kalau harus disisipkan di depan
                nodeBaru->selanjutnya = kepala;
                nodeBaru->sebelumnya = kepala->sebelumnya;
                kepala->sebelumnya->selanjutnya = nodeBaru;
                kepala->sebelumnya = nodeBaru;
                kepala = nodeBaru;
            }
            else
            {
                // Kalau disisipkan di tengah atau akhir
                nodeBaru->selanjutnya = sekarang;
                nodeBaru->sebelumnya = sebelum;
                sebelum->selanjutnya = nodeBaru;
                sekarang->sebelumnya = nodeBaru;
            }
        }

        cout << "Mahasiswa berhasil ditambahkan!\n";
    }

    // Hapus mahasiswa berdasarkan NIM
    void hapusMahasiswa(const string &nim)
    {
        if (!kepala)
        {
            cout << "Data kosong, gak ada yang bisa dihapus.\n";
            return;
        }

        Mahasiswa *sekarang = kepala;
        do
        {
            if (sekarang->nim == nim)
            {
                if (sekarang->selanjutnya == sekarang)
                {
                    // Kalau cuma ada satu node
                    kepala = nullptr;
                }
                else
                {
                    sekarang->sebelumnya->selanjutnya = sekarang->selanjutnya;
                    sekarang->selanjutnya->sebelumnya = sekarang->sebelumnya;
                    if (sekarang == kepala)
                    {
                        kepala = sekarang->selanjutnya;
                    }
                }

                delete sekarang;
                cout << "Mahasiswa dengan NIM " << nim << " berhasil dihapus!\n";
                return;
            }
            sekarang = sekarang->selanjutnya;
        } while (sekarang != kepala);

        cout << "Mahasiswa dengan NIM " << nim << " gak ketemu.\n";
    }

    // Cetak semua data mahasiswa
    void cetakMahasiswa()
    {
        if (!kepala)
        {
            cout << "List kosong, gak ada data untuk ditampilkan.\n";
            return;
        }

        cout << left << setw(15) << "NIM"
             << setw(25) << "Nama"
             << setw(10) << "Nilai" << endl;
        cout << string(50, '-') << endl;

        Mahasiswa *sekarang = kepala;
        do
        {
            cout << left << setw(15) << sekarang->nim
                 << setw(25) << sekarang->nama
                 << setw(10) << sekarang->nilai << endl;
            sekarang = sekarang->selanjutnya;
        } while (sekarang != kepala);
    }

    // Destructor buat hapus semua node
    ~CircularDoubleLinkedList()
    {
        if (!kepala)
            return;

        Mahasiswa *sekarang = kepala;
        do
        {
            Mahasiswa *sementara = sekarang;
            sekarang = sekarang->selanjutnya;
            delete sementara;
        } while (sekarang != kepala);
    }
};

// Fungsi utama
int main()
{
    CircularDoubleLinkedList listMahasiswa;
    int pilihan;
    string nama, nim;
    float nilai;

    do
    {
        cout << "\n===== MENU =====\n";
        cout << "1. Tambah Data Mahasiswa\n";
        cout << "2. Hapus Data Mahasiswa\n";
        cout << "3. Cetak Semua Data Mahasiswa\n";
        cout << "4. Keluar dari Program\n";
        cout << "Pilihan Anda: ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            cout << "\nNama Mahasiswa: ";
            cin.ignore();
            getline(cin, nama);
            cout << "NIM Mahasiswa: ";
            cin >> nim;
            cout << "Nilai Mahasiswa: ";
            cin >> nilai;
            listMahasiswa.tambahMahasiswa(nama, nim, nilai);
            break;

        case 2:
            cout << "\nMasukkan NIM yang mau dihapus: ";
            cin >> nim;
            listMahasiswa.hapusMahasiswa(nim);
            break;

        case 3:
            cout << "\nData Mahasiswa:\n";
            listMahasiswa.cetakMahasiswa();
            break;

        case 4:
            cout << "Keluar dari program. Bye!\n";
            break;

        default:
            cout << "Pilihan gak valid, coba lagi!\n";
        }
    } while (pilihan != 4);

    return 0;
}

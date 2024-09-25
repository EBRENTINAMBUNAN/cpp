#include <iostream>
#include <iomanip>
using namespace std;

struct Nilai
{
    float tugas;
    float ujian;
};

struct Mahasiswa
{
    string nama;
    string nim;
    Nilai nilai;
    float nilaiAkhir;
};

float hitungNilaiAkhir(Nilai nilai)
{
    return (nilai.tugas * 0.4) + (nilai.ujian * 0.6);
}

void tampilkanHeader()
{
    cout << "=====================================\n";
    cout << "   Program Penghitungan Nilai Akhir   \n";
    cout << "=====================================\n\n";
}

void tampilkanMahasiswa(const Mahasiswa &mhs)
{
    cout << fixed << setprecision(2);
    cout << "Nama          : " << mhs.nama << "\n";
    cout << "NIM           : " << mhs.nim << "\n";
    cout << "Nilai Tugas   : " << mhs.nilai.tugas << "\n";
    cout << "Nilai Ujian   : " << mhs.nilai.ujian << "\n";
    cout << "Nilai Akhir   : " << mhs.nilaiAkhir << "\n";
    cout << "-------------------------------------\n";
}

int main()
{
    tampilkanHeader();

    int jumlahMahasiswa;
    cout << "Masukkan jumlah mahasiswa: ";
    cin >> jumlahMahasiswa;
    cin.ignore();

    Mahasiswa *mahasiswa = new Mahasiswa[jumlahMahasiswa];

    for (int i = 0; i < jumlahMahasiswa; i++)
    {
        cout << "\nMasukkan data mahasiswa ke-" << i + 1 << ":\n";
        cout << "Nama: ";
        getline(cin, mahasiswa[i].nama);
        cout << "NIM: ";
        getline(cin, mahasiswa[i].nim);
        cout << "Nilai Tugas (0-100): ";
        cin >> mahasiswa[i].nilai.tugas;
        cout << "Nilai Ujian (0-100): ";
        cin >> mahasiswa[i].nilai.ujian;
        cin.ignore();

        mahasiswa[i]
            .nilaiAkhir = hitungNilaiAkhir(mahasiswa[i].nilai);
        cout << "Nilai Akhir mahasiswa " << mahasiswa[i].nama << " berhasil dihitung!\n";
    }

    cout << "\n=====================================\n";
    cout << "     Data Mahasiswa dan Nilai Akhir   \n";
    cout << "=====================================\n\n";

    for (int i = 0; i < jumlahMahasiswa; i++)
    {
        tampilkanMahasiswa(mahasiswa[i]);
    }

    delete[] mahasiswa;
    return 0;
}

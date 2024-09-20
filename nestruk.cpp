#include <iostream>
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

int main()
{
    int jumlahMahasiswa;
    cout << "Masukkan jumlah mahasiswa: ";
    cin >> jumlahMahasiswa;

    Mahasiswa mahasiswa[jumlahMahasiswa];

    for (int i = 0; i < jumlahMahasiswa; i++)
    {
        cout << "Masukkan data mahasiswa ke-" << i + 1 << ":\n";
        cout << "Nama: ";
        cin.ignore();
        getline(cin, mahasiswa[i].nama);
        cout << "NIM: ";
        cin >> mahasiswa[i].nim;
        cout << "Nilai tugas: ";
        cin >> mahasiswa[i].nilai.tugas;
        cout << "Nilai ujian: ";
        cin >> mahasiswa[i].nilai.ujian;

        mahasiswa[i].nilaiAkhir = hitungNilaiAkhir(mahasiswa[i].nilai);
    }

    cout << "\nData mahasiswa beserta nilai akhir:\n";
    for (int i = 0; i < jumlahMahasiswa; i++)
    {
        cout << "Nama: " << mahasiswa[i].nama << "\n";
        cout << "NIM: " << mahasiswa[i].nim << "\n";
        cout << "Nilai Tugas: " << mahasiswa[i].nilai.tugas << "\n";
        cout << "Nilai Ujian: " << mahasiswa[i].nilai.ujian << "\n";
        cout << "Nilai Akhir: " << mahasiswa[i].nilaiAkhir << "\n\n";
    }

    return 0;
}

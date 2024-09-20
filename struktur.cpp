#include <iostream>
using namespace std;

struct provinsi
{
    string kota;
    string namaProvinsi;
    double luasWilayah;
    long jumlahPenduduk;
};

int main()
{
    provinsi dataProvinsi;

    cout << "Masukkan Nama Kota: ";
    getline(cin, dataProvinsi.kota);

    if (dataProvinsi.kota == "tangerang selatan")
    {
        dataProvinsi.namaProvinsi = "Banten";
        dataProvinsi.luasWilayah = 147.19;
        dataProvinsi.jumlahPenduduk = 1500000;
    }
    else
    {
        cout << "Maaf, Kota tidak tersedia." << endl;
        return 0;
    }
    cout << "\nData Provinsi:" << endl;
    cout << "Kota: " << dataProvinsi.kota << endl;
    cout << "Nama Provinsi: " << dataProvinsi.namaProvinsi << endl;
    cout << "Luas Wilayah: " << dataProvinsi.luasWilayah << " km²" << endl;
    cout << "Jumlah Penduduk: " << dataProvinsi.jumlahPenduduk << endl;
    return 0;
}

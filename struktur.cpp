#include <iostream>
#include <map>
using namespace std;

struct Provinsi
{
    string namaProvinsi;
    double luasWilayah;
    long jumlahPenduduk;
    string namaWalikota;
    string kodePos;
    int tahunBerdiri;
};

int main()
{
    map<string, Provinsi> dataProvinsi = {
        {"tangerang selatan", {"Banten", 147.19, 1500000, "Benyamin Davnie", "15310", 2008}},
        {"medan", {"Sumatera Utara", 265.10, 2500000, "Bobby Nasution", "20111", 1590}},
        {"surabaya", {"Jawa Timur", 350.54, 2890000, "Eri Cahyadi", "60119", 1293}},
        {"bandung", {"Jawa Barat", 167.67, 2390000, "Yana Mulyana", "40111", 1810}},
        {"jakarta", {"DKI Jakarta", 662.33, 10770487, "Heru Budi Hartono", "10110", 1527}},
        {"semarang", {"Jawa Tengah", 373.78, 1670000, "Hendrar Prihadi", "50135", 1547}},
        {"makassar", {"Sulawesi Selatan", 199.26, 1410000, "Moh. Ramdhan Pomanto", "90111", 1607}},
        {"denpasar", {"Bali", 123.98, 897300, "I Gusti Ngurah Jaya Negara", "80232", 1788}},
        {"palembang", {"Sumatera Selatan", 358.55, 1640000, "Harnojoyo", "30111", 683}},
        {"yogyakarta", {"DI Yogyakarta", 32.8, 373589, "Haryadi Suyuti", "55111", 1756}},
        {"balikpapan", {"Kalimantan Timur", 503.3, 645800, "Rahmad Mas'ud", "76112", 1897}},
        {"malang", {"Jawa Timur", 252.1, 869000, "Sutiaji", "65111", 1914}},
        {"batam", {"Kepulauan Riau", 715, 1326000, "Muhammad Rudi", "29461", 1970}},
        {"pekanbaru", {"Riau", 632.26, 964000, "Firdaus", "28111", 1784}},
        {"manado", {"Sulawesi Utara", 157.26, 451916, "Andrei Angouw", "95111", 1623}},
        {"pontianak", {"Kalimantan Barat", 107.82, 655000, "Edi Rusdi Kamtono", "78111", 1771}},
        {"padang", {"Sumatera Barat", 694.96, 909000, "Hendri Septa", "25111", 1669}},
        {"samarinda", {"Kalimantan Timur", 718, 812597, "Andi Harun", "75111", 1668}},
        {"banda aceh", {"Aceh", 61.36, 224000, "Aminullah Usman", "23111", 1205}},
        {"jayapura", {"Papua", 935.92, 315872, "Benhur Tommy Mano", "99112", 1910}}};

    char pilihan;
    do
    {
        string kota;
        cout << "Masukkan Nama Kota: ";
        getline(cin, kota);

        auto it = dataProvinsi.find(kota);
        if (it != dataProvinsi.end())
        {
            cout << "\nData-data Kota:" << endl;
            cout << "=========================" << endl;
            cout << "Nama Kota: " << kota << endl;
            cout << "Nama Provinsi: " << it->second.namaProvinsi << endl;
            cout << "Luas Wilayah: " << it->second.luasWilayah << " km²" << endl;
            cout << "Jumlah Penduduk: " << it->second.jumlahPenduduk << endl;
            cout << "Nama Walikota: " << it->second.namaWalikota << endl;
            cout << "Kode Pos: " << it->second.kodePos << endl;
            cout << "Tahun Berdiri: " << it->second.tahunBerdiri << endl;
        }
        else
        {
            cout << "Maaf, Kota tidak tersedia. Silakan coba lagi.\n"
                 << endl;
        }

        cout << "\nApakah Anda ingin memasukkan data lagi? (y/n): ";
        cin >> pilihan;
        cin.ignore();

    } while (pilihan == 'y' || pilihan == 'Y');

    cout << "Terima kasih! Program berakhir." << endl;

    return 0;
}

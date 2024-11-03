#include <iostream>
using namespace std;

// Fungsi untuk mengonversi dari Dolar ke Rupiah.
void tukarRupiah(double *rupiah, double *dollar)
{
    const double rate = 15497; // Nilai tukar Dolar ke Rupiah
    *rupiah = *dollar * rate;  // Menghitung konversi ke Dolar
}

int main()
{
    double rupiah, dollar;

    // Meminta input dari pengguna untuk memasukan jumlah dollar
    // yang ingin di konversi ke rupiah
    cout << "Masukkan jumlah Dolar US: ";
    cin >> dollar;

    // Memanggil fungsi untuk mengonversi Dollar ke Rupiah
    tukarRupiah(&rupiah, &dollar);

    // Menampilkan hasil konversi ke mata uang Dollar US
    cout << "Hasil konversi : " << endl;
    cout << "Rp " << rupiah << endl;

    return 0;
}

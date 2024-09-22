#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

double convertDosaToSaldo(int jumlahDosa)
{
    const double rateDosaToDana = 500.0;
    return jumlahDosa * rateDosaToDana;
}

int main()
{
    string nama;
    string nomor;
    int jumlahDosa;

    char pilihan = 'y';
    while (pilihan == 'y')
    {
        cout << "Masukkan nama anda : ";
        getline(cin, nama);

        cout << "Masukkan nomor Dana anda : ";
        getline(cin, nomor);

        cout << "Berapa jumlah dosa anda, " << nama << "? ";
        cin >> jumlahDosa;

        double saldoDana = convertDosaToSaldo(jumlahDosa);

        cout << fixed << setprecision(0);

        cout << "====================================" << endl;
        cout << "| Selamat, dosa anda telah ditukar |" << endl;
        cout << "====================================" << endl;
        cout << "| Nama         : " << nama << endl;
        cout << "| Nomor Dana   : " << nomor << endl;
        cout << "| Jumlah Saldo : " << jumlahDosa << endl;
        cout << "====================================" << endl;
        cout << "Silahkan Cek saldo dana anda !!! " << endl
             << endl;

        cout
            << "Mau Convert lagi ? (y/n) : ";
        cin >> pilihan;
        cout << endl;
        cin.ignore();
    }
    cout << "Program telah berakhir, Terima kasih :)";
    return 0;
}

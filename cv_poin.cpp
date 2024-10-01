#include <iostream>
#include <iomanip>
using namespace std;

void showHeader()
{
    cout << "====================================================\n";
    cout << "\033[1;36m" << setw(35) << "PROGRAM CONVERT POIN INMPHNG\n"
         << "\033[0m";
    cout << "\033[1;36m" << setw(35) << "BY EBREN TINAMBUNAN\n"
         << "\033[0m";
    cout << "====================================================\n";
}

int main()
{
    string username;
    int poin = 1000;
    char pilihan;
    int nomorDana;

    showHeader();
    cout << "masukan nama anda : ";
    getline(cin, username);

    cout << "sisa poin kamu adalah " << poin << endl;
    cout << "apakah mau di convert ke dana ? (y/n) : ";
    cin >> pilihan;

    if (pilihan == 'y' || pilihan == 'Y')
    {
        cout << "masukan nomor dana kamu : ";
        cin >> nomorDana;

        cout << "selamat kamu berhasil menukar poin senilai " << poin;
    }
    else
    {
        cout << "program telah berakhir, terima kasih...";
    }

    return 0;
}
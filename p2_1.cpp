#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int arrayPertama[5], arrayKedua[5], arrayHasil[5];

    cout << "==============================" << endl;
    cout << "|  Selamat Datang di Program |" << endl;
    cout << "|      Penjumlahan Array     |" << endl;
    cout << "|     by Ebren Tinambunan    |" << endl;
    cout << "==============================" << endl;

    cout << "------------------------------" << endl;
    cout << "Array : pertama               " << endl;
    cout << "Silahkan Masukkan 5 angka     " << endl;
    cout << "------------------------------" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "Angka ke-" << i + 1 << ": ";
        cin >> arrayPertama[i];
    }

    cout << "------------------------------" << endl;
    cout << "Array Kedua                   " << endl;
    cout << "Silahkan Masukkan 5 angka     " << endl;
    cout << "------------------------------" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "Angka ke-" << i + 1 << ": ";
        cin >> arrayKedua[i];
    }

    for (int i = 0; i < 5; i++)
    {
        arrayHasil[i] = arrayPertama[i] + arrayKedua[i];
    }

    cout << "\nHasil penjumlahan kedua array adalah:" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "Elemen ke-" << i + 1 << ": " << arrayHasil[i] << endl;
    }

    cout << "\nTerima kasih telah menggunakan program ini!" << endl;
    return 0;
}

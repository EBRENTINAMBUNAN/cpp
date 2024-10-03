#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    const int angka = 5;
    int array[angka];
    int searchValue;
    bool found = false;

    cout << "========================================" << endl;
    cout << "      Selamat Datang di Program         " << endl;
    cout << "          Menggunakan array             " << endl;
    cout << "          by Ebren Tinambunan          " << endl;
    cout << "========================================" << endl;

    cout << "\nMasukkan 5 angka:" << endl;
    for (int i = 0; i < angka; i++)
    {
        cout << "Masukkan nilai pada indeks " << i << ": ";
        cin >> array[i];
    }

    cout << "\nMasukkan nilai yang akan dicari: ";
    cin >> searchValue;

    for (int i = 0; i < angka; i++)
    {
        if (array[i] == searchValue)
        {
            cout << "Nilai ditemukan pada indeks ke-" << i << " dalam array." << endl;
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "Nilai tidak ditemukan dalam array." << endl;
    }

    return 0;
}

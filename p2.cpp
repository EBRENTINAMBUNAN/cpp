#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int angka[10];

    cout << "========================================" << endl;
    cout << "  Selamat Datang di Program Pencari Nilai" << endl;
    cout << "    Maksimum dan Minimum dari 10 Angka!" << endl;
    cout << "          by Ebren Tinambunan          " << endl;
    cout << "========================================" << endl;

    cout << "\nMasukkan 10 angka:" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << "Angka ke-" << i + 1 << ": ";
        cin >> angka[i];
    }

    int max = angka[0];
    int min = angka[0];

    for (int i = 1; i < 10; i++)
    {
        if (angka[i] > max)
        {
            max = angka[i];
        }
        if (angka[i] < min)
        {
            min = angka[i];
        }
    }

    cout << "\n========================================" << endl;
    cout << "            Hasil Analisis               " << endl;
    cout << "========================================" << endl;

    cout << "Nilai maksimum dalam array: " << setw(10) << max << endl;
    cout << "Nilai minimum dalam array:  " << setw(10) << min << endl;
    cout << "========================================" << endl;

    cout << "\nTerima kasih telah menggunakan program ini!" << endl;
    cout << "========================================" << endl;

    return 0;
}

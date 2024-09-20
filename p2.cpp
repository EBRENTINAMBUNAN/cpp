#include <iostream>
using namespace std;

int main()
{
    int angka[5];

    cout << "Masukkan 5 angka:" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "Angka ke-" << i + 1 << ": ";
        cin >> angka[i];
    }

    cout << "\nIsi array:" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "Angka pada indeks " << i << ": " << angka[i] << endl;
    }

    int jumlah = 0;
    for (int i = 0; i < 5; i++)
    {
        jumlah += angka[i];
    }

    cout << "\nJumlah seluruh elemen array: " << jumlah << endl;

    int maksimum = angka[0];
    for (int i = 1; i < 5; i++)
    {
        if (angka[i] > maksimum)
        {
            maksimum = angka[i];
        }
    }

    cout << "Nilai maksimum dalam array: " << maksimum << endl;

    return 0;
}

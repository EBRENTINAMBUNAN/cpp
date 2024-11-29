/*
|==============================================|
|      IMPLEMENTASI BUBBLE SORT DENGAN         |
|              ANIMASI ARRAY                   |
|==============================================|
|       Created by [EBREN TINAMBUNAN]          |
|----------------------------------------------|
| Program ini membantu pengguna memahami cara  |
|kerja algoritma Bubble Sort dengan visualisasi|
| langsung di terminal. Animasi ditampilkan    |
| untuk mempermudah pengamatan proses sorting. |
|                                              |
| Fitur-fitur program:                         |
| 1. Menampilkan array awal sebelum proses     |
|    sorting dimulai.                          |
| 2. Menampilkan animasi selama proses sorting,|
|    dengan elemen yang dibandingkan disorot   |
|    menggunakan warna.                        |
| 3. Menampilkan hasil array setelah setiap    |
|    pass dari algoritma Bubble Sort.          |
| 4. Menampilkan array akhir setelah sorting.  |
|                                              |
| Program dirancang untuk mendemonstrasikan    |
| konsep sorting sederhana secara interaktif   |
| dan mudah dipahami.                          |
|                                              |
|         https://github.com/ebrentinambunan   |
|==============================================|
*/

#include <iostream>
#include <vector>
#include <iomanip>
#include <thread>
#include <chrono>

using namespace std;

// Fungsi buat nunjukin isi array
void tampilkanArray(const vector<int> &arr)
{
    for (int num : arr)
    {
        cout << setw(3) << num << " ";
    }
    cout << endl;
}

// Fungsi buat animasi proses sorting
void animasiArray(const vector<int> &arr, int sorot1 = -1, int sorot2 = -1)
{
    for (size_t i = 0; i < arr.size(); i++)
    {
        if (i == sorot1 || i == sorot2)
        {
            // Nunjuk elemen yang lagi dibandingin (warna merah)
            cout << "\033[1;31m" << setw(3) << arr[i] << "\033[0m ";
        }
        else
        {
            cout << setw(3) << arr[i] << " ";
        }
    }
    cout << endl;
    this_thread::sleep_for(chrono::milliseconds(300)); // Delay buat animasi
}

// Fungsi Bubble Sort dengan animasi
void bubbleSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false; // Buat cek apakah ada elemen yang ditukar
        for (int j = 0; j < n - i - 1; j++)
        {
            // Tampilkan array sebelum swap
            animasiArray(arr, j, j + 1);

            if (arr[j] > arr[j + 1])
            {
                // Tukar elemen kalau yang kiri lebih gede
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        // Tampilkan array setelah setiap iterasi
        cout << "Hasil Pass ke-" << i + 1 << ": ";
        tampilkanArray(arr);

        // Kalau gak ada elemen yang ditukar, berarti udah selesai sorting-nya
        if (!swapped)
            break;
    }
}

int main()
{
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};

    cout << "Array Awal: ";
    tampilkanArray(arr);

    cout << "\nProses Sorting Dimulai:\n";
    bubbleSort(arr);

    cout << "\nArray Setelah Sorting: ";
    tampilkanArray(arr);

    return 0;
}

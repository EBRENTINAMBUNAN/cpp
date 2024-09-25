#include <iostream>
#include <iomanip>
using namespace std;

void konversiSuhu(float suhu, char pilihan);
void tampilkanHeader();
void tampilkanMenu();

int main()
{
    float suhu;
    char pilihan;
    char ulang = 'y';

    do
    {
        tampilkanHeader();
        tampilkanMenu();

        cout << "\nSilahkan pilih jenis suhu yang ingin dikonversi (1/2/3/4): ";
        cin >> pilihan;

        cout << "Masukkan nilai suhu: ";
        cin >> suhu;

        konversiSuhu(suhu, pilihan);

        cout << "\n\nApakah Anda ingin mengonversi lagi? (y/n): ";
        cin >> ulang;

    } while (ulang == 'y' || ulang == 'Y');

    cout << "\nTerima kasih telah menggunakan program konversi suhu!\n";
    return 0;
}

void konversiSuhu(float suhu, char pilihan)
{
    float celcius, reamur, fahrenheit, kelvin;

    cout << fixed << setprecision(2);

                         switch (pilihan)
    {
    case 'C':
    case 'c':
    case '1':
        reamur = suhu * 4.0 / 5.0;
        fahrenheit = (suhu * 9.0 / 5.0) + 32;
        kelvin = suhu + 273.15;
        cout << "\n"
             << suhu << " derajat Celcius ke Reamur = " << reamur << " R";
        cout << "\n"
             << suhu << " derajat Celcius ke Fahrenheit = " << fahrenheit << " F";
        cout << "\n"
             << suhu << " derajat Celcius ke Kelvin = " << kelvin << " K";
        break;

    case 'R':
    case 'r':
    case '2':
        celcius = suhu * 5.0 / 4.0;
        fahrenheit = (suhu * 9.0 / 4.0) + 32;
        kelvin = celcius + 273.15;
        cout << "\n"
             << suhu << " derajat Reamur ke Celcius = " << celcius << " C";
        cout << "\n"
             << suhu << " derajat Reamur ke Fahrenheit = " << fahrenheit << " F";
        cout << "\n"
             << suhu << " derajat Reamur ke Kelvin = " << kelvin << " K";
        break;

    case 'F':
    case 'f':
    case '3':
        celcius = (suhu - 32) * 5.0 / 9.0;
        reamur = (suhu - 32) * 4.0 / 9.0;
        kelvin = celcius + 273.15;
        cout << "\n"
             << suhu << " derajat Fahrenheit ke Celcius = " << celcius << " C";
        cout << "\n"
             << suhu << " derajat Fahrenheit ke Reamur = " << reamur << " R";
        cout << "\n"
             << suhu << " derajat Fahrenheit ke Kelvin = " << kelvin << " K";
        break;

    case 'K':
    case 'k':
    case '4':
        celcius = suhu - 273.15;
        reamur = (suhu - 273.15) * 4.0 / 5.0;
        fahrenheit = (suhu - 273.15) * 9.0 / 5.0 + 32;
        cout << "\n"
             << suhu << " derajat Kelvin ke Celcius = " << celcius << " C";
        cout << "\n"
             << suhu << " derajat Kelvin ke Reamur = " << reamur << " R";
        cout << "\n"
             << suhu << " derajat Kelvin ke Fahrenheit = " << fahrenheit << " F";
        break;

    default:
        cout << "Pilihan tidak valid! Silakan coba lagi.";
        break;
    }
}

void tampilkanHeader()
{
    cout << "=============================\n";
    cout << "    Program Konversi Suhu     \n";
    cout << "=============================\n";
}

void tampilkanMenu()
{
    cout << "\nJenis Konversi Suhu yang Tersedia:";
    cout << "\n| 1. C - Celcius";
    cout << "\n| 2. R - Reamur";
    cout << "\n| 3. F - Fahrenheit";
    cout << "\n| 4. K - Kelvin";
}

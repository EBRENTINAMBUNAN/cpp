#include <iostream>
using namespace std;

void konversiSuhu(float suhu, char pilihan);

int main()
{
    float suhu;
    char pilihan;
    char ulang = 'y';

    do
    {
        cout << "==============\n";
        cout << "Konversi Suhu\n";
        cout << "==============\n";
        cout << "| 1. C - Celcius\n";
        cout << "| 2. R - Reamur\n";
        cout << "| 3. F - Fahrenheit\n";
        cout << "| 4. K - Kelvin\n";
        cout << "Silahkan pilih jenis suhu yang ingin dikonversi (C/R/F/K): ";
        cin >> pilihan;

        cout << "Masukkan nilai suhu: ";
        cin >> suhu;

        konversiSuhu(suhu, pilihan);

        cout << "\nApakah Anda ingin mengonversi lagi? (y/n): ";
        cin >> ulang;

    } while (ulang == 'y' || ulang == 'Y');

    return 0;
}

void konversiSuhu(float suhu, char pilihan)
{
    float celcius, reamur, fahrenheit, kelvin;

    switch (pilihan)
    {
    case 'C':
    case 'c':
        reamur = suhu * 4.0 / 5.0;
        fahrenheit = (suhu * 9.0 / 5.0) + 32;
        kelvin = suhu + 273.15;
        cout << "\nCelcius: " << suhu << " C";
        cout << "\nReamur: " << reamur << " R";
        cout << "\nFahrenheit: " << fahrenheit << " F";
        cout << "\nKelvin: " << kelvin << " K";
        break;

    case 'R':
    case 'r':
        celcius = suhu * 5.0 / 4.0;
        fahrenheit = (suhu * 9.0 / 4.0) + 32;
        kelvin = celcius + 273.15;
        cout << "\nReamur: " << suhu << " R";
        cout << "\nCelcius: " << celcius << " C";
        cout << "\nFahrenheit: " << fahrenheit << " F";
        cout << "\nKelvin: " << kelvin << " K";
        break;

    case 'F':
    case 'f':
        celcius = (suhu - 32) * 5.0 / 9.0;
        reamur = (suhu - 32) * 4.0 / 9.0;
        kelvin = celcius + 273.15;
        cout << "\nFahrenheit: " << suhu << " F";
        cout << "\nCelcius: " << celcius << " C";
        cout << "\nReamur: " << reamur << " R";
        cout << "\nKelvin: " << kelvin << " K";
        break;

    case 'K':
    case 'k':
        celcius = suhu - 273.15;
        reamur = (suhu - 273.15) * 4.0 / 5.0;
        fahrenheit = (suhu - 273.15) * 9.0 / 5.0 + 32;
        cout << "\nKelvin: " << suhu << " K";
        cout << "\nCelcius: " << celcius << " C";
        cout << "\nReamur: " << reamur << " R";
        cout << "\nFahrenheit: " << fahrenheit << " F";
        break;

    default:
        cout << "Pilihan tidak valid!";
        break;
    }
}

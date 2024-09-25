#include <iostream>
#include <iomanip>
using namespace std;

void konversiMataUang(float jumlah, char asal, char tujuan);
void tampilkanHeader();
void tampilkanMenuAsal();
void tampilkanMenuTujuan(char asal);
string getNamaMataUang(char kode);

int main()
{
    float jumlah;
    char asal, tujuan;
    char ulang = 'y';

    do
    {
        tampilkanHeader();

        tampilkanMenuAsal();
        cout << "\nSilahkan pilih mata uang asal (1/2/3/4): ";
        cin >> asal;

        tampilkanMenuTujuan(asal);
        cout << "\nSilahkan pilih mata uang tujuan (1/2/3/4): ";
        cin >> tujuan;

        cout << "Masukkan jumlah mata uang: ";
        cin >> jumlah;

        konversiMataUang(jumlah, asal, tujuan);

        cout << "\n\nApakah Anda ingin mengonversi lagi? (y/n): ";
        cin >> ulang;

    } while (ulang == 'y' || ulang == 'Y');

    cout << "\nTerima kasih telah menggunakan program konversi mata uang!\n";
    return 0;
}

void konversiMataUang(float jumlah, char asal, char tujuan)
{

    const float rateUSDtoIDR = 15000.0;
    const float rateJPYtoIDR = 110.0;
    const float rateCNYtoIDR = 2300.0;

    float hasil = 0;

    if (asal == '1')
    {
        if (tujuan == '2')
            hasil = jumlah / rateUSDtoIDR;
        else if (tujuan == '3')
            hasil = jumlah / rateJPYtoIDR;
        else if (tujuan == '4')
            hasil = jumlah / rateCNYtoIDR;
    }
    else if (asal == '2')
    {
        if (tujuan == '1')
            hasil = jumlah * rateUSDtoIDR;
        else if (tujuan == '3')
            hasil = (jumlah * rateUSDtoIDR) / rateJPYtoIDR;
        else if (tujuan == '4')
            hasil = (jumlah * rateUSDtoIDR) / rateCNYtoIDR;
    }
    else if (asal == '3')
    {
        if (tujuan == '1')
            hasil = jumlah * rateJPYtoIDR;
        else if (tujuan == '2')
            hasil = (jumlah * rateJPYtoIDR) / rateUSDtoIDR;
        else if (tujuan == '4')
            hasil = (jumlah * rateJPYtoIDR) / rateCNYtoIDR;
    }
    else if (asal == '4')
    {
        if (tujuan == '1')
            hasil = jumlah * rateCNYtoIDR;
        else if (tujuan == '2')
            hasil = (jumlah * rateCNYtoIDR) / rateUSDtoIDR;
        else if (tujuan == '3')
            hasil = (jumlah * rateCNYtoIDR) / rateJPYtoIDR;
    }

    cout << fixed << setprecision(2);
    string mataUangAsal = getNamaMataUang(asal);
    string mataUangTujuan = getNamaMataUang(tujuan);

    cout << "\nBerhasil mengonversi " << jumlah << " " << mataUangAsal << " ke " << hasil << " " << mataUangTujuan;
}

void tampilkanHeader()
{
    cout << "=================================\n";
    cout << "    Program Konversi Mata Uang   \n";
    cout << "=================================\n";
}

void tampilkanMenuAsal()
{
    cout << "\nPilih Mata Uang Asal:";
    cout << "\n1. Rupiah (IDR)";
    cout << "\n2. Dollar Amerika (USD)";
    cout << "\n3. Yen Jepang (JPY)";
    cout << "\n4. Yuan China (CNY)";
}

void tampilkanMenuTujuan(char asal)
{
    cout << "\nPilih Mata Uang Tujuan:";

    if (asal != '1')
        cout << "\n1. Rupiah (IDR)";
    if (asal != '2')
        cout << "\n2. Dollar Amerika (USD)";
    if (asal != '3')
        cout << "\n3. Yen Jepang (JPY)";
    if (asal != '4')
        cout << "\n4. Yuan China (CNY)";
}

string getNamaMataUang(char kode)
{
    switch (kode)
    {
    case '1':
        return "IDR";
    case '2':
        return "USD";
    case '3':
        return "JPY";
    case '4':
        return "CNY";
    default:
        return "";
    }
}

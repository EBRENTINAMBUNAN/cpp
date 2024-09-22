#include <iostream>
#include <string>
using namespace std;

string determineKhodam(const string &name)
{
    int asciiSum = 0;

    for (char c : name)
    {
        asciiSum += static_cast<int>(c);
    }

    int khodamIndex = asciiSum % 5;

    string khodams[] = {
        "Kucing Garong", "Harimau Putih", "Naga Hijau", "Gajah Perkasa", "Elang Emas",
        "Kucing Tidur", "Harimau Cemilan", "Naga Lucu", "Gajah Pinky", "Elang Gabut",
        "Kucing Galau", "Harimau Joget", "Naga Kremes", "Gajah Keliling", "Elang Melet",
        "Kucing Oyen", "Harimau Ketawa", "Naga Nyengir", "Gajah Imut", "Elang Kuy",
        "Kucing Selengean", "Harimau Santai", "Naga Tiktok", "Gajah Ngantuk", "Elang Kocak",
        "Kucing Penjaga Hati", "Harimau Temenan", "Naga Gabut", "Gajah Pelupa", "Elang Tiduran",
        "Kucing Mager", "Harimau Kopi", "Naga Dodol", "Gajah Joget", "Elang Siaga",
        "Kucing Kocak", "Harimau Selfie", "Naga Serem", "Gajah Sate", "Elang Karaoke",
        "Kucing Kampung", "Harimau Malam", "Naga Koplo", "Gajah Terbang", "Elang Kue",
        "Kucing Populer", "Harimau Kribo", "Naga Sayur", "Gajah Tukang Nasi", "Elang Jajan",
        "Kucing Nyasar", "Harimau Kebingungan", "Naga Nyanyi", "Gajah Main Layang", "Elang Ngopi",
        "Kucing Lapar", "Harimau Cilik", "Naga Kocak", "Gajah Tersenyum", "Elang Suka Jalan",
        "Kucing Aneh", "Harimau Happy", "Naga Santai", "Gajah Bersahabat", "Elang Tukang Gosip",
        "Kucing Pemalas", "Harimau Tukang Masak", "Naga Bumbu", "Gajah Peluk", "Elang Wangi",
        "Kucing Si Tuan", "Harimau Pemarah", "Naga Sereal", "Gajah Gesit", "Elang Bobo Siang",
        "Kucing Butuh Liburan", "Harimau Putih Sihir", "Naga Pancing", "Gajah Jago Belanja", "Elang Setia",
        "Kucing Suka Drama", "Harimau Pose", "Naga Manis", "Gajah Bahagia", "Elang Misterius",
        "Kucing Misterius", "Harimau Jomblo", "Naga Hitam", "Gajah Penasaran", "Elang Ceria"};

    return khodams[khodamIndex];
}

int main()
{
    string name;

    char pilihan = 'y';
    while (pilihan == 'y')
    {
        cout << "Masukkan nama anda: ";
        getline(cin, name);

        string khodam = determineKhodam(name);

        cout << "Khodam anda adalah: " << khodam << endl
             << endl;

        cout << "\nApakah Anda ingin bermain lagi? (y/n): ";
        cin >> pilihan;
        cout << endl;
        cin.ignore();
    }
    cout << "Program telah berakhir, Terima kasih" << endl;
    return 0;
}

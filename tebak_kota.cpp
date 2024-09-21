#include <iostream>
#include <map>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    map<string, vector<string>> kota_dan_clue;

    kota_dan_clue["jakarta"] = {"Ibu kota Indonesia", "Terkenal dengan Monas", "Kota metropolitan terbesar di Indonesia"};
    kota_dan_clue["surabaya"] = {"Kota Pahlawan", "Kota terbesar kedua di Indonesia", "Terletak di Jawa Timur"};
    kota_dan_clue["bandung"] = {"Dikenal sebagai Paris van Java", "Kota Kembang", "Kota di Jawa Barat"};
    kota_dan_clue["yogyakarta"] = {"Terkenal dengan Candi Borobudur", "Dikenal sebagai Kota Pelajar", "Terletak di Jawa Tengah"};
    kota_dan_clue["medan"] = {"Kota terbesar di Sumatera Utara", "Dekat dengan Danau Toba", "Terkenal dengan Durian Ucok"};
    kota_dan_clue["denpasar"] = {"Ibukota Provinsi Bali", "Terkenal dengan Pantai Kuta", "Pariwisata menjadi sektor utama"};
    kota_dan_clue["makassar"] = {"Kota terbesar di Sulawesi Selatan", "Terkenal dengan Pantai Losari", "Pusat perdagangan Indonesia Timur"};
    kota_dan_clue["palembang"] = {"Terkenal dengan Jembatan Ampera", "Kota pempek", "Kota terbesar di Sumatera Selatan"};
    kota_dan_clue["balikpapan"] = {"Kota minyak", "Terletak di Kalimantan Timur", "Dekat dengan Ibu Kota Negara (IKN)"};
    kota_dan_clue["manado"] = {"Kota di Sulawesi Utara", "Terkenal dengan Taman Laut Bunaken", "Kota pesisir di Utara Indonesia"};
    kota_dan_clue["semarang"] = {"Ibukota Provinsi Jawa Tengah", "Terkenal dengan Lawang Sewu", "Kota di tepi Laut Jawa"};
    kota_dan_clue["malang"] = {"Dikenal dengan apel", "Kota di Jawa Timur", "Terkenal dengan suasana sejuk"};
    kota_dan_clue["pontianak"] = {"Kota Khatulistiwa", "Terletak di Kalimantan Barat", "Terkenal dengan Tugu Khatulistiwa"};
    kota_dan_clue["pekanbaru"] = {"Ibukota Provinsi Riau", "Terkenal dengan ladang minyak", "Kota di tepi Sungai Siak"};
    kota_dan_clue["padang"] = {"Ibukota Provinsi Sumatera Barat", "Terkenal dengan rendang", "Dekat dengan Pantai Padang"};
    kota_dan_clue["jambi"] = {"Ibukota Provinsi Jambi", "Terletak di Sumatera", "Terkenal dengan Candi Muaro Jambi"};
    kota_dan_clue["banda aceh"] = {"Ibukota Provinsi Aceh", "Terkenal dengan Masjid Raya Baiturrahman", "Kota paling barat di Indonesia"};
    kota_dan_clue["samarinda"] = {"Ibukota Provinsi Kalimantan Timur", "Dekat dengan Ibu Kota Negara (IKN)", "Kota di tepi Sungai Mahakam"};
    kota_dan_clue["banjarmasin"] = {"Ibukota Provinsi Kalimantan Selatan", "Terkenal dengan Pasar Terapung", "Kota di tepi Sungai Barito"};
    kota_dan_clue["gorontalo"] = {"Kota di Sulawesi Utara", "Terkenal dengan Benteng Otanaha", "Kota pesisir di Teluk Tomini"};
    kota_dan_clue["palu"] = {"Ibukota Provinsi Sulawesi Tengah", "Terkenal dengan Teluk Palu", "Kota di tepi Teluk Palu"};
    kota_dan_clue["ambon"] = {"Ibukota Provinsi Maluku", "Kota di Kepulauan Maluku", "Terkenal dengan rempah-rempah"};
    kota_dan_clue["kupang"] = {"Ibukota Provinsi Nusa Tenggara Timur", "Kota di Pulau Timor", "Dekat dengan perbatasan Timor Leste"};
    kota_dan_clue["tangerang"] = {"Kota satelit Jakarta", "Terkenal dengan industri", "Kota di Banten"};
    kota_dan_clue["depok"] = {"Kota penyangga Jakarta", "Terkenal dengan Universitas Indonesia", "Kota di Jawa Barat"};
    kota_dan_clue["bekasi"] = {"Kota satelit Jakarta", "Terkenal dengan industri", "Terletak di Jawa Barat"};
    kota_dan_clue["solo"] = {"Dikenal sebagai Kota Batik", "Terletak di Jawa Tengah", "Terkenal dengan Keraton Kasunanan"};
    kota_dan_clue["tasikmalaya"] = {"Kota di Jawa Barat", "Terkenal dengan bordir", "Kota dengan produk sandal khas"};
    kota_dan_clue["ciamis"] = {"Kota di Jawa Barat", "Dekat dengan Pantai Pangandaran", "Terkenal dengan galendo"};

    srand(time(0));

    char pilihan = 'y';
    while (pilihan == 'y')
    {
        auto it = kota_dan_clue.begin();
        advance(it, rand() % kota_dan_clue.size());
        string kota = it->first;
        vector<string> clue = it->second;

        cout << "\nSelamat datang di permainan tebak kota!\n";
        cout << "Anda akan diberikan petunjuk untuk menebak nama kota.\n";
        cout << "Anda memiliki 3 kesempatan untuk menebak kota yang benar.\n\n";

        for (int i = 0; i < 3; i++)
        {
            cout << "Clue " << i + 1 << ": " << clue[i] << endl;
            cout << "Tebak nama kota: ";
            string tebakan;
            getline(cin, tebakan);

            if (tebakan == kota)
            {
                cout << "Selamat! Tebakan Anda benar!\n";
                break;
            }
            else
            {
                cout << "Tebakan Anda salah.\n";
            }

            if (i == 2)
            {
                cout << "Kesempatan habis! Kota yang benar adalah: " << kota << endl;
            }
        }
        cout << "\nApakah Anda ingin bermain lagi? (y/n): ";
        cin >> pilihan;
        cin.ignore();
    }

    cout << "Terima kasih telah bermain!\n";
    return 0;
}

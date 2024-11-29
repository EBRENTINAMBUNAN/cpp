#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib>

using namespace std;

void delay(int ms)
{
    this_thread::sleep_for(chrono::milliseconds(ms));
}

void printWithEffect(const string &text, int speed = 50)
{
    for (char ch : text)
    {
        cout << ch;
        cout.flush();
        delay(speed);
    }
    cout << endl;
}

void hack()
{
    const string fakeIPs[] = {
        "192.168.1.1", "10.0.0.5", "172.16.0.2", "203.0.113.45", "8.8.8.8",
        "185.199.108.153", "198.51.100.42", "203.0.113.27"};

    const string fakeUsers[] = {"admin", "root", "user", "guest", "hacker"};

    printWithEffect("[+] Memulai koneksi ke server...\n");
    for (int i = 0; i < 5; i++)
    {
        cout << "[*] Menyambungkan ke IP: " << fakeIPs[rand() % 8] << endl;
        delay(500);
    }

    printWithEffect("\n[+] Mencoba login...\n");
    for (int i = 0; i < 10; i++)
    {
        cout << "    -> Login: " << fakeUsers[rand() % 5]
             << " | Status: " << (rand() % 2 ? "Gagal" : "Berhasil") << endl;
        delay(300);
    }

    printWithEffect("\n[+] Mengambil data...\n");
    for (int i = 0; i < 15; i++)
    {
        cout << "    -> Downloading file_" << rand() % 100 << ".dat"
             << " [" << rand() % 100 + 1 << "%]" << endl;
        delay(200);
    }

    printWithEffect("\n[+] Proses selesai. Data berhasil diambil!");
    printWithEffect("    File disimpan di folder: /root/hacked_data\n");
}

int main()
{
    srand(time(0));

    cout << "=========================================\n";
    cout << "          NO SYSTEM IS SAVE              \n";
    cout << "          BY EBREN TINAMBUNAN            \n";
    cout << "=========================================\n\n";

    hack();

    printWithEffect("\n[+] Sistem keluar. Selamat datang di dunia maya.");
    return 0;
}

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <chrono>
#include <thread>

using namespace std;

void showHeader()
{
    cout << "\033[1;36m";
    cout << "====================================================\n";
    cout << setw(45) << "PROGRAM CONVERT POIN IMPHNEN MENJADI SALDO DANA\n";
    cout << setw(36) << "BY EBREN TINAMBUNAN\n";
    cout << "====================================================\n";
    cout << "\033[0m";
}

int randomPoin()
{
    srand(static_cast<unsigned>(time(0)));
    return rand() % 4501 + 500;
}

void loadingAnimation(const string &message, int duration)
{
    cout << message;
    for (int i = 0; i < 3; ++i)
    {
        cout << ".";
        cout.flush();
        this_thread::sleep_for(chrono::milliseconds(duration));
    }
    cout << endl;
}

void progressBar(int duration)
{
    int barWidth = 50;
    cout << "\033[1;32m[";
    for (int i = 0; i < barWidth; ++i)
    {
        cout << "-";
        cout.flush();
        this_thread::sleep_for(chrono::milliseconds(duration / barWidth));
    }
    cout << "]\033[0m" << endl;
}

void convertEffect(int poin)
{
    cout << "\033[1;34mProses konversi poin menjadi saldo Dana sedang berlangsung...\033[0m\n";
    loadingAnimation("Memverifikasi poin", 500);
    loadingAnimation("Memproses konversi", 500);
    loadingAnimation("Mengirim saldo ke akun Dana", 500);

    cout << "\033[1;32m";
    progressBar(2000);

    cout << "Konversi berhasil! Anda telah menukar " << poin << " poin menjadi saldo Dana.\033[0m\n";
}

int main()
{
    string username;
    int poin = randomPoin();
    char pilihan;
    long long nomorDana;
    bool validDana = false;

    showHeader();

    cout << "\033[1;37mMasukkan nama Anda: \033[0m";
    getline(cin, username);

    cout << "\033[1;33mSisa poin kamu adalah " << poin << " poin\033[0m\n";
    cout << "\033[1;37mApakah mau di-convert ke Dana? (y/n): \033[0m";
    cin >> pilihan;

    if (pilihan == 'y' || pilihan == 'Y')
    {
        while (!validDana)
        {
            cout << "\033[1;37mMasukkan nomor Dana kamu (10-13 digit): \033[0m";
            cin >> nomorDana;
            if (to_string(nomorDana).length() >= 10 && to_string(nomorDana).length() <= 13)
            {
                validDana = true;
            }
            else
            {
                cout << "\033[1;31mNomor Dana tidak valid. Silakan coba lagi.\033[0m\n";
            }
        }

        convertEffect(poin);

        cout << "\033[1;32mSelamat " << username << "! Dana kamu telah berhasil dikirim.\033[0m\n";
    }
    else
    {
        cout << "\033[1;33mProgram telah berakhir, terima kasih!\033[0m\n";
    }

    return 0;
}

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <chrono>
#include <thread>

using namespace std;

void hackerEffect(const string &message, int delay)
{
    for (char c : message)
    {
        cout << c;
        cout.flush();
        this_thread::sleep_for(chrono::milliseconds(delay));
    }
}

void showHackerHeader()
{
    hackerEffect("\033[1;32m", 0);
    hackerEffect("======================================================\n", 10);
    hackerEffect("||       PROGRAM CONVERT POIN GRUP MENJADI SALDO DANA ||\n", 10);
    hackerEffect("||              Ingin Menjadi Programmer Handal       ||\n", 10);
    hackerEffect("||                   namun Enggan Ngoding             ||\n", 10);
    hackerEffect("||                   by EBREN TINAMBUNAN              ||\n", 10);
    hackerEffect("======================================================\n\n", 10);
    hackerEffect("\033[0m", 0);
}

int randomPoin()
{
    srand(static_cast<unsigned>(time(0)));
    return rand() % 4501 + 500; //
}

void hackerLoading(const string &message, int delay)
{
    hackerEffect(message, 20);
    for (int i = 0; i < 5; ++i)
    {
        cout << ".";
        cout.flush();
        this_thread::sleep_for(chrono::milliseconds(delay));
    }
    cout << endl;
}

void hackerProgressBar(int duration)
{
    int barWidth = 40;
    cout << "\033[1;32m[";
    for (int i = 0; i < barWidth; ++i)
    {
        cout << "#";
        cout.flush();
        this_thread::sleep_for(chrono::milliseconds(duration / barWidth));
    }
    cout << "]\033[0m" << endl;
}

void hackerConvertEffect(int poin)
{
    hackerLoading("Verifying FB group points", 100);
    hackerLoading("Processing conversion", 100);
    hackerLoading("Transmitting to Dana account", 100);

    hackerEffect("\033[1;32m", 0);
    hackerProgressBar(1500);

    hackerEffect(">>> Conversion SUCCESSFUL: ", 30);
    cout << poin << " FB group points converted to Dana balance.\033[0m\n";
}

int main()
{
    string username;
    int poin = randomPoin();
    char pilihan;
    long long nomorDana;
    bool validDana = false;

    showHackerHeader();

    hackerEffect(">>> Enter your Facebook username: ", 30);
    getline(cin, username);

    hackerEffect("\n>>> Retrieving your FB group points...\n", 30);
    this_thread::sleep_for(chrono::milliseconds(1000));
    hackerEffect("\033[1;32m>>> " + to_string(poin) + " points available in 'Ingin Menjadi Programmer Handal Namun Enggan Ngoding' group.\033[0m\n", 30);

    hackerEffect("\n>>> Convert points to Dana balance? (y/n): ", 30);
    cin >> pilihan;

    if (pilihan == 'y' || pilihan == 'Y')
    {
        while (!validDana)
        {
            hackerEffect(">>> Enter your Dana account number (10-13 digits): ", 30);
            cin >> nomorDana;
            if (to_string(nomorDana).length() >= 10 && to_string(nomorDana).length() <= 13)
            {
                validDana = true;
            }
            else
            {
                hackerEffect("\033[1;31mERROR: Invalid Dana number. Try again.\033[0m\n", 30);
            }
        }

        hackerConvertEffect(poin);

        hackerEffect("\033[1;32m>>> Transaction COMPLETE: Dana balance has been updated.\033[0m\n", 30);
    }
    else
    {
        hackerEffect("\033[1;31m>>> Operation CANCELED. Exiting program...\033[0m\n", 30);
    }

    return 0;
}

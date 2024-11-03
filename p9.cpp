#include <iostream>
using namespace std;

int main()
{
    int a = 3, b = 6, c = 0;
    int *ip = &a, *ip_b = &b;

    cout << "Sebelum ditukar" << endl;
    cout << "Nilai A : " << a << endl;
    cout << "Nilai B : " << b << endl
         << endl;

    c = *ip;
    *ip = *ip_b;
    *ip_b = c;

    cout << "\nSetelah ditukar:" << endl;
    cout << "Nilai A : " << *ip << endl;
    cout << "Nilai B : " << *ip_b << endl;

    return 0;
}
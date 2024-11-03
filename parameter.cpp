#include <iostream>
using namespace std;
#include <conio.h>

int tambah(int nilai1, int nilai2)
{
    return (nilai1 + nilai2);
}

void garis()
{
    cout << "=======================";
}

int main()
{
    int a, b, c;
    int nilai1, nilai2;
    c = tambah(nilai1, nilai2);

    cout << c << endl;
    garis();
    getch();
}
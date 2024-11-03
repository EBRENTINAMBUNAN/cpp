#include <iostream>
using namespace std;

int main()
{
    int var_abc = 5;
    int *pnt_xyz;

    cout << "deklarasi var abc = " << var_abc << endl;
    cout << "alamat memory var_abc = " << &var_abc << endl
         << endl;
    cout << "deklarasi pnt_xyz = " << endl;
    cout << "alamat memory pnt_xyz = " << *pnt_xyz << endl;
    cout << "nilai *pnt_xyz = " << *pnt_xyz << endl;
}
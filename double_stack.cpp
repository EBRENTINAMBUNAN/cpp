#include <iostream>
#include <iomanip>
#include <limits>
#include <unistd.h>
using namespace std;

class Stack
{
private:
    int *arr;
    int top1;
    int top2;
    int capacity;

public:
    Stack(int amount)
    {
        arr = new int[amount];
        capacity = amount;
        top1 = -1;     // Stack1 starts from the beginning
        top2 = amount; // Stack2 starts from the end
    }

    ~Stack()
    {
        delete[] arr;
    }

    void push(int value1, int value2)
    {
        if (isFull())
        {
            cout << "\033[1;31m"
                 << "Result : Error \n";
            cout << "Msg    : Stack penuh. Tidak bisa menambahkan elemen " << value1 << ".\n";
            cout << "Msg    : Stack penuh. Tidak bisa menambahkan elemen " << value2 << ".\n";
            cout << "===================================================================\033[0m\n";
            return;
        }

        arr[++top1] = value1;
        arr[--top2] = value2;

        cout << "\033[1;32m"
             << "Result : Success \n";
        cout << "Msg    : Elemen " << value1 << " berhasil ditambahkan ke Stack 1.\n";
        cout << "Msg    : Elemen " << value2 << " berhasil ditambahkan ke Stack 2.\n";
        cout << "===================================================================\033[0m\n";
    }

    void pop1()
    {
        if (isEmpty1())
        {
            cout << "\033[1;31m"
                 << "Result : Error \n";
            cout << "Msg    : Stack 1 kosong. Tidak ada elemen yang dapat dihapus.\n";
            cout << "===================================================================\033[0m\n";
            return;
        }

        cout << "\033[1;32m"
             << "Result : Success \n";
        cout << "Msg    : Elemen " << arr[top1--] << " berhasil dihapus dari Stack 1.\n";
        cout << "===================================================================\033[0m\n";
    }

    void pop2()
    {
        if (isEmpty2())
        {
            cout << "\033[1;31m"
                 << "Result : Error \n";
            cout << "Msg    : Stack 2 kosong. Tidak ada elemen yang dapat dihapus.\n";
            cout << "===================================================================\033[0m\n";
            return;
        }

        cout << "\033[1;32m"
             << "Result : Success \n";
        cout << "Msg    : Elemen " << arr[top2++] << " berhasil dihapus dari Stack 2.\n";
        cout << "===================================================================\033[0m\n";
    }

    bool isFull()
    {
        return top1 + 1 == top2;
    }

    bool isEmpty1()
    {
        return top1 == -1;
    }

    bool isEmpty2()
    {
        return top2 == capacity;
    }

    void display1()
    {
        if (isEmpty1())
        {
            cout << "\033[1;31m"
                 << "Result : Error \n";
            cout << "Msg    : Stack 1 kosong. Tidak ada elemen yang dapat ditampilkan.\n";
            cout << "===================================================================\033[0m\n";
            return;
        }

        cout << "\033[1;34mIsi Stack 1: ";
        for (int i = 0; i <= top1; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\033[0m" << endl;
    }

    void display2()
    {
        if (isEmpty2())
        {
            cout << "\033[1;31m"
                 << "Result : Error \n";
            cout << "Msg    : Stack 2 kosong. Tidak ada elemen yang dapat ditampilkan.\n";
            cout << "===================================================================\033[0m\n";
            return;
        }

        cout << "\033[1;34mIsi Stack 2: ";
        for (int i = capacity - 1; i >= top2; i--)
        {
            cout << arr[i] << " ";
        }
        cout << "\033[0m" << endl;
    }
};

void loading()
{
    cout << "\nLoading";
    for (int i = 0; i < 3; i++)
    {
        cout << ".";
        cout.flush();
        sleep(1);
    }
    cout << "\n\n";
}

void showHeader()
{
    cout << "====================================================\n";
    cout << "\033[1;36m" << setw(35) << "PROGRAM DOUBLE STACK INTERAKTIF\n"
         << "\033[0m";
    cout << "\033[1;36m" << setw(35) << "BY EBREN TINAMBUNAN\n"
         << "\033[0m";
    cout << "====================================================\n";
}

bool confirmContinue()
{
    char pilihan;
    while (true)
    {
        cout << "\n\033[1;33mIngin kembali ke menu? (y/n): \033[0m";
        cin >> pilihan;

        if (pilihan == 'y' || pilihan == 'Y')
        {
            return true;
        }
        else if (pilihan == 'n' || pilihan == 'N')
        {
            cout << "\033[1;31mProgram telah berakhir, Terima kasih...\033[0m\n";
            return false;
        }
        else
        {
            cout << "\033[1;31mInput tidak valid. Harap masukkan 'y' atau 'n'.\033[0m\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

int main()
{
    int ukuran, pilihan, nilai1, nilai2;
    bool lanjut = true;

    showHeader();

    cout << "\033[1;33mMasukkan jumlah maksimal stack: \033[0m";
    cin >> ukuran;

    loading();

    Stack stack(ukuran);

    do
    {
        cout << "\nDaftar Menu:\n";
        cout << "1. Push ke kedua stack\n2. Pop dari Stack 1\n3. Pop dari Stack 2\n4. Display Stack 1\n5. Display Stack 2\n6. Exit\n";
        cout << "\033[1;33mPilih Menu (1/2/3/4/5/6): \033[0m";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            cout << "\033[1;33mMasukkan elemen untuk Stack 1: \033[0m";
            cin >> nilai1;
            cout << "\033[1;33mMasukkan elemen untuk Stack 2: \033[0m";
            cin >> nilai2;
            stack.push(nilai1, nilai2);
            break;
        case 2:
            stack.pop1();
            break;
        case 3:
            stack.pop2();
            break;
        case 4:
            stack.display1();
            break;
        case 5:
            stack.display2();
            break;
        case 6:
            cout << "\033[1;31mProgram telah berakhir, Terima kasih....\033[0m\n";
            lanjut = false;
            break;
        default:
            cout << "\033[1;31mPilihan tidak valid. Silakan coba lagi.\033[0m\n";
        }

        if (pilihan != 6)
        {
            lanjut = confirmContinue();
        }

    } while (lanjut);

    return 0;
}

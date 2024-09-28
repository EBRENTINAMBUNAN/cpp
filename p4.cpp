#include <iostream>
#include <iomanip>
#include <limits>
#include <unistd.h>
using namespace std;

class Stack
{
private:
    int *arr;
    int top;
    int capacity;

public:
    Stack(int amount)
    {
        arr = new int[amount];
        capacity = amount;
        top = -1;
    }

    ~Stack()
    {
        delete[] arr;
    }

    void push(int value)
    {
        if (isFull())
        {
            cout << "\033[1;31m"
                 << "Result : Error \n";
            cout << "Msg    : Stack penuh. Tidak bisa menambahkan elemen " << value << ".\n";
            cout << "===================================================================\033[0m\n";
            return;
        }
        arr[++top] = value;
        cout << "\033[1;32m"
             << "Result : Success \n";
        cout << "Msg    : Elemen " << value << " berhasil ditambahkan ke stack.\n";
        cout << "===================================================================\033[0m\n";
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "\033[1;31m"
                 << "Result : Error \n";
            cout << "Msg    : Stack kosong. Tidak ada elemen yang dapat dihapus.\n";
            cout << "===================================================================\033[0m\n";
            return;
        }
        cout << "\033[1;32m"
             << "Result : Success \n";
        cout << "Msg    : Elemen " << arr[top--] << " berhasil dihapus dari stack.\n";
        cout << "===================================================================\033[0m\n";
    }

    int peek()
    {
        if (isEmpty())
        {
            cout << "\033[1;31m"
                 << "Result : Error \n";
            cout << "Msg    : Stack kosong. Tidak ada elemen untuk dilihat.\n";
            cout << "===================================================================\033[0m\n";
            throw underflow_error("Stack kosong. Tidak ada elemen untuk dilihat.\n");
        }
        return arr[top];
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "\033[1;31m"
                 << "Result : Error \n";
            cout << "Msg    : Stack kosong. Tidak ada elemen yang dapat ditampilkan.\n";
            cout << "===================================================================\033[0m\n";
            return;
        }
        cout << "\033[1;34mIsi stack: ";
        for (int i = 0; i <= top; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\033[0m" << endl;
    }

    bool isFull()
    {
        return top == capacity - 1;
    }

    bool isEmpty()
    {
        return top == -1;
    }

    int amount()
    {
        return top + 1;
    }

    void increaseCapacity(int newCapacity)
    {
        if (newCapacity <= capacity)
        {
            cout << "\033[1;31m"
                 << "Ukuran baru harus lebih besar dari kapasitas saat ini.\033[0m\n";
            return;
        }

        int *newArr = new int[newCapacity];
        for (int i = 0; i <= top; i++)
        {
            newArr[i] = arr[i];
        }

        delete[] arr;
        arr = newArr;
        capacity = newCapacity;

        cout << "\033[1;32m"
             << "Kapasitas stack berhasil ditingkatkan menjadi " << capacity << ".\033[0m\n";
    }
};

void getInput(int &var, const string &prompt)
{
    while (true)
    {
        cout << prompt;
        cin >> var;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Input tidak valid. Harap masukkan angka.\n";
        }
        else if (var == 0)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Input tidak valid. Harap masukkan angka lebih besar dari 0\n";
        }
        else
        {
            break;
        }
    }
}

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
    cout << "\033[1;36m" << setw(35) << "PROGRAM STACK INTERAKTIF\n"
         << "\033[0m";
    cout << "\033[1;36m" << setw(35) << "BY EBREN TINAMBUNAN\n"
         << "\033[0m";
    cout << "====================================================\n";
    cout << "\033[1;35m"
         << "Program ini mendemonstrasikan operasi pada stack dengan pilihan:\n"
         << "- Push: Menambah elemen ke stack\n"
         << "- Pop: Menghapus elemen dari stack\n"
         << "- Peek: Melihat elemen teratas\n"
         << "- Display: Menampilkan semua elemen stack\n"
         << "- Jumlah Stack: Menampilkan jumlah stack saat ini\n"
         << "- Tambah Kapasitas Stack: Menambah jumlah stack\n"
         << "\033[0m";
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
    int ukuran, pilihan, nilai, kapasitasBaru;
    bool lanjut = true;

    showHeader();

    getInput(ukuran, "\033[1;33mMasukkan jumlah maksimal stack: \033[0m");

    loading();

    Stack stack(ukuran);

    do
    {
        cout << "\nDaftar Menu:\n";
        cout << "1. Push\n2. Pop\n3. Peek\n4. Display\n5. Jumlah Stack\n6. Tambah Kapasitas Stack\n7. Exit\n";
        getInput(pilihan, "\033[1;33mPilih Menu (1/2/3/4/5/6/7): \033[0m");

        try
        {
            switch (pilihan)
            {
            case 1:
                getInput(nilai, "\033[1;33mMasukkan elemen: \033[0m");
                stack.push(nilai);
                break;
            case 2:
                stack.pop();
                break;
            case 3:
                cout << "\033[1;36mElemen teratas: " << stack.peek() << "\033[0m" << endl;
                break;
            case 4:
                stack.display();
                break;
            case 5:
                cout << "\033[1;36mJumlah stack saat ini: " << stack.amount() << "\033[0m" << endl;
                break;
            case 6:
                getInput(kapasitasBaru, "\033[1;33mMasukkan kapasitas baru untuk stack: \033[0m");
                stack.increaseCapacity(kapasitasBaru);
                break;
            case 7:
                cout << "\033[1;31mProgram telah berakhir, Terima kasih....\033[0m\n";
                lanjut = false;
                break;
            default:
                cout << "\033[1;31mPilihan tidak valid. Silakan coba lagi.\033[0m\n";
            }
        }
        catch (const exception &e)
        {
            cerr << e.what();
        }

        if (pilihan != 7)
        {
            lanjut = confirmContinue();
        }

    } while (lanjut);

    return 0;
}

#include <iostream>

void encryption(char* message, int* arr, int key, int sz) {

    for (size_t i = 0; i < sz; i++)
    {
        arr[i] = int(message[i]) + key;
    }
}

void decryption(char* message, int* arr, int key, int sz) {

    for (size_t i = 0; i < sz; i++)
    {
        message[i] = char(arr[i] - key);
    }

}

int coll(int sz) {
    int q = 0;

    for (size_t i = 2; i < sz; i++)
    {
        if (sz % i == 0)
        {
            q = sz / i;
            break;
        }
        else if (i == sz - 1) {
            q = sz / 2;
        }
    }
    return q;
}

void encryption2(char* mess, char** mess2, int col, int sz) {
    int a = 0;
    const int roww = (sz / col) + 1;

    for (size_t i = 0; i < col; i++)
    {
        for (size_t j = 0; j < roww; j++)
        {
            if (a < sz)
            {
                mess2[j][i] = mess[a];
                a++;
            }
            else {
                mess2[j][i] = '*';
            }
        }
    }

}

void dencryption2(char* messd, char** mess2, int col, int sz) {
    int a = 0;
    const int roww = (sz / col) + 1;

    for (size_t i = 0; i < col; i++)
    {
        for (size_t j = 0; j < roww; j++)
        {
            if (mess2[j][i] != '*')
            {
                messd[a] = mess2[j][i];
                a++;
            }
        }
    }
}

int main()
{
    ////// exercise 1

    char message[] = "Hello World";
    const int n = sizeof(message) - 1;
    int arr[n];
    char message2[n];

    encryption(message, arr, 3, n);

    decryption(message2, arr, 3, n);

    for (size_t i = 0; i < n; i++)
    {
        std::cout << message2[i];
    }
    std::cout << std::endl;

    ////////

    ////// exercise 2

    char mess[] = "Secret message for you";
    const int m = sizeof(mess) - 1;
    char messd[m];
    const int col = coll(m);
    const int row = (m / col) + 1;
    char** mess2 = new char* [row];

    for (size_t i = 0; i < row; i++)
    {
        mess2[i] = new char[col];
    }

    encryption2(mess, mess2, col, m);

    dencryption2(messd, mess2, col, m);

    for (size_t i = 0; i < m; i++)
    {
        std::cout << messd[i];
    }
    std::cout << std::endl;

    delete[]mess2;

    ////////

    system("pause");
    return 0;
}

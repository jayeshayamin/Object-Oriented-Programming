#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    fstream file;
    file.open("config.txt", ios::out | ios::in | ios::trunc);
    if (!file)
    {
        cout << "Error 1!";
        return -1;
    }
    file << "AAAAABBBBBCCCCC" << endl;
    file.close();
    file.open("config.txt", ios::in);
    if (!file)
    {
        cout << "Error 2!";
        return -1;
    }
    string n;
    while (getline(file, n))
        cout << n << endl;
    file.close();
    file.open("config.txt", ios::in | ios::out);
    if (!file)
    {
        cout << "Error 3!";
        return -1;
    }
    file.seekp(5);
    file << "XXXXX";
    file.close();
    file.open("config.txt", ios::in);
    if (!file)
    {
        cout << "Error 4!";
        return -1;
    }
    while (getline(file, n))
        cout << n << endl;
    file.close();
    return 0;
}
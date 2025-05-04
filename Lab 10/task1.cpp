#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    ifstream file1;
    file1.open("vehicles.txt");
    if (!file1)
    {
        cout << "Error: while opening file!" << endl;
        return -1;
    }
    string variable;
    while (getline(file1, variable))
    {
        cout << variable << endl;
    }
    file1.close();
    return 0;
}
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ofstream fileo("data_records.txt");
    if (!fileo)
    {
        cout << "Error0:" << endl;
        return 0;
    }
    fileo << "Record 1\nRecord 2\nRecord 3\nRecord 4";
    fileo.close();
    fileo.clear();
    ifstream file2("data_records.txt");
    if (!file2)
    {
        cout << "Error1:" << endl;
        return 1;
    }
    file2.seekg(20);
    string record3;
    while (getline(file2, record3))
    {
        cout << record3 << endl;
        break;
    }

    file2.close();
    return 9;
}
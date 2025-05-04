#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
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
        istringstream line(variable);
        string type, id, name, year, extradata, certification;
        getline(line, type, ',');
        getline(line, id, ',');
        getline(line, name, ',');
        getline(line, year, ',');
        getline(line, extradata, ',');
        getline(line, certification, ',');

        cout << "Type: " << type << endl;
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Year: " << year << endl;
        cout << "Extra Data: " << extradata << endl;
        cout << "Certification: " << certification << endl;
        cout << "-----------------------" << endl;
    }
    file1.close();
    return 0;
}
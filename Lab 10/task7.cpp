#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    ofstream file("sensor_log.txt");
    if (!file)
    {
        cout << "Error!";
        return -1;
    }
    file << "Sensor 1: 25.5 C" << endl;
    cout << "Current position: " << file.tellp() << endl;
    file << "SSensor 2: 98.1 %RH" << endl;
    cout << "Current position: " << file.tellp() << endl;
    file.close();
    return 0;
}
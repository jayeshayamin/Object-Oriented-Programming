#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ofstream out("large_log.txt");
    out << "First line of text\nSecond line of text\nThird line";
    out.close();

    ifstream in("large_log.txt");
    string line;
    streampos pos;

    getline(in, line);
    pos = in.tellg();
    cout << "First line: " << line << "\nPosition: " << pos << endl;

    getline(in, line);
    pos = in.tellg();
    cout << "Second line: " << line << "\nPosition: " << pos << endl;

    in.close();
    return 0;
}
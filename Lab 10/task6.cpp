#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

class Inventoryitem
{
public:
    int itemid;
    char itemname[20];

    Inventoryitem(int a = 0, const char *c = "x") : itemid(a)
    {
        strcpy(itemname, c);
        itemname[19] = '\0';
    }
    void display()
    {
        cout << "Item ID: " << itemid << endl;
        cout << "Item Name: " << itemname << endl;
    }
};
int main()
{
    int a;
    char name[20];
    cout << "Enter ItemID: ";
    cin >> a;
    cout << "\nEnter itemName: ";
    cin >> name;
    if (strlen(name) >= 20)
    {
        cout << "Error: name too long." << endl;
        return 0;
    }
    Inventoryitem I1(a, name);
    fstream file;
    file.open("inventory.dat", ios::binary | ios::out);
    if (!file)
    {
        cout << "Error opening file." << endl;
        return 0;
    }
    file.write(reinterpret_cast<char *>(&I1), sizeof(I1));
    file.close();
    Inventoryitem I2;
    file.open("inventory.dat", ios::binary | ios::in);
    if (!file)
    {
        cout << "Error!" << endl;
        return 0;
    }
    file.read(reinterpret_cast<char *>(&I2), sizeof(I2));
    I2.display();
    file.close();
    return 0;
}
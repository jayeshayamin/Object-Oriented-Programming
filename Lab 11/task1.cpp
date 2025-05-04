#include <iostream>
#include <exception>
#include <cstring>
using namespace std;

class Invalidvalueexception : public std::exception
{
public:
    const char *msg;
    Invalidvalueexception(const char *m)
    {
        msg = m;
    }
    const char *what() const noexcept override
    {
        return msg;
    }
};
void validateage(int age)
{
    try
    {
        if (age > 120 || age < 0)
            throw Invalidvalueexception("Somethings wrong with your age.");
    }
    catch (const Invalidvalueexception &obj)
    {
        cout << "New exception: " << obj.what() << endl;
    }
}
int main()
{
    int age = -5;
    validateage(age);
    return 0;
}
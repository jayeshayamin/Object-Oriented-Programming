#include <iostream>
#include <string>
#include <exception>
#include <math.h>
#include <typeinfo>
using namespace std;

class Negativenumberexception : public exception
{
public:
    const char *what() const noexcept override
    {
        return "Negative number invalid.";
    }
};
class Invalidtypeexception : public exception
{
public:
    const char *what() const noexcept override
    {
        return "Data type invalid.";
    }
};
template <typename T>
auto sqrtfunc(T a) -> decltype(sqrt(a))
{
    try
    {
        if (a < 0)
            throw Negativenumberexception();
        if ((sizeof(a) == sizeof(char)) || (sizeof(a) == sizeof(string)) || (sizeof(a) == sizeof(const char *)))
            throw Invalidtypeexception();

        return sqrt(a);
    }
    catch (const Negativenumberexception &obj)
    {
        cout << obj.what() << '\n';
    }
    catch (const Invalidtypeexception &obj)
    {
        cout << obj.what() << '\n';
    }
}
int main()
{
    int a;
    cout << "Enter a: ";
    cin >> a;
    sqrtfunc(a);
    return 0;
}
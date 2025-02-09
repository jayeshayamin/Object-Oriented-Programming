#include <iostream>
using namespace std;
int *memoryallocation(int size)
{
    int *array = new int[size];
    return array;
}
int *userinput(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "Enter input " << i + 1 << endl;
        cin >> array[i];
    }
    return array;
}
int sumfunc(int *array, int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += array[i];
    }
    return sum;
}
float average(int size, int sum)
{
    float avg = (float)sum / (float)size;
    return avg;
}
int maxofarray(int *array, int size)
{
    int max = 0;
    for (int i = 0; i < size; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }
    return max;
}
void freememory(int *array)
{
    delete[] array;
    cout << "Memory has been freed." << endl;
}
int main()
{
    int size, sum;
    cout << "Enter the size of the array" << endl;
    cin >> size;
    int *array = memoryallocation(size);
    userinput(array, size);
    sum = sumfunc(array, size);
    cout << "The sum of the array is " << sum << endl;
    cout << "The average of the array is " << average(size, sum) << endl;
    cout << "The maximum element in the array is " << maxofarray(array, size) << endl;
    freememory(array);

    return 0;
}
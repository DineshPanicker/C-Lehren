#include <iostream>

using namespace std;

class BaseData
{
public:
    int *data;
    BaseData(int size)
    {
        data = new int[size];
    }

    virtual ~BaseData() // This should be virtual
    {
        cout << "BaseData destructor is running!" << endl;
        delete[] data;
    }
};

class DerivedData : public BaseData
{
public:
    int *extra_data;
    DerivedData(int size, int extra_size) : BaseData(size)
    {
        extra_data = new int[extra_size];
    }

    ~DerivedData()
    {
        cout << "DerivedData destructor is running!" << endl;
        delete[] extra_data;
    }
};

int main()
{
    BaseData *array[] =
        {
            new BaseData(5),
            new DerivedData(4, 4)};

    for (int i = 0; i < 2; i++)
        delete array[i]; // Potential issue: Base class destructor is not virtual

    return 0;
}

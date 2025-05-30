#include <iostream>
using namespace std;

class MyInt
{
public:
    explicit MyInt(int *p = nullptr) { data = p; }
    ~MyInt()
    {
        delete data;
        cout << "Deallocated data" << endl;
    }
    int &operator*() { return *data; }

private:
    int *data;
};

int main()
{
    int *p = new int(10);
    MyInt myint = MyInt(p);
    cout << *myint << endl;
    return 0;
} // pointer gets deallocated
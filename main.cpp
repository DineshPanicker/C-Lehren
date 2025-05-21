#include <iostream>

using namespace std;

int func(int *y)
{
    cout << "Address of y: " << &y << endl;
    *y = 9;
    return *y;
}

int main()
{
    int x = 3;
    cout << "Address of x is : " << &x << endl;
    int z = func(&x);
    cout << "Adress of z is : " << &z << endl;
    cout << "After calling func(), x = " << x << endl;
    cout << "After calling func(), z= " << z << endl;
    return 0;
}
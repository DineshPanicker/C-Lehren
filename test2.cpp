#include <iostream>

using namespace std;

class Rectangle
{
private:
    double length;
    double width;

public:
    void setDimensions(double l, double w)
    {
        length = l;
        width = w;
    }
    double perimeter();
};

double Rectangle::perimeter()
{
    return 2 * (length + width);
}

int main()
{
    Rectangle rectangle1;
    rectangle1.setDimensions(10, 20);

    cout << "Perimeter: " << rectangle1.perimeter() << endl;

    return 0;
}
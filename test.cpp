#include <iostream>
#include <string>
using namespace std;

class Employee
{
public:
    string name;

    void set_salary(double potential_salary)
    {
        if (potential_salary < 0)
            salary = 0;
        else
            salary = potential_salary;
    }
    double get_salary()
    {
        return salary;
    }

    void print_bonus()
    {
        cout << name << " bonus: " << calculate_bonus() << endl;
    }

private:
    double salary;

    double calculate_bonus()
    {
        return salary * 0.10;
    }
};

int main()
{
    Employee emp1;
    emp1.name = "Dinesh";
    emp1.set_salary(50000);
    cout << emp1.name << endl;
    cout << "Salary " << emp1.get_salary() << endl;
    emp1.print_bonus();

    return 0;
}
#include <iostream>
using namespace std;

struct Employee
{
    string employeeID;
    string name;
    string department;
    float salary;
};

int main()
{
    Employee *employee;

    int n;

    cout << "enter the number of employees: ";
    cin >> n;

    employee = new Employee[n];

    for (int i = 0; i < n; i++)
    {
        cout << "enter employee " << i + 1 << " name: ";
        cin >> employee[i].name;
        cout << "enter employee " << i + 1 << " ID: ";
        cin >> employee[i].employeeID;
        cout << "enter employee " << i + 1 << " department: ";
        cin >> employee[i].department;
        cout << "enter employee " << i + 1 << " salary: ";
        cin >> employee[i].salary;
    }

    int op;

    cout << "enter 1 to display employees and 2 for searching: ";
    cin >> op;

    string id;

    if (op == 2)
    {
        cout << "enter employee's id: ";
        cin >> id;

        for (int i = 0; i < n; i++)
        {
            if (id == employee[i].employeeID)
            {
                cout << "employee name: " << employee[i].name << endl;
                cout << "employee department: " << employee[i].department << endl;
                cout << "employee salary: " << employee[i].salary << endl;
            }
        }
    }
    else if (op == 1)
    {

        for (int i = 0; i < n; i++)
        {
            cout << "employee " << i + 1 << " ID: " << employee[i].employeeID << endl;
            cout << "employee " << i + 1 << " name: " << employee[i].name << endl;
            cout << "employee " << i + 1 << " department: " << employee[i].department << endl;
            cout << "employee " << i + 1 << " salary: " << employee[i].salary << endl;
        }
    }
    else
    {
        cout << "employee does not exist.";
    }

    delete[] employee;

    return 0;
}

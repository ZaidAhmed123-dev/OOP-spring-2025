#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the size of the array\n";
    cin >> n;

    int *arr;

    arr = new int[n];

    cout << "enter the numbers of the array: \n";

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int sum = 0, avg, max = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    avg = sum / n;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    cout << "sum: " << sum << "\naverage: " << avg << "\nmaximum value: " << max;

    delete[] arr;
}

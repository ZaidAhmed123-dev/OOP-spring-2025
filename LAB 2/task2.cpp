#include <iostream>
using namespace std;

int main()
{
    int rows, cols;
    cout << "enter the number of rows anf columns\n";
    cin >> rows;
    cin >> cols;

    int **matrix = new int *[rows];

    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new int[cols];
    }

    for (int i = 0; i < rows; i++)
    {
        cout << "enter the elements of row " << i + 1 << ": \n";
        for (int j = 0; j < cols; j++)
        {
            cin >> matrix[i][j];
        }
    }

    int **add = new int *[rows];

    for (int i = 0; i < rows; i++)
    {
        add[i] = new int[cols];
    }

    int **sub = new int *[rows];

    for (int i = 0; i < rows; i++)
    {
        sub[i] = new int[cols];
    }

    int **mul = new int *[rows];

    for (int i = 0; i < rows; i++)
    {
        mul[i] = new int[cols];
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            add[i][j] = 0;
            sub[i][j] = 0;
            mul[i][j] = 0;
        }
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            add[i][j] = matrix[i][j] + matrix[i][j];
        }
    }

    cout << "matrix addition: \n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << add[i][j] << " ";
        }

        cout << endl;
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            sub[i][j] = matrix[i][j] - matrix[i][j];
        }
    }

    cout << "matrix subtraction: \n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << sub[i][j] << " ";
        }

        cout << endl;
    }

    if (rows == cols)
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                for (int k = 0; k < rows; k++)
                {
                    mul[i][j] += (matrix[i][k] * matrix[k][j]);
                }
            }
        }

        cout << "matrix multiplication: \n";
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << mul[i][j] << " ";
            }

            cout << endl;
        }
    }
    else
    {
        cout << "multiplication is not possible";
    }

    for (int i = 0; i < rows; i++)
    {
        delete[] matrix[i];
        delete[] add[i];
        delete[] sub[i];
        delete[] mul[i];
    }

    delete[] matrix;
    delete[] add;
    delete[] sub;
    delete[] mul;

    return 0;
}

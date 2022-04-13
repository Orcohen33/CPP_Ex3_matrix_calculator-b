#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include "sources/Matrix.hpp"
using namespace std;
using namespace zich;
vector<double> randMat(int rows, int cols)
{
    vector<double> arr = vector<double>((size_t)(rows * cols), 0);
    for (size_t i = 0; i < rows * cols; i++)
    {
        arr[i] = rand() % 10;
    }
    return arr;
}

int main()
{
    Matrix m1 = Matrix(randMat(3, 3), 3, 3);
    Matrix m2 = Matrix(randMat(3, 3), 3, 3);

    cout << "First matrix :\n"
         << m1 << endl;
    cout << "Second matrix :\n"
         << m2 << endl;

    while (true)
    {
        cout << "------------------ MENU ------------------\n"
                "1. '+'\n"
                "2. '-'\n"
                "3. '*'\n"
                "4. '++' for first matrix\n"
                "5. '++' for second matrix\n"
                "6. '--' for first matrix\n"
                "7. '--' for second matrix\n"
                "8. '>'\n"
                "9. '>='\n"
                "10. '<'\n"
                "11. '<='\n"
                "12. '==' 0 is False, 1 is True\n"
                "13. '!=' 0 is True, 1 is False\n"
                "14. Exit\n"
                "------------------------------------------\n";
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Addition:\n";
            cout << m1 + m2 << endl;
            break;
        case 2:
            cout << "Subtraction:\n";
            cout << m1 - m2 << endl;
            break;
        case 3:
            cout << "Multiplication:\n";
            cout << m1 * m2 << endl;
            break;
        case 4:
            cout << "Increment first matrix:\n";
            m1++;
            cout << m1 << endl;
            break;
        case 5:
            cout << "Increment second matrix:\n";
            m2++;
            cout << m2 << endl;
            break;
        case 6:
            cout << "Decrement first matrix:\n";
            m1--;
            cout << m1 << endl;
            break;
        case 7:
            cout << "Decrement second matrix:\n";
            m2--;
            cout << m2 << endl;
            break;
        case 8:
            cout << "Compare first matrix with second matrix:\n";
            if (m1 > m2)
            {
                cout << "True" << endl;
            }
            else
            {
                cout << "False" << endl;
            }
            break;
        case 9:
            cout << "Compare first matrix with second matrix:\n";
            if (m1 >= m2)
            {
                cout << "True" << endl;
            }
            else
            {
                cout << "False" << endl;
            }
            break;
        case 10:
            cout << "Compare first matrix with second matrix:\n";
            if (m1 < m2)
            {
                cout << "True" << endl;
            }
            else
            {
                cout << "False" << endl;
            }
            break;
        case 11:
            cout << "Compare first matrix with second matrix:\n";
            if (m1 <= m2)
            {
                cout << "True" << endl;
            }
            else
            {
                cout << "False" << endl;
            }
            break;
        case 12:
            cout << "Compare first matrix with second matrix:\n";
            if (m1 == m2)
            {
                cout << "True" << endl;
            }
            else
            {
                cout << "False" << endl;
            }
            break;
        case 13:
            cout << "Compare first matrix with second matrix:\n";
            if (m1 != m2)
            {
                cout << "True" << endl;
            }
            else
            {
                cout << "False" << endl;
            }
            break;
        case 14:
            return 0;
        default:
            cout << "Invalid choice\n";
        }
    }

    return 0;
}